#include <wx/wx.h>

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size) {
        wxPanel* panel = new wxPanel(this, wxID_ANY);
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        wxButton* loadBtn = new wxButton(panel, wxID_ANY, wxT("Wczytaj"));
        wxButton* saveBtn = new wxButton(panel, wxID_ANY, wxT("Zapisz"));
        sizer->Add(loadBtn, 0, wxALL, 5);
        sizer->Add(saveBtn, 0, wxALL, 5);

        panel->SetSizer(sizer);

        wxPanel* drawPane = new wxPanel(this, wxID_ANY);
        drawPane->SetBackgroundColour(*wxWHITE);

        wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
        mainSizer->Add(panel, 0, wxEXPAND);
        mainSizer->Add(drawPane, 1, wxEXPAND);
        SetSizer(mainSizer);

    }
};

class MyApp : public wxApp {
public:
    virtual bool OnInit() {
        MyFrame* frame = new MyFrame(wxT("Vector Graphics Editor"), wxDefaultPosition, wxSize(800, 600));
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
