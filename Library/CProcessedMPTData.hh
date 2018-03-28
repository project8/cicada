/**
 @file CProcessedMPTData.hh
 @brief Contains TProcessedMPTData
 @details Contains the definition of the branches saved in the Katydid output for a processed multi-peak track
 @author E. Zayas
 @date Mar 22, 2018
 */

#include "CMemberVariables.hh"

#include "TObject.h"
#include "TClonesArray.h"

#define set_prefix Set
#define get_prefix Get
#define var_prefix f
#define static_prefix s

namespace Cicada
{

   /*!
     @class TProcessedMPTData
     @author E. Zayas

     @brief Contains the definition of the branches saved in the Katydid output for a processed multi-peak track

     @details
     The branches of the processed multi-peak tracks object saved as a Katydid output in a ROOT file are defined in this class.
     A TProcessedMPTData object contains the characteristics (such as identifications numbers, the start/end time and frequency, the slope and intercept) of a multi-peak track detected by the event reconstruction.
     The mv_accessible macros creates public class members and public Get and Set methods (e.g. SetVariable(value)).
    */

    class TProcessedMPTData : public TObject
    {
            mv_accessible(UInt_t, Component);
            mv_accessible(Int_t, EventSequenceID);
            mv_accessible(UInt_t, AcquisitionID);
            mv_accessible(UInt_t, TrackID);

            mv_accessible(Bool_t, IsCut);

            mv_accessible(Double_t, MVAClassifier);
            mv_accessible(Bool_t, Mainband);
            mv_accessible(Double_t, AxialFrequency);

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
            TProcessedMPTData();
            TProcessedMPTData(const TProcessedMPTData& orig);
            virtual ~TProcessedMPTData();
            TObject* Clone(const char* newname="");
            TProcessedMPTData& operator=(const TProcessedMPTData& rhs);

            ClassDef(TProcessedMPTData, 1);
    };

}
