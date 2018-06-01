#!/usr/bin/env python

'''
Name: ReadKTOutputFile
Author: MG 
Date: 2018/05/10
Purpose: 
    Example of how to open and read a Katydid output file.
    Can read 
'''

import CicadaPy
CicadaPy.loadLibraries(True)

from ROOT import TFile, TTreeReader, TTreeReaderValue
import sys

def ReadKTOutputFile(filename,var,katydid=False,objectType="TMultiTrackEventData",name="multiTrackEvents:Event"):
    '''
    Read a ROOT file and returns specified content.
    filename (str): name of the ROOT file
    var (str/list): Variable to extract from the object
    katydid (bool): Katydid (true) or Cicada (false) namespace
    objectType (str): class name of the object to read
    name (str:str): names of the tree and of the object to read, separated by a ":"
    '''
    # Open the ROOT file
    file = TFile.Open(filename)
    if not file:
        raise FileNotFoundError("File {} does not exist".format(filename))
    # Extract tree and object names
    # names[0]: name of the tree
    # names[1]: name of the object in the tree
    names = name.split(":")
    # Extract tree from file
    tree = file.Get(str(names[0]))
    # Create TTreeReader
    treeReader = TTreeReader(tree)
    # Create object TMultiTrackEventData to "point" to the object "Event" in the tree
    if katydid:
        import ROOT.Katydid as KT
    else:
        import ROOT.Cicada as KT
    if hasattr(KT,objectType):
        multiTrackEvents = TTreeReaderValue(getattr(KT,objectType))(treeReader, names[1])
    else:
        print("Couldn't find type <{}> in module; exiting!".format(objectType))
        sys.exit(1)

    result = {}
    if isinstance(var,list):
        for key in var:
            result.update({key:[]})
    elif isinstance(var,str):
        result.update({var: []})
    else:
        print("{} not a list or a string; exiting!".format(var))
    
    for var,_ in result.items():
        # Analyze var to see if we are looking for a subTree
        subArg = var.split(".")

        n=0
        # Go through the events
        if len(subArg)==1:
            while treeReader.Next():
                function = getattr(multiTrackEvents,"Get{}".format(subArg[0]))
                result[var].append(function())
                n+=1
        else:
            while treeReader.Next():
                function = getattr(multiTrackEvents,"Get{}".format(subArg[0]))
                obj = function()
                subList = []
                for i in range(multiTrackEvents.GetTracks().GetEntries()):
                    function = getattr(getattr(obj,"At")(i),"Get{}".format(subArg[1]))
                    subList.append(function())
                result[var].append(subList)
                n+=1
        treeReader.Restart()
        if n==0:
            print("Error: no data found; wrong branch? or wrong namespace (Cicada/Katydid) -- maybe, try '-k'/add True as last argument?")
    if len(result.keys())==1:
        return result[list(result.keys())[0]]
    return result

if __name__ =="__main__":
    print('\n P8 Katydid output file reader example\n')
    import argparse
    p = argparse.ArgumentParser(description='''
        Katydid output file reader script
    ''')
    p.add_argument('-i','--input',
                   help='ROOT input file',
                   type=str)
    p.add_argument('-b','--branch',
                   help='Branch to read in the TMultiTrackEventData object',
                   nargs='+',
                   default="StartTimeInAcq")
    p.add_argument('-k','--katydid',
                   help='Flag stating Katydid namespace should be used instead of Cicada',
                   action='store_true',
                   required=False,
                   default=False)
    p.add_argument('-t','--type',
                   help='Object Type to be read',
                   type=str,
                   required=False,
                   default="TMultiTrackEventData")
    p.add_argument('-n','--name',
                   help='Object and Tree Name to be read, separated by a ":" (ex: multiTrackEvents:Event)',
                   type=str,
                   required=False,
                   default="multiTrackEvents:Event")
    args = p.parse_args()

    result = ReadKTOutputFile(args.input, args.branch, katydid=args.katydid, objectType=args.type, name=args.name)
    if isinstance(result,dict):
        nElements=len(result[list(result.keys())[0]])
    else:
        nElements = len(result)
    print("Found {} elements for {}".format(nElements,args.branch))
