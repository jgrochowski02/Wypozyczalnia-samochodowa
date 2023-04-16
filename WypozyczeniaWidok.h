#ifndef WYPOZYCZENIAWIDOK_H
#define WYPOZYCZENIAWIDOK_H

//(*Headers(WypozyczeniaWidok)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>
//*)

class WypozyczeniaWidok: public wxDialog
{
	public:

		WypozyczeniaWidok(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~WypozyczeniaWidok();

		//(*Declarations(WypozyczeniaWidok)
		wxButton* Button1;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(WypozyczeniaWidok)
		static const long ID_BUTTON1;
		static const long ID_TEXTCTRL1;
		//*)

	private:

		//(*Handlers(WypozyczeniaWidok)
		void OnButton1Click(wxCommandEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
