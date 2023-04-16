#ifndef KLIENTDIALOG_H
#define KLIENTDIALOG_H

//(*Headers(KlientDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class KlientDialog: public wxDialog
{
	public:

		KlientDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~KlientDialog();

		//(*Declarations(KlientDialog)
		wxButton* ANULUJ;
		wxButton* OK;
		wxSpinCtrl* WiekRamka;
		wxStaticText* Imie;
		wxStaticText* Nazwisko;
		wxStaticText* NrTel;
		wxStaticText* PESEL;
		wxStaticText* Wiek;
		wxTextCtrl* ImieRamka;
		wxTextCtrl* NazwiskoRamka;
		wxTextCtrl* NrTelRamka;
		wxTextCtrl* PESELRamka;
		//*)

	protected:

		//(*Identifiers(KlientDialog)
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_SPINCTRL1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL4;
		static const long wxID_OKk;
		static const long wxID_ANULUJk;
		//*)

	private:

		//(*Handlers(KlientDialog)
		void OnSpinCtrl1Change(wxSpinEvent& event);
		void OnTextCtrl3Text(wxCommandEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnANULUJClick(wxCommandEvent& event);
		void OnOKClick(wxCommandEvent& event);
		void OnInit(wxInitDialogEvent& event);
		void OnPobranieKlientClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
