//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "uGlobal.h"
#include "uFormPrncipal.h"
#include "uFormRegistroEmp.h"
#include "uFormAltasMovimientos.h"
#include "uFormEstadoPlantilla.h"
#include "uFondoSalario.h"
#include "uFormAcercaDe.h"
#include "uFormConfigurar.h"
#include "uFormPlazasMenosOcupadas.h"
#include "uFormListadoNomina.h"
#include "FormBajasModificaciones.h"
#include "uFormIncidencias.h"
#include "uFormModificarRegistros.h"
#include "uFormEliminarRegistros.h"
#include "uFormVerDepartamentos.h"
#include "uFormVerCargos.h"
#include "uFormVerTrabajadores.h"
#include "uFormVerEmpresa.h"
#include "uFormListadoJefesDpto.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TFormPrincipal *FormPrincipal;
//---------------------------------------------------------------------------
__fastcall TFormPrincipal::TFormPrincipal(TComponent* Owner)
: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormPrincipal::Salir1Click(TObject *Sender)
{
	FormPrincipal->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormPrincipal::Timer1Timer(TObject *Sender)
{
	StatusBar1->Panels->Items[1]->Text = Now().TimeString();
}
//---------------------------------------------------------------------------
void __fastcall TFormPrincipal::FormClose(TObject *Sender,
										  TCloseAction &Action)
{
	if(!ControlFile->GetGuardado())
	{
		AnsiString NombFichEmp = ControlFile->GetNombreFichEmp();
		if(MessageDlg("¿Desea guardar los cambios efectuados en " + NombFichEmp + " antes de Salir?" , mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
		{
			ControlFile->GuardarFicheros();
			Action = caFree;
		}
		else
			Action = caFree;
	}

	if(TrayIcon1->Visible)
	{
		TrayIcon1->Visible = false;
		Update();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormPrincipal::FormShow(TObject *Sender)
{
	AnsiString name = "";
	if(InputQuery("Entre el nombre de la Empresa","Nombre de la Empresa:",name))
	{
		if(Trim(name) != "")
		{
			empresa = new TEmpresa(name);
			ControlFile = new TControlFile();
			FormPrincipal->Caption = (empresa->GetNombre()) +" - Departamento de Recursos Humanos";
			TrayIcon1->Visible = FormConfigurar->chboxVisibleCheck->Checked;
			if(ControlFile->GetFiheroCargo()->FileExists() && ControlFile->GetFiheroTrab()->FileExists() && ControlFile->GetFiheroDpto()->FileExists())
			{
				ControlFile->AbrirFicheros();
			}
			StatusBar1->Panels->Items[0]->Text = "Bienvenido...";
		}
		else
		{
			Application->MessageBoxA("Para iniciar la aplicación, deberá entrar el nombre de la empresa.","Administración",MB_OK);
			FormShow(this);
		}
	}
	else
		Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::RegistroEmpresa1Click(TObject *Sender)
{
	FormRegEmpresa->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TFormPrincipal::Empresa1Click(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "Para obtener Ayuda, haga clic en Temas de Ayuda en el menú Ayuda.";
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Trabajadores1Click(TObject *Sender)
{
	FormAltasYMov->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::EstadodelaPlantilla1Click(TObject *Sender)
{
	FormEstadoPlantilla->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::FondodeSalario1Click(TObject *Sender)
{
	FormFondoSalario->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Acercade1Click(TObject *Sender)
{
	FormAcercaDe->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Configurar1Click(TObject *Sender)
{
	FormConfigurar->ShowModal();        
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Restaurar1Click(TObject *Sender)
{
	TrayIcon1->Restore();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Salir2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::PlazasMenosCubiertas1Click(TObject *Sender)
{
	FormPlazasMenosCubiertas->ShowModal();              
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Archivo1Click(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "Para obtener Ayuda, haga clic en Temas de Ayuda en el menú Ayuda.";
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Plantilla1Click(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "Para obtener Ayuda, haga clic en Temas de Ayuda en el menú Ayuda.";
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Reportes1Click(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = "Para obtener Ayuda, haga clic en Temas de Ayuda en el menú Ayuda.";
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Abrir1Click(TObject *Sender)
{
	if(!ControlFile->GetGuardado())
	{
		AnsiString NombFichEmp = ControlFile->GetNombreFichEmp();
		if(MessageDlg("¿Desea guardar los cambios efectuados en " + NombFichEmp + "?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
		{
			ControlFile->GuardarFicheros();
		}
		else
			Action = caNone;
	}
	if(OpenDialog1->Execute())
	{
		AnsiString Direccion = OpenDialog1->FileName;
		Direccion.Delete(Direccion.Length()- 2,3);

		AnsiString CrgNameFile = Direccion + "crg";
		AnsiString TrbNameFile = Direccion + "trb";
		AnsiString EmpNameFile = Direccion + "drh";


		AnsiString name= empresa->GetNombre();
		delete empresa;
		empresa= new TEmpresa(name);
		delete ControlFile;
		ControlFile = new TControlFile(CrgNameFile,TrbNameFile,EmpNameFile);
		ControlFile->AbrirFicheros();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Guardar1Click(TObject *Sender)
{
	try
	{
		ControlFile->GuardarFicheros();
	}
	catch(...)
	{
		SaveDialog1->Options.Clear();
		SaveDialog1->Filter = "Archivo DRH(*.drh)|*.drh";
		if(SaveDialog1->Execute())
		{

			AnsiString Direccion = SaveDialog1->FileName;
			Direccion.Delete(Direccion.Length()- 2,3);
			AnsiString CrgNameFile = Direccion + "crg";
			AnsiString TrbNameFile = Direccion + "trb";
			AnsiString EmpNameFile = Direccion + "drh";
			ControlFile = new TControlFile(CrgNameFile,TrbNameFile,EmpNameFile);
			ControlFile->GuardarFicheros();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::GuardarComo1Click(TObject *Sender)
{
	SaveDialog1->Options.Clear();
	SaveDialog1->Filter="Archivo DRH(*.drh)|*.drh";
	if(SaveDialog1->Execute())
	{
		AnsiString Direccion = SaveDialog1->FileName;
		Direccion.Delete(Direccion.Length()- 2,3);

		AnsiString CrgNameFile = Direccion + "crg";
		AnsiString TrbNameFile = Direccion + "trb";
		AnsiString EmpNameFile = Direccion + "drh";
		ControlFile = new TControlFile(CrgNameFile,TrbNameFile,EmpNameFile);
		ControlFile->GuardarFicheros();
	}

}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::ListadodelaNmina1Click(TObject *Sender)
{
	FormListadoNomina->ShowModal();        
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Bajas1Click(TObject *Sender)
{
	FormBajasModific->ShowModal();        
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::IncidenciasLaborales1Click(TObject *Sender)
{
	FormIncidencias->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TFormPrincipal::Nuevo1Click(TObject *Sender)
{
	if(!ControlFile->GetGuardado())
	{
		AnsiString NombFichEmp = ControlFile->GetNombreFichEmp();
		if(MessageDlg("¿Desea guardar los cambios efectuados en " + NombFichEmp + "?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
		{
			ControlFile->GuardarFicheros();
		}
		else
			Action = caNone;
	}
	SaveDialog1->Options.Clear();
	SaveDialog1->Filter="Archivo DRH(*.drh)|*.drh";
	if(SaveDialog1->Execute())
	{
		AnsiString Direccion = SaveDialog1->FileName;
		Direccion.Delete(Direccion.Length()- 2,3);

		AnsiString CrgNameFile = Direccion + "crg";
		AnsiString TrbNameFile = Direccion + "trb";
		AnsiString EmpNameFile = Direccion + "drh";
		delete ControlFile;
		ControlFile = new TControlFile(CrgNameFile,TrbNameFile,EmpNameFile);
		AnsiString name= empresa->GetNombre();
		delete empresa;
		empresa= new TEmpresa(name);
		ControlFile->GuardarFicheros();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Modificarregistros1Click(TObject *Sender)
{
	FormModificarRegistros->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Eliminar1Click(TObject *Sender)
{
	FormEliminarRegistros->ShowModal();        
}
//---------------------------------------------------------------------------


void __fastcall TFormPrincipal::ExportarDBF1Click(TObject *Sender)
{
	SaveDialog1->Options.Clear();
	SaveDialog1->Filter="Archivo DBF(*.dbf)|*.dbf";
	if(SaveDialog1->Execute())
	{
		AnsiString FileName = SaveDialog1->FileName;
		ControlFile->GenerarArchivoDBF(FileName);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Acercade2Click(TObject *Sender)
{
	Acercade1Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::CargosdelaEmpresa1Click(TObject *Sender)
{
	FormVerCargos->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::TrabajadoresdelaEmpresa1Click(
	TObject *Sender)
{
	FormVerTrabajadores->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::DepartamentosdelaEmpresa1Click(
	TObject *Sender)
{
	FormVerDepartamentos->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::DatosdelaEmpresa1Click(TObject *Sender)
{
	FormVerEmpresa->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::ListadodeJefesdeDepartamento1Click(
      TObject *Sender)
{
FormListadoJefesDpto->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::TemasdeAyuda1Click(TObject *Sender)
{
 Application->HelpSystem->ShowHelp("F1",".\\Ayuda\\AyudaGRH.hlp");
 Application->HelpSystem->ShowTableOfContents();
}
//---------------------------------------------------------------------------

