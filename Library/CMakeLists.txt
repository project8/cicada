# CMakeLists for Cicada/Library
# Author: N. Oblath
# Date: Jan 15, 2018

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

set( CICADA_DICT_HEADERFILES
    CClassifierResultsData.hh
    CMemberVariables.hh
    CMTEWithClassifierResultsData.hh
    CProcessedMPTData.hh
    CROOTData.hh
)

set( CICADA_SOURCEFILES
    CClassifierResultsData.cc
    CMTEWithClassifierResultsData.cc
    CProcessedMPTData.cc
    CROOTData.cc
)

set( CICADA_LINKDEF_HEADERFILE LinkDef/CicadaLinkDef.hh )

##################################################

set( lib_name Cicada )
pbuilder_expand_lib_name( ${lib_name} )
set( full_lib_name ${FULL_LIB_NAME} )
pbuilder_library(
    TARGET ${lib_name}
    SOURCES ${CICADA_SOURCEFILES} ${ADDITIONAL_SOURCES}
    PUBLIC_EXTERNAL_LIBRARIES ${PUBLIC_EXT_LIBS}
)

set( dict_name CicadaDict )
message( STATUS "Generating ROOT dictionary <${dict_name}>")
ROOT_GENERATE_DICTIONARY( ${dict_name} ${CICADA_DICT_HEADERFILES} MODULE ${full_lib_name} LINKDEF ${CICADA_LINKDEF_HEADERFILE} OPTIONS -inlineInputHeader )
pbuilder_install_files (${LIB_INSTALL_DIR} ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}${full_lib_name}_rdict.pcm)

pbuilder_component_install_and_export( 
    COMPONENT Library
    LIBTARGETS Cicada
)

pbuilder_install_headers( ${CICADA_DICT_HEADERFILES} )

if( Cicada_ADD_CICADA_PY )
    set( lib_target Cicada${Cicada_PARENT_LIB_NAME_SUFFIX} )
    configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/python/CicadaPy.py.in ${CMAKE_CURRENT_BINARY_DIR}/CicadaPy.py.gen.in )
    file( GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/CicadaPy.py INPUT ${CMAKE_CURRENT_BINARY_DIR}/CicadaPy.py.gen.in )
    
    pbuilder_install_files( ${LIB_INSTALL_DIR}/CicadaPy ${CMAKE_CURRENT_BINARY_DIR}/CicadaPy.py )
    pbuilder_install_files( ${LIB_INSTALL_DIR}/CicadaPy ${CMAKE_CURRENT_SOURCE_DIR}/python/__init__.py )
    pbuilder_install_files( ${LIB_INSTALL_DIR}/CicadaPy ${CMAKE_CURRENT_SOURCE_DIR}/python/ReadKTOutputFile.py )
endif( Cicada_ADD_CICADA_PY )
