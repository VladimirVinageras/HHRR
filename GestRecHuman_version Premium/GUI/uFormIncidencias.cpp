//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFormIncidencias.h"
#include "uGlobal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormIncidencias *FormIncidencias;
//---------------------------------------------------------------------------
__fastcall TFormIncidencias::TFormIncidencias(TComponent* Owner)
: TForm(Owner)
{
	/*try
	{
	StrToFloat("0.0");
	pt = '.';
	}
	catch(...)
	{
	pt = ',';
	}*/
}                    
//---------------------------------------------------------------------------

void __fastcall TFormIncidencias::FormShow(TObject *Sender)
{
	btnCancelar->Click();
	ComboBox1->Clear();
	TGLinkedList* TempList = empresa->GetListaDptos();
	int i = TempList->Length();                                      
	for(int j=0; j<i; j++)
	{
		TDepartamento* tempDpto = (TDepartamento*)TempList->ItemInfo(j);
		ComboBox1->AddItem(tempDpto->GetNombre(),(TObject*)tempDpto);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormIncidencias::ComboBox1Change(TObject *Sender)
{
	ListView1->Clear();
	btnAceptar->Enabled = true;
	TDepartamento* tempDpto = (TDepartamento*)(ComboBox1->Items->Objects[ComboBox1->ItemIndex]);
	TGLinkedList* TempList = tempDpto->GetListaTrabDep();
	int i = TempList->Length();
	for(int j=0; j<i; j++)
	{
		TTrabajador* tempTrab = (TTrabajador*)TempList->ItemInfo(j);
		TListItem* item;
		item = ListView1->Items->Add();
		item->Caption = tempTrab->GetNombre();
		item->SubItems->Add(tempTrab->GetIdW());
		item->Data = tempTrab;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormIncidencias::btnAceptarClick(TObject *Sender)
{
	AnsiString HExtras;
	AnsiString HAusencias;
	AnsiString DiasFeriados;
	if(ListView1->Selected)
	{
		if((Edit1->Text != "")||(Edit2->Text != "")||(Edit3->Text != ""))
		{
			if(Edit1->Text == "")
				HExtras = 0;
			else
				HExtras = Edit1->Text;
			if(Edit2->Text == "")
				HAusencias = 0;
			else
				HAusencias = Edit2->Text;
			if(Edit3->Text == "")
				DiasFeriados = 0;
			else
				DiasFeriados = Edit3->Text;

			TTrabajador* TempTrab = (TTrabajador*)ListView1->Selected->Data;
			TempTrab->SetHorasExtras((StrToFloat(HExtras)+(StrToFloat(DiasFeriados)*16)));
			TempTrab->SetHorasAusencias(StrToFloat(HAusencias));

			bool Estado = false;
			ControlFile->SetGuardado(Estado);
		}
		else
		{
			Application->MessageBox(LPWSTR("Debe indicar al menos una incidencia"),LPWSTR("Información"),(MB_OK));
			Edit1->SetFocus();
			return;
		}
	}
	else
	{
		   Application->MessageBox(LPWSTR("Debe seleccionar el trabajador"),LPWSTR("Informacion"),MB_OK);
		return;
	}

	Edit1->Clear();
	Edit2->Clear();
	Edit3->Clear();
        ListView1->Clear();
        ComboBox1->Text="";
	btnAceptar->Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TFormIncidencias::btnCancelarClick(TObject *Sender)
{
	Edit1->Clear();
	Edit2->Clear();
	Edit3->Clear();
	ComboBox1->ItemIndex = -1;
	ListView1->Clear();
	btnAceptar->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormIncidencias::btnCerrarClick(TObject *Sender)
{
	FormIncidencias->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormIncidencias::Edit1KeyPress(TObject *Sender, char &Key)
{
	if ((Key != '\b')&&(Key != pt)&&((Key < '0')||(Key > '9')))
		Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormIncidencias::Edit2KeyPress(TObject *Sender, char &Key)
{
	if ((Key != '\b')&&(Key != pt)&&((Key < '0')||(Key > '9')))
		Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormIncidencias::Edit3KeyPress(TObject *Sender, char &Key)
{
	if ((Key != '\b')&&((Key< '0')||(Key > '9')))
		Key = 0;    
}
//---------------------------------------------------------------------------

