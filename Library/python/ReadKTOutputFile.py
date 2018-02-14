#!/usr/bin/env python

'''
Example of how to open and read a Katydid output file.
'''

import CicadaPy

import ROOT.Katydid as KT
from ROOT import TFile, TTreeReader, TTreeReaderValue

def ReadKTOutputFile(filename,var):
    # Change to point to the ROOT file you want
    # filename = "../../scripts/PhaseI_analysis_roofit/events_000001097_katydid_v2.7.0_concat.root"
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
        exec("resultList.append(multiTrackEvents.Get{}())\n".format(var))
        print(resultList[-1])
    return resultList

if __name__ =="__main__":
    print('\n P8 Katydid output file reader example\n')
    import argparse
    p = argparse.ArgumentParser(description='''
        Katydid output file reader script
    ''')
    p.add_argument('-i','--input',
                   help='Input file',
                   type=str)
    p.add_argument('-b','--branch',
                   help='Branch',
                   type=str,
                   default="StartTimeInAcq")
    args = p.parse_args()

    ReadKTOutputFile(args.input, args.branch)
