//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFormListadoNomina.h"
#include "uGlobal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormListadoNomina *FormListadoNomina;
//---------------------------------------------------------------------------
__fastcall TFormListadoNomina::TFormListadoNomina(TComponent* Owner)
: TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TFormListadoNomina::Button1Click(TObject *Sender)
{
        FormListadoNomina->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormListadoNomina::FormShow(TObject *Sender)
{
        ListView1->Clear();
        TGLinkedList* MyList = empresa->NominaDeTrabajadores();
        int max = MyList->Length();
		for(int i=0; i<max; i++)
		{
			TTrabajador* TempTrab = (TTrabajador*)(MyList->ItemInfo(i));
                        TDepartamento* TempDpto = empresa->BuscaDepartamentoTrabajador(TempTrab->GetIdW());
			TListItem* item;
			item = ListView1->Items->Add();
			item->Data = TempTrab;
			item->Caption = TempDpto->GetNombre();
			item->SubItems->Add((TempTrab->GetCargo())->GetNombre());
			item->SubItems->Add(TempTrab->GetIdW());
			item->SubItems->Add(TempTrab->GetNombre());
                        item->SubItems->Add(FloatToStr(TempTrab->GetHorasExtras()));
                        item->SubItems->Add(FloatToStr(TempTrab->GetHorasAusencias()));
                        float Salario = TempTrab->GetCargo()->GetSalario();
                        if(TempTrab->GetResolucion())
                                Salario = TempTrab->GetSalarioRes();
                        item->SubItems->Add( "$ " + FloatToStr(Salario));
                        item->SubItems->Add( "$ " + FloatToStr(TempTrab->CalcularSalarioCobro()));
                }
}
//---------------------------------------------------------------------------

