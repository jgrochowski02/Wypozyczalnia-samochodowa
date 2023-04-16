/***************************************************************
 * Name:      ObslugaWypoMain.h
 * Purpose:   Defines Application Frame
 * Author:    my ()
 * Created:   2022-12-06
 * Copyright: my ()
 * License:
 **************************************************************/

#ifndef OBSLUGAWYPOMAIN_H
#define OBSLUGAWYPOMAIN_H

//(*Headers(ObslugaWypoFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
//*)

class ObslugaWypoFrame: public wxFrame
{
    public:

        ObslugaWypoFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ObslugaWypoFrame();

    private:

        //(*Handlers(ObslugaWypoFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnKlientClick(wxCommandEvent& event);
        void OnSamochodClick(wxCommandEvent& event);
        void OnMenuKlientClick(wxCommandEvent& event);
        void OnSamochodMenuClick(wxCommandEvent& event);
        void OnKosztyClick(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void TloGlowne(wxMouseEvent& event);
        void OnEraseBackground(wxEraseEvent& event);
        void OnPokaWypoClick(wxCommandEvent& event);
        void OnWypozyczClick(wxCommandEvent& event);
        void OnPokazKlientowClick(wxCommandEvent& event);
        void OnPokazSamochodyClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(ObslugaWypoFrame)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_DodajKlienta;
        static const long ID_PokazKlientow;
        static const long ID_DodajSamochod;
        static const long ID_PokazSamochody;
        static const long ID_PokazWypozyczone;
        static const long ID_Kalkulacja;
        static const long ID_Wypozycz;
        //*)

        //(*Declarations(ObslugaWypoFrame)
        wxButton* Button3;
        wxButton* Klient;
        wxButton* Samochod;
        wxMenu MenuKlient;
        wxMenu MenuSamochod;
        wxMenu MenuWypozyczenie;
        wxMenuItem* MenuItem10;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem8;
        wxMenuItem* MenuItem9;
        wxStaticBitmap* StaticBitmap1;
        wxStaticText* WYPOZYCZALNIA;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // OBSLUGAWYPOMAIN_H
