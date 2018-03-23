/**
 @file CProcessedMPTData.cc
 @author E. Zayas
 @date Mar 22, 2018
 */

#include "logger.hh"

#include "CProcessedMPTData.hh"
#include "TClonesArray.h"

#include <iostream>

ClassImp(Cicada::TProcessedMPTData);

namespace Cicada
{

    //***********************
    // TProcessedMPTData
    //***********************

    TProcessedMPTData::TProcessedMPTData() :
            TObject(),
            fComponent(0), fTrackID(0), fEventSequenceID(-1), fIsCut(false),
            fMVAClassifier(-999.), fMainband(true), fAxialFrequency(0.),
            fAcquisitionID(0),
            fStartTimeInRunC(0.), fStartTimeInAcq(0.), fEndTimeInRunC(0.),fTimeLength(0.),
            fStartFrequency(0.), fEndFrequency(0.), fFrequencyWidth(0.),
            fSlope(0.), fIntercept(0.), fTotalPower(0.),
            fStartTimeInRunCSigma(0.), fEndTimeInRunCSigma(0.), fTimeLengthSigma(0.),
            fStartFrequencySigma(0.), fEndFrequencySigma(0.), fFrequencyWidthSigma(0.),
            fSlopeSigma(0.), fInterceptSigma(0.), fTotalPowerSigma(0.)
    {}

    TProcessedMPTData::TProcessedMPTData(const TProcessedMPTData& orig) :
            TObject(orig),
            fComponent(orig.fComponent), fTrackID(orig.fTrackID), fEventSequenceID(orig.fEventSequenceID), fIsCut(orig.fIsCut),
            fMVAClassifier(orig.fMVAClassifier), fMainband(orig.fMainband), fAxialFrequency(orig.fAxialFrequency),
            fAcquisitionID(orig.fAcquisitionID),
            fStartTimeInRunC(orig.fStartTimeInRunC), fStartTimeInAcq(orig.fStartTimeInAcq), fEndTimeInRunC(orig.fEndTimeInRunC), fTimeLength(orig.fTimeLength),
            fStartFrequency(orig.fStartFrequency), fEndFrequency(orig.fEndFrequency), fFrequencyWidth(orig.fFrequencyWidth),
            fSlope(orig.fSlope), fIntercept(orig.fIntercept), fTotalPower(orig.fTotalPower),
            fStartTimeInRunCSigma(orig.fStartTimeInRunCSigma), fEndTimeInRunCSigma(orig.fEndTimeInRunCSigma), fTimeLengthSigma(orig.fTimeLengthSigma),
            fStartFrequencySigma(orig.fStartFrequencySigma), fEndFrequencySigma(orig.fEndFrequencySigma), fFrequencyWidthSigma(orig.fFrequencyWidthSigma),
            fSlopeSigma(orig.fSlopeSigma), fInterceptSigma(orig.fInterceptSigma), fTotalPowerSigma(orig.fTotalPowerSigma)
    {}

    TProcessedMPTData::~TProcessedMPTData()
    {}

    TObject* TProcessedMPTData::Clone(const char* newname)
    {
        TProcessedMPTData* newData = new TProcessedMPTData(*this);
        return newData;
    }

    TProcessedMPTData& TProcessedMPTData::operator=(const TProcessedMPTData& rhs)
    {
        fComponent = rhs.fComponent; fTrackID = rhs.fTrackID; fEventSequenceID = rhs.fEventSequenceID; fIsCut = rhs.fIsCut;
        fMVAClassifier = rhs.fMVAClassifier; fMainband = rhs.fMainband; fAxialFrequency = rhs.fAxialFrequency;
        fAcquisitionID = rhs.fAcquisitionID;
        fStartTimeInRunC = rhs.fStartTimeInRunC; fStartTimeInAcq = rhs.fStartTimeInAcq; fEndTimeInRunC = rhs.fEndTimeInRunC; fTimeLength = rhs.fTimeLength;
        fStartFrequency = rhs.fStartFrequency; fEndFrequency = rhs.fEndFrequency; fFrequencyWidth = rhs.fFrequencyWidth;
        fSlope = rhs.fSlope; fIntercept = rhs.fIntercept; fTotalPower = rhs.fTotalPower;
        fStartTimeInRunCSigma = rhs.fStartTimeInRunCSigma; fEndTimeInRunCSigma = rhs.fEndTimeInRunCSigma; fTimeLengthSigma = rhs.fTimeLengthSigma;
        fStartFrequencySigma = rhs.fStartFrequencySigma; fEndFrequencySigma = rhs.fEndFrequencySigma; fFrequencyWidthSigma = rhs.fFrequencyWidthSigma;
        fSlopeSigma = rhs.fSlopeSigma; fInterceptSigma = rhs.fInterceptSigma; fTotalPowerSigma = rhs.fTotalPowerSigma;
        return *this;
    }

}
