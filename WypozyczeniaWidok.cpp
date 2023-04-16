#include "WypozyczeniaWidok.h"
#include <sstream>
#include <vector>
#include "fileAdapter.h"
//(*InternalHeaders(WypozyczeniaWidok)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(WypozyczeniaWidok)
const long WypozyczeniaWidok::ID_BUTTON1 = wxNewId();
const long WypozyczeniaWidok::ID_TEXTCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(WypozyczeniaWidok,wxDialog)
	//(*EventTable(WypozyczeniaWidok)
	//*)
END_EVENT_TABLE()

WypozyczeniaWidok::WypozyczeniaWidok(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(WypozyczeniaWidok)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(947,443));
	Move(wxDefaultPosition);
	Button1 = new wxButton(this, ID_BUTTON1, _("Pokaz wypozyczenia"), wxPoint(384,376), wxSize(168,32), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxPoint(912,416), wxSize(8,8), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&WypozyczeniaWidok::OnButton1Click);
	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&WypozyczeniaWidok::OnTextCtrl1Text);
	//*)
}

WypozyczeniaWidok::~WypozyczeniaWidok()
{
	//(*Destroy(WypozyczeniaWidok)
	//*)
}


void WypozyczeniaWidok::OnButton1Click(wxCommandEvent& event)
{
    FileAdapter order("order.txt");
    FileAdapter car("car.txt");
    FileAdapter client("client.txt");

    int IDKlienta, IDSamochodu, IDWypozyczenia;
    wxString result;
    std::string IloscDni, dzien, miesiac, rok;
    wxTextCtrl  * wypo = new wxTextCtrl (this, 0, wxEmptyString, wxPoint(50,70), wxSize(800,250),
                                         wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));

    std::vector<std::string> wypo_data = order.readAllRecords();

    for (int i = 0; i < wypo_data.size(); ++i) {
        istringstream iss(wypo_data[i]);
        iss >> IDWypozyczenia >> IDKlienta >> IDSamochodu >> IloscDni >> dzien >> miesiac >> dzien >> rok >> rok;

    std::string Klient = client.readRecord(IDKlienta);
    std::string Samochod = car.readRecord(IDSamochodu);

        wxString mystring(Klient.c_str(), wxConvUTF8);
            result+=(mystring+"   ");

        wxString my_string(Samochod.c_str(), wxConvUTF8);
            result+=(my_string+"  ");

        wxString IloscDniwx (IloscDni.c_str(), wxConvUTF8);
        wxString dzienwx(dzien.c_str(), wxConvUTF8);
        wxString miesiacwx(miesiac.c_str(), wxConvUTF8);
        wxString rokwx(rok.c_str(), wxConvUTF8);
        result+=(IloscDniwx+"  "+dzienwx+" "+miesiacwx+" "+rokwx+"\n");
    }
    wypo->SetValue(result);
}

void WypozyczeniaWidok::OnTextCtrl1Text(wxCommandEvent& event)
{
}
