/***************************************************************
 * Name:      ObslugaWypoApp.cpp
 * Purpose:   Code for Application Class
 * Author:    my ()
 * Created:   2022-12-06
 * Copyright: my ()
 * License:
 **************************************************************/

#include "ObslugaWypoApp.h"

//(*AppHeaders
#include "ObslugaWypoMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ObslugaWypoApp);

bool ObslugaWypoApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ObslugaWypoFrame* Frame = new ObslugaWypoFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
