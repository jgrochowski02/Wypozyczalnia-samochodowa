#ifndef KLIENTDLG_H
#define KLIENTDLG_H

//(*Headers(KlientDlg)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class KlientDlg: public wxDialog
{
	public:

		KlientDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~KlientDlg();

		//(*Declarations(KlientDlg)
		wxButton* ANULUJ;
		wxButton* OK;
		wxCheckBox* PelnoletnoscRamka;
		wxStaticText* Imie;
		wxStaticText* Nazwisko;
		wxStaticText* NrTel;
		wxStaticText* PESEL;
		wxTextCtrl* ImieRamka;
		wxTextCtrl* NazwiskoRamka;
		wxTextCtrl* NrTelRamka;
		wxTextCtrl* PESELRamka;
		//*)

	protected:

		//(*Identifiers(KlientDlg)
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_CHECKBOX1;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		//*)

	private:

		//(*Handlers(KlientDlg)
		void OnOKClick(wxCommandEvent& event);
		void OnANULUJClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
