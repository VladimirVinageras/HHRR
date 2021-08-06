//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFormVerDepartamentos.h"
#include "uGlobal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormVerDepartamentos *FormVerDepartamentos;
//---------------------------------------------------------------------------
__fastcall TFormVerDepartamentos::TFormVerDepartamentos(TComponent* Owner)
: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormVerDepartamentos::FormShow(TObject *Sender)
{
	ListView1->Clear();
	int largo = ((TGLinkedList*)empresa->GetListaDptos())->Length();
	for(int i=0; i<largo; i++)
	{
		TDepartamento* TempDpto = (TDepartamento*)((TGLinkedList*)empresa->GetListaDptos())->ItemInfo(i);
		TListItem* item;
		item = ListView1->Items->Add();
		item->Data = TempDpto;
		item->Caption = TempDpto->GetCodigo();
		item->SubItems->Add(TempDpto->GetNombre());
		if(TempDpto->GetJefeDepartamento())
			item->SubItems->Add(TempDpto->GetJefeDepartamento()->GetNombre());
		else
			item->SubItems->Add("No asignado");
		item->SubItems->Add(TempDpto->GetListaCargos()->Length());
		item->SubItems->Add(TempDpto->GetListaTrabDep()->Length());
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormVerDepartamentos::Button1Click(TObject *Sender)
{
	FormVerDepartamentos->Close();
}
//---------------------------------------------------------------------------

