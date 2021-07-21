# CMakeLists for Executables
# Author: M. Guigue
# Date: Feb 9 2018
# Inspired by Katydid

# Executables

set( Cicada_EXE_SOURCES
    BasicTest.cc
)

set( Cicada_LIBS
    Cicada
)

pbuilder_executables( programs all_libs )

set( Cicada_PROGRAMS )
pbuilder_executables( 
    SOURCES ${Cicada_EXE_SOURCES}
    TARGETS_VAR Cicada_PROGRAMS
    PROJECT_LIBRARIES ${Cicada_LIBS}
)

pbuilder_component_install_and_export( 
    COMPONENT Executables
    EXETARGETS ${Cicada_PROGRAMS}
)
