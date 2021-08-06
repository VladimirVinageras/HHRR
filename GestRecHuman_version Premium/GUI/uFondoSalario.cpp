//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFondoSalario.h"
#include "uGlobal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormFondoSalario *FormFondoSalario;
AnsiString simboloPeso = "$ ";
//---------------------------------------------------------------------------
__fastcall TFormFondoSalario::TFormFondoSalario(TComponent* Owner)
: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormFondoSalario::RadioGroup1Click(TObject *Sender)
{
	if(RadioGroup1->ItemIndex == 0)
	{
		Label1->Visible = false;                         
		ComboBox1->Visible = false;
		StaticText2->Caption = simboloPeso + (empresa->FondoSalarioAprobado());
		StaticText4->Caption = simboloPeso + (empresa->FondoSalarioReal());
	}
	else
	{                                     
		ComboBox1->Clear();
		Label1->Visible = true;
		ComboBox1->Visible = true;
		StaticText2->Caption = "";
		StaticText4->Caption = "";

		TGLinkedList* ListDptosTemp = ((TGLinkedList*)empresa->GetListaDptos());
		int length = ListDptosTemp->Length();
		for(int i=0; i<length; i++)
		{
			TCargo* dptoTemp = (TCargo*)ListDptosTemp->ItemInfo(i);
			ComboBox1->AddItem(dptoTemp->GetNombre(),(TObject*)dptoTemp);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormFondoSalario::FormShow(TObject *Sender)
{
	RadioGroup1->ItemIndex = -1;
	Label1->Visible = false;
	ComboBox1->Visible = false;
	StaticText2->Caption = "";
	StaticText4->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TFormFondoSalario::btnCerrarClick(TObject *Sender)
{
	FormFondoSalario->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormFondoSalario::ComboBox1Change(TObject *Sender)
{
	TDepartamento* dpto = (TDepartamento*)ComboBox1->Items->Objects[ComboBox1->ItemIndex];
	StaticText2->Caption = simboloPeso + (dpto->FondoSalarioAprobadoDpto());
	StaticText4->Caption = simboloPeso + (dpto->FondoSalarioRealDpto());
}
//---------------------------------------------------------------------------

