/**
 @file CClassifierResultsData.hh
 @brief Contains TClassifierResultsData
 @details Contains the definition of the branches saved in the Katydid output for a classifier results data
 @author E. Zayas
 @date Mar 22, 2018
 */

#include "CMemberVariables.hh"

#include "TObject.h"
#include "TClonesArray.h"

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
        public:
            TClassifierResultsData();
            TClassifierResultsData(const TClassifierResultsData& orig);
            virtual ~TClassifierResultsData();
            TObject* Clone(const char* newname="");
            TClassifierResultsData& operator=(const TClassifierResultsData& rhs);

            mv_accessible(UInt_t, Component);
            mv_accessible(Int_t, MainCarrierHigh);
            mv_accessible(Int_t, MainCarrierLow);
            mv_accessible(Int_t, SideBand);
        
        public:
            std::string GetBranchName() { return std::string("ClassifiedEvent"); } // Defines the default name of the object saved inside the output tree                  

            ClassDef(TClassifierResultsData, 1);
    };

}
