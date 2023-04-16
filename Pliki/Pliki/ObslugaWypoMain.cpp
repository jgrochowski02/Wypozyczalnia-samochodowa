/***************************************************************
 * Name:      ObslugaWypoMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    my ()
 * Created:   2022-12-06
 * Copyright: my ()
 * License:
 **************************************************************/

#include "ObslugaWypoMain.h"
#include <wx/msgdlg.h>
#include <wx/menu.h>
#include <wx/mousestate.h>
#include <wx/event.h>
#include "KlientDialog.h"
#include "SamochodDialog.h"
#include "WypozyczenieDialog.h"
#include "Koszty.h"
#include "KlientDlg.h"
#include "WypozyczeniaWidok.h"
#include <wx/statbmp.h>
#include <wx/bitmap.h>
#include "fileAdapter.h"

//(*InternalHeaders(ObslugaWypoFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ObslugaWypoFrame)
const long ObslugaWypoFrame::ID_STATICTEXT1 = wxNewId();
const long ObslugaWypoFrame::ID_BUTTON1 = wxNewId();
const long ObslugaWypoFrame::ID_BUTTON2 = wxNewId();
const long ObslugaWypoFrame::ID_BUTTON3 = wxNewId();
const long ObslugaWypoFrame::idMenuQuit = wxNewId();
const long ObslugaWypoFrame::idMenuAbout = wxNewId();
const long ObslugaWypoFrame::ID_STATUSBAR1 = wxNewId();
const long ObslugaWypoFrame::ID_DodajKlienta = wxNewId();
const long ObslugaWypoFrame::ID_PokazKlientow = wxNewId();
const long ObslugaWypoFrame::ID_DodajSamochod = wxNewId();
const long ObslugaWypoFrame::ID_PokazSamochody = wxNewId();
const long ObslugaWypoFrame::ID_PokazWypozyczone = wxNewId();
const long ObslugaWypoFrame::ID_Kalkulacja = wxNewId();
const long ObslugaWypoFrame::ID_Wypozycz = wxNewId();
//*)

BEGIN_EVENT_TABLE(ObslugaWypoFrame,wxFrame)
    //(*EventTable(ObslugaWypoFrame)
    //*)
END_EVENT_TABLE()

