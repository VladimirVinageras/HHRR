//---------------------------------------------------------------------------

#ifndef FormBajasModificacionesH
#define FormBajasModificacionesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormBajasModific : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TButton *btnCerrar;
	TGroupBox *GroupBox3;
	TLabel *Label3;
	TEdit *Edit2;
	TBitBtn *bitbtnBuscarTrab;
	TButton *btnEliminar;
	TButton *btnCancelar;
	TButton *btnAceptar;
	TButton *btnCancelar1;
	TGroupBox *GroupBox4;
	TStaticText *StaticText2;
	TStaticText *StaticText7;
	TStaticText *StaticText8;
	TMemo *Memo1;
	TStaticText *StaticText3;
	TStaticText *StaticText4;
	TStaticText *StaticText6;
	TStaticText *StaticText5;
	TStaticText *StaticText9;
	TStaticText *StaticText10;
	TStaticText *StaticText1;
        TGroupBox *GroupBox1;
        TLabel *Label2;
        TBitBtn *bitbtnBuscarTrab1;
        TGroupBox *GroupBox2;
        TBevel *Bevel2;
        TLabel *Label5;
        TLabel *Label8;
        TLabel *Label7;
        TLabel *Label1;
        TEdit *Edit3;
        TEdit *Edit6;
        TEdit *Edit5;
        TCheckBox *CheckBox1;
        TEdit *Edit1;
        TEdit *Edit7;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnCerrarClick(TObject *Sender);
	void __fastcall bitbtnBuscarTrabClick(TObject *Sender);
	void __fastcall btnEliminarClick(TObject *Sender);
	void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
	void __fastcall btnCancelarClick(TObject *Sender);
	void __fastcall TabSheet1Show(TObject *Sender);
	void __fastcall Edit7KeyPress(TObject *Sender, char &Key);
	void __fastcall TabSheet2Enter(TObject *Sender);
	void __fastcall bitbtnBuscarTrab1Click(TObject *Sender);
	void __fastcall btnCancelar1Click(TObject *Sender);
	void __fastcall Edit4KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit6KeyPress(TObject *Sender, char &Key);
	void __fastcall btnAceptarClick(TObject *Sender);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall CheckBox1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormBajasModific(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormBajasModific *FormBajasModific;
//---------------------------------------------------------------------------
#endif
