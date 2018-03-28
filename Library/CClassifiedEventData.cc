/**
 @file CClassifiedEventData.cc
 @brief Contains TClassifiedEventData
 @details Contains the definition of the branches saved in the Katydid output for a classified event data
 @author E. Zayas
 @date Mar 22, 2018
 */

#include "logger.hh"

#include "CClassifiedEventData.hh"
#include "TClonesArray.h"

#include <iostream>

ClassImp(Cicada::TClassifiedEventData);

namespace Cicada
{

    TClassifiedEventData::TClassifiedEventData() : TObject(),
            fComponent(0), fAcquisitionID(0), fEventID(0), fTotalEventSequences(0),
            fStartTimeInRunC(0.), fStartTimeInAcq(0.), fEndTimeInRunC(0.),fTimeLength(0.),
            fStartFrequency(0.), fEndFrequency(0.), fMinimumFrequency(0.), fMaximumFrequency(0.), fFrequencyWidth(0.),
            fStartTimeInRunCSigma(0.), fEndTimeInRunCSigma(0.), fTimeLengthSigma(0.),
            fStartFrequencySigma(0.), fEndFrequencySigma(0.), fFrequencyWidthSigma(0.),
            fFirstTrackID(0), fFirstTrackTimeLength(0.), fFirstTrackFrequencyWidth(0.), fFirstTrackSlope(0.), fFirstTrackIntercept(0.), fFirstTrackTotalPower(0.),
            fUnknownEventTopology(false)
    {
        // this cannot be initialized in the initializer list because ROOT
        static const std::string className = std::string(TOSTRING(NAMESPACE)) + "::TProcessedTrackData";
        static const std::string otherClassName = std::string(TOSTRING(NAMESPACE)) + "::TClassifierResultsData";
        fTracks = new TClonesArray(className.c_str(), 20);
        fClassifierResults = new TClonesArray(otherClassName.c_str(), 20);
    }

    TClassifiedEventData::TClassifiedEventData(const TClassifiedEventData& orig) : TObject(orig),
            fComponent(orig.fComponent), fAcquisitionID(orig.fAcquisitionID), fEventID(orig.fEventID), fTotalEventSequences(orig.fTotalEventSequences),
            fStartTimeInRunC(orig.fStartTimeInRunC), fStartTimeInAcq(orig.fStartTimeInAcq), fEndTimeInRunC(orig.fEndTimeInRunC),fTimeLength(orig.fTimeLength),
            fStartFrequency(orig.fStartFrequency), fEndFrequency(orig.fEndFrequency), fMinimumFrequency(orig.fMaximumFrequency), fMaximumFrequency(orig.fMinimumFrequency), fFrequencyWidth(orig.fFrequencyWidth),
            fStartTimeInRunCSigma(orig.fStartTimeInRunCSigma), fEndTimeInRunCSigma(orig.fEndTimeInRunCSigma), fTimeLengthSigma(orig.fTimeLengthSigma),
            fStartFrequencySigma(orig.fStartFrequencySigma), fEndFrequencySigma(orig.fEndFrequencySigma), fFrequencyWidthSigma(orig.fFrequencyWidthSigma),
            fFirstTrackID(orig.fFirstTrackID), fFirstTrackTimeLength(orig.fFirstTrackTimeLength), fFirstTrackFrequencyWidth(orig.fFirstTrackFrequencyWidth), fFirstTrackSlope(orig.fFirstTrackSlope), fFirstTrackIntercept(orig.fFirstTrackIntercept), fFirstTrackTotalPower(orig.fFirstTrackTotalPower),
            fUnknownEventTopology(orig.fUnknownEventTopology)
    {
        // this cannot be initialized in the initializer list because ROOT
        fTracks = new TClonesArray(*orig.fTracks);
        fClassifierResults = new TClonesArray(*orig.fClassifierResults);
    }

    TClassifiedEventData::~TClassifiedEventData()
    {
        fTracks->Clear();
        fClassifierResults->Clear();
    }

    TObject* TClassifiedEventData::Clone(const char* newname)
    {
        TClassifiedEventData* newData = new TClassifiedEventData(*this);
        return newData;
    }

    TClassifiedEventData& TClassifiedEventData::operator=(const TClassifiedEventData& rhs)
    {
        fComponent = rhs.fComponent; fAcquisitionID = rhs.fAcquisitionID; fEventID = rhs.fEventID; fTotalEventSequences = rhs.fTotalEventSequences;
        fStartTimeInRunC = rhs.fStartTimeInRunC; fStartTimeInAcq = rhs.fStartTimeInAcq; fEndTimeInRunC = rhs.fEndTimeInRunC;fTimeLength = rhs.fTimeLength;
        fStartFrequency = rhs.fStartFrequency; fEndFrequency = rhs.fEndFrequency; fMinimumFrequency = rhs.fMinimumFrequency; fMaximumFrequency = rhs.fMaximumFrequency; fFrequencyWidth = rhs.fFrequencyWidth;
        fStartTimeInRunCSigma = rhs.fStartTimeInRunCSigma; fEndTimeInRunCSigma = rhs.fEndTimeInRunCSigma; fTimeLengthSigma = rhs.fTimeLengthSigma;
        fStartFrequencySigma = rhs.fStartFrequencySigma; fEndFrequencySigma = rhs.fEndFrequencySigma; fFrequencyWidthSigma = rhs.fFrequencyWidthSigma;
        fFirstTrackID = rhs.fFirstTrackID; fFirstTrackTimeLength = rhs.fFirstTrackTimeLength; fFirstTrackFrequencyWidth = rhs.fFirstTrackFrequencyWidth; fFirstTrackSlope = rhs.fFirstTrackSlope; fFirstTrackIntercept = rhs.fFirstTrackIntercept; fFirstTrackTotalPower = rhs.fFirstTrackTotalPower;
        fUnknownEventTopology = rhs.fUnknownEventTopology;
        fTracks->Clear(); (*fTracks) = *(rhs.fTracks);
        fClassifierResults->Clear(); (*fClassifierResults) = *(rhs.fClassifierResults);
        return *this;
    }

}
