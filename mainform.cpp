/////////////////////////////////////////////////////////////////////////////
// Name:        mainform.cpp
// Purpose:     
// Author:      Sergey Talipov
// Modified by: 
// Created:     26/02/2025 10:50:03
// RCS-ID:      
// Copyright:   15681627-3C745D8E-630127F2
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"
#include <wx/webview.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "mainform.h"

////@begin XPM images
#include "tsnsoft.xpm"
#include "quit.xpm"
////@end XPM images


/*
 * MainForm type definition
 */

IMPLEMENT_CLASS(MainForm, wxFrame)


/*
 * MainForm event table definition
 */

	BEGIN_EVENT_TABLE(MainForm, wxFrame)

	////@begin MainForm event table entries
    EVT_SLIDER( ID_SLIDER, MainForm::OnSliderUpdated )
    EVT_TEXT( ID_TEXTCTRL1, MainForm::OnTextctrl1TextUpdated )
    EVT_BUTTON( ID_BITMAPBUTTON, MainForm::OnBitmapbuttonClick )
    EVT_BUTTON( ID_BUTTON_EXIT, MainForm::OnButtonExitClick )
    EVT_MENU( ID_MENUITEM_EXIT, MainForm::OnMenuitemExitClick )
	////@end MainForm event table entries

	END_EVENT_TABLE()


	/*
	 * MainForm constructors
	 */

	MainForm::MainForm()
{
	Init();
}

MainForm::MainForm(wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
	Init();
	Create(parent, id, caption, pos, size, style);
}


/*
 * MainForm creator
 */

bool MainForm::Create(wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
	wxFrame::Create(parent, id, caption, pos, size, style);

	CreateControls();
	SetIcon(GetIconResource(wxT("tsnsoft.xpm")));
	if (GetSizer())
	{
		GetSizer()->SetSizeHints(this);
	}
	Centre();

	// --- Сами сюда дописали для обновления данных в компонентах формы при старте программы ---
	wxCommandEvent dummyEvent; // Создаем фиктивное событие
	OnTextctrl1TextUpdated(dummyEvent); // Вызываем обработчик события
	OnSliderUpdated(dummyEvent); // Вызываем обработчик события
	// ------------------------------------------------------------------------------------------

	return true;
}


/*
 * MainForm destructor
 */

MainForm::~MainForm()
{
	////@begin MainForm destruction
	////@end MainForm destruction
}


/*
 * Member initialisation
 */

void MainForm::Init()
{
}


/*
 * Control creation for MainForm
 */

