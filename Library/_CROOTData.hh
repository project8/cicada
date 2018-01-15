/*
 * _CROOTData.hh
 *
 *  Created on: Jan 15, 2018
 *      Author: nsoblath
 *
 *  NOTE: this file was not meant to be used by itself.  It should be included in another file with proper include guards and a definition of NAMESPACE
 */

#define set_prefix Set
#define get_prefix Get
#define var_prefix f
#define static_prefix s

#include "_member_variables.hh"

#include "TObject.h"

class TClonesArray;

namespace NAMESPACE
{
    //***********************
    // TProcessedTrackData
    //***********************

    //class KTProcessedTrackData;

    class TProcessedTrackData : public TObject
    {
            mv_accessible(UInt_t, Component);
            mv_accessible(UInt_t, AcquisitionID);
            mv_accessible(UInt_t, TrackID);
            mv_accessible(UInt_t, EventID);
            mv_accessible(Int_t, EventSequenceID);

            mv_accessible(Bool_t, IsCut);

            mv_accessible(Double_t, StartTimeInRunC);
            mv_accessible(Double_t, StartTimeInAcq);
            mv_accessible(Double_t, EndTimeInRunC);
            mv_accessible(Double_t, TimeLength);
            mv_accessible(Double_t, StartFrequency);
            mv_accessible(Double_t, EndFrequency);
            mv_accessible(Double_t, FrequencyWidth);
            mv_accessible(Double_t, Slope);
            mv_accessible(Double_t, Intercept);
            mv_accessible(Double_t, TotalPower);

            mv_accessible(Double_t, StartTimeInRunCSigma);
            mv_accessible(Double_t, EndTimeInRunCSigma);
            mv_accessible(Double_t, TimeLengthSigma);
            mv_accessible(Double_t, StartFrequencySigma);
            mv_accessible(Double_t, EndFrequencySigma);
            mv_accessible(Double_t, FrequencyWidthSigma);
            mv_accessible(Double_t, SlopeSigma);
            mv_accessible(Double_t, InterceptSigma);
            mv_accessible(Double_t, TotalPowerSigma);

        public:
            TProcessedTrackData();
            //TProcessedTrackData(const KTProcessedTrackData& data);
            TProcessedTrackData(const TProcessedTrackData& orig);
            virtual ~TProcessedTrackData();
            TObject* Clone(const char* newname="");
            TProcessedTrackData& operator=(const TProcessedTrackData& rhs);

            //void Load(const KTProcessedTrackData& data);
            //void Unload(KTProcessedTrackData& data) const;

            ClassDef(TProcessedTrackData, 1);
    };

    //************************
    // TMultiTrackEventData
    //************************

    //class KTMultiTrackEventData;

    class TMultiTrackEventData : public TObject
    {
            mv_accessible(UInt_t, Component);
            mv_accessible(UInt_t, AcquisitionID);
            mv_accessible(UInt_t, EventID);
            mv_accessible(UInt_t, TotalEventSequences);

            mv_accessible(Double_t, StartTimeInRunC);
            mv_accessible(Double_t, StartTimeInAcq);
            mv_accessible(Double_t, EndTimeInRunC);
            mv_accessible(Double_t, TimeLength);
            mv_accessible(Double_t, StartFrequency);
            mv_accessible(Double_t, EndFrequency);
            mv_accessible(Double_t, MinimumFrequency);
            mv_accessible(Double_t, MaximumFrequency);
            mv_accessible(Double_t, FrequencyWidth);

            mv_accessible(Double_t, StartTimeInRunCSigma);
            mv_accessible(Double_t, EndTimeInRunCSigma);
            mv_accessible(Double_t, TimeLengthSigma);
            mv_accessible(Double_t, StartFrequencySigma);
            mv_accessible(Double_t, EndFrequencySigma);
            mv_accessible(Double_t, FrequencyWidthSigma);

            mv_accessible(UInt_t, FirstTrackID);
            mv_accessible(Double_t, FirstTrackTimeLength);
            mv_accessible(Double_t, FirstTrackFrequencyWidth);
            mv_accessible(Double_t, FirstTrackSlope);
            mv_accessible(Double_t, FirstTrackIntercept);
            mv_accessible(Double_t, FirstTrackTotalPower);

            mv_accessible(Double_t, UnknownEventTopology);

        public:
            TClonesArray* GetTracks() {return fTracks;}

        private:
            TClonesArray* fTracks; //->

        public:
            TMultiTrackEventData();
            //TMultiTrackEventData(const KTMultiTrackEventData& data);
            TMultiTrackEventData(const TMultiTrackEventData& orig);
            virtual ~TMultiTrackEventData();
            TObject* Clone(const char* newname="");
            TMultiTrackEventData& operator=(const TMultiTrackEventData& rhs);

            //void Load(const KTMultiTrackEventData& data);
            //void Unload(KTMultiTrackEventData& data) const;

            ClassDef(TMultiTrackEventData, 1);
    };


}

