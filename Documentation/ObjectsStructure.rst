Objects' structure and description
========================================

Here is described the content and associated description of the Cicada objects.

Version 1.x.x
~~~~~~~~~~~~~~~~~~~

TMultiTrackEventData
````````````````````

* **Component** -- UInt_t: 
* **AcquisitionID** -- UInt_t: 
* **EventID** -- UInt_t: number of the event in the katydid instance
* **TotalEventSequences** -- UInt_t: number of sequences in the event

* **StartTimeInRunC** -- Double_t: start time of the event in the Katydid instance
* **StartTimeInAcq** -- Double_t: start time of the event within the chunk of data
* **EndTimeInRunC** -- Double_t: end time of the event in the Katydid instance
* **TimeLength** -- Double_t: duration of the event
* **StartFrequency** -- Double_t: start frequency of the event
* **EndFrequency** -- Double_t: end frequency of the event
* **MinimumFrequency** -- Double_t: minimum frequency reached by the event
* **MaximumFrequency** -- Double_t: maximum frequency reached by the event
* **FrequencyWidth** -- Double_t: range of frequencies covered by the event tracks

* **StartTimeInRunCSigma** -- Double_t: error on the start time of the event in the Katydid instance
* **EndTimeInRunCSigma** -- Double_t: error on the end time of the event in the Katydid instance
* **StartFrequencySigma** -- Double_t: error on the start frequency of the event
* **EndFrequencySigma** -- Double_t: error on the end frequency of the event
* **FrequencyWidthSigma** -- Double_t: error on the range of frequencies covered by the event tracks

* **FirstTrackID** -- UInt_t: ID number of the first track in the event
* **FirstTrackTimeLength** -- Double_t: length of the first track
* **FirstTrackFrequencyWidth** -- Double_t: range of frequencies covered by the first track
* **FirstTrackSlope** -- Double_t: slope of the first track
* **FirstTrackIntercept** -- Double_t: intercept at t=0 of the first track
* **FirstTrackTotalPower** -- Double_t: sum of the power of the bins composing the first track
* **FirstTrackTotalTrackSNR** -- Double_t: Sum of the track bins SNR of the first track
* **FirstTrackMaxTrackSNR** -- Double_t: Max of the track bins SNR of the first track
* **FirstTrackTotalTrackNUP** -- Double_t: Sum of the track bins Normalized Unitless Power (NUP) of the first track
* **FirstTrackMaxTrackNUP** -- Double_t: Max of the track bins Normalized Unitless Power (NUP) of the first track
* **FirstTrackTotalWideTrackSNR** -- Double_t: Sum of the track extended bins SNR of the first track
* **FirstTrackTotalWideTrackNUP** -- Double_t: Sum of the track extended bins Normalized Unitless Power (NUP) of the first track

* **UnknownEventTopology** -- Double_t: boolean describing if a track has some weird topology

