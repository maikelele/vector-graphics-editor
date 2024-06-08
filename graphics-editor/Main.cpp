#include <wx/wx.h>
#include "VGE_GUI.h"

class MyApp : public wxApp {

public:

	virtual bool OnInit();
	virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	SetProcessDPIAware();
	wxFrame* mainFrame = new VGE_GUI(NULL);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}