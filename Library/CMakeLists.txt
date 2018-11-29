# CMakeLists for Cicada/Library
# Author: N. Oblath
# Date: Jan 15, 2018


set( CICADA_DICT_HEADERFILES
    _CROOTData.hh
    CClassifierResultsData.hh
    CMemberVariables.hh
    CMTEWithClassifierResultsData.hh
    CProcessedMPTData.hh
    CROOTData.hh
)

set( CICADA_HEADERFILES
    ${CICADA_DICT_HEADERFILES}
)

set( CICADA_SOURCEFILES
    CClassifierResultsData.cc
    CMTEWithClassifierResultsData.cc
    CProcessedMPTData.cc
    CROOTData.cc
)

set( CICADA_LINKDEF_HEADERFILE LinkDef/CicadaLinkDef.hh )
set( CICADA_SOURCEFILES ${CICADA_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/CicadaDict.cxx )
set( CICADA_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/CicadaDict_rdict.pcm )

if( Cicada_ENABLE_KATYDID_NAMESPACE )
    set( CICADA_KT_DICT_HEADERFILES
        KTROOTData.hh
    )
    
    set( CICADA_HEADERFILES
        ${CICADA_HEADERFILES}
        ${CICADA_KT_DICT_HEADERFILES}
    )
    
    set( CICADA_SOURCEFILES
        ${CICADA_SOURCEFILES}
        KTROOTData.cc
    )
    
    set( CICADA_KT_LINKDEF_HEADERFILE LinkDef/CicadaKTLinkDef.hh )
    set( CICADA_SOURCEFILES ${CICADA_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/CicadaKTDict.cxx )
    set( CICADA_KT_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/CicadaKTDict_rdict.pcm )
endif( Cicada_ENABLE_KATYDID_NAMESPACE )

##################################################

ROOT_GENERATE_DICTIONARY( CicadaDict ${CICADA_DICT_HEADERFILES} LINKDEF ${CICADA_LINKDEF_HEADERFILE} OPTIONS -inlineInputHeader )
pbuilder_install_files( ${LIB_INSTALL_DIR} ${CICADA_DICT_PCMFILE} )

if( Cicada_ENABLE_KATYDID_NAMESPACE )
    ROOT_GENERATE_DICTIONARY( CicadaKTDict ${CICADA_KT_DICT_HEADERFILES} LINKDEF ${CICADA_KT_LINKDEF_HEADERFILE} OPTIONS -inlineInputHeader )
    pbuilder_install_files( ${LIB_INSTALL_DIR} ${CICADA_KT_DICT_PCMFILE} )
endif( Cicada_ENABLE_KATYDID_NAMESPACE )

pbuilder_library( Cicada CICADA_SOURCEFILES "" )
pbuilder_install_headers( ${CICADA_HEADERFILES} )

if( Cicada_ADD_CICADA_PY )
    set( lib_target Cicada${Cicada_PARENT_LIB_NAME_SUFFIX} )
    configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/python/CicadaPy.py.in ${CMAKE_CURRENT_BINARY_DIR}/CicadaPy.py.gen.in )
    file( GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/CicadaPy.py INPUT ${CMAKE_CURRENT_BINARY_DIR}/CicadaPy.py.gen.in )
    
    pbuilder_install_files( ${LIB_INSTALL_DIR}/CicadaPy ${CMAKE_CURRENT_BINARY_DIR}/CicadaPy.py )
    pbuilder_install_files( ${LIB_INSTALL_DIR}/CicadaPy ${CMAKE_CURRENT_SOURCE_DIR}/python/__init__.py )
    pbuilder_install_files( ${LIB_INSTALL_DIR}/CicadaPy ${CMAKE_CURRENT_SOURCE_DIR}/python/ReadKTOutputFile.py )
endif( Cicada_ADD_CICADA_PY )
