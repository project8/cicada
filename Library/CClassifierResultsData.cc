/**
 @file CClassifierResultsData.hh
 @brief Contains TClassifierResultsData
 @details Contains the definition of the branches saved in the Katydid output for a classifier results data
 @author E. Zayas
 @date Mar 22, 2018
 */

#include "logger.hh"

#include "CClassifierResultsData.hh"
#include "TClonesArray.h"

#include <iostream>

ClassImp(Cicada::TClassifierResultsData);

namespace Cicada
{

    //***********************
    // TClassifierResultsData
    //***********************

    TClassifierResultsData::TClassifierResultsData() :
            TObject(),
            fComponent(0), fMainCarrierHigh(0), fMainCarrierLow(0), fSideBand(0)
    {}

    TClassifierResultsData::TClassifierResultsData(const TClassifierResultsData& orig) :
            TObject(orig),
            fComponent(orig.fComponent), fMainCarrierHigh(orig.fMainCarrierHigh), fMainCarrierLow(orig.fMainCarrierLow), fSideBand(orig.fSideBand)
    {}

    TClassifierResultsData::~TClassifierResultsData()
    {}

    TObject* TClassifierResultsData::Clone(const char* newname)
    {
        TClassifierResultsData* newData = new TClassifierResultsData(*this);
        return newData;
    }

    TClassifierResultsData& TClassifierResultsData::operator=(const TClassifierResultsData& rhs)
    {
        fComponent = rhs.fComponent; fMainCarrierHigh = rhs.fMainCarrierHigh; fMainCarrierLow = rhs.fMainCarrierLow; fSideBand = rhs.fSideBand;
        return *this;
    }

}
