//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FormBajasModificaciones.h"
#include "uGlobal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormBajasModific *FormBajasModific;
TTrabajador* TrabFound = NULL;
TTrabajador* TrabFoundModif = NULL;
AnsiString cadena = "Direcci?n particular: ";
//---------------------------------------------------------------------------
__fastcall TFormBajasModific::TFormBajasModific(TComponent* Owner)
: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormBajasModific::bitbtnBuscarTrabClick(TObject *Sender)
{
	StaticText2->Caption = "";
	StaticText8->Caption = "";
	StaticText4->Caption = "";
	StaticText5->Caption = "";
	StaticText10->Caption = "";
	Memo1->Text = cadena;

	bool alta = true;
	if(Edit2->Text != "")
	{
		try
		{
			TrabFound = empresa->BuscarTrabajadorID(Edit2->Text);
			StaticText2->Caption = TrabFound->GetNombre();
			AnsiString telefono = TrabFound->GetTelefono();
			if(telefono == '0')
				telefono = "";
			StaticText8->Caption = telefono;
			Memo1->Text = (cadena + TrabFound->GetDirParticular());
		}
		catch(...)
		{
			Application->MessageBoxA(LPWSTR("No se obtuvieron resultados en la b?squeda, verifique el n?mero de identidad."),LPWSTR("Error"),MB_OK);
			Edit2->SetFocus();
			return;
		}
		try
		{
			TDepartamento* dpto = empresa->BuscaDepartamentoTrabajador(Edit2->Text);
			StaticText4->Caption = dpto->GetNombre();
		}
		catch(...)
		{
			Application->MessageBoxA(LPWSTR("No se ha dado alta al trabajador."),LPWSTR("Informaci?n"),MB_OK);
			alta = false;
		}
		if(alta)
		{
			TCargo* cargo = TrabFound->GetCargo();
			StaticText5->Caption = cargo->GetNombre();
			float salario;
			if(TrabFound->GetResolucion())
			{
				salario = TrabFound->GetSalarioRes();
				StaticText10->Caption = "$ " + FloatToStr(salario);
			}
			else
				StaticText10->Caption = "$ " + FloatToStr(TrabFound->GetCargo()->GetSalario());
		}
		btnEliminar->Enabled = true;
		Edit2->SetFocus();
	}
	else
		Application->MessageBoxA("Debe introducir el n?mero de identidad del trabajador que desea buscar.","Informaci?n",MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TFormBajasModific::btnEliminarClick(TObject *Sender)
{
	if(TrabFound)
	{
		if(MessageDlg("?Est? seguro que desea eliminar este trabajador de la empresa?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
		{
			empresa->EliminarTrabajador(TrabFound);
			//Application->MessageBoxA("El trabajador fue eliminado con ?xito.","Informaci?n",MB_OK);

			bool Estado = false;
			ControlFile->SetGuardado(Estado);

			TrabFound = NULL;
			btnEliminar->Enabled = false;
			Edit2->Clear();
			Edit2->SetFocus();
			StaticText2->Caption = "";
			StaticText8->Caption = "";
			StaticText4->Caption = "";
			StaticText5->Caption = "";
			StaticText10->Caption = "";
			Memo1->Text = cadena;
		}
		else
			Action = caNone;
	}
	else
	{
		Application->MessageBoxA("Debe buscar el trabajador que desea eliminar.","Informaci?n",MB_OK);
		Edit2->SetFocus();
	} 
}
//---------------------------------------------------------------------------

void __fastcall TFormBajasModific::FormShow(TObject *Sender)
{
	PageControl1->ActivePageIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormBajasModific::btnCerrarClick(TObject *Sender)
{
	FormBajasModific->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormBajasModific::Edit2KeyPress(TObject *Sender,
												 char &Key)
{
	if ((Key != '\b')&&((Key< '0')||(Key > '9')))
		Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormBajasModific::btnCancelarClick(TObject *Sender)
{
	TrabFound = NULL;
	btnEliminar->Enabled = false;
	Edit2->Clear();
	Edit2->SetFocus();
	StaticText2->Caption = "";
	StaticText8->Caption = "";
	StaticText4->Caption = "";
	StaticText5->Caption = "";
	StaticText10->Caption = "";
	Memo1->Text = cadena;
}
//---------------------------------------------------------------------------

void __fastcall TFormBajasModific::TabSheet1Show(TObject *Sender)
{
	Edit2->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormBajasModific::Edit7KeyPress(TObject *Sender,
												 char &Key)
{
	if ((Key != '\b')&&((Key< '0')||(Key > '9')))
		Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormBajasModific::TabSheet2Enter(TObject *Sender)
{
	Edit7->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormBajasModific::bitbtnBuscarTrab1Click(TObject *Sender)
{
 if(Edit7->Text != "")
 {
  try
  {
   TrabFoundModif = empresa->BuscarTrabajadorID(Edit7->Text);
   Edit3->Text = TrabFoundModif->GetNombre();
   Edit3->Enabled = true;
   Edit3->Color = clWindow;
   Edit6->Enabled = true;
   Edit6->Color = clWindow;
   AnsiString telefono = TrabFoundModif->GetTelefono();
   if(telefono == "0")
    telefono = "";
   Edit6->Text = telefono;
   Edit5->Enabled = true;
   Edit5->Color = clWindow;
   Edit5->Text = TrabFoundModif->GetDirParticular();
   if(TrabFoundModif->GetAlta())
   {
    if(TrabFoundModif->GetResolucion())
    {
     CheckBox1->Enabled = true;
     CheckBox1->Checked = true;
     Edit1->Enabled = true;
     Edit1->Color = clWindow;
     Edit1->Text = FloatToStr(TrabFoundModif->GetSalarioRes());
    }
    else                                                   
     CheckBox1->Enabled = true;
   }
   btnAceptar->Enabled = true;
   Edit3->SetFocus();
  }
  catch(...)
  {
   Application->MessageBoxA("No se obtuvieron resultados en la b?squeda, verifique el n?mero de identidad.","Error",MB_OK);
   Edit7->SetFocus();
   return;
  }
 }
 else
  Application->MessageBoxA("Debe introducir el n?mero de identidad del trabajador que desea buscar.","Informaci?n",MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TFormBajasModific::btnAceptarClick(TObject *Sender)
{
 bool resolucion;
 float salarioRes;
 AnsiString telef;
 if((Edit3->Text != "")&&(Edit5->Text != ""))
 {
  AnsiString nombre = Edit3->Text;
  AnsiString direccion = Edit5->Text;
  if(Edit6->Text != "")
   telef = Edit6->Text;
  else
    telef = "0";

  if((CheckBox1->Checked)&&(Edit1->Text == "")||(Edit1->Text == "0"))
  {
   Application->MessageBoxA("Debe especificar un salario por resoluci?n.","Informaci?n",MB_OK);
   Edit1->Clear();
   Edit1->SetFocus();
   return;
  }
  else
  {
   if(CheckBox1->Checked)
   {
    resolucion = true;
    salarioRes = StrToFloat(Edit1->Text);
   }
   else
   {
    resolucion = false;
    salarioRes = 0;
   }
  }
  TrabFoundModif->SetNombre(nombre);
  TrabFoundModif->SetDirParticular(direccion);
  TrabFoundModif->SetTelefono(telef);
  TrabFoundModif->SetResolucion(resolucion);
  TrabFoundModif->SetSalarioRes(salarioRes);

  ControlFile->SetGuardado(false);
 }
 else
  {
   Application->MessageBoxA("Aseg?rese de haber indicado almenos, Nombre y Apellidos y Direcci?n particular.","Informaci?n",MB_OK);
   Edit3->SetFocus();
   return;
  }
 btnCancelar1->Click();
}
//---------------------------------------------------------------------------
void __fastcall TFormBajasModific::btnCancelar1Click(TObject *Sender)
{
        TrabFoundModif = NULL;
        Edit7->Clear();
        Edit7->SetFocus();
        Edit3->Clear();
        Edit3->Color = clBtnFace;
        Edit3->Enabled = false;
        Edit6->Clear();
        Edit6->Color = clBtnFace;
        Edit6->Enabled = false;
        Edit5->Clear();
        Edit5->Color = clBtnFace;
        Edit5->Enabled = false;
        CheckBox1->Enabled = false;
        CheckBox1->Checked = false;
        Edit5->Clear();
        Edit1->Clear();
        Edit1->Enabled = false;
        Edit1->Color = clBtnFace;
 
 btnAceptar->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormBajasModific::Edit4KeyPress(TObject *Sender,
												 char &Key)
{
	if ((Key != '\b')&&((Key< '0')||(Key > '9')))
		Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormBajasModific::Edit6KeyPress(TObject *Sender,
												 char &Key)
{
	if ((Key != '\b')&&((Key< '0')||(Key > '9')))
		Key = 0;        
}
//---------------------------------------------------------------------------


void __fastcall TFormBajasModific::Edit1KeyPress(TObject *Sender,
      char &Key)
{
 if ((Key != '\b')&&(Key != pt)&&((Key < '0')||(Key > '9')))
		Key = 0;        
}
//---------------------------------------------------------------------------

void __fastcall TFormBajasModific::CheckBox1Click(TObject *Sender)
{
 if(CheckBox1->Checked)
 {
  Edit1->Enabled = true;
  Edit1->Color = clWindow;
  Edit1->SetFocus();
 }
 else
 {
  Edit1->Clear();
  Edit1->Enabled = false;
  Edit1->Color = clBtnFace;
 }
}
//---------------------------------------------------------------------------

