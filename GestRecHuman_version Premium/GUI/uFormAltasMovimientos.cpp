//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFormAltasMovimientos.h"
#include "uGlobal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAltasYMov *FormAltasYMov;
//---------------------------------------------------------------------------
__fastcall TFormAltasYMov::TFormAltasYMov(TComponent* Owner)
: TForm(Owner)
{/*
 try
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

void __fastcall TFormAltasYMov::ComboBox1Change(TObject *Sender)
{
	ListView1->Clear();
	ComboBox5->Clear();
	ComboBox5->Enabled = true;
	CheckBox1->Checked = false;
	Edit10->Clear();
	Edit10->Color = clBtnFace;
	Edit10->Enabled = false;
	ListView1->Height = 177;
	Label2->Visible = false;

	TDepartamento* dpto = (TDepartamento*)(ComboBox1->Items->Objects[ComboBox1->ItemIndex]);
	TGLinkedList* listaCargos = dpto->GetListaCargos();
	int max = listaCargos->Length();
	for(int i = 0; i < max; i++)
	{
		TCargo* TempCargo = (TCargo*)(listaCargos->ItemInfo(i));
		if((TempCargo->PlazasDisponibles())>0)
			ComboBox5->AddItem(TempCargo->GetNombre(),(TObject*)TempCargo);
		TListItem* item;
		item = ListView1->Items->Add();
		item->Caption = TempCargo->GetNombre();
		item->Data = TempCargo;
		item->SubItems->Add(IntToStr(TempCargo->PlazasDisponibles()));
	}
	int cant = ComboBox5->Items->Count;

	if(cant == 0 && max != 0)
	{
		ListView1->Height = 163;
		Label2->Visible = true;
		ComboBox5->Enabled = false;
		return;
	}
	btnAceptarAlta->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormAltasYMov::btnAceptarAltaClick(TObject *Sender)
{
	bool resolucion;
	float salarioRes;
	if((ComboBox4->ItemIndex != -1)&&(ComboBox5->ItemIndex != -1))
	{
		try
		{
			if((CheckBox1->Checked)&&(Edit10->Text == "")||(Edit10->Text == "0"))
			{
				Application->MessageBoxA("Debe especificar un salario por resolución.","Información",MB_OK);
				Edit10->SetFocus();
				return;
			}
			else
			{
				if(CheckBox1->Checked)
				{
					resolucion = true;
					salarioRes = StrToFloat(Edit10->Text);
				}
				else
				{
					resolucion = false;
					salarioRes = 0;
				}
			}
			TDepartamento* dpto = (TDepartamento*)(ComboBox1->Items->Objects[ComboBox1->ItemIndex]);
			TTrabajador* trab = (TTrabajador*)(ComboBox4->Items->Objects[ComboBox4->ItemIndex]);
			TCargo* cargoDpto = (TCargo*)(ComboBox5->Items->Objects[ComboBox5->ItemIndex]);

			//validacion de Jefe de Departamento
			if(cargoDpto->GetNombre() == "Jefe de Departamento")
			{
				TTrabajador* JefeDpto = empresa->BuscarTrabajadorID(trab->GetIdW());
				dpto->SetJefeDepartamento(JefeDpto);
			}
			cargoDpto->IncPlazasReales();
			TCargo* cargoEmp = (TCargo*)(empresa->BuscarCargo(cargoDpto->GetNombre()));
			cargoEmp->IncPlazasReales();
			trab->SetCargo(cargoDpto);
			trab->SetResolucion(resolucion);
			trab->SetSalarioRes(salarioRes);
			trab->SetAltaTrue();
			dpto->AdicionarTrab(trab);

			bool Estado = false;
			ControlFile->SetGuardado(Estado);
		}
		catch(...)
		{
			Application->MessageBoxA("Escriba correctamente el salario.","Error",MB_OK);
			Edit10->Clear();
			Edit10->SetFocus();
			return;
		}
	}
	else
	{
		Application->MessageBoxA("Debe seleccionar el trabajador y el cargo a ocupar.","Información",MB_OK);
		return;
	}
	int Item = ComboBox4->ItemIndex;
	ComboBox1->ItemIndex = -1;
	ComboBox4->ItemIndex = -1;
	ComboBox4->Items->Delete(Item);
	ComboBox5->ItemIndex = -1;
	ComboBox5->Clear();
	CheckBox1->Checked = false;
	Edit10->Clear();
	Edit10->Color = clBtnFace;
	Edit10->Enabled = false;
	ListView1->Clear();
	btnAceptarAlta->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormAltasYMov::bitbtnBuscarTrabClick(TObject *Sender)
{
	TTrabajador* TrabFound;
	if(Edit2->Text != "")
	{
		try
		{
			TrabFound = empresa->BuscarTrabajadorID(Edit2->Text);
			StaticText2->Caption = TrabFound->GetNombre();
		}
		catch(...)
		{
			Application->MessageBoxA("No se obtuvieron resultados en la búsqueda, verifique el número de identidad.","Error",MB_OK);
			return;
		}
		try
		{
			TDepartamento* dpto = empresa->BuscaDepartamentoTrabajador(Edit2->Text);
			StaticText4->Caption = dpto->GetNombre();
		}
		catch(...)
		{
			Application->MessageBoxA("Debe darle alta al trabajador, antes de moverlo a otra plaza.","Error",MB_OK);
			return;
		}
		TCargo* cargo = TrabFound->GetCargo();
		StaticText5->Caption = cargo->GetNombre();

		ComboBox2->Enabled = true;
		btnAceptarMover->Enabled = true;
		bitbtnBuscarTrab->Enabled = false;
	}
	else
		Application->MessageBoxA("Debe introducir el número de identidad del trabajador que desea buscar.","Información",MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TFormAltasYMov::ComboBox2Change(TObject *Sender)
{
	ListView2->Clear();
	ComboBox3->Enabled = true;
	ComboBox3->Clear();
	ListView2->Height = 177;
	Label5->Visible = false;

	TDepartamento* dpto = (TDepartamento*)(ComboBox2->Items->Objects[ComboBox2->ItemIndex]);
	TGLinkedList* listaCargos = dpto->GetListaCargos();
	int max = listaCargos->Length();
	for(int i = 0; i < max; i++)
	{
		TCargo* TempCargo = (TCargo*)(listaCargos->ItemInfo(i));
		if((TempCargo->PlazasDisponibles())>0)
			ComboBox3->AddItem(TempCargo->GetNombre(),(TObject*)TempCargo);
		TListItem* item;
		item = ListView2->Items->Add();
		item->Caption = TempCargo->GetNombre();
		item->Data = TempCargo;
		item->SubItems->Add(IntToStr(TempCargo->PlazasDisponibles()));
	}
	int cant = ComboBox3->Items->Count;
	if(cant == 0)
	{
		ListView2->Height = 163;
		Label5->Visible = true;
		ComboBox3->Enabled = false;
		btnAceptarMover->Enabled = false;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormAltasYMov::btnAceptarMoverClick(TObject *Sender)
{
	if((ComboBox2->ItemIndex != -1)&&(ComboBox3->ItemIndex != -1))
	{
		TTrabajador* trab = empresa->BuscarTrabajadorID(Edit2->Text);
		TDepartamento* dptoActual = empresa->BuscaDepartamentoTrabajador(Edit2->Text);
		TDepartamento* dptoDestino = (TDepartamento*)(ComboBox2->Items->Objects[ComboBox2->ItemIndex]);
		TCargo* cargoDestino = (TCargo*)(ComboBox3->Items->Objects[ComboBox3->ItemIndex]);

		((TCargo*)trab->GetCargo())->DecPlazasReales(); // dpto cargoActual
		AnsiString nombre =(trab->GetCargo())->GetNombre();
		((TCargo*)(empresa->BuscarCargo(nombre)))->DecPlazasReales(); //empresa cargoActual
		dptoActual->EliminarTrabajador(trab->GetIdW());

		trab->SetCargo(cargoDestino);
		dptoDestino->AdicionarTrab(trab);
		((TCargo*)trab->GetCargo())->IncPlazasReales(); //dpto cargoDestino
		nombre =(trab->GetCargo())->GetNombre();
		((TCargo*)(empresa->BuscarCargo(nombre)))->IncPlazasReales(); //empresa cargoDestino

		bool Estado = false;
		ControlFile->SetGuardado(Estado);
	}
	else
	{
		Application->MessageBoxA("Debe seleccionar el departamento de destino y el cargo a ocupar.","Información",MB_OK);
		return;
	}
	Edit2->Clear();
	Edit2->SetFocus();
	bitbtnBuscarTrab->Enabled = true;
	ComboBox2->ItemIndex = -1;
	ComboBox3->ItemIndex = -1;
	ComboBox3->Clear();
	ComboBox2->Enabled = false;
	ComboBox3->Enabled = false;
	ListView2->Clear();
	StaticText2->Caption = "";
	StaticText4->Caption = "";
	StaticText5->Caption = "";
	btnAceptarMover->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TFormAltasYMov::FormShow(TObject *Sender)
{
	PageControl1->ActivePageIndex = 0;
	ComboBox4->Clear(); //Trab
	ComboBox1->Clear(); //Dpto
	ComboBox2->Clear(); //Dpto
	ComboBox5->Clear();
	ComboBox3->Clear();
	ComboBox5->Enabled = true;
	ListView1->Clear();
	ListView2->Clear();
	CheckBox1->Checked = false;
	Edit10->Clear();
	Edit10->Color = clBtnFace;
	Edit10->Enabled = false;
	ListView1->Height = 177;
	Label2->Visible = false;
	ListView2->Height = 177;
	Label5->Visible = false;
	ComboBox3->Enabled = false;

	//llenar el ComboBox4 con los Trab que no se les a dado Alta
	TGLinkedList* ListTrabEmp = empresa->GetListaTrabEmp();
	int length = ListTrabEmp->Length();
	for(int i=0; i<length; i++)
	{
		TTrabajador* tempTrab = (TTrabajador*)(ListTrabEmp->ItemInfo(i));
		if(!(tempTrab->GetAlta()))
			ComboBox4->AddItem(tempTrab->GetNombre(),(TObject*)tempTrab);
	}
	//llenar los ComboBox1 y ComboBox2 Dptos
	TGLinkedList* ListaDeptos = empresa->GetListaDptos();
	int length1 = ListaDeptos->Length();
	for(int i=0; i<length1; i++)
	{
		TDepartamento* tempDpto = (TDepartamento*)(ListaDeptos->ItemInfo(i));
		ComboBox1->AddItem(tempDpto->GetNombre(),(TObject*)tempDpto);
		ComboBox2->AddItem(tempDpto->GetNombre(),(TObject*)tempDpto);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormAltasYMov::btnCerrarClick(TObject *Sender)
{
	FormAltasYMov->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormAltasYMov::Edit2KeyPress(TObject *Sender, char &Key)
{
	if ((Key != '\b')&&((Key< '0')||(Key > '9')))
		Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormAltasYMov::btnCancelarMoverClick(TObject *Sender)
{
	Edit2->Clear();
	Edit2->SetFocus();
	bitbtnBuscarTrab->Enabled = true;
	ComboBox2->ItemIndex = -1;
	ComboBox3->ItemIndex = -1;
	ComboBox3->Clear();
	ComboBox2->Enabled = false;
	ComboBox3->Enabled = false;
	ListView2->Clear();
	StaticText2->Caption = "";
	StaticText4->Caption = "";
	StaticText5->Caption = "";
	ListView2->Height = 177;
	Label5->Visible = false;
	btnAceptarMover->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormAltasYMov::btnCancelarAltaClick(TObject *Sender)
{
	ComboBox1->ItemIndex = -1;
	ComboBox4->ItemIndex = -1;
	ComboBox5->ItemIndex = -1;
	ComboBox5->Enabled = true;
	ComboBox5->Clear();
	ListView1->Clear();
	CheckBox1->Checked = false;
	Edit10->Clear();
	Edit10->Color = clBtnFace;
	Edit10->Enabled = false;
	ListView1->Height = 177;
	Label2->Visible = false;
	btnAceptarAlta->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormAltasYMov::CheckBox1Click(TObject *Sender)
{
	if(CheckBox1->Checked)
	{
		Edit10->Enabled = true;
		Edit10->Color = clWindow;
		Edit10->SetFocus();
	}
	else
	{
		Edit10->Enabled = false;
		Edit10->Clear();
		Edit10->Color = clBtnFace;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormAltasYMov::Edit10KeyPress(TObject *Sender, char &Key)
{
	if ((Key != '\b')&&(Key != pt)&&((Key < '0')||(Key > '9')))
		Key = 0;        
}
//---------------------------------------------------------------------------

void __fastcall TFormAltasYMov::TabSheet2Show(TObject *Sender)
{
	Edit2->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormAltasYMov::ListView1Click(TObject *Sender)
{
	//ListView1-> ***
}
//---------------------------------------------------------------------------




