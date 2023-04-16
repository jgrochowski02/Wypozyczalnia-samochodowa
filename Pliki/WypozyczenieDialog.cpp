#include "WypozyczenieDialog.h"
#include "SamochodDialog.h"
#include "KlientDialog.h"
#include <wx/datetime.h>
#include <sstream>
#include <vector>
#include "fileAdapter.h"
#include <wx/utils.h>
//(*InternalHeaders(WypozyczenieDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(WypozyczenieDialog)
const long WypozyczenieDialog::ID_TEXTCTRL3 = wxNewId();
const long WypozyczenieDialog::ID_TEXTCTRL4 = wxNewId();
const long WypozyczenieDialog::ID_BUTTON1 = wxNewId();
const long WypozyczenieDialog::ID_STATICTEXT1 = wxNewId();
const long WypozyczenieDialog::ID_STATICTEXT2 = wxNewId();
const long WypozyczenieDialog::ID_STATICTEXT3 = wxNewId();
const long WypozyczenieDialog::ID_TEXTCTRL5 = wxNewId();
const long WypozyczenieDialog::ID_BUTTON2 = wxNewId();
const long WypozyczenieDialog::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(WypozyczenieDialog,wxDialog)
	//(*EventTable(WypozyczenieDialog)
	//*)
END_EVENT_TABLE()

WypozyczenieDialog::WypozyczenieDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(WypozyczenieDialog)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(947,443));
	IDSamochoduRamka = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(160,392), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	IDSamochoduRamka->SetMaxLength(100);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(616,392), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	TextCtrl1->SetMaxLength(1000);
	OK = new wxButton(this, ID_BUTTON1, _("OK"), wxPoint(800,376), wxSize(120,48), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	wxFont OKFont(16,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	OK->SetFont(OKFont);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Podaj ID samochodu"), wxPoint(160,360), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	IDKlientaRamka = new wxStaticText(this, ID_STATICTEXT2, _("Podaj ID klienta"), wxPoint(632,360), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Podaj ilosc dni"), wxPoint(408,360), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	DataWypoRamka = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(392,392), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	DataWypoRamka->SetMaxLength(1000);
	Button1 = new wxButton(this, ID_BUTTON2, _("Pokaz samochody"), wxPoint(160,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2 = new wxButton(this, ID_BUTTON3, _("Pokaz klientow"), wxPoint(616,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));

	Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&WypozyczenieDialog::OnTextCtrl4Text);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&WypozyczenieDialog::OnOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&WypozyczenieDialog::OnButton1Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&WypozyczenieDialog::OnklienciText);
	//*)
}

WypozyczenieDialog::~WypozyczenieDialog()
{
	//(*Destroy(WypozyczenieDialog)
	//*)
}


void WypozyczenieDialog::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void WypozyczenieDialog::OnTextCtrl4Text(wxCommandEvent& event)
{
}

void WypozyczenieDialog::OnOKClick(wxCommandEvent& event)
{
    FileAdapter order("order.txt");
    wxString IDklient, IDsamochod, DataWypo, date;
    IDklient=TextCtrl1->GetValue();
    IDsamochod=IDSamochoduRamka->GetValue();
    DataWypo=DataWypoRamka->GetValue();

     std::string KLIENT=IDklient.ToStdString();
      std::string SAMOCHOD=IDsamochod.ToStdString();
       std::string DATAW=DataWypo.ToStdString();

    date=wxNow();
       std::string data=date.ToStdString();

    order.writeRecord(KLIENT+" "+SAMOCHOD+ " "+DATAW+" "+data);

    EndModal(0);
}

void WypozyczenieDialog::OnklienciText(wxCommandEvent& event)
{
        FileAdapter clients("client.txt");
   wxTextCtrl  * klienci = new wxTextCtrl (this, 0, wxEmptyString, wxPoint(570,70), wxSize(344,250), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));

    std::vector<std::string> client_data = clients.readAllRecords();
    wxString result;
    for (int i = 0; i < client_data.size(); ++i) {
        wxString mystring(client_data[i].c_str(), wxConvUTF8);
        result+=(mystring+"\n");
    }
    klienci->SetValue(result);
}

void WypozyczenieDialog::OnButton1Click(wxCommandEvent& event)
{
    FileAdapter car("car.txt");
   wxTextCtrl  * samochody = new wxTextCtrl (this, 0, wxEmptyString, wxPoint(30,70), wxSize(450,250), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));

    std::vector<std::string> car_data = car.readAllRecords();
    wxString result;
    for (int i = 0; i < car_data.size(); ++i) {
        wxString mystring(car_data[i].c_str(), wxConvUTF8);
        result+=(mystring+"\n");
    }
    samochody->SetValue(result);
}


