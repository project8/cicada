/**
 @file CMTEWithClassfierResultsData.hh
 @brief Contains TMTEWithClassfierResultsData
 @details Contains the definition of the branches saved in the Katydid output for a classified event data
 @author E. Zayas
 @date Mar 22, 2018
 */

#include "TObject.h"
#include "TClonesArray.h"

#include "CMemberVariables.hh"
#include "CROOTData.hh"

namespace Cicada
{

   /*!
     @class TMTEWithClassfierResultsData
     @author E. Zayas

     @brief Contains the definition of the branches saved in the Katydid output for a classified event data

     @details
     The branches of the classified event data object saved as a Katydid output in a ROOT file are defined in this class.
     A TMTEWithClassfierResultsData object contains the characteristics (such as identifications numbers, the start/end time and frequency, the slope and intercept) of a classified track detected by the event reconstruction.
     The mv_accessible macros creates public class members and public Get and Set methods (e.g. SetVariable(value)).
    */

    class TMTEWithClassifierResultsData : public TMultiTrackEventData
    {
        public:
            TMTEWithClassifierResultsData();
            TMTEWithClassifierResultsData(const TMTEWithClassifierResultsData& orig);
            virtual ~TMTEWithClassifierResultsData();
            virtual TObject* Clone(const char* newname="");
            TMTEWithClassifierResultsData& operator=(const TMTEWithClassifierResultsData& rhs);

        public:
            TClonesArray* GetClassifierResults() {return fClassifierResults;}
            const TClonesArray* GetClassifierResults() const {return fClassifierResults;}

        private:
            TClonesArray* fClassifierResults;

            ClassDef(TMTEWithClassifierResultsData, 1);
    };

}
