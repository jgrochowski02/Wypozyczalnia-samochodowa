#ifndef SAMOCHODDIALOG_H
#define SAMOCHODDIALOG_H

//(*Headers(SamochodDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class SamochodDialog: public wxDialog
{
	public:

		SamochodDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~SamochodDialog();

		//(*Declarations(SamochodDialog)
		wxButton* ANULUJ;
		wxButton* OK;
		wxStaticText* Kategoria;
		wxStaticText* Kolor;
		wxStaticText* Moc;
		wxStaticText* Model;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* Tablice;
		wxTextCtrl* CenaRamka;
		wxTextCtrl* KategoriaRamka;
		wxTextCtrl* KolorRamka;
		wxTextCtrl* MarkaRamka;
		wxTextCtrl* MocRamka;
		wxTextCtrl* ModelRamka;
		wxTextCtrl* TabliceRamka;
		//*)

	protected:

		//(*Identifiers(SamochodDialog)
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL5;
		static const long wxID_OKs;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL7;
		//*)

	private:

		//(*Handlers(SamochodDialog)
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnModelRamkaText(wxCommandEvent& event);
		void OnOKClick(wxCommandEvent& event);
		void OnMocRamkaText(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