TProcessedTrackData
```````````````````

* **Component** -- UInt_t: 
* **AcquisitionID** -- UInt_t: 
* **TrackID** -- UInt_t: number of the track in the event
* **EventID** -- UInt_t: number of the event in the katydid instance
* **EventSequenceID** -- UInt_t: number of the sequence in the event reconstruction
* **IsCut** -- Bool_t: should this line be cut when calculating the start frequency...?

* **StartTimeInRunC** -- Double_t: start time of the track in the Katydid instance
* **StartTimeInAcq** -- Double_t: start time of the track within the chunk of data
* **EndTimeInRunC** -- Double_t: end time of the track in the Katydid instance
* **TimeLength** -- Double_t: track length
* **StartFrequency** -- Double_t: start frequency of the track
* **EndFrequency** -- Double_t: end frequency of the track
* **FrequencyWidth** -- Double_t: range of frequencies covered by the track
* **Slope** -- Double_t: slope of the track
* **Intercept** -- Double_t: intercept at t=0 of the track
* **TotalPower** -- Double_t: sum of the power of the bins composing the track

* **NTrackBins** -- UInt_t: number of bins in the track
* **TotalTrackSNR** -- Double_t: Sum of the track bins SNR
* **MaxTrackSNR** -- Double_t: Max of the track bins SNR
* **TotalTrackNUP** -- Double_t: Sum of the track bins Normalized Unitless Power (NUP)
* **MaxTrackNUP** -- Double_t: Max of the track bins Normalized Unitless Power (NUP)
* **TotalWideTrackSNR** -- Double_t: Sum of the track extended bins SNR
* **TotalWideTrackNUP** -- Double_t: Sum of the track extended bins Normalized Unitless Power (NUP)

* **StartTimeInRunCSigma** -- Double_t: error on the start time of the track in the Katydid instance
* **EndTimeInRunCSigma** -- Double_t: error on the end time of the track in the Katydid instance
* **TimeLengthSigma** -- Double_t: error on the track length
* **StartFrequencySigma** -- Double_t: error on the track start frequency
* **EndFrequencySigma** -- Double_t: error on the track end frequency
* **FrequencyWidthSigma** -- Double_t: error on the range of frequencies covered by the track
* **SlopeSigma** -- Double_t: error on the slope track
* **InterceptSigma** -- Double_t: error on the track intercept
* **TotalPowerSigma** -- Double_t: error on the sum of the power of the bins composing the track

Version 1.1.0
~~~~~~~~~~~~~~~~~~~

TMultiTrackEventData
````````````````````

* **Component** -- UInt_t: 
* **AcquisitionID** -- UInt_t: 
* **EventID** -- UInt_t: number of the event in the katydid instance
* **TotalEventSequences** -- UInt_t: number of sequences in the event

* **StartTimeInRunC** -- Double_t: start time of the event in the Katydid instance
* **StartTimeInAcq** -- Double_t: start time of the event within the chunk of data
* **EndTimeInRunC** -- Double_t: end time of the event in the Katydid instance
* **TimeLength** -- Double_t: duration of the event
* **StartFrequency** -- Double_t: start frequency of the event
* **EndFrequency** -- Double_t: end frequency of the event
* **MinimumFrequency** -- Double_t: minimum frequency reached by the event
* **MaximumFrequency** -- Double_t: maximum frequency reached by the event
* **FrequencyWidth** -- Double_t: range of frequencies covered by the event tracks

* **NTrackBins** -- UInt_t: number of bins in the track
* **TotalTrackSNR** -- Double_t: Sum of the track bins SNR
* **MaxTrackSNR** -- Double_t: Max of the track bins SNR
* **TotalTrackNUP** -- Double_t: Sum of the track bins Normalized Unitless Power (NUP)
* **MaxTrackNUP** -- Double_t: Max of the track bins Normalized Unitless Power (NUP)
* **TotalWideTrackSNR** -- Double_t: Sum of the track extended bins SNR
* **TotalWideTrackNUP** -- Double_t: Sum of the track extended bins Normalized Unitless Power (NUP)

* **StartTimeInRunCSigma** -- Double_t: error on the start time of the event in the Katydid instance
* **EndTimeInRunCSigma** -- Double_t: error on the end time of the event in the Katydid instance
* **StartFrequencySigma** -- Double_t: error on the start frequency of the event
* **EndFrequencySigma** -- Double_t: error on the end frequency of the event
* **FrequencyWidthSigma** -- Double_t: error on the range of frequencies covered by the event tracks

* **FirstTrackID** -- UInt_t: ID number of the first track in the event
* **FirstTrackTimeLength** -- Double_t: length of the first track
* **FirstTrackFrequencyWidth** -- Double_t: range of frequencies covered by the first track
* **FirstTrackSlope** -- Double_t: slope of the first track
* **FirstTrackIntercept** -- Double_t: intercept at t=0 of the first track
* **FirstTrackTotalPower** -- Double_t: sum of the power of the bins composing the first track

* **UnknownEventTopology** -- Double_t: boolean describing if a track has some weird topology

TProcessedTrackData
```````````````````

* **Component** -- UInt_t: 
* **AcquisitionID** -- UInt_t: 
* **TrackID** -- UInt_t: number of the track in the event
* **EventID** -- UInt_t: number of the event in the katydid instance
* **EventSequenceID** -- UInt_t: number of the sequence in the event reconstruction
* **IsCut** -- Bool_t: should this line be cut when calculating the start frequency...?

* **StartTimeInRunC** -- Double_t: start time of the track in the Katydid instance
* **StartTimeInAcq** -- Double_t: start time of the track within the chunk of data
* **EndTimeInRunC** -- Double_t: end time of the track in the Katydid instance
* **TimeLength** -- Double_t: track length
* **StartFrequency** -- Double_t: start frequency of the track
* **EndFrequency** -- Double_t: end frequency of the track
* **FrequencyWidth** -- Double_t: range of frequencies covered by the track
* **Slope** -- Double_t: slope of the track
* **Intercept** -- Double_t: intercept at t=0 of the track
* **TotalPower** -- Double_t: sum of the power of the bins composing the track

