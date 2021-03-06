/*
  ==============================================================================

    OfflineLoudnessScanItem.h
    Created: 12 Sep 2018 12:41:21pm
    Author:  Ken

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
struct TrackModel
{
	public:
		TrackModel()
		{
			reset();
		}

		// Input Parameters
		int rowNo = 0;
		File file;
		File destinationFolder;
		float dBLufsTarget = -14.0f;
		bool writeFile = false;
		AudioProcessor* limiterPlugin = nullptr;

		// Output Results
		float preIntegratedLufs = 0;
		float prePeakDbfs = 0;
		float diffLufs = 0;
		float gain = 0;
		float postPeakDbfs = 0;
		float postIntegratedLufs = 0;
		float postShortTermLoudness = 0;
		float postMaximumShortTermLoudness = 0;
		float postMomentaryLoudness = 0;
		float postMaximumMomentaryLoudness = 0;
		float postLoudnessRangeStart = 0;
		float postLoudnessRangeEnd = 0;
		float postLoudnessRange = 0;

		void reset()
		{
			preIntegratedLufs = 0;
			prePeakDbfs = 0;
			diffLufs = 0;
			gain = 0;
			postPeakDbfs = 0;
			postIntegratedLufs = 0;
			postShortTermLoudness = 0;
			postMaximumShortTermLoudness = 0;
			postMomentaryLoudness = 0;
			postMaximumMomentaryLoudness = 0;
			postLoudnessRangeStart = 0;
			postLoudnessRangeEnd = 0;
			postLoudnessRange = 0;
		}

};