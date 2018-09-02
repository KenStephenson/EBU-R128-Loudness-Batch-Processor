/*
  ==============================================================================

    InputFileListBoxModel.h
    Created: 2 Sep 2018 4:02:34pm
    Author:  Ken

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class InputFileListBoxModel : public ListBoxModel
{
	public:
		InputFileListBoxModel()
		{
			data.clear();
		}
		int getNumRows() override
		{
			return data.size();
		}
		void paintListBoxItem(int rowNumber, Graphics &g, int width, int height, bool rowIsSelected) override
		{
			Rectangle<int> r(width, height);
			File f = data[rowNumber];
			g.drawText(f.getFileName(), r, Justification::centredLeft);
		}

		void listBoxItemClicked(int row, const MouseEvent &) override
		{
		}

		Array<File> data;
};