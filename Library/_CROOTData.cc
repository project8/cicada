/**
 @file _CROOTData.hh
 @brief Contains TProcessedTrackData and TMultiTrackEventData
 @details This file was not meant to be used by itself.  It should be included in another file with proper include guards and a definition of NAMESPACE
 @author N. S. Oblath
 @date Jan 15, 2018
 */

#include "logger.hh"

#include "TClonesArray.h"

#include <iostream>

ClassImp(NAMESPACE::TProcessedTrackData);
ClassImp(NAMESPACE::TMultiTrackEventData);

namespace NAMESPACE
{
    //***********************
    // TProcessedTrackData
    //***********************

    TProcessedTrackData::TProcessedTrackData() :
            TObject(),
            fComponent(0), fAcquisitionID(0), fTrackID(0), fEventID(0), fEventSequenceID(-1), fIsCut(false),
            fStartTimeInRunC(0.), fStartTimeInAcq(0.), fEndTimeInRunC(0.),fTimeLength(0.),
            fStartFrequency(0.), fEndFrequency(0.), fFrequencyWidth(0.),
            fSlope(0.), fIntercept(0.), fTotalPower(0.),
            fNTrackBins(0.), fTotalTrackSNR(0.), fMaxTrackSNR(0.), fTotalTrackNUP(0.), fMaxTrackNUP(0.), fTotalWideTrackSNR(0.), fTotalWideTrackNUP(0.),
            fStartTimeInRunCSigma(0.), fEndTimeInRunCSigma(0.), fTimeLengthSigma(0.),
            fStartFrequencySigma(0.), fEndFrequencySigma(0.), fFrequencyWidthSigma(0.),
            fSlopeSigma(0.), fInterceptSigma(0.), fTotalPowerSigma(0.)
    {}
/*
    TProcessedTrackData::TProcessedTrackData(const KTProcessedTrackData& orig) :
            TObject(),
            fComponent(0), fAcquisitionID(0), fTrackID(0), fEventID(0), fEventSequenceID(-1), fIsCut(false),
            fStartTimeInRunC(0.), fStartTimeInAcq(0.), fEndTimeInRunC(0.),fTimeLength(0.),
            fStartFrequency(0.), fEndFrequency(0.), fFrequencyWidth(0.),
            fSlope(0.), fIntercept(0.), fTotalPower(0.),
            fStartTimeInRunCSigma(0.), fEndTimeInRunCSigma(0.), fTimeLengthSigma(0.),
            fStartFrequencySigma(0.), fEndFrequencySigma(0.), fFrequencyWidthSigma(0.),
            fSlopeSigma(0.), fInterceptSigma(0.), fTotalPowerSigma(0.)
    {
        Load(orig);
    }
*/
    TProcessedTrackData::TProcessedTrackData(const TProcessedTrackData& orig) :
            TObject(orig),
            fComponent(orig.fComponent), fAcquisitionID(orig.fAcquisitionID), fTrackID(orig.fTrackID), fEventID(orig.fEventID), fEventSequenceID(orig.fEventSequenceID), fIsCut(orig.fIsCut),
            fStartTimeInRunC(orig.fStartTimeInRunC), fStartTimeInAcq(orig.fStartTimeInAcq), fEndTimeInRunC(orig.fEndTimeInRunC),fTimeLength(orig.fTimeLength),
            fStartFrequency(orig.fStartFrequency), fEndFrequency(orig.fEndFrequency), fFrequencyWidth(orig.fFrequencyWidth),
            fSlope(orig.fSlope), fIntercept(orig.fIntercept), fTotalPower(orig.fTotalPower),
            fNTrackBins(orig.fNTrackBins), fTotalTrackSNR(orig.fTotalTrackSNR), fMaxTrackSNR(orig.fMaxTrackSNR), fTotalTrackNUP(orig.fTotalTrackNUP), fMaxTrackNUP(orig.fMaxTrackNUP), fTotalWideTrackSNR(orig.fTotalWideTrackSNR), fTotalWideTrackNUP(orig.fTotalWideTrackNUP),
            fStartTimeInRunCSigma(orig.fStartTimeInRunCSigma), fEndTimeInRunCSigma(orig.fEndTimeInRunCSigma), fTimeLengthSigma(orig.fTimeLengthSigma),
            fStartFrequencySigma(orig.fStartFrequencySigma), fEndFrequencySigma(orig.fEndFrequencySigma), fFrequencyWidthSigma(orig.fFrequencyWidthSigma),
            fSlopeSigma(orig.fSlopeSigma), fInterceptSigma(orig.fInterceptSigma), fTotalPowerSigma(orig.fTotalPowerSigma)
    {}

