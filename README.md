# cicada

Library for common processed-data file formats

## Description

This repository contains the libraries describing the objects generated by the [Katydid](https://github/project8/katydid) processing.
These objects should be contained in [ROOT](https://root.cern.ch/root-files) files: as such they inherit from the [TObject](https://root.cern.ch/doc/master/classTObject.html) class (the "mother of all ROOT objects").
Their nature should be very close to [TTree](https://root.cern.ch/root-trees) objects. 

## Documentation

Additional documentation can be found [here](https://www.project8.org/cicada).

## Repository content

 - **documentation:** contains the repository documentation that gets built on [RTD](https://www.project8.org/cicada).
 - **Library:** contains the headers and ccp files of the repository.
 - **Scarab:** [Scarab](https://github/project8/scarab) submodule.

## Operating System Support

* Mac OS X (usually tested on OS X 10.12 and 10.13)
* Linux (usually tested on Debian Jessie and Scientific Linux 6)

## Requirements

**External**
- CMake (3.1 or better)
- ROOT (6.0 or better)

**Submodules** (included with Cicada; must be fetched via Git)

- [Scarab](https://github.com/project8/scarab)

## Installation

The following steps will build Cicada from scratch.  Starting with a terminal window . . .

1. Clone the repository and make a build directory as recommended above. You will also have to initialize the submodules.
  ```
  $ git clone "https://github.com/project8/cicada"
  $ cd cicada
  $ git submodule update --init --recursive
  $ mkdir build
  ```

2. To configure the installation you can use cmake, ccmake, or cmake-gui.

  For a first configuration, using either ccmake or cmake-gui is highly recommended.  The following instructions are for ccmake, but the steps with cmake-gui would be approximately the same.
  ```
  $ cd build
  $ ccmake ..
  ```

  You will be prompted to press [c] to configure, and the window will fill up with several options. 

  You should set the CMake variable `CMAKE_BUILD_TYPE` to either `RELEASE`, `STANDARD`, or `DEBUG` (default), in order of how much text output you would like (from least to most) and how much compiler optimization should be performed (from most to least).

  The install prefix is specified by the CMake variable `CMAKE_INSTALL_PREFIX`.
  The library, binaries, and header files will be installed in the lib, bin, and include subdirectories. The default install prefix is the build directory.

  After you've finished, if you've changed anything press [c] again to configure.  Then [g] to generate and exit.

3. Build and install.

  ```
  $ make install
  ```

  Or if you want to take advantage of parallel building to get things done faster:
  ```
  $ make -j install
  ```

  If the compiler runs into errors during the build, first check that you've updated the submodules and that you have all of the required dependencies installed (many are called "optional" on this page, but if you want to build without them you must also specify this in the cmake window). If you made a change to the dependencies or submodules, you may have to wipe the build directory and start again from step 1; simply writing `make install` again will not always work. 

4. **Developpers:** Add the installation folder (where the bin and lib have been installed) path to your paths.
  - `export PATH=/path/to/install/folder/bin:$PATH`
  - `export LD_LIBRARY_PATH=/path/to/install/folder/lib:$LD_LIBRARY_PATH`

5. **Python interface:** TODO_DOC (once we get it working)

## Usage

Cicada does not have a use case by itself: it can be a dependencies to be added to your c++ package or uses via its Python interface to extract/read the Katydid output objects from your ROOT file.
You can find a example on how to use it in the [morpho](https://github.com/project8/morpho) Python package (TODO_DOC).


