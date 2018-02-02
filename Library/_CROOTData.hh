/**
 @file _CROOTData.hh
 @brief Contains TProcessedTrackData and TMultiTrackEventData
 @details This file was not meant to be used by itself.  It should be included in another file with proper include guards and a definition of NAMESPACE
 @author: N. S. Oblath
 @date: Jan 15, 2018
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

   /*!
     @class TProcessedTrackData
     @author N. S. Oblath

     @brief Contains the definition of the branches saved in the Katydid output for the processed tracks

     @details
     The branches of the processed tracks object saved as a Katydid output in a ROOT file are defined in this class.
     A TProcessedTrackData object contains the characteristics (such as identifications numbers, the start/end time and frequency, the slope and intercept) of the tracks detected by the event reconstruction.
     The mv_accessible macros creates public class members and public Get and Set methods (e.g. SetVariable(type, value)).
    */

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

   /*!
     @class TProcessedTrackData
     @author N. S. Oblath

     @brief Contains the definition of the branches saved in the Katydid output for the processed event

     @details
     The branches of the processed events object saved as a Katydid output in a ROOT file are defined in this class.
     A TMultiTrackEventData object contains the characteristics of the reconstructed events as long as the tracks (via TProcessedTracks objects) associated to each event.
     The mv_accessible macros creates public class members and public Get and Set methods (e.g. SetVariable(type, value)).
    */

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

