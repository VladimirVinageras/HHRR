//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFormAcercaDe.h"
#include "uGlobal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAcercaDe *FormAcercaDe;
//---------------------------------------------------------------------------
__fastcall TFormAcercaDe::TFormAcercaDe(TComponent* Owner)
: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormAcercaDe::btnOkClick(TObject *Sender)
{
	FormAcercaDe->Close();    
}
//---------------------------------------------------------------------------

