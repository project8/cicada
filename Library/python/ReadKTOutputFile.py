#!/usr/bin/env python

'''
Example of how to open and read a Katydid output file.
'''

import CicadaPy
CicadaPy.loadLibraries(True)

from ROOT import TFile, TTreeReader, TTreeReaderValue

def ReadKTOutputFile(filename,var,katydid=False):
    # Open the ROOT file
    file = TFile.Open(filename)
    if not file:
        raise FileNotFoundError("File {} does not exist".format(filename))

    # Extract tree from file
    tree = file.Get("multiTrackEvents")
    # Create TTreeReader
    treeReader = TTreeReader(tree)
    # Create object TMultiTrackEventData to "point" to the object "Event" in the tree
    if katydid:
        import ROOT.Katydid as KT
    else:
        import ROOT.Cicada as KT
    multiTrackEvents = TTreeReaderValue(KT.TMultiTrackEventData)(treeReader, "Event")

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
    args = p.parse_args()

    print("Found {} elements for {}".format(len(ReadKTOutputFile(args.input, args.branch,args.katydid)),args.branch))