    TProcessedTrackData::~TProcessedTrackData()
    {}

    TObject* TProcessedTrackData::Clone(const char* newname)
    {
        TProcessedTrackData* newData = new TProcessedTrackData(*this);
        return newData;
    }

    TProcessedTrackData& TProcessedTrackData::operator=(const TProcessedTrackData& rhs)
    {
        fComponent = rhs.fComponent; fAcquisitionID = rhs.fAcquisitionID; fTrackID = rhs.fTrackID; fEventID = rhs.fEventID; fEventSequenceID = rhs.fEventSequenceID; fIsCut = rhs.fIsCut;
        fStartTimeInRunC = rhs.fStartTimeInRunC; fStartTimeInAcq = rhs.fStartTimeInAcq; fEndTimeInRunC = rhs.fEndTimeInRunC;fTimeLength = rhs.fTimeLength;
        fStartFrequency = rhs.fStartFrequency; fEndFrequency = rhs.fEndFrequency; fFrequencyWidth = rhs.fFrequencyWidth;
        fSlope = rhs.fSlope; fIntercept = rhs.fIntercept; fTotalPower = rhs.fTotalPower;
        fNTrackBins = rhs.fNTrackBins; fTotalTrackSNR = rhs.fTotalTrackSNR; fMaxTrackSNR = rhs.fMaxTrackSNR; fTotalTrackNUP = rhs.fTotalTrackNUP; fMaxTrackNUP = rhs.fMaxTrackNUP; fTotalWideTrackSNR = rhs.fTotalWideTrackSNR; fTotalWideTrackNUP = rhs.fTotalWideTrackNUP;
        fStartTimeInRunCSigma = rhs.fStartTimeInRunCSigma; fEndTimeInRunCSigma = rhs.fEndTimeInRunCSigma; fTimeLengthSigma = rhs.fTimeLengthSigma;
        fStartFrequencySigma = rhs.fStartFrequencySigma; fEndFrequencySigma = rhs.fEndFrequencySigma; fFrequencyWidthSigma = rhs.fFrequencyWidthSigma;
        fSlopeSigma = rhs.fSlopeSigma; fInterceptSigma = rhs.fInterceptSigma; fTotalPowerSigma = rhs.fTotalPowerSigma;        
        return *this;
    }
/*
    void TProcessedTrackData::Load(const KTProcessedTrackData& data)
    {
        fComponent = data.GetComponent(); fAcquisitionID = data.GetAcquisitionID(); fTrackID = data.GetTrackID(); fEventID = data.GetEventID(); fEventSequenceID = data.GetEventSequenceID(); fIsCut = data.GetIsCut();
        fStartTimeInRunC = data.GetStartTimeInRunC(); fStartTimeInAcq = data.GetStartTimeInAcq(); fEndTimeInRunC = data.GetEndTimeInRunC();fTimeLength = data.GetTimeLength();
        fStartFrequency = data.GetStartFrequency(); fEndFrequency = data.GetEndFrequency(); fFrequencyWidth = data.GetFrequencyWidth();
        fSlope = data.GetSlope(); fIntercept = data.GetIntercept(); fTotalPower = data.GetTotalPower();
        fStartTimeInRunCSigma = data.GetStartTimeInRunCSigma(); fEndTimeInRunCSigma = data.GetEndTimeInRunCSigma(); fTimeLengthSigma = data.GetTimeLengthSigma();
        fStartFrequencySigma = data.GetStartFrequencySigma(); fEndFrequencySigma = data.GetEndFrequencySigma(); fFrequencyWidthSigma = data.GetFrequencyWidthSigma();
        fSlopeSigma = data.GetSlopeSigma(); fInterceptSigma = data.GetInterceptSigma(); fTotalPowerSigma = data.GetTotalPowerSigma();
        return;
    }
    void TProcessedTrackData::Unload(KTProcessedTrackData& data) const
    {
        data.SetComponent(fComponent); data.SetAcquisitionID(fAcquisitionID); data.SetTrackID(fTrackID); data.SetEventID(fEventID); data.SetEventSequenceID(fEventSequenceID); data.SetIsCut(fIsCut);
        data.SetStartTimeInRunC(fStartTimeInRunC); data.SetStartTimeInAcq(fStartTimeInAcq); data.SetEndTimeInRunC(fEndTimeInRunC); data.SetTimeLength(fTimeLength);
        data.SetStartFrequency(fStartFrequency); data.SetEndFrequency(fEndFrequency); data.SetFrequencyWidth(fFrequencyWidth);
        data.SetSlope(fSlope); data.SetIntercept(fIntercept); data.SetTotalPower(fTotalPower);
        data.SetStartTimeInRunCSigma(fStartTimeInRunCSigma); data.SetEndTimeInRunCSigma(fEndTimeInRunCSigma); data.SetTimeLengthSigma(fTimeLengthSigma);
        data.SetStartFrequencySigma(fStartFrequencySigma); data.SetEndFrequencySigma(fEndFrequencySigma); data.SetFrequencyWidthSigma(fFrequencyWidthSigma);
        data.SetSlopeSigma(fSlopeSigma); data.SetInterceptSigma(fInterceptSigma); data.SetTotalPowerSigma(fTotalPowerSigma);
        return;
    }
*/


