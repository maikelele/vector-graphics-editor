#include "VGE_GUI.h"
#include "GlobalStorage.h"

VGE_GUI::VGE_GUI( wxWindow* parent )
:
GUI( parent )
{
	store = std::make_shared<GlobalStorage>();
	//store->objectStore.push_back("gui");
}

void VGE_GUI::onFileLoad( wxCommandEvent& event )
{
// TODO: Implement onFileLoad
	//wxLogMessage(wxString(store->objectStore[0]));
}

void VGE_GUI::onFileSave( wxCommandEvent& event )
{
	//Repaint();
}

void VGE_GUI::onColourPickerChange( wxColourPickerEvent& event )
{
// TODO: Implement onColourPickerChange
}

void VGE_GUI::onLineClick( wxCommandEvent& event )
{
// TODO: Implement onLineClick
}

void VGE_GUI::onBezierClick( wxCommandEvent& event )
{
// TODO: Implement onBezierClick
}

void VGE_GUI::onCircleClick( wxCommandEvent& event )
{
// TODO: Implement onCircleClick
}

void VGE_GUI::onRectClick( wxCommandEvent& event )
{
// TODO: Implement onRectClick
}

void VGE_GUI::onPolygonClick( wxCommandEvent& event )
{
// TODO: Implement onPolygonClick
}

void VGE_GUI::onInscPolyClick( wxCommandEvent& event )
{
// TODO: Implement onInscPolyClick
}

void VGE_GUI::Repaint() {
	wxClientDC _dc(m_panel1);
	wxBufferedDC dc(&_dc);
	wxPoint(1, 4);

	Panel panel = Panel(store);
	panel.Draw(&dc);
}