ObslugaWypoFrame::ObslugaWypoFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ObslugaWypoFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(947,496));
    Move(wxPoint(200,200));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DDKSHADOW));
    StaticBitmap1 = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxImage(_T("C:\\Users\\48662\\OneDrive\\Pulpit\\ObslugaWypo\\LamboGreen.png")).Rescale(wxSize(504,200).GetWidth(),wxSize(504,200).GetHeight())), wxPoint(224,240), wxSize(504,200), 0, _T("wxID_ANY"));
    StaticBitmap1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DDKSHADOW));
    WYPOZYCZALNIA = new wxStaticText(this, ID_STATICTEXT1, _("WYPOZYCZALNIA SAMOCHODOW"), wxPoint(128,40), wxSize(248,72), 0, _T("ID_STATICTEXT1"));
    WYPOZYCZALNIA->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
    wxFont WYPOZYCZALNIAFont(26,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    WYPOZYCZALNIA->SetFont(WYPOZYCZALNIAFont);
    Klient = new wxButton(this, ID_BUTTON1, _("Klient"), wxPoint(80,130), wxSize(240,100), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Klient->SetMaxSize(wxDLG_UNIT(this,wxSize(-1,-1)));
    wxFont KlientFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Klient->SetFont(KlientFont);
    Samochod = new wxButton(this, ID_BUTTON2, _("Samochod"), wxPoint(368,130), wxSize(240,100), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    wxFont SamochodFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Samochod->SetFont(SamochodFont);
    Button3 = new wxButton(this, ID_BUTTON3, _("Wypozyczenie"), wxPoint(648,130), wxSize(240,100), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    wxFont Button3Font(20,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button3->SetFont(Button3Font);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    MenuItem3 = new wxMenuItem((&MenuKlient), ID_DodajKlienta, _("Dodaj klienta"), wxEmptyString, wxITEM_NORMAL);
    MenuKlient.Append(MenuItem3);
    MenuItem4 = new wxMenuItem((&MenuKlient), ID_PokazKlientow, _("Pokaz klientow"), wxEmptyString, wxITEM_NORMAL);
    MenuKlient.Append(MenuItem4);
    MenuItem6 = new wxMenuItem((&MenuSamochod), ID_DodajSamochod, _("Dodaj samochod"), wxEmptyString, wxITEM_NORMAL);
    MenuSamochod.Append(MenuItem6);
    MenuItem7 = new wxMenuItem((&MenuSamochod), ID_PokazSamochody, _("Pokaz samochody"), wxEmptyString, wxITEM_NORMAL);
    MenuSamochod.Append(MenuItem7);
    MenuItem8 = new wxMenuItem((&MenuWypozyczenie), ID_PokazWypozyczone, _("Pokaz wypozyczone"), wxEmptyString, wxITEM_NORMAL);
    MenuWypozyczenie.Append(MenuItem8);
    MenuItem10 = new wxMenuItem((&MenuWypozyczenie), ID_Kalkulacja, _("Kalkulacja kosztow"), wxEmptyString, wxITEM_NORMAL);
    MenuWypozyczenie.Append(MenuItem10);
    MenuItem9 = new wxMenuItem((&MenuWypozyczenie), ID_Wypozycz, _("Wypozycz"), wxEmptyString, wxITEM_NORMAL);
    MenuWypozyczenie.Append(MenuItem9);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ObslugaWypoFrame::OnMenuKlientClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ObslugaWypoFrame::OnSamochodMenuClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ObslugaWypoFrame::OnButton3Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ObslugaWypoFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ObslugaWypoFrame::OnAbout);
    //*)
    Connect(ID_DodajKlienta, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&ObslugaWypoFrame::OnKlientClick);
    Connect(ID_PokazKlientow, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&ObslugaWypoFrame::OnPokazKlientowClick);
    Connect(ID_Kalkulacja, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&ObslugaWypoFrame::OnKosztyClick);
    Connect(ID_DodajSamochod, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&ObslugaWypoFrame::OnSamochodClick);
    Connect(ID_PokazSamochody, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&ObslugaWypoFrame::OnPokazSamochodyClick);

    Connect(ID_PokazWypozyczone, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&ObslugaWypoFrame::OnPokaWypoClick);
    Connect(ID_Wypozycz, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&ObslugaWypoFrame::OnWypozyczClick);
}

ObslugaWypoFrame::~ObslugaWypoFrame()
{
    //(*Destroy(ObslugaWypoFrame)
    //*)
}

void ObslugaWypoFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void ObslugaWypoFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void ObslugaWypoFrame::OnButton3Click(wxCommandEvent& event)
{
    PopupMenu(&MenuWypozyczenie);
}


void ObslugaWypoFrame::OnKlientClick(wxCommandEvent& event)
{
     KlientDlg *kdlg= new KlientDlg(this, wxID_ANY);
    if(kdlg->ShowModal()==wxID_OK){}
    kdlg->Destroy();

}

void ObslugaWypoFrame::OnSamochodClick(wxCommandEvent& event)
{
     SamochodDialog *sdlg= new SamochodDialog(this, wxID_ANY);
    if(sdlg->ShowModal()==wxID_OK)
    {
    }
    sdlg->Destroy();
}

void ObslugaWypoFrame::OnMenuKlientClick(wxCommandEvent& event)
{
    PopupMenu(&MenuKlient);
}

void ObslugaWypoFrame::OnSamochodMenuClick(wxCommandEvent& event)
{
    PopupMenu(&MenuSamochod);
}

void ObslugaWypoFrame::OnKosztyClick(wxCommandEvent& event)
{
    Koszty *ksdlg= new Koszty(this, wxID_ANY);
    if(ksdlg->ShowModal()==wxID_OK){}
    ksdlg->Destroy();
}

void ObslugaWypoFrame::OnPokaWypoClick(wxCommandEvent& event)
{
     WypozyczeniaWidok *wwdlg= new WypozyczeniaWidok(this, wxID_ANY);
    if(wwdlg->ShowModal()==wxID_OK){}
    wwdlg->Destroy();
}
void ObslugaWypoFrame::OnWypozyczClick(wxCommandEvent& event)
{
     WypozyczenieDialog *wddlg= new WypozyczenieDialog(this, wxID_ANY);
    if(wddlg->ShowModal()==wxID_OK){}
    wddlg->Destroy();
}

void ObslugaWypoFrame::OnPokazKlientowClick(wxCommandEvent& event)
{
    FileAdapter clients("client.txt");

    std::vector<std::string> client_data = clients.readAllRecords();
    wxString result;
    for (int i = 0; i < client_data.size(); ++i) {
        wxString mystring(client_data[i].c_str(), wxConvUTF8);
        result+=(mystring+"\n");
    }
        wxMessageBox(result,"Klienci",wxCENTRE);
}
void ObslugaWypoFrame::OnPokazSamochodyClick(wxCommandEvent& event)
{
    FileAdapter clients("car.txt");

    std::vector<std::string> car = clients.readAllRecords();
    wxString result;
    for (int i = 0; i < car.size(); ++i) {
        wxString mystring(car[i].c_str(), wxConvUTF8);
        result+=(mystring+"\n");
    }
   wxMessageBox(result,"Samochody",wxCENTRE);
}
