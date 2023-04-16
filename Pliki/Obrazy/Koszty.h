#ifndef KOSZTY_H
#define KOSZTY_H

//(*Headers(Koszty)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/spinctrl.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Koszty: public wxDialog
{
	public:

		Koszty(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Koszty();

		//(*Declarations(Koszty)
		wxButton* Button1;
		wxButton* Policz;
		wxCheckBox* KaucjaRamka;
		wxSpinCtrl* IloscDniRamka;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* IlsocDob;
		wxStaticText* KalkulacjaKosztow;
		wxStaticText* Markaw;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxTextCtrl* IDSamochoduRamka;
		//*)

	protected:

		//(*Identifiers(Koszty)
		static const long ID_STATICBITMAP1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_SPINCTRL1;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT3;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		//*)

	private:

		//(*Handlers(Koszty)
		void OnPoliczClick(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
