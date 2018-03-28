/**
 @file CClassifiedEventData.hh
 @brief Contains TClassifiedEventData
 @details Contains the definition of the branches saved in the Katydid output for a classified event data
 @author E. Zayas
 @date Mar 22, 2018
 */

#include "TObject.h"
#include "TClonesArray.h"

#include "CMemberVariables.hh"

namespace Cicada
{

   /*!
     @class TClassifiedEventData
     @author E. Zayas

     @brief Contains the definition of the branches saved in the Katydid output for a classified event data

     @details
     The branches of the classified event data object saved as a Katydid output in a ROOT file are defined in this class.
     A TClassifiedEventData object contains the characteristics (such as identifications numbers, the start/end time and frequency, the slope and intercept) of a classified track detected by the event reconstruction.
     The mv_accessible macros creates public class members and public Get and Set methods (e.g. SetVariable(value)).
    */

    class TClassifiedEventData : public TObject
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
            const TClonesArray* GetTracks() const {return fTracks;}

            TClonesArray* GetClassifierResults() {return fClassifierResults;}
            const TClonesArray* GetClassifierResults() const {return fClassifierResults;}

        private:
            TClonesArray* fTracks; /**< Contains all the processed tracks informations (a.k.a. TProcessedTracksData object) for an event. */
            TClonesArray* fClassifierResults;

        public:
            TClassifiedEventData();
            TClassifiedEventData(const TClassifiedEventData& orig);
            virtual ~TClassifiedEventData();
            TObject* Clone(const char* newname="");
            TClassifiedEventData& operator=(const TClassifiedEventData& rhs);

            ClassDef(TClassifiedEventData, 1);
    };

}
