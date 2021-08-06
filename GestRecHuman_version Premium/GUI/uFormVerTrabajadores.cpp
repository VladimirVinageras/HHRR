//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFormVerTrabajadores.h"
#include "uGlobal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormVerTrabajadores *FormVerTrabajadores;
//---------------------------------------------------------------------------
__fastcall TFormVerTrabajadores::TFormVerTrabajadores(TComponent* Owner)
: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormVerTrabajadores::FormShow(TObject *Sender)
{
	ListView1->Clear();
	int largo = ((TGLinkedList*)empresa->GetListaTrabEmp())->Length();
	for(int i=0; i<largo; i++)
	{
		TTrabajador* TempTrab = (TTrabajador*)((TGLinkedList*)empresa->GetListaTrabEmp())->ItemInfo(i);
		TListItem* item;
		item = ListView1->Items->Add();
		item->Data = TempTrab;
		item->Caption = TempTrab->GetIdW();
		item->SubItems->Add(TempTrab->GetNombre());
		item->SubItems->Add(TempTrab->GetDirParticular());
		item->SubItems->Add(TempTrab->GetTelefono());
		if(TempTrab->GetAlta())
		{
			item->SubItems->Add(((TCargo*)(TempTrab->GetCargo()))->GetNombre());
			item->SubItems->Add(((TDepartamento*)(empresa->BuscaDepartamentoTrabajador(TempTrab->GetIdW())))->GetNombre());
			if(TempTrab->GetResolucion())
				item->SubItems->Add( "$ " + FloatToStr(TempTrab->GetSalarioRes()));
			else
				item->SubItems->Add( "$ " + FloatToStr(((TCargo*)(TempTrab->GetCargo()))->GetSalario()));
		}
		else
		{
			item->SubItems->Add("No Ubicado");
			item->SubItems->Add("No Ubicado");
			item->SubItems->Add("No Tiene");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormVerTrabajadores::Button1Click(TObject *Sender)
{
	FormVerTrabajadores->Close();
}
//---------------------------------------------------------------------------
