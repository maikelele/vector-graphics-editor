///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

GUI::GUI( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );

	bSizer2->Add( m_panel1, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	loadButton = new wxButton( this, wxID_ANY, wxT("Wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( loadButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	saveButton = new wxButton( this, wxID_ANY, wxT("Zapisz"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( saveButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline1, 0, wxEXPAND|wxALL, 5 );

	colourLabel = new wxStaticText( this, wxID_ANY, wxT("Kolor linii:"), wxDefaultPosition, wxDefaultSize, 0 );
	colourLabel->Wrap( -1 );
	bSizer3->Add( colourLabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	colourPicker = new wxColourPickerCtrl( this, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer3->Add( colourPicker, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline2, 0, wxEXPAND|wxALL, 5 );

	lineButton = new wxButton( this, wxID_ANY, wxT("Linia"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( lineButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	bezierButton = new wxButton( this, wxID_ANY, wxT("Krzywa Beziera"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( bezierButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	circleButton = new wxButton( this, wxID_ANY, wxT("Okrag"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( circleButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	rectButton = new wxButton( this, wxID_ANY, wxT("Prostokat"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( rectButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	polygonButton = new wxButton( this, wxID_ANY, wxT("Wielokat"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( polygonButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	inscPolyButton = new wxButton( this, wxID_ANY, wxT("Wielokat wpisany"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( inscPolyButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_panel1->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GUI::onPanelClick ), NULL, this );
	loadButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI::onFileLoad ), NULL, this );
	saveButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI::onFileSave ), NULL, this );
	colourPicker->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( GUI::onColourPickerChange ), NULL, this );
	lineButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI::onLineClick ), NULL, this );
	bezierButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI::onBezierClick ), NULL, this );
	circleButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI::onCircleClick ), NULL, this );
	rectButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI::onRectClick ), NULL, this );
	polygonButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI::onPolygonClick ), NULL, this );
	inscPolyButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI::onInscPolyClick ), NULL, this );
}

GUI::~GUI()
{
	// Disconnect Events
	m_panel1->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GUI::onPanelClick ), NULL, this );
	loadButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI::onFileLoad ), NULL, this );
	saveButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI::onFileSave ), NULL, this );
	colourPicker->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( GUI::onColourPickerChange ), NULL, this );
	lineButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI::onLineClick ), NULL, this );
	bezierButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI::onBezierClick ), NULL, this );
	circleButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI::onCircleClick ), NULL, this );
	rectButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI::onRectClick ), NULL, this );
	polygonButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI::onPolygonClick ), NULL, this );
	inscPolyButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI::onInscPolyClick ), NULL, this );

}
