# CMakeLists for Executables
# Author: M. Guigue
# Date: Feb 9 2018
# Inspired by Katydid

# Executables

get_property( all_libs GLOBAL PROPERTY ${PROJECT_NAME}_LIBRARIES )
message(STATUS "Cicada exectuables library dependencies: ${all_libs}" )

set( programs
    BasicTest
)

pbuilder_executables( programs all_libs )
