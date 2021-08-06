//---------------------------------------------------------------------------

#ifndef uFormIncidenciasH
#define uFormIncidenciasH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormIncidencias : public TForm
{
__published:	// IDE-managed Components
	TComboBox *ComboBox1;
	TLabel *Label6;
	TButton *btnAceptar;
	TButton *btnCancelar;
	TBevel *Bevel2;
	TButton *btnCerrar;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TListView *ListView1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall btnAceptarClick(TObject *Sender);
	void __fastcall btnCancelarClick(TObject *Sender);
	void __fastcall btnCerrarClick(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit3KeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TFormIncidencias(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormIncidencias *FormIncidencias;
//---------------------------------------------------------------------------
#endif
