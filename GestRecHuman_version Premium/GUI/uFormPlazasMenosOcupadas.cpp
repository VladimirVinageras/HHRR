//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "uFormPrncipal.h"
#include "uFormPlazasMenosOcupadas.h"
#include "uGlobal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TFormPlazasMenosCubiertas *FormPlazasMenosCubiertas;
//---------------------------------------------------------------------------
__fastcall TFormPlazasMenosCubiertas::TFormPlazasMenosCubiertas(TComponent* Owner)
: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormPlazasMenosCubiertas::btnCerrarClick(TObject *Sender)
{
	ListView1->Clear();
	CSpinEdit1->Text = "";
	FormPlazasMenosCubiertas->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormPlazasMenosCubiertas::btnMostrarClick(TObject *Sender)
{
	ListView1->Clear();
	if(CSpinEdit1->Text != "")
	{
		int max = StrToInt(CSpinEdit1->Text);
		TGLinkedList* lista = empresa->PlazasMenosCubiertas();
		if(max > lista->Length())
			max = lista->Length();
		for(int i=0; i<max; i++)
		{
			TSCargoPlazas* structCargoPlazas = (TSCargoPlazas*)(lista->ItemInfo(i));
			TListItem* item;
			item = ListView1->Items->Add();
			item->Data = structCargoPlazas;
			item->Caption = structCargoPlazas->cargo->GetNombre();
			item->SubItems->Add(FloatToStr(structCargoPlazas->cargo->EstadoCargo())+ " %");
                        item->SubItems->Add( "$ " + FloatToStr(structCargoPlazas->cargo->GetSalario()));
			item->SubItems->Add(structCargoPlazas->departamento->GetNombre());
			if(structCargoPlazas->departamento->GetJefeDepartamento())
				item->SubItems->Add(((TTrabajador*)(structCargoPlazas->departamento->GetJefeDepartamento()))->GetNombre());
			else
				item->SubItems->Add("No posee");
		}
	}
	else
	{
		Application->MessageBoxA(LPWSTR("Debe indicar la cantidad de plazas menos cubiertas que desea listar."),LPWSTR("Informaci?n"),MB_OK);
		CSpinEdit1->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormPlazasMenosCubiertas::CSpinEdit1KeyPress(
	TObject *Sender, char &Key)
{
	if ((Key != '\b')&&((Key< '0')||(Key > '9')))
		Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormPlazasMenosCubiertas::CSpinEdit1Change(
	TObject *Sender)
{
	if((CSpinEdit1->Text) < "0")
		CSpinEdit1->Text = "0";
}
//---------------------------------------------------------------------------

void __fastcall TFormPlazasMenosCubiertas::btnMostarTodosClick(TObject *Sender)
{
	ListView1->Clear();
        TGLinkedList* lista = empresa->PlazasMenosCubiertas();
        int max = lista->Length();
	for(int i=0; i<max; i++)
	{
		TSCargoPlazas* structCargoPlazas = (TSCargoPlazas*)(lista->ItemInfo(i));
		TListItem* item;
		item = ListView1->Items->Add();
		item->Data = structCargoPlazas;
		item->Caption = structCargoPlazas->cargo->GetNombre();
                item->SubItems->Add(FloatToStr(structCargoPlazas->cargo->EstadoCargo()));
		item->SubItems->Add(FloatToStr(structCargoPlazas->cargo->GetSalario()));
		item->SubItems->Add(structCargoPlazas->departamento->GetNombre());
		if(structCargoPlazas->departamento->GetJefeDepartamento())
			item->SubItems->Add(((TTrabajador*)(structCargoPlazas->departamento->GetJefeDepartamento()))->GetNombre());
		else
			item->SubItems->Add("No posee");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormPlazasMenosCubiertas::FormShow(TObject *Sender)
{
 ListView1->Clear();
}
//---------------------------------------------------------------------------

