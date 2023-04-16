#include "Koszty.h"
#include "fileAdapter.h"
#include <sstream>
//(*InternalHeaders(Koszty)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(Koszty)
const long Koszty::ID_STATICBITMAP1 = wxNewId();
const long Koszty::ID_TEXTCTRL1 = wxNewId();
const long Koszty::ID_STATICTEXT1 = wxNewId();
const long Koszty::ID_STATICTEXT2 = wxNewId();
const long Koszty::ID_SPINCTRL1 = wxNewId();
const long Koszty::ID_CHECKBOX1 = wxNewId();
const long Koszty::ID_STATICTEXT3 = wxNewId();
const long Koszty::ID_BUTTON1 = wxNewId();
const long Koszty::ID_BUTTON2 = wxNewId();
const long Koszty::ID_STATICTEXT4 = wxNewId();
const long Koszty::ID_STATICTEXT5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Koszty,wxDialog)
	//(*EventTable(Koszty)
	//*)
END_EVENT_TABLE()

Koszty::Koszty(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Koszty)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(947,443));
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
	StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("C:\\Users\\48662\\OneDrive\\Pulpit\\ObslugaWypo\\ObrazekKoszty.png")).Rescale(wxSize(455,368).GetWidth(),wxSize(455,368).GetHeight())), wxPoint(496,0), wxSize(455,368), 0, _T("ID_STATICBITMAP1"));
	IDSamochoduRamka = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(240,80), wxSize(104,40), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	IDSamochoduRamka->SetMaxLength(1000);
	wxFont IDSamochoduRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	IDSamochoduRamka->SetFont(IDSamochoduRamkaFont);
	Markaw = new wxStaticText(this, ID_STATICTEXT1, _("ID samochodu"), wxPoint(24,80), wxSize(72,32), 0, _T("ID_STATICTEXT1"));
	wxFont MarkawFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Markaw->SetFont(MarkawFont);
	IlsocDob = new wxStaticText(this, ID_STATICTEXT2, _("Ilosc dob"), wxPoint(24,168), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont IlsocDobFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	IlsocDob->SetFont(IlsocDobFont);
	IloscDniRamka = new wxSpinCtrl(this, ID_SPINCTRL1, _T("1"), wxPoint(192,168), wxSize(82,40), 0, 1, 30, 1, _T("ID_SPINCTRL1"));
	IloscDniRamka->SetValue(_T("1"));
	wxFont IloscDniRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	IloscDniRamka->SetFont(IloscDniRamkaFont);
	KaucjaRamka = new wxCheckBox(this, ID_CHECKBOX1, _("Wynajem z kaucja"), wxPoint(24,256), wxSize(272,40), 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	KaucjaRamka->SetValue(false);
	wxFont KaucjaRamkaFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	KaucjaRamka->SetFont(KaucjaRamkaFont);
	KalkulacjaKosztow = new wxStaticText(this, ID_STATICTEXT3, _("Kalkulcja kosztow"), wxPoint(272,8), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont KalkulacjaKosztowFont(26,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_NORMAL,false,_T("Arial Narrow"),wxFONTENCODING_DEFAULT);
	KalkulacjaKosztow->SetFont(KalkulacjaKosztowFont);
	Policz = new wxButton(this, ID_BUTTON1, _("OK"), wxPoint(296,376), wxSize(120,48), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	wxFont PoliczFont(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Policz->SetFont(PoliczFont);
	Button1 = new wxButton(this, ID_BUTTON2, _("ANULUJ"), wxPoint(464,376), wxSize(128,48), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	wxFont Button1Font(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Button1->SetFont(Button1Font);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT4, wxEmptyString, wxPoint(184,304), wxSize(512,64), 0, _T("ID_STATICTEXT4"));
	wxFont StaticText1Font(26,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT5, _("-10% ceny"), wxPoint(48,296), wxDefaultSize, 0, _T("ID_STATICTEXT5"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Koszty::OnPoliczClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Koszty::OnButton1Click);
	//*)
}

Koszty::~Koszty()
{
	//(*Destroy(Koszty)
	//*)
}


void Koszty::OnPoliczClick(wxCommandEvent& event)
{
    FileAdapter car("car.txt");

    double IDSamochodu, IloscDni, koszt;
    wxString tmp, result, wynik;
    std::string samochod;

    IloscDni=IloscDniRamka->GetValue();

    tmp= IDSamochoduRamka->GetValue();
    tmp.ToDouble(&IDSamochodu);
    samochod = car.readRecord((int) IDSamochodu);
    istringstream iss(samochod);
    iss >> koszt >> koszt;
    if(KaucjaRamka->IsChecked())
        wynik<<IloscDni*koszt*0.9;
    else
        wynik<<IloscDni*koszt;

    StaticText1->SetLabel("Do zaplaty: "+wynik+"PLN");
}

void Koszty::OnButton1Click(wxCommandEvent& event)
{
    Close();
}
