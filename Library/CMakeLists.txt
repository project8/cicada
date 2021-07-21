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

pbuilder_add_library( 
    TARGET Cicada 
    SOURCES ${CICADA_SOURCEFILES} ${ADDITIONAL_SOURCES}
)

set( dict_name CicadaDict )
message( STATUS "Generating ROOT dictionary <${dict_name}>")
ROOT_GENERATE_DICTIONARY( ${dict_name} ${CICADA_DICT_HEADERFILES} MODULE Cicada LINKDEF ${CICADA_LINKDEF_HEADERFILE} OPTIONS -inlineInputHeader )

pbuilder_link_library( 
    TARGET Cicada 
    PUBLIC_EXTERNAL_LIBRARIES ${PUBLIC_EXT_LIBS}
)

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
