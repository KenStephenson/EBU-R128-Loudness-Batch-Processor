/*
  ==============================================================================

    InputFileListBoxModel.h
    Created: 2 Sep 2018 4:02:34pm
    Author:  Ken

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../OfflineLoudnessProcessor/OfflineLoudnessScanDataPacket.h"


class ListBoxModelListener
{
	public:
		virtual void refreshFileTableModel(String tag) {};
};

class FileListBoxModel : public TableListBoxModel
{
	public:
		FileListBoxModel()
		{
			data.clear();
		}
		void setListener(ListBoxModelListener* l, String t)
		{
			listener = l; 
			tag = t;
		}
		int getNumRows() override
		{
			return data.size();
		}
		void paintRowBackground(Graphics& g, int rowNumber, int width, int height, bool rowIsSelected) override
		{
			g.fillAll(Colours::lightgrey);
		}
		void paintCell(Graphics& g, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override
		{
			Rectangle<int> r(width, height);
			OfflineLoudnessScanDataPacket* row = data[rowNumber];
			switch (columnId)
			{
			case 1:
				g.drawText(row->file.getFileName(), r, Justification::centredLeft);
				break;
			case 2:
				g.drawText(String(row->preIntegratedLufs, 2), r, Justification::centredRight);
				break;
			case 3:
				g.drawText(String(row->prePeakDbfs, 2), r, Justification::centredRight);
				break;
			case 4:
				g.drawText(String(row->diffLufs, 2), r, Justification::centredRight);
				break;
			case 5:
				g.drawText(String(row->gain, 2), r, Justification::centredRight);
				break;
			case 6:
				g.drawText(String(row->postIntegratedLufs, 2), r, Justification::centredRight);
				break;
			case 7:
				g.drawText(String(row->postPeakDbfs, 2), r, Justification::centredRight);
				break;
			default:
				break;
			}
		}
		void cellDoubleClicked(int rowNumber, int columnId, const MouseEvent &) override
		{
			if (columnId == 1)
			{
				data.remove(rowNumber);
				listener->refreshFileTableModel(tag);
			}
		}

		
		OwnedArray<OfflineLoudnessScanDataPacket> data;
		ListBoxModelListener* listener;
		String tag;
};