    //************************
    // TMultiTrackEventData
    //************************

    TMultiTrackEventData::TMultiTrackEventData() :
            fComponent(0), fAcquisitionID(0), fEventID(0), fTotalEventSequences(0),
            fStartTimeInRunC(0.), fStartTimeInAcq(0.), fEndTimeInRunC(0.),fTimeLength(0.),
            fStartFrequency(0.), fEndFrequency(0.), fMinimumFrequency(0.), fMaximumFrequency(0.), fFrequencyWidth(0.),
            fStartTimeInRunCSigma(0.), fEndTimeInRunCSigma(0.), fTimeLengthSigma(0.),
            fStartFrequencySigma(0.), fEndFrequencySigma(0.), fFrequencyWidthSigma(0.),
            fFirstTrackID(0), fFirstTrackTimeLength(0.), fFirstTrackFrequencyWidth(0.), fFirstTrackSlope(0.), fFirstTrackIntercept(0.), fFirstTrackTotalPower(0.),
            fUnknownEventTopology(false)
    {
        static const std::string className = std::string(TOSTRING(NAMESPACE)) + "::TProcessedTrackData";
        // this cannot be initialized in the initializer list because ROOT
        fTracks = new TClonesArray(className.c_str(), 20);
    }

    TMultiTrackEventData::TMultiTrackEventData(const TMultiTrackEventData& orig) :
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
    }