* **StartTimeInRunCSigma** -- Double_t: error on the start time of the track in the Katydid instance
* **EndTimeInRunCSigma** -- Double_t: error on the end time of the track in the Katydid instance
* **TimeLengthSigma** -- Double_t: error on the track length
* **StartFrequencySigma** -- Double_t: error on the track start frequency
* **EndFrequencySigma** -- Double_t: error on the track end frequency
* **FrequencyWidthSigma** -- Double_t: error on the range of frequencies covered by the track
* **SlopeSigma** -- Double_t: error on the slope track
* **InterceptSigma** -- Double_t: error on the track intercept
* **TotalPowerSigma** -- Double_t: error on the sum of the power of the bins composing the track


Version 0.4.2
~~~~~~~~~~~~~~~~~~~

TMultiTrackEventData
````````````````````

* **Component** -- UInt_t: 
* **AcquisitionID** -- UInt_t: 
* **EventID** -- UInt_t: number of the event in the katydid instance
* **TotalEventSequences** -- UInt_t: number of sequences in the event

* **StartTimeInRunC** -- Double_t: start time of the event in the Katydid instance
* **StartTimeInAcq** -- Double_t: start time of the event within the chunk of data
* **EndTimeInRunC** -- Double_t: end time of the event in the Katydid instance
* **TimeLength** -- Double_t: duration of the event
* **StartFrequency** -- Double_t: start frequency of the event
* **EndFrequency** -- Double_t: end frequency of the event
* **MinimumFrequency** -- Double_t: minimum frequency reached by the event
* **MaximumFrequency** -- Double_t: maximum frequency reached by the event
* **FrequencyWidth** -- Double_t: range of frequencies covered by the event tracks

* **StartTimeInRunCSigma** -- Double_t: error on the start time of the event in the Katydid instance
* **EndTimeInRunCSigma** -- Double_t: error on the end time of the event in the Katydid instance
* **StartFrequencySigma** -- Double_t: error on the start frequency of the event
* **EndFrequencySigma** -- Double_t: error on the end frequency of the event
* **FrequencyWidthSigma** -- Double_t: error on the range of frequencies covered by the event tracks

* **FirstTrackID** -- UInt_t: ID number of the first track in the event
* **FirstTrackTimeLength** -- Double_t: length of the first track
* **FirstTrackFrequencyWidth** -- Double_t: range of frequencies covered by the first track
* **FirstTrackSlope** -- Double_t: slope of the first track
* **FirstTrackIntercept** -- Double_t: intercept at t=0 of the first track
* **FirstTrackTotalPower** -- Double_t: sum of the power of the bins composing the first track

* **UnknownEventTopology** -- Double_t: boolean describing if a track has some weird topology

TProcessedTrackData
```````````````````

* **Component** -- UInt_t: 
* **AcquisitionID** -- UInt_t: 
* **TrackID** -- UInt_t: number of the track in the event
* **EventID** -- UInt_t: number of the event in the katydid instance
* **EventSequenceID** -- UInt_t: number of the sequence in the event reconstruction
* **IsCut** -- Bool_t: should this line be cut when calculating the start frequency...?

* **StartTimeInRunC** -- Double_t: start time of the track in the Katydid instance
* **StartTimeInAcq** -- Double_t: start time of the track within the chunk of data
* **EndTimeInRunC** -- Double_t: end time of the track in the Katydid instance
* **TimeLength** -- Double_t: track length
* **StartFrequency** -- Double_t: start frequency of the track
* **EndFrequency** -- Double_t: end frequency of the track
* **FrequencyWidth** -- Double_t: range of frequencies covered by the track
* **Slope** -- Double_t: slope of the track
* **Intercept** -- Double_t: intercept at t=0 of the track
* **TotalPower** -- Double_t: sum of the power of the bins composing the track

* **StartTimeInRunCSigma** -- Double_t: error on the start time of the track in the Katydid instance
* **EndTimeInRunCSigma** -- Double_t: error on the end time of the track in the Katydid instance
* **TimeLengthSigma** -- Double_t: error on the track length
* **StartFrequencySigma** -- Double_t: error on the track start frequency
* **EndFrequencySigma** -- Double_t: error on the track end frequency
* **FrequencyWidthSigma** -- Double_t: error on the range of frequencies covered by the track
* **SlopeSigma** -- Double_t: error on the slope track
* **InterceptSigma** -- Double_t: error on the track intercept
* **TotalPowerSigma** -- Double_t: error on the sum of the power of the bins composing the track

