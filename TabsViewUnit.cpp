//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TabsViewUnit.h"
#include "PageInfoUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTabsView *TabsView;
//---------------------------------------------------------------------------
__fastcall TTabsView::TTabsView(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTabsView::closeBtnClick(TObject *Sender)
{
	TabsView->Hide();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
