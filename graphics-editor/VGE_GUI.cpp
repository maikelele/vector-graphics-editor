#include "VGE_GUI.h"

VGE_GUI::VGE_GUI(wxWindow* parent)
	:
	GUI(parent)
{
	store = std::make_shared<GlobalStorage>();
	simpleLine = SimpleLine(store);
}

void VGE_GUI::onPanelClick(wxMouseEvent& event)
{
	if (!store->editMode) return;
	switch (store->editID) {
	case 0:
		simpleLine.handleClick(event);
		break;
	default:
		wxLogMessage("uhh?");
	}
	Repaint();
}

void VGE_GUI::onFileLoad(wxCommandEvent& event)
{
	// TODO: Implement onFileLoad
	//wxLogMessage(wxString(store->objectStore[0]));
}

void VGE_GUI::onFileSave(wxCommandEvent& event)
{
	//Repaint();
}

void VGE_GUI::onColourPickerChange(wxColourPickerEvent& event)
{
	store->currentColor = event.GetColour();
}

void VGE_GUI::onLineClick(wxCommandEvent& event)
{
	if (store->editMode) {
		if (store->editID == 0) {
			store->editMode = false;
			lineButton->SetBackgroundColour(wxNullColour);
			lineButton->Refresh();
		}
		return;
	}
	store->editMode = true;
	store->editID = 0;
	lineButton->SetBackgroundColour(activeColor);
	lineButton->Refresh();

}

void VGE_GUI::onBezierClick(wxCommandEvent& event)
{
	// TODO: Implement onBezierClick
}

void VGE_GUI::onCircleClick(wxCommandEvent& event)
{
	// TODO: Implement onCircleClick
}

void VGE_GUI::onRectClick(wxCommandEvent& event)
{
	// TODO: Implement onRectClick
}

void VGE_GUI::onPolygonClick(wxCommandEvent& event)
{
	// TODO: Implement onPolygonClick
}

void VGE_GUI::onInscPolyClick(wxCommandEvent& event)
{
	// TODO: Implement onInscPolyClick
}


void VGE_GUI::Repaint()
{
	wxClientDC _dc(m_panel1);
	wxBufferedDC dc(&_dc);

	Panel panel = Panel(store);
	panel.Draw(&dc);
}