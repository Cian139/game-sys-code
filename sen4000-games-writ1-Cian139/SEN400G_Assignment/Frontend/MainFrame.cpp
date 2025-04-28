#include "MainFrame.h"

// Backend includes here. 


#include <wx/wx.h>

BEGIN_EVENT_TABLE (MainFrame, wxFrame)
	EVT_MENU(MENU_Quit, MainFrame::OnExit)
	EVT_MENU(MENU_Open, MainFrame::OpenFile)
	EVT_MENU(MENU_Close, MainFrame::CloseFile)
END_EVENT_TABLE() 

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) 
: wxFrame((wxFrame *) NULL, -1, title, pos, size) 
{
	CreateStatusBar(); 

	mainMenu = new wxMenuBar(); // Creates the menu bar
	wxMenu *fileMenu = new wxMenu(); // Creates the menu

	fileMenu->Append(MENU_Open, wxT("&Open"), wxT("Open an existing file"));
	fileMenu->Append(MENU_Close, wxT("&Close"), wxT("Close the current file"));
	fileMenu->Append(MENU_Quit, wxT("&Quit"), wxT("Quit the editor"));

	mainMenu->Append(fileMenu, wxT("&File")); // Adds the fileMenu to the menu bar
	SetMenuBar(mainMenu); // Adds the menu bar to the frame


	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_textCtrl1, 0, wxALL|wxEXPAND, 5 );

	m_listCtrl1 = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT );

	// Add first column       
	wxListItem col0;
	col0.SetId(0);
	col0.SetText( _("Name") );
	col0.SetWidth(50);
	m_listCtrl1->InsertColumn(0, col0);
	
	// Add second column
	wxListItem col1;
	col1.SetId(1);
	col1.SetText( _("Value") );
	m_listCtrl1->InsertColumn(1, col1);


	bSizer1->Add( m_listCtrl1, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	//Create file manager


	blank();
}

void MainFrame::blank()
{
	// Clear the box text

	m_textCtrl1->Clear();

	m_listCtrl1->DeleteAllItems();

	// Clear the current document path
	currentDocPath = wxEmptyString;
	// Set the title to "Edit - Untitled"
	SetTitle(wxT("No document"));
}

void MainFrame::OpenFile(wxCommandEvent& WXUNUSED(event))
{
	wxFileDialog *openDialog = new wxFileDialog(this, 
				wxT("Choose a file to open"), 
				wxEmptyString, wxEmptyString, 
				wxT("Ogre cfg Files (*.cfg)|*.cfg"),
				wxFD_OPEN, wxDefaultPosition);

	if(openDialog->ShowModal() == wxID_OK)
	{
		currentDocPath = openDialog->GetPath();

		std::string filepath = openDialog->GetFilename().ToStdString();
		std::string fileDirectory = openDialog->GetDirectory().ToStdString();


		SetTitle(wxString("Edit - ") << openDialog->GetFilename());
	}

	openDialog->Destroy();
}

void MainFrame::CloseFile(wxCommandEvent& WXUNUSED(event))
{
	blank();
}

void MainFrame::OnExit(wxCommandEvent& event)
{


	Close(TRUE); // This tells the OS to quit running this process
}