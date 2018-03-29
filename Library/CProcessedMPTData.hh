

#include "CMemberVariables.hh"
#include "CROOTData.hh"

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
        public:
            TProcessedMPTData();
            TProcessedMPTData(const TProcessedMPTData& orig);
            virtual ~TProcessedMPTData();
            TObject* Clone(const char* newname="");
            TProcessedMPTData& operator=(const TProcessedMPTData& rhs);

            mv_accessible(UInt_t, Component);
            mv_referrable(TProcessedTrackData, MainTrack);
            mv_accessible(Double_t, AxialFrequency);

            ClassDef(TProcessedMPTData, 2);
    };

}