/*
    TMultiTrackEventData::TMultiTrackEventData(const KTMultiTrackEventData& orig) :
            fComponent(0), fAcquisitionID(0), fEventID(0), fTotalEventSequences(0),
            fStartTimeInRunC(0.), fStartTimeInAcq(0.), fEndTimeInRunC(0.),fTimeLength(0.),
            fStartFrequency(0.), fEndFrequency(0.), fMinimumFrequency(0.), fMaximumFrequency(0.), fFrequencyWidth(0.),
            fStartTimeInRunCSigma(0.), fEndTimeInRunCSigma(0.), fTimeLengthSigma(0.),
            fStartFrequencySigma(0.), fEndFrequencySigma(0.), fFrequencyWidthSigma(0.),
            fFirstTrackID(0), fFirstTrackTimeLength(0.), fFirstTrackFrequencyWidth(0.), fFirstTrackSlope(0.), fFirstTrackIntercept(0.), fFirstTrackTotalPower(0.),
            fUnknownEventTopology(false)
    {
        // this cannot be initialized in the initializer list because ROOT
        fTracks = new TClonesArray("Katydid::TProcessedTrackData", 20);
        Load(orig);
    }
*/
    TMultiTrackEventData::~TMultiTrackEventData()
    {
        fTracks->Clear();
    }

    TObject* TMultiTrackEventData::Clone(const char* newname)
    {
        TMultiTrackEventData* newData = new TMultiTrackEventData(*this);
        return newData;
    }

    TMultiTrackEventData& TMultiTrackEventData::operator=(const TMultiTrackEventData& rhs)
    {
        fComponent = rhs.fComponent; fAcquisitionID = rhs.fAcquisitionID; fEventID = rhs.fEventID; fTotalEventSequences = rhs.fTotalEventSequences;
        fStartTimeInRunC = rhs.fStartTimeInRunC; fStartTimeInAcq = rhs.fStartTimeInAcq; fEndTimeInRunC = rhs.fEndTimeInRunC;fTimeLength = rhs.fTimeLength;
        fStartFrequency = rhs.fStartFrequency; fEndFrequency = rhs.fEndFrequency; fMinimumFrequency = rhs.fMinimumFrequency; fMaximumFrequency = rhs.fMaximumFrequency; fFrequencyWidth = rhs.fFrequencyWidth;
        fStartTimeInRunCSigma = rhs.fStartTimeInRunCSigma; fEndTimeInRunCSigma = rhs.fEndTimeInRunCSigma; fTimeLengthSigma = rhs.fTimeLengthSigma;
        fStartFrequencySigma = rhs.fStartFrequencySigma; fEndFrequencySigma = rhs.fEndFrequencySigma; fFrequencyWidthSigma = rhs.fFrequencyWidthSigma;
        fFirstTrackID = rhs.fFirstTrackID; fFirstTrackTimeLength = rhs.fFirstTrackTimeLength; fFirstTrackFrequencyWidth = rhs.fFirstTrackFrequencyWidth; fFirstTrackSlope = rhs.fFirstTrackSlope; fFirstTrackIntercept = rhs.fFirstTrackIntercept; fFirstTrackTotalPower = rhs.fFirstTrackTotalPower;
        fFirstTrackTotalSNR = rhs.fFirstTrackTotalSNR; fFirstTrackMaxSNR = rhs.fFirstTrackMaxSNR; fFirstTrackTotalNUP = rhs.fFirstTrackTotalNUP; fFirstTrackMaxNUP = rhs.fFirstTrackMaxNUP; fFirstTrackTotalWideSNR = rhs.fFirstTrackTotalWideSNR; fFirstTrackTotalWideNUP = rhs.fFirstTrackTotalWideNUP;
        fUnknownEventTopology = rhs.fUnknownEventTopology;
        fTracks->Clear(); (*fTracks) = *(rhs.fTracks);
        return *this;
    }
