#include "TObject.h"
#include "_member_variables.hh"
#include "TClonesArray.h"

#define set_prefix Set
#define get_prefix Get
#define var_prefix f
#define static_prefix s

namespace Cicada
{

   /*!
     @class TClassifierResultsData
     @author E. Zayas

     @brief Contains the definition of the branches saved in the Katydid output for a classifier results data

     @details
     The branches of the classifier results data object saved as a Katydid output in a ROOT file are defined in this class.
     A TClassifierResultsData object contains the characteristics (such as identifications numbers, the start/end time and frequency, the slope and intercept) of a classified track detected by the event reconstruction.
     The mv_accessible macros creates public class members and public Get and Set methods (e.g. SetVariable(value)).
    */

    class TClassifierResultsData : public TObject
    {
            mv_accessible(UInt_t, Component);
            mv_accessible(Int_t, MainCarrierHigh);
            mv_accessible(Int_t, MainCarrierLow);
            mv_accessible(Int_t, SideBand);

        public:
            TClassifierResultsData();
            TClassifierResultsData(const TClassifierResultsData& orig);
            virtual ~TClassifierResultsData();
            TObject* Clone(const char* newname="");
            TClassifierResultsData& operator=(const TClassifierResultsData& rhs);

            ClassDef(TClassifierResultsData, 1);
    };

}
