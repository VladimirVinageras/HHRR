//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "uFormConfigurar.h"
#include "uFormPrncipal.h"
#include "uGlobal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TFormConfigurar *FormConfigurar;
bool estado;
//---------------------------------------------------------------------------
__fastcall TFormConfigurar::TFormConfigurar(TComponent* Owner)
: TForm(Owner)                   
{
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigurar::btnAceptarClick(TObject *Sender)
{
	if(estado != chboxVisibleCheck->Checked)
	{
		FormPrincipal->TrayIcon1->Visible = chboxVisibleCheck->Checked;
		Update();
	}
	FormConfigurar->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigurar::btnCancelarClick(TObject *Sender)
{
	chboxVisibleCheck->Checked = estado;
	FormConfigurar->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigurar::btnAplicarClick(TObject *Sender)
{
	if(estado != chboxVisibleCheck->Checked)
	{
		estado = chboxVisibleCheck->Checked;
		FormPrincipal->TrayIcon1->Visible = chboxVisibleCheck->Checked;
		Update();
	}
	btnAplicar->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigurar::FormShow(TObject *Sender)
{
	estado = chboxVisibleCheck->Checked;
	btnAplicar->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigurar::chboxVisibleCheckClick(TObject *Sender)
{
	btnAplicar->Enabled = true;
}
//---------------------------------------------------------------------------

