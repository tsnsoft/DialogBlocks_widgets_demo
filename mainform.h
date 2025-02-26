/////////////////////////////////////////////////////////////////////////////
// Name:        mainform.h
// Purpose:     
// Author:      Sergey Talipov
// Modified by: 
// Created:     14/11/2023 13:41:03
// RCS-ID:      
// Copyright:   15681627-3C745D8E-630127F2
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _MAINFORM_H_
#define _MAINFORM_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/frame.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_MAINFORM 10000
#define ID_GAUGE 10002
#define ID_SLIDER 10003
#define wxID_STATIC1 10004
#define ID_TEXTCTRL1 10001
#define wxID_STATIC2 10005
#define ID_BITMAPBUTTON 10006
#define ID_BUTTON_EXIT 10007
#define ID_MENUITEM_EXIT 10009
#define SYMBOL_MAINFORM_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_MAINFORM_TITLE wxT("Виджеты и события")
#define SYMBOL_MAINFORM_IDNAME ID_MAINFORM
#define SYMBOL_MAINFORM_SIZE wxSize(400, 400)
#define SYMBOL_MAINFORM_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * MainForm class declaration
 */

class MainForm: public wxFrame
{    
    DECLARE_CLASS( MainForm )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    MainForm();
    MainForm( wxWindow* parent, wxWindowID id = SYMBOL_MAINFORM_IDNAME, const wxString& caption = SYMBOL_MAINFORM_TITLE, const wxPoint& pos = SYMBOL_MAINFORM_POSITION, const wxSize& size = SYMBOL_MAINFORM_SIZE, long style = SYMBOL_MAINFORM_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_MAINFORM_IDNAME, const wxString& caption = SYMBOL_MAINFORM_TITLE, const wxPoint& pos = SYMBOL_MAINFORM_POSITION, const wxSize& size = SYMBOL_MAINFORM_SIZE, long style = SYMBOL_MAINFORM_STYLE );

    /// Destructor
    ~MainForm();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin MainForm event handler declarations

    /// wxEVT_COMMAND_SLIDER_UPDATED event handler for ID_SLIDER
    void OnSliderUpdated( wxCommandEvent& event );

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL1
    void OnTextctrl1TextUpdated( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON
    void OnBitmapbuttonClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_EXIT
    void OnButtonExitClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_EXIT
    void OnMenuitemExitClick( wxCommandEvent& event );

////@end MainForm event handler declarations

////@begin MainForm member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end MainForm member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin MainForm member variables
////@end MainForm member variables
};

#endif
    // _MAINFORM_H_
