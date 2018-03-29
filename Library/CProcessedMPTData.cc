/**
 @file CProcessedMPTData.cc
 @brief Contains TProcessedMPTData
 @details Contains the definition of the branches saved in the Katydid output for a processed multi-peak track
 @author E. Zayas
 @date Mar 22, 2018
 */

#include "logger.hh"

#include "CProcessedMPTData.hh"
#include "TClonesArray.h"

#include <iostream>

ClassImp(Cicada::TProcessedMPTData);

namespace Cicada
{

    //***********************
    // TProcessedMPTData
    //***********************

    TProcessedMPTData::TProcessedMPTData() :
            TObject(),
            fComponent(0),
            fMainTrack(),
            fAxialFrequency(0.)
    {}

    TProcessedMPTData::TProcessedMPTData(const TProcessedMPTData& orig) :
            TObject(orig),
            fComponent(orig.fComponent),
            fMainTrack(orig.fMainTrack),
            fAxialFrequency(orig.fAxialFrequency)
    {}

    TProcessedMPTData::~TProcessedMPTData()
    {}

    TObject* TProcessedMPTData::Clone(const char* newname)
    {
        TProcessedMPTData* newData = new TProcessedMPTData(*this);
        return newData;
    }

    TProcessedMPTData& TProcessedMPTData::operator=(const TProcessedMPTData& rhs)
    {
        fComponent = rhs.fComponent;
        fMainTrack = rhs.fMainTrack;
        fAxialFrequency = rhs.fAxialFrequency;
        return *this;
    }

}
