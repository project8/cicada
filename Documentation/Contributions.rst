Contributions
=============

Reporting bugs
~~~~~~~~~~~~~~

You can report bugs using the Cicada `issue tracker`_. 
When doing so, please provide your configuration (gcc, cmake and ROOT versions, virtual environment) and a detailed description of the steps to reproduce the bug.

Development scheme, code testing et release procedure
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Development scheme
------------------

The Project 8 collaboration has adopted the Git flow development scheme: you can find details and the correct git commands about how to use it on this `page`_.
For a more visual way of developing code, the use of the `SourceTree`_ application is recommended as it natively integrates the Git flow scheme.

Code testing with Docker
------------------------

If you would like to modify your local installation of Cicada (to add features or resolve any bugs), we recommend you use a Docker container as a uniform test bench. To do so:
* Install Docker: https://docs.docker.com/engine/installation/
* Clone and pull the latest master version of Cicada
* Inside the cicada folder, execute 
::
    docker build -t cicada . 
    docker run -it cicada bash 
A new terminal prompter (for example, `root@413ab10d7a8f:`) should appear. 
Then you have to load the environment:
::
    source /setup_cicada.sh

You may make changes to Cicada either inside or outside of the Docker container. 
If you wish to work outside of the container, you will need to mount a local folder in the container (see Docker documentation).

You can remove the container image using 
:: 
    docker rmi Cicada_Cicada

Release procedure
-----------------

When making a release or a hotfix, several steps shall be done:

* update the documentation (see Documentation section)
* update the project number in the top CMakeLists.txt file
* update the authors lists (if applicable)
* update the Documentation/ValidationLog.rst file

After making the release:

* create a `release`_ entry on Github and add the corresponding entry from the ValidationLog.rst file

Contributing to the code
~~~~~~~~~~~~~~~~~~~~~~~~

If you are new to the code and are willing to contribute by developing new features or maintaining the code, please refer to the `issue tracker`_.
There are issues you can look at and decide on solving.
When you have found your ideal issue, please comment in the issue tracker, so the main developers are aware you are working on this.

If you wish to contribute to maintaining a proper documentation, please refer to the Documentation section.

Documentation
~~~~~~~~~~~~~

The documentation of Cicada happens at several levels:

* in the repository, we maintain README.md files describing the content of each folder.
* in the `Documentation`_ folder, we maintain RST files.
  With each release of the code, ReadTheDocs reads these files and produces pages (such as this one).
* inside the code, documentation is provided as comments and Doxygen headers.
  Once compiled by ReadTheDocs, it produces a proper `Doxygen documentation`_ of the code.
* a ValidationLog.rst file keeps track of the new features or fixes added to the code.
  For each Github issue solved, a entry describing the solved issue (and its Github number) should be added in the upcoming release subsection.

This documentation must be updated at any release/hotfix/pull-request to keep the repository as up-to-date as possible.

.. _issue tracker: https://github.com/project8/cicada/issues
.. _Documentation: https://github.com/project8/cicada/tree/master/Documentation
.. _Doxygen documentation: http://p8-cicada.readthedocs.io/en/stable/_static/index.html
.. _page: http://nvie.com/posts/a-successful-git-branching-model/
.. _SourceTree: https://www.sourcetreeapp.com/
.. _release: https://github.com/project8/cicada/releases


