/**
 @file BasicTest.cc
 @brief Test the reading of a Katydid output file
 @details 
 Basic test for making sure the library is working on Katydid output results.
 The first argument given by the user is used to open a ROOT file and extract the tree of TMultiTrackEventData.
 For each entry of this tree, the StartTimeInAcq is displayed.
 @author M. Guigue
 @date Feb 9, 2018
 */

#include "logger.hh"

#include "TFile.h"
#include "TTree.h"
#include "CROOTData.hh"

LOGGER(bt, "BasicTest");

int main(int argc, char *argv[]){
	// Testing the number of arguments
	if (argc<2) {
		LERROR(bt,"No argument provided; exiting...");
		return 1;
	}
	LINFO(bt, "Reading file:\t" << argv[1]);

	TFile* myFile = new TFile(argv[1], "READ");
	TTree* myTree;
	myFile->GetObject("multiTrackEvents", myTree);

	// Change Katydid into Cicada if necessary
	Cicada::TMultiTrackEventData *myEvent = 0;
	myTree->SetBranchAddress("Event", &myEvent);
	for( int i=0; i<myTree->GetEntries(); ++i) {
		myTree->GetEntry(i);
		LINFO(bt,"StartTimeInAcq: " << myEvent->GetStartTimeInAcq());
	}
	return 1;
}

