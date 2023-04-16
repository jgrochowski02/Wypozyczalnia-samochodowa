#include "SamochodDialog.h"
#include "fileAdapter.h"
//(*InternalHeaders(SamochodDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(SamochodDialog)
const long SamochodDialog::ID_TEXTCTRL1 = wxNewId();
const long SamochodDialog::ID_TEXTCTRL2 = wxNewId();
const long SamochodDialog::ID_STATICTEXT1 = wxNewId();
const long SamochodDialog::ID_STATICTEXT2 = wxNewId();
const long SamochodDialog::ID_STATICTEXT3 = wxNewId();
const long SamochodDialog::ID_TEXTCTRL3 = wxNewId();
const long SamochodDialog::ID_STATICTEXT4 = wxNewId();
const long SamochodDialog::ID_TEXTCTRL4 = wxNewId();
const long SamochodDialog::ID_STATICTEXT5 = wxNewId();
const long SamochodDialog::ID_TEXTCTRL5 = wxNewId();
const long SamochodDialog::wxID_OKs = wxNewId();
const long SamochodDialog::ID_BUTTON1 = wxNewId();
const long SamochodDialog::ID_STATICTEXT6 = wxNewId();
const long SamochodDialog::ID_TEXTCTRL6 = wxNewId();
const long SamochodDialog::ID_STATICTEXT7 = wxNewId();
const long SamochodDialog::ID_STATICTEXT8 = wxNewId();
const long SamochodDialog::ID_TEXTCTRL7 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SamochodDialog,wxDialog)
	//(*EventTable(SamochodDialog)
	//*)
END_EVENT_TABLE()

SamochodDialog::SamochodDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(SamochodDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(947,443));
	Move(wxDefaultPosition);
	MarkaRamka = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(192,80), wxSize(224,40), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	MarkaRamka->SetMaxLength(30);
	wxFont MarkaRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	MarkaRamka->SetFont(MarkaRamkaFont);
	ModelRamka = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(632,80), wxSize(224,40), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	ModelRamka->SetMaxLength(30);
	wxFont ModelRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	ModelRamka->SetFont(ModelRamkaFont);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Marka"), wxPoint(24,80), wxSize(72,32), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	Model = new wxStaticText(this, ID_STATICTEXT2, _("Model"), wxPoint(480,80), wxSize(72,32), 0, _T("ID_STATICTEXT2"));
	wxFont ModelFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Model->SetFont(ModelFont);
	Tablice = new wxStaticText(this, ID_STATICTEXT3, _("Tablice"), wxPoint(24,168), wxSize(72,32), 0, _T("ID_STATICTEXT3"));
	wxFont TabliceFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Tablice->SetFont(TabliceFont);
	TabliceRamka = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(192,168), wxSize(224,40), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TabliceRamka->SetMaxLength(10);
	wxFont TabliceRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	TabliceRamka->SetFont(TabliceRamkaFont);
	Kolor = new wxStaticText(this, ID_STATICTEXT4, _("Kolor"), wxPoint(480,168), wxSize(72,32), 0, _T("ID_STATICTEXT4"));
	wxFont KolorFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Kolor->SetFont(KolorFont);
	KolorRamka = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(632,168), wxSize(224,40), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	KolorRamka->SetMaxLength(40);
	wxFont KolorRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	KolorRamka->SetFont(KolorRamkaFont);
	Moc = new wxStaticText(this, ID_STATICTEXT5, _("Moc w KM"), wxPoint(24,256), wxSize(72,32), 0, _T("ID_STATICTEXT5"));
	wxFont MocFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Moc->SetFont(MocFont);
	MocRamka = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(192,256), wxSize(224,40), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	MocRamka->SetMaxLength(4);
	wxFont MocRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	MocRamka->SetFont(MocRamkaFont);
	OK = new wxButton(this, wxID_OKs, _("OK"), wxPoint(296,376), wxSize(120,48), 0, wxDefaultValidator, _T("wxID_OKs"));
	wxFont OKFont(16,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	OK->SetFont(OKFont);
	ANULUJ = new wxButton(this, ID_BUTTON1, _("ANULUJ"), wxPoint(472,376), wxSize(120,48), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	wxFont ANULUJFont(16,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	ANULUJ->SetFont(ANULUJFont);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT6, _("Kategoria"), wxPoint(480,256), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	wxFont StaticText2Font(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	KategoriaRamka = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(632,256), wxSize(224,40), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	KategoriaRamka->SetMaxLength(100);
	wxFont KategoriaRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	KategoriaRamka->SetFont(KategoriaRamkaFont);
	Kategoria = new wxStaticText(this, ID_STATICTEXT7, _("Wysoka/ Srednia/ Niska"), wxPoint(656,304), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT8, _("Cena\nza dobe"), wxPoint(32,320), wxSize(72,32), 0, _T("ID_STATICTEXT8"));
	wxFont StaticText3Font(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	CenaRamka = new wxTextCtrl(this, ID_TEXTCTRL7, wxEmptyString, wxPoint(192,328), wxSize(224,40), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	CenaRamka->SetMaxLength(10000);
	wxFont CenaRamkaFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	CenaRamka->SetFont(CenaRamkaFont);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SamochodDialog::OnTextCtrl1Text);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SamochodDialog::OnModelRamkaText);
	Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SamochodDialog::OnMocRamkaText);
	Connect(wxID_OKs,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SamochodDialog::OnOKClick);
	//*)
}

SamochodDialog::~SamochodDialog()
{
	//(*Destroy(SamochodDialog)
	//*)
}


void SamochodDialog::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void SamochodDialog::OnModelRamkaText(wxCommandEvent& event)
{
}

void SamochodDialog::OnOKClick(wxCommandEvent& event)
{
    long int m;
    wxString model, marka, tablice, kolor, moc, kategoria, cena;
        model=ModelRamka->GetValue();
        marka=MarkaRamka->GetValue();
        tablice=TabliceRamka->GetValue();
        kolor=KolorRamka->GetValue();
        moc=MocRamka->GetValue();
            moc.ToLong(&m);
        kategoria=KategoriaRamka->GetValue();
        cena=CenaRamka->GetValue();

    FileAdapter cars("car.txt");
    std::string MODEL=model.ToStdString();
    std::string MARKA=marka.ToStdString();
    std::string TABLICE=tablice.ToStdString();
    std::string KOLOR=kolor.ToStdString();
    std::string MOC=moc.ToStdString();
    std::string KATEGORIA=kategoria.ToStdString();
    std::string CENA=cena.ToStdString();
    cars.writeRecord(CENA+" "+MODEL+" "+MARKA+" "+TABLICE+" " +KOLOR+" "+MOC+" "+KATEGORIA);

    EndModal(0);
}

void SamochodDialog::OnMocRamkaText(wxCommandEvent& event)
{
}
