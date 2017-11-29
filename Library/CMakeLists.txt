# CMakeLists for Cicada/Library
# Author: N. Oblath


set( CICADA_DICT_HEADERFILES
    CROOTData.hh
)

set( CICADA_HEADERFILES
    ${CICADA_DICT_HEADERFILES}
)

set( CICADA_SOURCEFILES
    CROOTData.cc
)

set( CICADA_LINKDEF_HEADERFILE LinkDef/CicadaLinkDef.hh )
set( CICADA_SOURCEFILES ${CICADA_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/CicadaDict.cxx )
set( CICADA_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/CicadaDict_rdict.pcm )

##################################################

ROOT_GENERATE_DICTIONARY( CicadaDict ${CICADA_DICT_HEADERFILES} LINKDEF ${CICADA_LINKDEF_HEADERFILE} )
pbuilder_install_files( ${LIB_INSTALL_DIR} ${CICADA_DICT_PCMFILE} )

pbuilder_library( Cicada CICADA_SOURCEFILES "" )
pbuilder_install_headers( ${CICADA_HEADERFILES} )

#add_library( Cicada ${CICADA_SOURCEFILES} ${CICADA_DICT_OUTFILE} )
#target_link_libraries( Cicada ${EXTERNAL_LIBRARIES} )

#pbuilder_install_headers( ${CICADA_HEADERFILES} )
#pbuilder_install_libraries( Cicada )

