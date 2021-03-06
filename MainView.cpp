//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <fstream>
//#include <msclr\marshal_cppstd.h>
#include <string>
#pragma hdrstop

#include "MainView.h"
#include "PageInfoUnit.h"
#include "BookmarksReader.h"
#include "BookmarksWriter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWebView *WebView;
bool isFullScreen = false;
bool isLoaded = true;
String title = "";
String pageURL = "";
bool isSelectedBar = false;
int tabId = 0;
std::vector<std::pair<std::string, std::string>> bookmarks;

//---------------------------------------------------------------------------
__fastcall TWebView::TWebView(TComponent* Owner)
	: TForm(Owner)
{

}

void __fastcall TWebView::FormCreate(TObject *Sender)
{
	createNewTab();
	BookmarksReader *reader = new BookmarksReader();
	bookmarks = reader->readBookmarks("test.txt");
	for (int i = 0; i < bookmarks.size(); i++) {
		bookmarksBox->Items->Add(bookmarks[i].first.c_str());
	}
}


void __fastcall TWebView::backBtnClick(TObject *Sender)
{
	getCurrentBrowser()->GoBack();
}

void __fastcall TWebView::forwardBtnClick(TObject *Sender)
{
	getCurrentBrowser()->GoForward();
}

void __fastcall TWebView::updateBtnClick(TObject *Sender)
{
	getCurrentBrowser()->Refresh();
}

void __fastcall TWebView::searchBtnClick(TObject *Sender)
{
	AnsiString str = addressBar->Text;
	std::string request = str.c_str();
	if(request.rfind("https://", 0) == 0)
	{
		getCurrentBrowser()->Navigate(str);
	}
	else
	{
		getCurrentBrowser()->Navigate("https://www.google.com/search?q=" + addressBar->Text);
    }

}

void __fastcall TWebView::backBtnMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	backBtn->Top = backBtn->Top + 3;
}

void __fastcall TWebView::backBtnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
    backBtn->Top = backBtn->Top - 3;
}

void __fastcall TWebView::forwardBtnMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	forwardBtn->Top = forwardBtn->Top + 3;
}

void __fastcall TWebView::forwardBtnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
    forwardBtn->Top = forwardBtn->Top - 3;
}

void __fastcall TWebView::updateBtnMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
    updateBtn->Top = updateBtn->Top + 3;
}

void __fastcall TWebView::updateBtnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
    updateBtn->Top = updateBtn->Top - 3;
}

void __fastcall TWebView::homeBtnMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
    homeBtn->Top = homeBtn->Top + 3;
}

void __fastcall TWebView::homeBtnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
    homeBtn->Top = homeBtn->Top - 3;
}

void __fastcall TWebView::addressBarClick(TObject *Sender)
{
	addressBar->Text = pageURL;
	if (!isSelectedBar)
	{
		addressBar->SelectAll();
	}
	isSelectedBar = true;
}

void __fastcall TWebView::homeBtnClick(TObject *Sender)
{
	getCurrentBrowser()->Navigate("https://www.google.com/");
}

void __fastcall TWebView::searchBtnMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	searchBtn->Top = searchBtn->Top + 3;
}

void __fastcall TWebView::searchBtnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
    searchBtn->Top = searchBtn->Top - 3;
}

void __fastcall TWebView::settingsBtnMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	settingsBtn->Top = settingsBtn->Top + 3;
}

void __fastcall TWebView::settingsBtnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	settingsBtn->Top = settingsBtn->Top - 3;
}

void __fastcall TWebView::newTabBtnMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	newTabBtn->Top = newTabBtn->Top + 3;
}

void __fastcall TWebView::newTabBtnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	newTabBtn->Top = newTabBtn->Top - 3;
}

void __fastcall TWebView::showBookmarksBtnMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	showBookmarksBtn->Top = showBookmarksBtn->Top + 3;
}

void __fastcall TWebView::showBookmarksBtnMouseUp(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
    showBookmarksBtn->Top = showBookmarksBtn->Top - 3;
}

void __fastcall TWebView::closeBtnClick(TObject *Sender)
{
   Application->Terminate();
}

void __fastcall TWebView::closeBtnMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	closeBtn->Top = closeBtn->Top + 3;
}

void __fastcall TWebView::closeBtnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	closeBtn->Top = closeBtn->Top - 3;
}

void __fastcall TWebView::hideBtnClick(TObject *Sender)
{
	Application->Minimize();
}

void __fastcall TWebView::hideBtnMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	hideBtn->Top = hideBtn->Top + 3;
}

