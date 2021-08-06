//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "uFormEstadoPlantilla.h"
#include "uGlobal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEstadoPlantilla *FormEstadoPlantilla;
//---------------------------------------------------------------------------
__fastcall TFormEstadoPlantilla::TFormEstadoPlantilla(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormEstadoPlantilla::RadioGroup1Click(TObject *Sender)
{
 float estadoCargo;
 AnsiString porciento;
 AnsiString porciento1;

 if(RadioGroup1->ItemIndex == 0)
  {
   ListView1->Clear();
   Label1->Visible = false;
   ComboBox1->Visible = false;
   Panel1->Visible = true;
   try
    {
     porciento1 = empresa->CalcularEstadoPlantilla();
     StaticText2->Caption = porciento1 + " %";
    }
   catch(...)
    {
     Application->MessageBoxA("No existen plazas aprobadas en la empresa.","Información",MB_OK);
     return;
    }
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
       try
       {
        porciento = FloatToStr(TempCargo->EstadoCargo())+ " %";
        item->SubItems->Add(porciento);
       }
       catch(...)
       {
        item->SubItems->Add("0 %");
       }
    }
  }
 else
  {
   Label1->Visible = true;
   ComboBox1->Clear();
   ComboBox1->Visible = true;
   Panel1->Visible = true;
   StaticText2->Caption = "";
   ListView1->Clear();

   TGLinkedList* TempList = empresa->GetListaDptos();
   int i = TempList->Length();
   for(int j=0; j<i; j++)
   {
    TDepartamento* tempDpto = (TDepartamento*)TempList->ItemInfo(j);
    ComboBox1->AddItem(tempDpto->GetNombre(),(TObject*)tempDpto);
   }
 }
}
//---------------------------------------------------------------------------

void __fastcall TFormEstadoPlantilla::ComboBox1Change(TObject *Sender)
{
 try
 {
  ListView1->Clear();
  float result;
  AnsiString porciento;
  AnsiString porciento1;
  TDepartamento* tempDpto = (TDepartamento*)(ComboBox1->Items->Objects[ComboBox1->ItemIndex]);
  porciento1 = tempDpto->CalcularEstadoPlantilla();
  StaticText2->Caption = porciento1 + " %";

  TGLinkedList* TempList = tempDpto->GetListaCargos();
  int i = TempList->Length();
  for(int j=0; j<i; j++)
  {
   TCargo* tempCargo = (TCargo*)TempList->ItemInfo(j);
   TListItem* item;
   item = ListView1->Items->Add();
   item->Data = tempCargo;
   item->Caption = tempCargo->GetNombre();
   item->SubItems->Add(IntToStr(tempCargo->GetPlazasApr()));
   item->SubItems->Add(IntToStr(tempCargo->GetPlazasReales()));
   result = tempCargo->EstadoCargo();
   porciento = FloatToStr(result)+ " %";
   item->SubItems->Add(porciento);
  }
 }
 catch(...)
 {
  Application->MessageBoxA("Este departamento no posee cargos","Información",MB_OK);
 }
}
//---------------------------------------------------------------------------

void __fastcall TFormEstadoPlantilla::FormShow(TObject *Sender)
{
 RadioGroup1->ItemIndex = -1;
 ListView1->Clear();
 ComboBox1->Visible = false;
 Panel1->Visible = false;
 Label1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormEstadoPlantilla::btnCerrarClick(TObject *Sender)
{
 FormEstadoPlantilla->Close();
}
//---------------------------------------------------------------------------

