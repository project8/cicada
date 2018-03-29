/**
 @file CicadaLinkDef.hh
 @brief Defines links for compiler for Cicada
 @details Defines links for compiler with the Cicada namespace
 @author N. S. Oblath
 @date Jan 15, 2018
 */

#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclasses;
#pragma link C++ nestedtypedefs;

#pragma link C++ namespace Cicada;

#pragma link C++ class Cicada::TClassifierResultsData+;
#pragma link C++ class Cicada::TMTEWithClassifierResultsData+;
#pragma link C++ class Cicada::TProcessedMPTData+;
#pragma link C++ class Cicada::TProcessedTrackData+;
#pragma link C++ class Cicada::TMultiTrackEventData+;

#endif
