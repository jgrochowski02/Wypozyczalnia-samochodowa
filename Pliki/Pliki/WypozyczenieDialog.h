#ifndef WYPOZYCZENIEDIALOG_H
#define WYPOZYCZENIEDIALOG_H

//(*Headers(WypozyczenieDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class WypozyczenieDialog: public wxDialog
{
	public:

		WypozyczenieDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~WypozyczenieDialog();

		//(*Declarations(WypozyczenieDialog)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* OK;
		wxStaticText* IDKlientaRamka;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxTextCtrl* DataWypoRamka;
		wxTextCtrl* IDSamochoduRamka;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(WypozyczenieDialog)
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL5;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(WypozyczenieDialog)
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnTextCtrl4Text(wxCommandEvent& event);
		void OnOKClick(wxCommandEvent& event);
		void OnklienciText(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);

		//*)

		DECLARE_EVENT_TABLE()
};

#endif