/*
    void TMultiTrackEventData::Load(const KTMultiTrackEventData& data)
    {
        fComponent = data.GetComponent(); fAcquisitionID = data.GetAcquisitionID(); fEventID = data.GetEventID(); fTotalEventSequences = data.GetTotalEventSequences();
        fStartTimeInRunC = data.GetStartTimeInRunC(); fStartTimeInAcq = data.GetStartTimeInAcq(); fEndTimeInRunC = data.GetEndTimeInRunC();fTimeLength = data.GetTimeLength();
        fStartFrequency = data.GetStartFrequency(); fEndFrequency = data.GetEndFrequency(); fMinimumFrequency = data.GetMinimumFrequency(); fMaximumFrequency = data.GetMaximumFrequency(); fFrequencyWidth = data.GetFrequencyWidth();
        fStartTimeInRunCSigma = data.GetStartTimeInRunCSigma(); fEndTimeInRunCSigma = data.GetEndTimeInRunCSigma(); fTimeLengthSigma = data.GetTimeLengthSigma();
        fStartFrequencySigma = data.GetStartFrequencySigma(); fEndFrequencySigma = data.GetEndFrequencySigma(); fFrequencyWidthSigma = data.GetFrequencyWidthSigma();
        fFirstTrackID = data.GetFirstTrackID(); fFirstTrackTimeLength = data.GetFirstTrackTimeLength(); fFirstTrackFrequencyWidth = data.GetFirstTrackFrequencyWidth(); fFirstTrackSlope = data.GetFirstTrackSlope(); fFirstTrackIntercept = data.GetFirstTrackIntercept(); fFirstTrackTotalPower = data.GetFirstTrackTotalPower();
        fUnknownEventTopology = data.GetUnknownEventTopology();
        Int_t nTracks = (Int_t)data.GetNTracks();
        fTracks->Clear(); fTracks->Expand(nTracks);
        Int_t iTrack = 0;
        for (TrackSetCIt trIt = data.GetTracksBegin(); trIt != data.GetTracksEnd(); ++trIt)
        {
            TProcessedTrackData* track = new((*fTracks)[iTrack]) TProcessedTrackData(*trIt);
            ++iTrack;
        }
        return;
    }
    void TMultiTrackEventData::Unload(KTMultiTrackEventData& data) const
    {
        data.ClearTracks(); // do this first, since it clears some of the member variables other than just fTracks
        data.SetComponent(fComponent); data.SetAcquisitionID(fAcquisitionID); data.SetEventID(fEventID); data.SetTotalEventSequences(fTotalEventSequences);
        data.SetStartTimeInRunC(fStartTimeInRunC); data.SetStartTimeInAcq(fStartTimeInAcq); data.SetEndTimeInRunC(fEndTimeInRunC); data.SetTimeLength(fTimeLength);
        data.SetStartFrequency(fStartFrequency); data.SetEndFrequency(fEndFrequency); data.SetMinimumFrequency(fMinimumFrequency); data.SetMaximumFrequency(fMaximumFrequency); data.SetFrequencyWidth(fFrequencyWidth);
        data.SetStartTimeInRunCSigma(fStartTimeInRunCSigma); data.SetEndTimeInRunCSigma(fEndTimeInRunCSigma); data.SetTimeLengthSigma(fTimeLengthSigma);
        data.SetStartFrequencySigma(fStartFrequencySigma); data.SetEndFrequencySigma(fEndFrequencySigma); data.SetFrequencyWidthSigma(fFrequencyWidthSigma);
        data.SetFirstTrackID(fFirstTrackID); data.SetFirstTrackTimeLength(fFirstTrackTimeLength); data.SetFirstTrackFrequencyWidth(fFirstTrackFrequencyWidth); data.SetFirstTrackSlope(fFirstTrackSlope); data.SetFirstTrackIntercept(fFirstTrackIntercept); data.SetFirstTrackTotalPower(fFirstTrackTotalPower);
        data.SetUnknownEventTopology(fUnknownEventTopology);
        Int_t nTracks = fTracks->GetSize();
        KTProcessedTrackData track;
        for (Int_t iTrack = 0; iTrack < nTracks; ++iTrack)
        {
            ((TProcessedTrackData*)((*fTracks)[iTrack]))->Unload(track);
            data.AddTrack(track);
        }
        return;
    }
*/
}
