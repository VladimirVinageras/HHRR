//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFormVerCargos.h"
#include "uGlobal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormVerCargos *FormVerCargos;
//---------------------------------------------------------------------------
__fastcall TFormVerCargos::TFormVerCargos(TComponent* Owner)
: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFormVerCargos::Button1Click(TObject *Sender)
{
	ListView1->Clear();
	FormVerCargos->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormVerCargos::FormShow(TObject *Sender)
{
	ListView1->Clear();
	int largo = ((TGLinkedList*)empresa->GetListaCargosEmp())->Length();
	for(int i=0; i<largo; i++)
	{
		TCargo* TempCargo = (TCargo*)((TGLinkedList*)empresa->GetListaCargosEmp())->ItemInfo(i);
		TListItem* item;
		item = ListView1->Items->Add();
		item->Data = TempCargo;
		item->Caption = TempCargo->GetNombre();
		item->SubItems->Add(IntToStr(TempCargo->GetPlazasApr()));
		item->SubItems->Add(IntToStr(TempCargo->GetPlazasReales()));
		item->SubItems->Add( "$ " + FloatToStr(TempCargo->GetSalario()));
	}
}
//---------------------------------------------------------------------------
