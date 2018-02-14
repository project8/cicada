Objects' structure and description
========================================

Here is described the content and associated description of the Cicada objects.

Version up-to 0.4.0
~~~~~~~~~~~~~~~~~~~

TMultiTrackEventData
````````````````````

* **Component** -- UInt_t: 
* **AcquisitionID** -- UInt_t: 
* **EventID** -- UInt_t: 
* **TotalEventSequences** -- UInt_t: 

* **StartTimeInRunC** -- Double_t: 
* **StartTimeInAcq** -- Double_t: 
* **EndTimeInRunC** -- Double_t: 
* **TimeLength** -- Double_t: 
* **StartFrequency** -- Double_t: 
* **EndFrequency** -- Double_t: 
* **MinimumFrequency** -- Double_t: 
* **MaximumFrequency** -- Double_t: 
* **FrequencyWidth** -- Double_t: 

* **StartTimeInRunCSigma** -- Double_t: 
* **EndTimeInRunCSigma** -- Double_t: 
* **StartFrequencySigma** -- Double_t: 
* **EndFrequencySigma** -- Double_t: 
* **FrequencyWidthSigma** -- Double_t: 

* **FirstTrackID** -- UInt_t: 
* **FirstTrackTimeLength** -- Double_t: 
* **FirstTrackFrequencyWidth** -- Double_t: 
* **FirstTrackSlope** -- Double_t: 
* **FirstTrackIntercept** -- Double_t: 
* **FirstTrackTotalPower** -- Double_t:

* **UnknownEventTopology** -- Double_t: 

TProcessedTrackData
```````````````````

* **Component** -- UInt_t: 
* **AcquisitionID** -- UInt_t: 
* **TrackID** -- UInt_t: 
* **EventID** -- UInt_t: 
* **EventSequenceID** -- UInt_t: 
* **IsCut** -- Bool_t: 

* **StartTimeInRunC** -- Double_t: 
* **StartTimeInAcq** -- Double_t: 
* **EndTimeInRunC** -- Double_t: 
* **TimeLength** -- Double_t: 
* **StartFrequency** -- Double_t: 
* **EndFrequency** -- Double_t: 
* **FrequencyWidth** -- Double_t: 
* **Slope** -- Double_t: 
* **Intercept** -- Double_t: 
* **TotalPower** -- Double_t: 

* **StartTimeInRunCSigma** -- Double_t: 
* **EndTimeInRunCSigma** -- Double_t: 
* **TimeLengthSigma** -- Double_t: 
* **StartFrequencySigma** -- Double_t: 
* **EndFrequencySigma** -- Double_t: 
* **FrequencyWidthSigma** -- Double_t: 
* **SlopeSigma** -- Double_t: 
* **InterceptSigma** -- Double_t: 
* **TotalPowerSigma** -- Double_t: 

