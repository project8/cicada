/**
 @file CicadaLinkDef.hh
 @brief Defines links for compiler for Katydid
 @details Defines links for compiler with the Katydid namespace
 @author N. S. Oblath
 @date Jan 15, 2018
 */

#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclasses;
#pragma link C++ nestedtypedefs;

#pragma link C++ namespace Katydid;

#pragma link C++ class Katydid::TProcessedTrackData+;
#pragma link C++ class Katydid::TMultiTrackEventData+;

#endif
