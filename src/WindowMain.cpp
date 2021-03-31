#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif // WX_PRECOMP

class Summon: public wxApp {
public:
    virtual bool OnInit();
};

class MainWindow: public wxFrame {
public:
    MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

enum {
    ID_HELLO = 1
};

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_MENU(ID_HELLO,  MainWindow::OnHello)
    EVT_MENU(wxID_EXIT, MainWindow::OnExit)
    EVT_MENU(wxID_ABOUT, MainWindow::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(Summon);

bool Summon::OnInit() {
    MainWindow *frame = new MainWindow("Summon", wxPoint(50, 50), wxSize(1000, 800));
    frame->Show(true);
    return true;
}

MainWindow::MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size)
           : wxFrame(NULL, wxID_ANY, title, pos, size) {
    wxMenu *menuFile = new wxMenu;
    menuFile -> Append(ID_HELLO, "&TEST...\tCtrl-H", "String shown in status bar?");
    menuFile -> AppendSeparator();
    menuFile -> Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp -> Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar -> Append(menuFile, "&File");
    menuBar -> Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Summon - Open Source Hashing Tool");
}

void MainWindow::OnExit(wxCommandEvent& event) {
    Close(true);
}

void MainWindow::OnAbout(wxCommandEvent& event) {
    wxMessageBox("Summon - Open Source Hashing Tool","Summon", wxOK | wxICON_INFORMATION);
}

void MainWindow::OnHello(wxCommandEvent& event) {
    wxLogMessage("Just a test");
}
