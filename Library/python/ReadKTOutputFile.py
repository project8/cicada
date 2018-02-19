#!/usr/bin/env python

'''
Example of how to open and read a Katydid output file.
'''

import CicadaPy
CicadaPy.loadLibraries()

import ROOT.Katydid as KT
from ROOT import TFile, TTreeReader, TTreeReaderValue

def ReadKTOutputFile(filename,var):
    # Open the ROOT file
    file = TFile.Open(filename)
    if not file:
        raise FileNotFoundError("File {} does not exist".format(filename))

    # Extract tree from file
    tree = file.Get("multiTrackEvents")
    # Create TTreeReader
    treeReader = TTreeReader(tree)
    # Create object TMultiTrackEventData to "point" to the object "Event" in the tree
    multiTrackEvents = TTreeReaderValue(KT.TMultiTrackEventData)(treeReader, "Event")

    resultList = []
    # Go through the events
    while treeReader.Next():
        function = getattr(multiTrackEvents,"Get{}".format(var))
        resultList.append(function())
        print(resultList[-1])
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
    args = p.parse_args()

    ReadKTOutputFile(args.input, args.branch)
