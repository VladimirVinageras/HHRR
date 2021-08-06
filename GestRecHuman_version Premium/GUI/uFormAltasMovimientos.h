//---------------------------------------------------------------------------

#ifndef uFormAltasMovimientosH
#define uFormAltasMovimientosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormAltasYMov : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TButton *btnCerrar;
	TGroupBox *GroupBox2;
	TButton *btnAceptarAlta;
	TButton *btnCancelarAlta;
	TGroupBox *GroupBox3;
	TEdit *Edit2;
	TLabel *Label3;
	TBitBtn *bitbtnBuscarTrab;
	TComboBox *ComboBox1;
	TPanel *Panel1;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TStaticText *StaticText3;
	TStaticText *StaticText4;
	TStaticText *StaticText5;
	TStaticText *StaticText6;
	TGroupBox *GroupBox4;
	TComboBox *ComboBox2;
	TLabel *Label4;
	TListView *ListView2;
	TButton *btnAceptarMover;
	TButton *btnCancelarMover;
	TGroupBox *GroupBox5;
	TLabel *Label6;
	TComboBox *ComboBox3;
	TComboBox *ComboBox4;
	TLabel *Label7;
	TLabel *Label8;
	TComboBox *ComboBox5;
	TListView *ListView1;
	TLabel *Label2;
	TLabel *Label5;
	TGroupBox *GroupBox6;
	TBevel *Bevel2;
	TLabel *Label13;
	TCheckBox *CheckBox1;
	TEdit *Edit10;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnCerrarClick(TObject *Sender);
	void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
	void __fastcall btnCancelarMoverClick(TObject *Sender);
	void __fastcall btnCancelarAltaClick(TObject *Sender);
	void __fastcall bitbtnBuscarTrabClick(TObject *Sender);
	void __fastcall btnAceptarAltaClick(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall Edit10KeyPress(TObject *Sender, char &Key);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall TabSheet2Show(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall btnAceptarMoverClick(TObject *Sender);
	void __fastcall ListView1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormAltasYMov(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAltasYMov *FormAltasYMov;
//---------------------------------------------------------------------------
#endif
