#include "VGE_GUI.h"

VGE_GUI::VGE_GUI(wxWindow* parent)
	:
	GUI(parent)
{
	store = std::make_shared<GlobalStorage>();
	simpleLine = SimpleLine(store);
	bezierCurve = BezierCurve(store);
	circle = Circle(store);
	rectangle = Rect(store);
	polygon = Poly(store);
	this->SetTitle("Vector graphics editor");
}

void VGE_GUI::onPanelClick(wxMouseEvent& event)
{
	if (!store->editMode) return;
	switch (store->editID) {
	case 0:
		simpleLine.handleClick(event);
		break;
	case 1:
		bezierCurve.handleClick(event);
		break;
	case 2:
		circle.handleClick(event);
		break;
	case 3:
		rectangle.handleClick(event);
		break;
	case 4:
		polygon.handleClick(event);
		break;
	default:
		wxLogMessage("we shouldn't be here");
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
	if (store->editMode) {
		if (store->editID == 1) {
			store->editMode = false;
			store->commitCurrentItem();
			bezierButton->SetBackgroundColour(wxNullColour);
			bezierButton->Refresh();
			Repaint();
		}
		return;
	}
	store->editMode = true;
	store->editID = 1;
	bezierButton->SetBackgroundColour(activeColor);
	bezierButton->Refresh();
}

void VGE_GUI::onCircleClick(wxCommandEvent& event)
{
	if (store->editMode) {
		if (store->editID == 2) {
			store->editMode = false;
			circleButton->SetBackgroundColour(wxNullColour);
			circleButton->Refresh();
		}
		return;
	}
	store->editMode = true;
	store->editID = 2;
	circleButton->SetBackgroundColour(activeColor);
	circleButton->Refresh();
}

void VGE_GUI::onRectClick(wxCommandEvent& event)
{
	if (store->editMode) {
		if (store->editID == 3) {
			store->editMode = false;
			rectButton->SetBackgroundColour(wxNullColour);
			rectButton->Refresh();
		}
		return;
	}
	store->editMode = true;
	store->editID = 3;

	rectButton->SetBackgroundColour(activeColor);
	rectButton->Refresh();
}

void VGE_GUI::onPolygonClick(wxCommandEvent& event)
{
	if (store->editMode) {
		if (store->editID == 4) {
			store->editMode = false;
			polygonButton->SetBackgroundColour(wxNullColour);
			polygonButton->Refresh();
		}
		return;
	}

	wxTextEntryDialog dialog(this, wxT("Wprowad� liczb� wierzcho�k�w wielok�ta:"),
		wxT("Polygon Sides"), wxT("4"));
	if (dialog.ShowModal() == wxID_OK) {
		wxString input = dialog.GetValue();
		long sides;
		if (input.ToLong(&sides) && sides > 2) {
			store->currentItem.vertexes_count = sides;
		}
		else {
			wxMessageBox("Prosz� wprowadzi� liczb� wi�ksz� od 2", "Invalid Input", wxOK | wxICON_ERROR);
			return;
		}
	}
	else {
		return;  // User cancelled the dialog
	}

	store->editMode = true;
	store->editID = 4;
	polygonButton->SetBackgroundColour(activeColor);
	polygonButton->Refresh();
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