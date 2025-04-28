#include "MainApp.h"
#include "MainFrame.h"

IMPLEMENT_APP(MainApp)  

bool MainApp::OnInit() 
{

	MainFrame *MainWin = new MainFrame(_("XXX File Reading Application"), wxDefaultPosition, wxSize(300, 200));
	MainWin->Show(true); // Show the window 
	SetTopWindow(MainWin); // Set it as the main window 
	return true;
} 