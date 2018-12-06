Validation Log
==============

Guidelines
----------

* All new features incorporated into a tagged release should have their validation documented.
  * Document the new feature.
  * Perform tests to validate the new feature.
  * If the feature is slated for incorporation into an official analysis, perform tests to show that the overall analysis works and benefits from this feature.
  * Indicate in this log where to find documentation of the new feature.
  * Indicate in this log what tests were performed, and where to find a writeup of the results.
* Fixes to existing features should also be validated.
  * Perform tests to show that the fix solves the problem that had been indicated.
  * Perform tests to show that the fix does not cause other problems.
  * Indicate in this log what tests were performed and how you know the problem was fixed.

Log
---

Version: 1.3.2
~~~~~~~~~~~~~~

Release Date: Dec 6, 2018 
'''''''''''''''''''''''''''''

Fixes:
'''''''''''''

* New docker dependencies


Version: 1.3.1
~~~~~~~~~~~~~~

Release Date: Dec 5, 2018 
'''''''''''''''''''''''''''''

Fixes:
'''''''''''''

* Removing unused libraries (yaml, json, param) from build
* Switched docker build to use COPY instead of git clone


Version: 1.3.0
~~~~~~~~~~~~~~

Release Date: Nov 29, 2018
'''''''''''''''''''''''''''''
New Features:
'''''''''''''

* New Dockerfile based on the p8compute-dependencies container
* Added this_cicada.sh script to properly set ROOT include path and python path
* Fixed the ROOT dictionary build so that it doesn't hard-code source-tree paths


Version: 1.2.1
~~~~~~~~~~~~~~

Release Date: June 27th, 2018
'''''''''''''''''''''''''''''
Fixes:
'''''''''

* Update Scarab

Version: 1.2.0
~~~~~~~~~~~~~~

Release Date: June 15th, 2018
'''''''''''''''''''''''''''''
New Features:
''''''''''''''

* TMultiTrackEventData: adding SNR and NUP based quantities for the first track:
    * FirstTrackNTrackBins
    * FirstTrackTotalSNR
    * FirstTrackMaxSNR
    * FirstTrackTotalNUP
    * FirstTrackMaxNUP
    * FirstTrackTotalWideSNR
    * FirstTrackTotalWideNUP

Version: 1.1.1
~~~~~~~~~~~~~~

Release Date: June 7th, 2018
''''''''''''''''''''''''''''

Fixes:
''''''

* Bumping ClassDef version for TProcessedTrackData

Version: 1.1.0
~~~~~~~~~~~~~~

Release Date: June 1st, 2018
''''''''''''''''''''''''''''

New Features:
'''''''''''''

* TProcessedTrackData: adding SNR and NUP based quantities:
    * NTrackBins
    * TotalTrackSNR
    * MaxTrackSNR
    * TotalTrackNUP
    * MaxTrackNUP
    * TotalWideTrackSNR
    * TotalWideTrackNUP
* Moving the default object name from the Katydid Writer into Cicada:
      * TMultiTrackEventData
      * TProcessedTrackData
      * TProcessedMPTData (not done as inherits from TMultiTrackEventData)
      * TClassifierResultsData
* ReadKTOutputFile: 
    * Extraction of tracks information from TMultiTrackEventData.
    * Extraction of multiple branches without one execution.


Version: 1.0.2
~~~~~~~~~~~~~~

Release Date: April 12, 2018
'''''''''''''''''''''''''''''''

New Features:
'''''''''''''

* ReadKTOutputFile: Support of Cicada and Katydid namespaces and access to TMultiTrackEventData members.

Fixes:
''''''

* Documentation update about the python libraries.


Version: 1.0.1
~~~~~~~~~~~~~~

Release Date: April 10, 2018
'''''''''''''''''''''''''''''''

Fixes:
''''''

* Docker: Sleep time after chmod of installation script.


Version: 1.0.0
~~~~~~~~~~~~~~

Release Date: March 29, 2018
'''''''''''''''''''''''''''''''

New Features:
'''''''''''''

* Classification related objects; added CMTEWithClassifierResultsData, CClassifierResultsData, and CProcessedMPTData.
* Definition of a Cicada-specific prefixes for Set, Get and variables; added CMemberVariables.hh.

Fixes:
''''''

* Docker: correction of the installation location (from /cicada/build to /build).
* Documentation/Doxygen updates.


Version: 0.4.2
~~~~~~~~~~~~~~

Release Date: March 14, 2018
'''''''''''''''''''''''''''''''

New Features:
'''''''''''''

Fixes:
''''''

* Fixed the namespace in the constructor for the Tracks TClonesArray in TMultiTrackEventData.


Version: 0.4.1
~~~~~~~~~~~~~~

Release Date: February 22, 2018
'''''''''''''''''''''''''''''''

New Features:
'''''''''''''

Fixes:
''''''

* Add const return of the Tracks TClonesArray in TMultiTrackEventData.


Version: 0.4.0
~~~~~~~~~~~~~~

Release Date: February 14, 2018
'''''''''''''''''''''''''''''''

New Features:
'''''''''''''

* Python interface via ```import CicadaPy``` after installation #2
* Dockerfile
* A proper documentation
  
Fixes:
''''''

Version: v0.3.0
~~~~~~~~~~~~~~~

Release Date: January 29, 2018
''''''''''''''''''''''''''''''

New Features:
'''''''''''''
* Classes TProcessedTrackData and TMultiTrackEventData defined across Katydid and Cicada namespaces


  
Template
--------

Version: 
~~~~~~~~

Release Date: 
'''''''''''''

New Features:
'''''''''''''

* Feature 1
    * Details
* Feature 2
    * Details
  
Fixes:
''''''

* Fix 1
    * Details
* Fix 2
    * Details
  
