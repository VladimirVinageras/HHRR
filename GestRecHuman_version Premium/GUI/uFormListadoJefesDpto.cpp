//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uGlobal.h"
#include "uFormPrncipal.h"
#include "uFormListadoJefesDpto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TFormListadoJefesDpto *FormListadoJefesDpto;
//---------------------------------------------------------------------------
__fastcall TFormListadoJefesDpto::TFormListadoJefesDpto(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormListadoJefesDpto::btnCerrarClick(TObject *Sender)
{
	ListView1->Clear();
	FormListadoJefesDpto->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormListadoJefesDpto::CSpinEdit1Change(TObject *Sender)
{
        try
        {
	        ListView1->Clear();
	        if(CSpinEdit1->Text != "")
	        {
                        int max = StrToInt(CSpinEdit1->Text);
		        TGLinkedList* lista = empresa->OrdenaListaDptos();
		        if(max > lista->Length())
		                max = lista->Length();
        		for(int i=0; i<max; i++)
	        	{
		        	TDepartamento* TempDpto = (TDepartamento*)(lista->ItemInfo(i));
			        TListItem* item;
        			item = ListView1->Items->Add();
        			item->Data = TempDpto;
	        		item->Caption = TempDpto->GetJefeDepartamento()->GetNombre();
		        	item->SubItems->Add(TempDpto->GetNombre());
			        item->SubItems->Add(IntToStr(TempDpto->GetListaTrabDep()->Length()));
        			item->SubItems->Add(FloatToStr(TempDpto->CalcularHorasAusentismo()));
	        		item->SubItems->Add(FloatToStr(TempDpto->CalcularPorcientoAusentismo())+ " %");
		        }
        	}
	        else
	        {
		        Application->MessageBoxA("Debe indicar la cantidad de jefes de Departamento que desea listar.","Información",MB_OK);
        		CSpinEdit1->SetFocus();
	        }
        }
        catch(...)
        {
                Application->MessageBoxA("Asegúrese de que todos los departamentos tengan asignado un Jefe de Departamento.","Error",MB_OK);
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormListadoJefesDpto::FormShow(TObject *Sender)
{
        try
        {
	        TGLinkedList* lista = empresa->OrdenaListaDptos();
	        int max = lista->Length();
                CSpinEdit1->Text = IntToStr(max);
                ListView1->Clear();
	        for(int i=0; i<max; i++)
	        {
		        TDepartamento* TempDpto = (TDepartamento*)(lista->ItemInfo(i));
		        TListItem* item;
        		item = ListView1->Items->Add();
	        	item->Data = TempDpto;
		        item->Caption = TempDpto->GetJefeDepartamento()->GetNombre();
        		item->SubItems->Add(TempDpto->GetNombre());
	        	item->SubItems->Add(IntToStr(TempDpto->GetListaTrabDep()->Length()));
	        	item->SubItems->Add(FloatToStr(TempDpto->CalcularHorasAusentismo()));
	        	item->SubItems->Add(FloatToStr(TempDpto->CalcularPorcientoAusentismo())+ " %");
        	}
        }
        catch(...)
        {
                Application->MessageBoxA("Asegúrese de que todos los departamentos tengan asignado un Jefe de Departamento.","Error",MB_OK);
        }

}
//---------------------------------------------------------------------------
void __fastcall TFormListadoJefesDpto::Button1Click(TObject *Sender)
{
        try
        {
	        TGLinkedList* lista = empresa->OrdenaListaDptos();
	        int max = lista->Length();
                CSpinEdit1->Text = IntToStr(max);
                ListView1->Clear();
	        for(int i=0; i<max; i++)
	        {
		        TDepartamento* TempDpto = (TDepartamento*)(lista->ItemInfo(i));
		        TListItem* item;
        		item = ListView1->Items->Add();
	        	item->Data = TempDpto;
		        item->Caption = TempDpto->GetJefeDepartamento()->GetNombre();
        		item->SubItems->Add(TempDpto->GetNombre());
	        	item->SubItems->Add(IntToStr(TempDpto->GetListaTrabDep()->Length()));
	        	item->SubItems->Add(FloatToStr(TempDpto->CalcularHorasAusentismo()));
	        	item->SubItems->Add(FloatToStr(TempDpto->CalcularPorcientoAusentismo())+ " %");
        	}
        }
        catch(...)
        {
                Application->MessageBoxA("Asegúrese de que todos los departamentos tengan asignado un Jefe de Departamento.","Error",MB_OK);
        }

}
//---------------------------------------------------------------------------

