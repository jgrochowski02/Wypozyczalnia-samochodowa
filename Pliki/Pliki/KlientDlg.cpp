#include "KlientDlg.h"
#include "fileAdapter.h"

//(*InternalHeaders(KlientDlg)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(KlientDlg)
const long KlientDlg::ID_TEXTCTRL1 = wxNewId();
const long KlientDlg::ID_TEXTCTRL2 = wxNewId();
const long KlientDlg::ID_BUTTON1 = wxNewId();
const long KlientDlg::ID_BUTTON2 = wxNewId();
const long KlientDlg::ID_STATICTEXT1 = wxNewId();
const long KlientDlg::ID_STATICTEXT2 = wxNewId();
const long KlientDlg::ID_STATICTEXT3 = wxNewId();
const long KlientDlg::ID_CHECKBOX1 = wxNewId();
const long KlientDlg::ID_TEXTCTRL3 = wxNewId();
const long KlientDlg::ID_STATICTEXT4 = wxNewId();
const long KlientDlg::ID_TEXTCTRL4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(KlientDlg,wxDialog)
	//(*EventTable(KlientDlg)
	//*)
END_EVENT_TABLE()

KlientDlg::KlientDlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(KlientDlg)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(947,443));
	Move(wxDefaultPosition);
	ImieRamka = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(144,80), wxSize(224,48), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	ImieRamka->SetMaxLength(30);
	wxFont ImieRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	ImieRamka->SetFont(ImieRamkaFont);
	NazwiskoRamka = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(632,80), wxSize(224,48), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	NazwiskoRamka->SetMaxLength(50);
	wxFont NazwiskoRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	NazwiskoRamka->SetFont(NazwiskoRamkaFont);
	OK = new wxButton(this, ID_BUTTON1, _("OK"), wxPoint(296,376), wxSize(120,48), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	wxFont OKFont(16,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	OK->SetFont(OKFont);
	ANULUJ = new wxButton(this, ID_BUTTON2, _("ANULUJ"), wxPoint(464,376), wxSize(120,48), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	wxFont ANULUJFont(16,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	ANULUJ->SetFont(ANULUJFont);
	Imie = new wxStaticText(this, ID_STATICTEXT1, _("Imie"), wxPoint(24,80), wxSize(72,32), 0, _T("ID_STATICTEXT1"));
	wxFont ImieFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Imie->SetFont(ImieFont);
	Nazwisko = new wxStaticText(this, ID_STATICTEXT2, _("Nazwisko"), wxPoint(448,80), wxSize(72,32), 0, _T("ID_STATICTEXT2"));
	wxFont NazwiskoFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Nazwisko->SetFont(NazwiskoFont);
	PESEL = new wxStaticText(this, ID_STATICTEXT3, _("PESEL"), wxPoint(24,160), wxSize(72,32), 0, _T("ID_STATICTEXT3"));
	wxFont PESELFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	PESEL->SetFont(PESELFont);
	PelnoletnoscRamka = new wxCheckBox(this, ID_CHECKBOX1, _("Pelnoletnosc"), wxPoint(24,240), wxSize(216,32), 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	PelnoletnoscRamka->SetValue(false);
	wxFont PelnoletnoscRamkaFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	PelnoletnoscRamka->SetFont(PelnoletnoscRamkaFont);
	PESELRamka = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(144,160), wxSize(224,48), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	PESELRamka->SetMaxLength(12);
	wxFont PESELRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	PESELRamka->SetFont(PESELRamkaFont);
	NrTel = new wxStaticText(this, ID_STATICTEXT4, _("Nr tel"), wxPoint(448,160), wxSize(72,32), 0, _T("ID_STATICTEXT4"));
	wxFont NrTelFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	NrTel->SetFont(NrTelFont);
	NrTelRamka = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(632,160), wxSize(224,48), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	wxFont NrTelRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	NrTelRamka->SetFont(NrTelRamkaFont);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KlientDlg::OnOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KlientDlg::OnANULUJClick);
	//*)
}

KlientDlg::~KlientDlg()
{
	//(*Destroy(KlientDlg)
	//*)
}


void KlientDlg::OnOKClick(wxCommandEvent& event)
{
        long int t, p;
    wxString imie, nazwisko, telefon, PESEL;
        imie=ImieRamka->GetValue();
        nazwisko=NazwiskoRamka->GetValue();
        telefon=NrTelRamka->GetValue();
        PESEL=PESELRamka->GetValue();
            PESEL.ToLong(&p);
            telefon.ToLong(&t);

    FileAdapter clients("client.txt");
    std::string name=imie.ToStdString();
    std::string lastname=nazwisko.ToStdString();
    std::string phone=telefon.ToStdString();
    std::string pesel=PESEL.ToStdString();

    if(PelnoletnoscRamka->IsChecked())
        {
    clients.writeRecord(name+" "+lastname+" "+phone+"  "+pesel);
        }
    EndModal(0);
}

void KlientDlg::OnANULUJClick(wxCommandEvent& event)
{
    Close();
}
