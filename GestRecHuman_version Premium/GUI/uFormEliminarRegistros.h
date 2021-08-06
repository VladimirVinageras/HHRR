//---------------------------------------------------------------------------

#ifndef uFormEliminarRegistrosH
#define uFormEliminarRegistrosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormEliminarRegistros : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TButton *btnCerrar;
	TRadioGroup *RadioGroup1;
	TBevel *Bevel1;
	TButton *btnEliminar;
	TButton *btnCancelar;
	TBevel *Bevel2;
	TButton *btnEliminarDep;
	TButton *btnCancelarDep;
	TListView *ListView2;
	TLabel *Label3;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TListView *ListView1;
	TLabel *Label2;
	TLabel *Label4;
        TListView *ListView3;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnCerrarClick(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall btnEliminarClick(TObject *Sender);
	void __fastcall ListView3SelectItem(TObject *Sender,
		TListItem *Item, bool Selected);
	void __fastcall ListView1SelectItem(TObject *Sender,
		TListItem *Item, bool Selected);
	void __fastcall btnCancelarClick(TObject *Sender);
	void __fastcall btnCancelarDepClick(TObject *Sender);
	void __fastcall ListView2SelectItem(TObject *Sender,
		TListItem *Item, bool Selected);
	void __fastcall btnEliminarDepClick(TObject *Sender);
	void __fastcall TabSheet1Show(TObject *Sender);
	void __fastcall TabSheet2Show(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormEliminarRegistros(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEliminarRegistros *FormEliminarRegistros;
//---------------------------------------------------------------------------
#endif