void MainForm::CreateControls()
{
	////@begin MainForm content construction
    MainForm* itemFrame1 = this;

    wxMenuBar* menuBar = new wxMenuBar;
    wxMenu* itemMenu2 = new wxMenu;
    {
        wxMenuItem* menuItem = new wxMenuItem(itemMenu2, ID_MENUITEM_EXIT, wxT("Выход"), wxEmptyString, wxITEM_NORMAL);
        wxBitmap bitmap(itemFrame1->GetBitmapResource(wxT("quit.xpm")));
        menuItem->SetBitmap(bitmap);
        itemMenu2->Append(menuItem);
    }
    menuBar->Append(itemMenu2, wxT("Меню"));
    itemFrame1->SetMenuBar(menuBar);

    wxBoxSizer* itemBoxSizer1 = new wxBoxSizer(wxVERTICAL);
    itemFrame1->SetSizer(itemBoxSizer1);

    wxGauge* itemGauge2 = new wxGauge( itemFrame1, ID_GAUGE, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
    itemGauge2->SetValue(1);
    itemBoxSizer1->Add(itemGauge2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxSlider* itemSlider1 = new wxSlider( itemFrame1, ID_SLIDER, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
    itemBoxSizer1->Add(itemSlider1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText2 = new wxStaticText( itemFrame1, wxID_STATIC1, wxT("Static text"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer1->Add(itemStaticText2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxTextCtrl* itemTextCtrl3 = new wxTextCtrl( itemFrame1, ID_TEXTCTRL1, wxT("Hello!"), wxDefaultPosition, wxSize(150, 150), wxTE_MULTILINE );
    itemBoxSizer1->Add(itemTextCtrl3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText1 = new wxStaticText( itemFrame1, wxID_STATIC2, wxT("Static text"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
    itemBoxSizer1->Add(itemStaticText1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBitmapButton* itemBitmapButton2 = new wxBitmapButton( itemFrame1, ID_BITMAPBUTTON, itemFrame1->GetBitmapResource(wxT("tsnsoft.xpm")), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
    if (MainForm::ShowToolTips())
        itemBitmapButton2->SetToolTip(wxT("Нажми меня!"));
    itemBoxSizer1->Add(itemBitmapButton2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton1 = new wxButton( itemFrame1, ID_BUTTON_EXIT, wxT("Выход"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer1->Add(itemButton1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

	////@end MainForm content construction
}

/*
 * Should we show tooltips?
 */

bool MainForm::ShowToolTips()
{
	return true;
}

/*
 * Get bitmap resources
 */

wxBitmap MainForm::GetBitmapResource(const wxString& name)
{
	// Bitmap retrieval
////@begin MainForm bitmap retrieval
    wxUnusedVar(name);
    if (name == wxT("tsnsoft.xpm"))
    {
        wxBitmap bitmap(tsnsoft_xpm);
        return bitmap;
    }
    else if (name == wxT("quit.xpm"))
    {
        wxBitmap bitmap(quit_xpm);
        return bitmap;
    }
    return wxNullBitmap;
	////@end MainForm bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon MainForm::GetIconResource(const wxString& name)
{
	// Icon retrieval
////@begin MainForm icon retrieval
    wxUnusedVar(name);
    if (name == wxT("tsnsoft.xpm"))
    {
        wxIcon icon(tsnsoft_xpm);
        return icon;
    }
    return wxNullIcon;
	////@end MainForm icon retrieval
}



/*
 * wxEVT_COMMAND_SLIDER_UPDATED event handler for ID_SLIDER
 */

 // Обработчик события обновления слайдера
void MainForm::OnSliderUpdated(wxCommandEvent& event)
{
	int value = event.GetInt(); // Получаем значение слайдера

	wxGauge* wxGauge1 = static_cast<wxGauge*>(FindWindow(ID_GAUGE)); // Находим компонент wxGauge
	wxGauge1->SetValue(value); // Устанавливаем значение в компоненте wxGauge

	wxStaticText* wxStaticText1 = static_cast<wxStaticText*>(FindWindow(wxID_STATIC1)); // Находим компонент wxStaticText
	wxStaticText1->SetLabel(wxString::Format("%d", value)); // Устанавливаем значение в компоненте wxStaticText
}


/*
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL
 */

 // Обработчик события обновления текстового поля
void MainForm::OnTextctrl1TextUpdated(wxCommandEvent& event)
{
	// Получаем доступ к компоненту wxStaticText и wxTextCtrl
	wxStaticText* wxStaticText1 = static_cast<wxStaticText*>(FindWindow(wxID_STATIC2));
	wxTextCtrl* wxTextCtrl1 = static_cast<wxTextCtrl*>(FindWindow(ID_TEXTCTRL1));

	// Устанавливаем значение в компоненте wxStaticText
	wxStaticText1->SetLabel(wxTextCtrl1->GetValue());
	
	this->Fit(); // Подгоняем размеры формы под содержимое
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON
 */

 // Обработчик события нажатия на кнопку
void MainForm::OnBitmapbuttonClick(wxCommandEvent& event)
{
	wxString url = "https://github.com/tsnsoft"; // Ссылка на репозиторий
	if (!wxLaunchDefaultBrowser(url)) // Открываем ссылку в браузере
	{
		wxLogError("Не удалось открыть браузер по ссылке: %s", url);
	}
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */

 // Обработчик события нажатия на кнопку "Выход"
void MainForm::OnButtonExitClick(wxCommandEvent& event)
{
	Close(); // Закрываем форму
}


/*
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_EXIT
 */

 // Обработчик события выбора пункта меню "Выход"
void MainForm::OnMenuitemExitClick(wxCommandEvent& event)
{
	Close(); // Закрываем форму
}

