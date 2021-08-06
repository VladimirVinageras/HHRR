//---------------------------------------------------------------------------

#ifndef uFormModificarRegistrosH
#define uFormModificarRegistrosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormModificarRegistros : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TButton *btnCerrar;
        TListView *ListView1;
        TButton *btnAceptarCargo;
        TButton *btnCancelar;
        TListView *ListView2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *Edit3;
        TEdit *Edit4;
        TGroupBox *GroupBox1;
        TRadioGroup *RadioGroup1;
        TLabel *Label6;
        TEdit *Edit6;
        TButton *btnAceptarRadioGroup;
        TButton *btnCancelarDpto;
        TComboBox *ComboBox1;
        TLabel *Label7;
        TButton *btnAceptar;
        TLabel *Label5;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TEdit *Edit1;
        TLabel *Label2;
        TEdit *Edit2;
        TLabel *Label8;
	void __fastcall btnCerrarClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall btnAceptarCargoClick(TObject *Sender);
        void __fastcall btnCancelarClick(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall btnAceptarRadioGroupClick(TObject *Sender);
        void __fastcall ListView1Click(TObject *Sender);
        void __fastcall ListView2Click(TObject *Sender);
        void __fastcall TabSheet1Show(TObject *Sender);
        void __fastcall TabSheet2Show(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall Edit3KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit6KeyPress(TObject *Sender, char &Key);
        void __fastcall btnAceptarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormModificarRegistros(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormModificarRegistros *FormModificarRegistros;
//---------------------------------------------------------------------------
#endif
