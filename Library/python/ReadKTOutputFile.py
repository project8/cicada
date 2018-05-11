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

    # Analyze var to see if we are looking for a subTree
    subArg = var.split(".")

    resultList = []
    # Go through the events
        
    if len(subArg)==1:
        while treeReader.Next():
            function = getattr(multiTrackEvents,"Get{}".format(subArg[0]))
            resultList.append(function())
    else:
        while treeReader.Next():
            function = getattr(multiTrackEvents,"Get{}".format(subArg[0]))
            obj = function()
            subList = []
            for i in range(multiTrackEvents.GetTracks().GetEntries()-1):
                function = getattr(getattr(obj,"At")(i),"Get{}".format(subArg[1]))
                subList.append(function())
            resultList.append(subList)
    if len(resultList)==0:
        print("Error: no data found; wrong branch? or wrong namespace (Cicada/Katydid) -- maybe, try '-k'?")
    return resultList

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
                   type=str,
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

    nElements = len(ReadKTOutputFile(args.input, args.branch, katydid=args.katydid, objectType=args.type, name=args.name))
    print("Found {} elements for {}".format(nElements,args.branch))
