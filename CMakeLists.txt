# CMakeLists for Cicada
# Author: N. Oblath

# Minimum cmake verison 3.1 required for the variable CMAKE_CXX_STANDARD
cmake_minimum_required (VERSION 3.1)

#########
# Setup #
#########

cmake_policy( SET CMP0048 NEW ) # version in project()
project( Cicada VERSION 0.3.0 )

list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/Scarab/cmake )
include( PackageBuilder )

pbuilder_prepare_project()

#################
# Cicada options #
#################

option( Cicada_ENABLE_KATYDID_NAMESPACE "Build an additional library with the Cicada classes defined additionally in the Katydid namespace" OFF )
  

######################
# Cicada dependencies #
######################

########
# Scarab
########

pbuilder_add_submodule( Scarab Scarab/library )

######
# ROOT
######

find_package (ROOT 6.00)
if (ROOT_FOUND)
    pbuilder_add_ext_libraries (${ROOT_LIBRARIES})
    #message(STATUS "${ROOT_LIBRARIES}")
else (ROOT_FOUND)
    message(FATAL "Unable to find ROOT")
endif (ROOT_FOUND)
include_directories (${ROOT_INCLUDE_DIR})


################
# Build Cicada #
################

include_directories (BEFORE 
    ${PROJECT_SOURCE_DIR}/Library
)

add_subdirectory( Library )

pbuilder_variables_for_parent()
