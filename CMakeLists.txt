# CMakeLists for Cicada
# Author: N. Oblath
# Date: Jan 15, 2018

# Minimum cmake verison 3.12 required by Scarab
cmake_minimum_required (VERSION 3.12)

#########
# Setup #
#########

cmake_policy( SET CMP0048 NEW ) # version in project()
project( Cicada VERSION 1.4.1 )

list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/Scarab/cmake )
include( PackageBuilder )

#################
# Cicada options #
#################

option( Cicada_ENABLE_KATYDID_NAMESPACE "Build an additional library with the Cicada classes defined additionally in the Katydid namespace" ON )
option (Cicada_ADD_CICADA_PY "Add PhylloxeraPy file in the build" ON )

if( PBUILDER_STANDALONE )
    set_option( Scarab_BUILD_CODEC_JSON OFF )
    set_option( Scarab_BUILD_CODEC_YAML OFF )
    set_option( Scarab_BUILD_AUTHENTICATION OFF )
    set_option( Scarab_BUILD_CLI OFF )
    set_option( Scarab_BUILD_PARAM OFF )
    set_option( Scarab_ENABLE_EXECUTABLES OFF )
endif()

#######################
# Cicada dependencies #
#######################

set( PUBLIC_EXT_LIBS )

######
# ROOT
######

set( root_components Tree )
list( APPEND PUBLIC_EXT_LIBS ROOT::Tree )
if( Cicada_ENABLE_EXECUTABLES )
    list( APPEND root_components RIO )
    list( APPEND PUBLIC_EXT_LIBS ROOT::RIO )
endif()
find_package( ROOT 6.20 REQUIRED CONFIG COMPONENTS ${root_components} )

#####################
# Prepare for build #
#####################

pbuilder_prepare_project()

##############
# Submodules #
##############

pbuilder_add_submodule( Scarab Scarab )

# all parts of Cicada use Scarab, so include it here
pbuilder_use_sm_library( Scarab Scarab )

################
# Build Cicada #
################

add_subdirectory( Library )

if( Cicada_ENABLE_EXECUTABLES )
    add_subdirectory( Executables )
endif()

#configure_file( this_cicada.sh.in this_cicada.sh )
#pbuilder_install_files( ${BIN_INSTALL_DIR} ${CMAKE_CURRENT_BINARY_DIR}/this_cicada.sh )

##################
# Package Config #
##################

configure_file( ${PROJECT_SOURCE_DIR}/CicadaConfig.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/CicadaConfig.cmake @ONLY )

pbuilder_do_package_config()
