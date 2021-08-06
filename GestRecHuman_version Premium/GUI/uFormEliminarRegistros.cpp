//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFormEliminarRegistros.h"
#include "uGlobal.h"
#include "uFormRegistroEmp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEliminarRegistros *FormEliminarRegistros;
//---------------------------------------------------------------------------
__fastcall TFormEliminarRegistros::TFormEliminarRegistros(TComponent* Owner)
: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormEliminarRegistros::FormShow(TObject *Sender)
{
	RadioGroup1->ItemIndex = -1;
	PageControl1->ActivePageIndex = 0;

	btnEliminar->Enabled = false;
	btnEliminarDep->Enabled = false;
	Label1->Visible = false;
	ComboBox1->Visible = false;
	Label2->Visible = false;
	ListView1->Visible = false;
	Label4->Visible = false;
	ListView3->Visible = false;
	ComboBox1->Clear();
	ListView1->Clear();
	ListView3->Clear();
	ListView2->Clear();

	TGLinkedList* ListaDptos = empresa->GetListaDptos();
	int length = ListaDptos->Length();
	for(int i=0; i<length; i++)
	{
		TDepartamento* tempDpto = (TDepartamento*)ListaDptos->ItemInfo(i);
		TListItem* item;
		item = ListView2->Items->Add();
		item->Data = tempDpto;
		item->Caption = tempDpto->GetNombre();
		item->SubItems->Add(tempDpto->GetCodigo());
		if(tempDpto->GetJefeDepartamento())
			item->SubItems->Add((tempDpto->GetJefeDepartamento())->GetNombre());
		else
			item->SubItems->Add("No posee");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormEliminarRegistros::RadioGroup1Click(TObject *Sender)
{
	if(RadioGroup1->ItemIndex == 0)
	{
		ListView1->ItemIndex = -1;
		Label2->Visible = false;
		ListView1->Visible = false;
		Label1->Visible = false;
		ComboBox1->Visible = false;
		Label4->Visible = true;
		ListView3->Visible = true;
		ListView3->Clear();
		btnEliminar->Enabled = false;

		TGLinkedList* ListCargos = empresa->GetListaCargosEmp();
		int length = ListCargos->Length();
		for(int i=0; i<length; i++)
		{
			TCargo* TempCargo = (TCargo*)ListCargos->ItemInfo(i);
			TListItem* item;
			item = ListView3->Items->Add();
			item->Data = TempCargo;
			item->Caption = TempCargo->GetNombre();
			item->SubItems->Add("$ " + FloatToStr(TempCargo->GetSalario()));
		}
	}
	else
	{
		ListView3->ItemIndex = -1;
		Label4->Visible = false;
		ListView3->Visible = false;
		Label1->Visible = true;
		ComboBox1->Visible = true;
		Label2->Visible = true;
		ListView1->Visible = true;
		ComboBox1->Clear();
		ListView1->Clear();
		btnEliminar->Enabled = false;

		TGLinkedList* ListaDptos = empresa->GetListaDptos();
		int length = ListaDptos->Length();
		for(int i=0; i<length; i++)
		{
			TDepartamento* TempDpto = (TDepartamento*)ListaDptos->ItemInfo(i);
			ComboBox1->AddItem(TempDpto->GetNombre(),(TObject*)TempDpto);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormEliminarRegistros::ComboBox1Change(TObject *Sender)
{
	ListView1->Clear();
	TDepartamento* tempDpto = (TDepartamento*)ComboBox1->Items->Objects[ComboBox1->ItemIndex];
	TGLinkedList* ListCargos = tempDpto->GetListaCargos();
	int length = ListCargos->Length();
	for(int i=0; i<length; i++)
	{
		TCargo* tempCargo = (TCargo*)ListCargos->ItemInfo(i);
		TListItem* item;
		item = ListView1->Items->Add();
		item->Data = tempCargo;
		item->Caption = tempCargo->GetNombre();
		item->SubItems->Add("$ " + FloatToStr(tempCargo->GetSalario()));
		item->SubItems->Add(IntToStr(tempCargo->GetPlazasApr()));
		item->SubItems->Add(IntToStr(tempCargo->GetPlazasReales()));
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormEliminarRegistros::btnEliminarClick(TObject *Sender)
{
	TCargo* tempCargo;
	bool cambio = false;
	if(ListView3->Selected)
	{
		if(MessageDlg("¿Está seguro que desea eliminar este cargo de la empresa?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
		{
			tempCargo = (TCargo*)ListView3->Selected->Data;
			empresa->EliminarCargo(tempCargo);
			ListView3->Items->Delete(ListView3->ItemIndex);

			//habilitar Button y Edit en Adicionar Cargo Jefe de Departamento
			if(tempCargo->GetNombre()== "Jefe de Departamento")
			{
				FormRegEmpresa->Edit10->Enabled = true;
				FormRegEmpresa->Edit10->Color = clWindow;
				FormRegEmpresa->btnCargoJefeDpto->Enabled = true;
			}
			cambio = true;
		}
		else
			Action = caNone;
	}
	else
	{
		if(ListView1->Selected)
		{
			if(MessageDlg("¿Está seguro que desea eliminar este cargo del departamento?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
			{
				tempCargo = (TCargo*)ListView1->Selected->Data;
				TDepartamento* tempDpto = (TDepartamento*)ComboBox1->Items->Objects[ComboBox1->ItemIndex];
				tempDpto->EliminarCargo(tempCargo);
				ListView1->Items->Delete(ListView1->ItemIndex);
				cambio = true;
			}
			else
				Action = caNone;
		}
		else
		{
			Application->MessageBoxA("Debe seleccionar el cargo que desea eliminar","Información",MB_OK);
			return;
		}
	}

	if(cambio)
	{
		ControlFile->SetGuardado(false);
	}
	ListView3->ItemIndex = -1;
	btnEliminar->Enabled = false;
}

//---------------------------------------------------------------------------

void __fastcall TFormEliminarRegistros::btnEliminarDepClick(
	TObject *Sender)
{
	if(ListView2->Selected)
	{
		if(MessageDlg("¿Está seguro que desea eliminar este departamento de la empresa?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
		{
			TDepartamento* tempDpto = (TDepartamento*)ListView2->Selected->Data;
			empresa->EliminarDepartamento(tempDpto);

			ListView2->Items->Delete(ListView2->ItemIndex);

			ControlFile->SetGuardado(false);

			ListView2->ItemIndex = -1;
			btnEliminarDep->Enabled = false;
		}
		else
			Action = caNone;
	}
	else
		Application->MessageBoxA("Debe seleccionar el departamento que desea eliminar","Información",MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TFormEliminarRegistros::ListView3SelectItem(
	TObject *Sender, TListItem *Item, bool Selected)
{
	btnEliminar->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormEliminarRegistros::ListView1SelectItem(
	TObject *Sender, TListItem *Item, bool Selected)
{
	btnEliminar->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormEliminarRegistros::btnCancelarClick(TObject *Sender)
{
	RadioGroup1->ItemIndex = -1;

	Label1->Visible = false;
	ComboBox1->Visible = false;
	Label2->Visible = false;
	ListView1->Visible = false;
	Label4->Visible = false;
	ListView3->Visible = false;
	ComboBox1->Clear();
	ListView1->Clear();
	ListView3->Clear();

	btnEliminar->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormEliminarRegistros::btnCancelarDepClick(
	TObject *Sender)
{
	ListView2->ItemIndex = -1;
	btnEliminarDep->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormEliminarRegistros::ListView2SelectItem(
	TObject *Sender, TListItem *Item, bool Selected)
{
	btnEliminarDep->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormEliminarRegistros::btnCerrarClick(TObject *Sender)
{
	FormEliminarRegistros->Close();        
}
//---------------------------------------------------------------------------

void __fastcall TFormEliminarRegistros::TabSheet1Show(TObject *Sender)
{
	ListView1->ItemIndex = -1;
	ListView3->ItemIndex = -1;
}
//---------------------------------------------------------------------------

void __fastcall TFormEliminarRegistros::TabSheet2Show(TObject *Sender)
{
	ListView2->ItemIndex = -1;
}
//---------------------------------------------------------------------------

