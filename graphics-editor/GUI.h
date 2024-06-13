///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/clrpicker.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GUI
///////////////////////////////////////////////////////////////////////////////
class GUI : public wxFrame
{
	private:

	protected:
		wxPanel* m_panel1;
		wxButton* loadButton;
		wxButton* saveButton;
		wxStaticLine* m_staticline1;
		wxStaticText* colourLabel;
		wxColourPickerCtrl* colourPicker;
		wxStaticLine* m_staticline2;
		wxButton* lineButton;
		wxButton* bezierButton;
		wxButton* circleButton;
		wxButton* rectButton;
		wxButton* polygonButton;
		wxButton* inscPolyButton;

		// Virtual event handlers, override them in your derived class
		virtual void onResize( wxSizeEvent& event ) { event.Skip(); }
		virtual void onPanelClick( wxMouseEvent& event ) { event.Skip(); }
		virtual void onFileLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFileSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void onColourPickerChange( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void onLineClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onBezierClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCircleClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onRectClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPolygonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onInscPolyClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		GUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1000,700 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~GUI();

};

