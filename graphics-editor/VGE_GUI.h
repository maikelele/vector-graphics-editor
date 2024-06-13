#ifndef __VGE_GUI__
#define __VGE_GUI__

/**
@file
Subclass of GUI, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include

#include <wx/wx.h>
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/file.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <wx/tokenzr.h>
#include "memory"
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include "Panel.h"
#include "GlobalStorage.h"
#include "Item.h"
#include "SimpleLine.h"
#include "BezierCurve.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "InscribedPolygon.h"

/** Implementing GUI */
class VGE_GUI : public GUI
{
protected:
	// Handlers for GUI events.
	void onResize(wxSizeEvent& event);
	void onPanelClick(wxMouseEvent& event);
	void onFileLoad(wxCommandEvent& event);
	void onFileSave(wxCommandEvent& event);
	void onColourPickerChange(wxColourPickerEvent& event);
	void onLineClick(wxCommandEvent& event);
	void onBezierClick(wxCommandEvent& event);
	void onCircleClick(wxCommandEvent& event);
	void onRectClick(wxCommandEvent& event);
	void onPolygonClick(wxCommandEvent& event);
	void onInscPolyClick(wxCommandEvent& event);
public:
	/** Constructor */
	VGE_GUI(wxWindow* parent);
	//// end generated class members
	std::shared_ptr<GlobalStorage> store;
	void Repaint();
	SimpleLine simpleLine;
	BezierCurve bezierCurve;
	Circle circle;
	Rect rectangle;
	Poly polygon;
	InscribedPolygon inscrPoly;
	wxColor activeColor = wxColor(RGB(105, 211, 235));




};

#endif // __VGE_GUI__
