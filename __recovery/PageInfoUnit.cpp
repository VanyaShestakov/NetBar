//---------------------------------------------------------------------------

#pragma hdrstop

#include "PageInfoUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


String PageInfo::getPageURL()
{
	return pageURL;
}

void PageInfo::setPageURL(String url)
{
	pageURL = url;
}

String PageInfo::getPageTitle()
{
	return pageTitle;
}

void PageInfo::setPageTitle(String title)
{
	pageTitle = title;
}

TWebBrowser PageInfo::getWebBrowser()
{
	return webBrowser;
}

void PageInfo::setWebBrowser(TWebBrowser *browser)
{
    webBrowser = browser;
}


