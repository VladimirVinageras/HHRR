//---------------------------------------------------------------------------

#ifndef uFormRegistroEmpH
#define uFormRegistroEmpH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Mask.hpp>
#include <ExtCtrls.hpp>
#include "uGlobal.h"
//---------------------------------------------------------------------------
class TFormRegEmpresa : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TButton *btnCerrar;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label2;
	TButton *btnAdicionarCargos;
	TListView *ListView1;
	TButton *btnAdicionarTrab;
	TButton *btnCancelarTrab;
	TPanel *Panel1;
	TLabel *Label3;
	TEdit *Edit3;
	TLabel *Label4;
	TEdit *Edit4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *Edit6;
	TListView *ListView2;
	TEdit *Edit7;
	TEdit *Edit8;
	TLabel *Label8;
	TLabel *Label9;
	TBevel *Bevel2;
	TGroupBox *GroupBox3;
	TComboBox *ComboBox1;
	TEdit *Edit9;
	TLabel *Label10;
	TLabel *Label11;
	TButton *btnCargoPlazas;
	TButton *btnAdicionarDep;
	TButton *btnCancelarDep;
	TEdit *Edit5;
	TListView *ListView3;
	TBevel *Bevel1;
	TGroupBox *GroupBox2;
	TEdit *Edit10;
	TLabel *Label7;
	TButton *btnCargoJefeDpto;
	void __fastcall btnCerrarClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
	void __fastcall btnAdicionarCargosClick(TObject *Sender);
	void __fastcall btnAdicionarTrabClick(TObject *Sender);
	void __fastcall btnCancelarTrabClick(TObject *Sender);
	void __fastcall Edit4KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit6KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit3KeyPress(TObject *Sender, char &Key);
	void __fastcall TabSheet2Enter(TObject *Sender);
	void __fastcall Edit9KeyPress(TObject *Sender, char &Key);
	void __fastcall btnAdicionarDepClick(TObject *Sender);
	void __fastcall btnCargoPlazasClick(TObject *Sender);
	void __fastcall btnCancelarDepClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
	void __fastcall btnCargoJefeDptoClick(TObject *Sender);
	void __fastcall Edit10KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit7KeyPress(TObject *Sender, char &Key);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall TabSheet1Show(TObject *Sender);
        void __fastcall TabSheet3Show(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormRegEmpresa(TComponent* Owner);
	TGLinkedList* ListCargosTemp;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRegEmpresa *FormRegEmpresa;
//---------------------------------------------------------------------------

#endif
