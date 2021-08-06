//---------------------------------------------------------------------------

#ifndef uFormConfigurarH
#define uFormConfigurarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "trayicon.h"                       
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFormConfigurar : public TForm
{
__published:	// IDE-managed Components
	TCheckBox *chboxVisibleCheck;
	TButton *btnCancelar;
	TGroupBox *GroupBox1;
	TButton *btnAplicar;
	TButton *btnAceptar;
	void __fastcall btnCancelarClick(TObject *Sender);
	void __fastcall btnAceptarClick(TObject *Sender);
	void __fastcall btnAplicarClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall chboxVisibleCheckClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormConfigurar(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormConfigurar *FormConfigurar;
//---------------------------------------------------------------------------
#endif
