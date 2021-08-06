//---------------------------------------------------------------------------

#ifndef uFormPrncipalH
#define uFormPrncipalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include "trayicon.h"
#include <Graphics.hpp>
#include <ImgList.hpp>
#include <ActnList.hpp>
#include <StdActns.hpp>
//---------------------------------------------------------------------------
class TFormPrincipal : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TStatusBar *StatusBar1;
	TMenuItem *Empresa1;
	TMenuItem *Salir1;
	TMenuItem *Ayuda1;
	TMenuItem *TemasdeAyuda1;
	TMenuItem *N1;
	TMenuItem *Acercade1;
	TTimer *Timer1;
	TMenuItem *RegistroEmpresa1;
	TMenuItem *Plantilla1;
	TMenuItem *Trabajadores1;
	TMenuItem *EstadodelaPlantilla1;
	TMenuItem *Reportes1;
	TMenuItem *FondodeSalario1;
	TMenuItem *PlazasMenosCubiertas1;
	TMenuItem *ListadodelaNmina1;
	TMenuItem *Configurar1;
	TPopupMenu *PopupMenu1;
	TMenuItem *Restaurar1;
	TMenuItem *N3;
	TMenuItem *Salir2;
	TMenuItem *Archivo1;
	TMenuItem *Guardar1;
	TMenuItem *Abrir1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TMenuItem *N4;
	TMenuItem *GuardarComo1;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *Bajas1;
	TMenuItem *IncidenciasLaborales1;
	TTrayIcon *TrayIcon1;
	TImageList *ImageList1;
	TImage *Image1;
	TMenuItem *Nuevo1;
	TMenuItem *Modificarregistros1;
	TMenuItem *Eliminar1;
	TMenuItem *ExportarDBF1;
	TMenuItem *N2;
	TMenuItem *N7;
	TMenuItem *TemasdeAyuda2;
	TMenuItem *Acercade2;
	TMenuItem *N8;
	TMenuItem *Mover1;
	TMenuItem *Ver1;
	TMenuItem *CargosdelaEmpresa1;
	TMenuItem *TrabajadoresdelaEmpresa1;
	TMenuItem *DepartamentosdelaEmpresa1;
	TMenuItem *DatosdelaEmpresa1;
        TMenuItem *ListadodeJefesdeDepartamento1;
	void __fastcall Salir1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall RegistroEmpresa1Click(TObject *Sender);
	void __fastcall Empresa1Click(TObject *Sender);
	void __fastcall Trabajadores1Click(TObject *Sender);
	void __fastcall EstadodelaPlantilla1Click(TObject *Sender);
	void __fastcall FondodeSalario1Click(TObject *Sender);
	void __fastcall Acercade1Click(TObject *Sender);
	void __fastcall Configurar1Click(TObject *Sender);
	void __fastcall Restaurar1Click(TObject *Sender);
	void __fastcall Salir2Click(TObject *Sender);
	void __fastcall Guardar1Click(TObject *Sender);
	void __fastcall PlazasMenosCubiertas1Click(TObject *Sender);
	void __fastcall Archivo1Click(TObject *Sender);
	void __fastcall Plantilla1Click(TObject *Sender);
	void __fastcall Reportes1Click(TObject *Sender);
	void __fastcall GuardarComo1Click(TObject *Sender);
	void __fastcall Abrir1Click(TObject *Sender);
	void __fastcall ListadodelaNmina1Click(TObject *Sender);
	void __fastcall Bajas1Click(TObject *Sender);
	void __fastcall IncidenciasLaborales1Click(TObject *Sender);
	void __fastcall Nuevo1Click(TObject *Sender);
	void __fastcall Modificarregistros1Click(TObject *Sender);
	void __fastcall Eliminar1Click(TObject *Sender);
	void __fastcall ExportarDBF1Click(TObject *Sender);
	void __fastcall Acercade2Click(TObject *Sender);
	void __fastcall CargosdelaEmpresa1Click(TObject *Sender);
	void __fastcall TrabajadoresdelaEmpresa1Click(TObject *Sender);
	void __fastcall DepartamentosdelaEmpresa1Click(TObject *Sender);
	void __fastcall DatosdelaEmpresa1Click(TObject *Sender);
        void __fastcall ListadodeJefesdeDepartamento1Click(
          TObject *Sender);
        void __fastcall TemasdeAyuda1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormPrincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPrincipal *FormPrincipal;
//---------------------------------------------------------------------------
#endif
