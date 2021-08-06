//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFormVerEmpresa.h"
#include "uGlobal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormVerEmpresa *FormVerEmpresa;
//---------------------------------------------------------------------------
__fastcall TFormVerEmpresa::TFormVerEmpresa(TComponent* Owner)
: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormVerEmpresa::FormShow(TObject *Sender)
{
	try
	{
		StaticText8->Caption=empresa->GetNombre();
		StaticText9->Caption=empresa->GetListaTrabEmp()->Length();
		StaticText10->Caption=empresa->GetListaDptos()->Length();
		StaticText11->Caption=empresa->GetListaCargosEmp()->Length();
                float estado = empresa->CalcularEstadoPlantilla();
		StaticText12->Caption = FloatToStr(estado) + " %";
                float salApr = empresa->FondoSalarioAprobado();
		StaticText13->Caption= "$ " + FloatToStr(salApr);
                float salReal = empresa->FondoSalarioReal();
		StaticText14->Caption = "$ " + FloatToStr(salReal);
	}
	catch(...)
	{
         StaticText12->Caption = "0 %";
         StaticText13->Caption = "$ 0.00";
	 StaticText14->Caption = "$ 0.00";
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormVerEmpresa::btnClick(TObject *Sender)
{
	FormVerEmpresa->Close();
}
//---------------------------------------------------------------------------
