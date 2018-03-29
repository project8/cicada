/**
 @file CMTEWithClassifierResultsData.cc
 @brief Contains TMTEWithClassifierResultsData
 @details Contains the definition of the branches saved in the Katydid output for a classified event data
 @author E. Zayas
 @date Mar 22, 2018
 */

#include "CMTEWithClassifierResultsData.hh"

#include "logger.hh"

#include "TClonesArray.h"


ClassImp(Cicada::TMTEWithClassifierResultsData);

namespace Cicada
{

    TMTEWithClassifierResultsData::TMTEWithClassifierResultsData() :
            TMultiTrackEventData()
    {
        // this cannot be initialized in the initializer list because ROOT
        fClassifierResults = new TClonesArray("Cicada::TClassifierResultsData", 20);
    }

    TMTEWithClassifierResultsData::TMTEWithClassifierResultsData(const TMTEWithClassifierResultsData& orig) :
            TMultiTrackEventData(orig)
    {
        // this cannot be initialized in the initializer list because ROOT
        fClassifierResults = new TClonesArray(*orig.fClassifierResults);
    }

    TMTEWithClassifierResultsData::~TMTEWithClassifierResultsData()
    {
        fClassifierResults->Clear();
    }

    TObject* TMTEWithClassifierResultsData::Clone(const char* newname)
    {
        TMTEWithClassifierResultsData* newData = new TMTEWithClassifierResultsData(*this);
        return newData;
    }

    TMTEWithClassifierResultsData& TMTEWithClassifierResultsData::operator=(const TMTEWithClassifierResultsData& rhs)
    {
        this->TMultiTrackEventData::operator=(rhs);
        fClassifierResults->Clear();
        (*fClassifierResults) = *(rhs.fClassifierResults);
        return *this;
    }

}
