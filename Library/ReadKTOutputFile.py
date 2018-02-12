#!/usr/bin/env python

'''
Example of how to open and read a Katydid output file.
'''

import CicadaPy

import ROOT.Katydid as KT
from ROOT import TFile, TTreeReader, TTreeReaderValue

# Change to point to the ROOT file you want
filename = "../../scripts/PhaseI_analysis_roofit/events_000001097_katydid_v2.7.0_concat.root"
file = TFile.Open(filename)
if not file:
    raise FileNotFoundError("File {} does not exist".format(filename))

# Extract tree from file
tree = file.Get("multiTrackEvents")
# Create TTreeReader
treeReader = TTreeReader(tree)
# Create object TMultiTrackEventData to "point" to the object "Event" in the tree
multiTrackEvents = TTreeReaderValue(KT.TMultiTrackEventData)(treeReader, "Event")
# Go through the events
while treeReader.Next():
    print(multiTrackEvents.GetStartTimeInAcq())
