Getting started
===============

Installation
~~~~~~~~~~~~


The following steps will build Cicada from scratch.  Starting with a terminal window . . .

1. Clone the repository and make a build directory as recommended above. You will also have to initialize the submodules.
.. code-block:: bash
   $ git clone "https://github.com/project8/cicada"
   $ cd cicada
   $ git submodule update --init --recursive
   $ mkdir build


2. To configure the installation you can use cmake, ccmake, or cmake-gui.
  For a first configuration, using either ccmake or cmake-gui is highly recommended.  
  The following instructions are for ccmake, but the steps with cmake-gui would be approximately the same.
.. code-block:: bash
   $ cd build
   $ ccmake ..


  You will be prompted to press [c] to configure, and the window will fill up with several options. 

  You should set the CMake variable `CMAKE_BUILD_TYPE` to either `RELEASE`, `STANDARD`, or `DEBUG` (default), in order of how much text output you would like (from least to most) and how much compiler optimization should be performed (from most to least).

  The install prefix is specified by the CMake variable `CMAKE_INSTALL_PREFIX`.
  The library, binaries, and header files will be installed in the lib, bin, and include subdirectories. The default install prefix is the build directory.

  After you've finished, if you've changed anything press [c] again to configure.  Then [g] to generate and exit.

3. Build and install.

.. code-block:: bash
   $ make install


  Or if you want to take advantage of parallel building to get things done faster:
.. code-block:: bash
   $ make -j install


  If the compiler runs into errors during the build, first check that you've updated the submodules and that you have all of the required dependencies installed (many are called "optional" on this page, but if you want to build without them you must also specify this in the cmake window). If you made a change to the dependencies or submodules, you may have to wipe the build directory and start again from step 1; simply writing `make install` again will not always work. 

4. **Developpers:** Add the installation folder (where the bin and lib have been installed) path to your paths.
  - `export PATH=/path/to/install/folder/bin:$PATH`
  - `export LD_LIBRARY_PATH=/path/to/install/folder/lib:$LD_LIBRARY_PATH`

How to use
~~~~~~~~~~



