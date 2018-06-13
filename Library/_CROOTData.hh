/**
 @file _CROOTData.hh
 @brief Contains TProcessedTrackData and TMultiTrackEventData
 @details This file was not meant to be used by itself.  It should be included in another file with proper include guards and a definition of NAMESPACE
 @author N. S. Oblath
 @date Jan 15, 2018
 */

#include "CMemberVariables.hh"

#include "TObject.h"

class TClonesArray;

namespace NAMESPACE
{

   /*!
     @class TProcessedTrackData
     @author N. S. Oblath

     @brief Contains the definition of the branches saved in the Katydid output for a processed track

     @details
     The branches of the processed tracks object saved as a Katydid output in a ROOT file are defined in this class.
     A TProcessedTrackData object contains the characteristics (such as identifications numbers, the start/end time and frequency, the slope and intercept) of a track detected by the event reconstruction.
     The mv_accessible macros creates public class members and public Get and Set methods (e.g. SetVariable(value)).
    */

    class TProcessedTrackData : public TObject
    {
        public:    
            mv_accessible(UInt_t, Component); 
            mv_accessible(UInt_t, AcquisitionID);
            mv_accessible(UInt_t, TrackID);
            mv_accessible(UInt_t, EventID);
            mv_accessible(Int_t, EventSequenceID);

            mv_accessible(Bool_t, IsCut);

            // Track properties obtained from "fit"
            mv_accessible(Double_t, StartTimeInRunC);
            mv_accessible(Double_t, StartTimeInAcq);
            mv_accessible(Double_t, EndTimeInRunC);
            mv_accessible(Double_t, TimeLength);
            mv_accessible(Double_t, StartFrequency);
            mv_accessible(Double_t, EndFrequency);
            mv_accessible(Double_t, FrequencyWidth);
            mv_accessible(Double_t, Slope);
            mv_accessible(Double_t, Intercept);

            // Track properties obtained by combining the points that belong to the track
            mv_accessible(Double_t, TotalPower);
            mv_accessible(UInt_t, NTrackBins);
            mv_accessible(Double_t, TotalTrackSNR);
            mv_accessible(Double_t, MaxTrackSNR);
            mv_accessible(Double_t, TotalTrackNUP);
            mv_accessible(Double_t, MaxTrackNUP);
            mv_accessible(Double_t, TotalWideTrackSNR);
            mv_accessible(Double_t, TotalWideTrackNUP);

            // Errors on the estimated parameters
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
            TProcessedTrackData(const TProcessedTrackData& orig);
            virtual ~TProcessedTrackData();
            TObject* Clone(const char* newname="");
            TProcessedTrackData& operator=(const TProcessedTrackData& rhs);

            //void Load(const KTProcessedTrackData& data);
            //void Unload(KTProcessedTrackData& data) const;

            std::string GetBranchName() { return std::string("Track"); } // Defines the default name of the object saved inside the output tree      

            ClassDef(TProcessedTrackData, 2);
    };

   /*!
     @class TMultiTrackEventData
     @author N. S. Oblath

     @brief Contains the definition of the branches saved in the Katydid output for a processed event

     @details
     The branches of the processed events object saved as a Katydid output in a ROOT file are defined in this class.
     A TMultiTrackEventData object contains the characteristics of the reconstructed events as long as the tracks (via TProcessedTracks objects) associated to each event.
     The mv_accessible macros creates public class members and public Get and Set methods (e.g. SetVariable(value)).
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
            mv_accessible(Double_t, FirstTrackTotalSNR);
            mv_accessible(Double_t, FirstTrackMaxSNR);
            mv_accessible(Double_t, FirstTrackTotalNUP);
            mv_accessible(Double_t, FirstTrackMaxNUP);
            mv_accessible(Double_t, FirstTrackTotalWideSNR);
            mv_accessible(Double_t, FirstTrackTotalWideNUP);

            mv_accessible(Double_t, UnknownEventTopology);

        public:
            TClonesArray* GetTracks() {return fTracks;}
            const TClonesArray* GetTracks() const {return fTracks;}

        private:
            TClonesArray* fTracks; /**< Contains all the processed tracks informations (a.k.a. TProcessedTracksData object) for an event. */

        public:
            TMultiTrackEventData();
            TMultiTrackEventData(const TMultiTrackEventData& orig);
            virtual ~TMultiTrackEventData();
            TObject* Clone(const char* newname="");
            TMultiTrackEventData& operator=(const TMultiTrackEventData& rhs);

            //void Load(const KTMultiTrackEventData& data);
            //void Unload(KTMultiTrackEventData& data) const;

            std::string GetBranchName() { return std::string("Event"); } // Defines the default name of the object saved inside the output tree

            ClassDef(TMultiTrackEventData, 1);
    };


}

