#include "KlientDialog.h"

//(*InternalHeaders(KlientDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(KlientDialog)
const long KlientDialog::ID_TEXTCTRL1 = wxNewId();
const long KlientDialog::ID_TEXTCTRL2 = wxNewId();
const long KlientDialog::ID_SPINCTRL1 = wxNewId();
const long KlientDialog::ID_STATICTEXT1 = wxNewId();
const long KlientDialog::ID_STATICTEXT2 = wxNewId();
const long KlientDialog::ID_STATICTEXT3 = wxNewId();
const long KlientDialog::ID_STATICTEXT4 = wxNewId();
const long KlientDialog::ID_TEXTCTRL3 = wxNewId();
const long KlientDialog::ID_STATICTEXT5 = wxNewId();
const long KlientDialog::ID_TEXTCTRL4 = wxNewId();
const long KlientDialog::wxID_OKk = wxNewId();
const long KlientDialog::wxID_ANULUJk = wxNewId();
//*)

BEGIN_EVENT_TABLE(KlientDialog,wxDialog)
	//(*EventTable(KlientDialog)
	//*)
END_EVENT_TABLE()

KlientDialog::KlientDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(KlientDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(947,443));
	Move(wxDefaultPosition);
	Disable();
	ImieRamka = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(144,80), wxSize(224,48), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	ImieRamka->SetMaxLength(30);
	wxFont ImieRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	ImieRamka->SetFont(ImieRamkaFont);
	NazwiskoRamka = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(632,80), wxSize(224,48), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	NazwiskoRamka->SetMaxLength(40);
	wxFont NazwiskoRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	NazwiskoRamka->SetFont(NazwiskoRamkaFont);
	WiekRamka = new wxSpinCtrl(this, ID_SPINCTRL1, _T("18"), wxPoint(144,160), wxSize(98,48), 0, 18, 70, 18, _T("ID_SPINCTRL1"));
	WiekRamka->SetValue(_T("18"));
	WiekRamka->SetMaxSize(wxSize(0,0));
	wxFont WiekRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	WiekRamka->SetFont(WiekRamkaFont);
	Imie = new wxStaticText(this, ID_STATICTEXT1, _("Imie"), wxPoint(24,80), wxSize(72,32), 0, _T("ID_STATICTEXT1"));
	wxFont ImieFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Imie->SetFont(ImieFont);
	Nazwisko = new wxStaticText(this, ID_STATICTEXT2, _("Nazwisko"), wxPoint(448,80), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont NazwiskoFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Nazwisko->SetFont(NazwiskoFont);
	Wiek = new wxStaticText(this, ID_STATICTEXT3, _("Wiek"), wxPoint(24,160), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont WiekFont(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Wiek->SetFont(WiekFont);
	PESEL = new wxStaticText(this, ID_STATICTEXT4, _("PESEL"), wxPoint(24,240), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	wxFont PESELFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	PESEL->SetFont(PESELFont);
	PESELRamka = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(144,232), wxSize(224,48), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	PESELRamka->SetMaxLength(12);
	wxFont PESELRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	PESELRamka->SetFont(PESELRamkaFont);
	NrTel = new wxStaticText(this, ID_STATICTEXT5, _("NrTel"), wxPoint(448,160), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	wxFont NrTelFont(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	NrTel->SetFont(NrTelFont);
	NrTelRamka = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(632,160), wxSize(224,48), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	NrTelRamka->SetMaxLength(15);
	wxFont NrTelRamkaFont(20,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	NrTelRamka->SetFont(NrTelRamkaFont);
	OK = new wxButton(this, wxID_OKk, _("OK"), wxPoint(296,376), wxSize(120,48), 0, wxDefaultValidator, _T("wxID_OKk"));
	wxFont OKFont(16,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	OK->SetFont(OKFont);
	ANULUJ = new wxButton(this, wxID_ANULUJk, _("ANULUJ"), wxPoint(464,376), wxSize(120,48), 0, wxDefaultValidator, _T("wxID_ANULUJk"));
	wxFont ANULUJFont(16,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	ANULUJ->SetFont(ANULUJFont);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&KlientDialog::OnTextCtrl1Text);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&KlientDialog::OnTextCtrl2Text);
	Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&KlientDialog::OnSpinCtrl1Change);
	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&KlientDialog::OnTextCtrl3Text);
	Connect(wxID_OKk,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KlientDialog::OnOKClick);
	Connect(wxID_ANULUJk,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KlientDialog::OnANULUJClick);
	//*)
}

KlientDialog::~KlientDialog()
{
	//(*Destroy(KlientDialog)
	//*)
}


void KlientDialog::OnSpinCtrl1Change(wxSpinEvent& event)
{
}

void KlientDialog::OnTextCtrl3Text(wxCommandEvent& event)
{
}

void KlientDialog::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void KlientDialog::OnTextCtrl2Text(wxCommandEvent& event)
{
}

void KlientDialog::OnANULUJClick(wxCommandEvent& event)
{
}

void KlientDialog::OnOKClick(wxCommandEvent& event)
{
}

void KlientDialog::OnInit(wxInitDialogEvent& event)
{
}

void KlientDialog::OnPobranieKlientClick(wxCommandEvent& event)
{
    long int t, p;
    wxString imie, nazwisko, telefon, PESEL;
        imie=ImieRamka->GetValue();
        nazwisko=NazwiskoRamka->GetValue();
        int wiek=WiekRamka->GetValue();
        telefon=NrTelRamka->GetValue();
            telefon.ToLong(&t);
        PESEL=PESELRamka->GetValue();
            PESEL.ToLong(&p);

//    EndModal();
}