void __fastcall TWebView::hideBtnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	hideBtn->Top = hideBtn->Top - 3;
}

void __fastcall TWebView::expandBtnClick(TObject *Sender)
{
	if (isFullScreen)
	{
        WebView->WindowState = wsNormal;
		isFullScreen = false;
	}
	else
	{
		WebView->WindowState = wsMaximized;
		isFullScreen = true;
	}
}

void __fastcall TWebView::WebBrowserTitleChange(TObject *ASender, const WideString Text)

{
	title = Text;
	addressBar->Text = title;
}

void __fastcall TWebView::addressBarMouseLeave(TObject *Sender)
{
    isSelectedBar = false;
}

void __fastcall TWebView::newTabBtnClick(TObject *Sender)
{
	if (isLoaded)
	{
		createNewTab();
	}
}

void TWebView::createNewTab()
{
	TTabSheet *tab = new TTabSheet(PageControl);
	tab->Visible = true;
	tab->Caption = "????? ???????";
	tab->PageControl = PageControl;
	PageControl->ActivePage = tab;
	tab->Name = "tab" + String(tabId);

	TWebBrowser *browser = new TWebBrowser(PageControl);
	browser->SelectedEngine = TWebBrowser::TSelectedEngine::EdgeOnly;
	browser->TOleControl::Parent = tab;
	browser->Align = alClient;
	browser->Navigate("https://www.google.com/");
	tab->Tag = Integer(browser);
	browser->TOleControl::Name = tab->Name + "_browser";
	browser->OnDocumentComplete = DocumentComplete;
	browser->OnNewWindow3 = NewWindow3;
	browser->OnTitleChange = TitleChange;
	browser->OnBeforeNavigate2 = BeforeNavigate2;
	tabId++;
}

void __fastcall TWebView::DocumentComplete(TObject *ASender, _di_IDispatch const pDisp, const OleVariant &URL)
{
	pageURL = URL;
	PageControl->ActivePage->Caption = "         " + title + "         ";
	isLoaded = true;
}

void __fastcall TWebView::NewWindow3(TObject *ASender, _di_IDispatch &ppDisp, WordBool &Cancel,
		  unsigned int val, const WideString bstrUrlContext, const WideString bstrUrl)
{
	createNewTab();
	getCurrentBrowser()->Navigate(bstrUrl);
	Cancel = true;
}

void __fastcall TWebView::TitleChange(TObject *ASender, const WideString Text)
{
	title = Text;
	addressBar->Text = title;
}

TWebBrowser* TWebView::getCurrentBrowser() {
	return (TWebBrowser*) PageControl->ActivePage->FindChildControl(PageControl->ActivePage->Name + "_browser");
}

void __fastcall TWebView::PageControlChange(TObject *Sender)
{
	title = getCurrentBrowser()->LocationName;
	pageURL = getCurrentBrowser()->LocationURL;
	addressBar->Text = title;
}

void __fastcall TWebView::PageControlMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if(Button == mbRight && PageControl->PageCount>1)
	{
		int i = PageControl->IndexOfTabAt(X,Y);
		PageControl->Pages[i]->Free();
	}
}


//---------------------------------------------------------------------------

void __fastcall TWebView::showBookmarksBtnClick(TObject *Sender)
{
    bookmarksBox->DroppedDown = true;
}
//---------------------------------------------------------------------------

void __fastcall TWebView::addBookmarkBtnClick(TObject *Sender)
{
	if (isLoaded)
	{
		BookmarksWriter *writer = new BookmarksWriter();
		std::pair<std::string, std::string> pair;
		pair.first = convertToStdString(title);
		pair.second = convertToStdString(pageURL);
		bookmarks.push_back(pair);
		writer->writeBookmarks(bookmarks, "test.txt");
		Application->MessageBox(L"???????? ??????? ?????????", L"NetBar", MB_OK);
		updateBookmarksBox();
	}
}

std::string TWebView::convertToStdString(String str)
{
	AnsiString ansiStr = str;
	return ansiStr.c_str();
}

void TWebView::updateBookmarksBox()
{
	bookmarksBox->Clear();
	for (int i = 0; i < bookmarks.size(); i++)
	{
		bookmarksBox->Items->Add(bookmarks[i].first.c_str());
	}
}

//---------------------------------------------------------------------------

void __fastcall TWebView::BeforeNavigate2(TObject *ASender, _di_IDispatch const pDisp,
		  const OleVariant &URL, const OleVariant &Flags, const OleVariant &TargetFrameName,
		  const OleVariant &PostData, const OleVariant &Headers,
		  WordBool &Cancel)
{
	isLoaded = false;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

