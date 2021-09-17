//---------------------------------------------------------------------------

#ifndef PageInfoUnitH
#define PageInfoUnitH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Edge.hpp>
#include <WebView2.hpp>
#include <Winapi.ActiveX.hpp>
#include <Vcl.TitleBarCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <SHDocVw.hpp>
#include <Vcl.OleCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Imaging.pngimage.hpp>

class PageInfo {
	private:
		String pageURL;
		String pageTitle;
		TWebBrowser *webBrowser;
	public:
		String getPageURL();
		void setPageURL(String url);
		String getPageTitle();
		void setPageTitle(String title);
		TWebBrowser getWebBrowser();
		void setWebBrowser(TWebBrowser *browser);


};
//---------------------------------------------------------------------------
#endif
