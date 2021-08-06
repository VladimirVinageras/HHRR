//---------------------------------------------------------------------------

#ifndef uFormPlazasMenosOcupadasH
#define uFormPlazasMenosOcupadasH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "CSPIN.h"
//---------------------------------------------------------------------------
class TFormPlazasMenosCubiertas : public TForm
{
__published:	// IDE-managed Components
	TListView *ListView1;
	TBevel *Bevel1;
	TButton *btnCerrar;
	TButton *btnMostrar;
	TCSpinEdit *CSpinEdit1;
	TPanel *Panel1;
	TLabel *Label1;
        TButton *btnMostarTodos;
	void __fastcall btnCerrarClick(TObject *Sender);
	void __fastcall btnMostrarClick(TObject *Sender);
	void __fastcall CSpinEdit1KeyPress(TObject *Sender, char &Key);
	void __fastcall CSpinEdit1Change(TObject *Sender);
	void __fastcall btnMostarTodosClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormPlazasMenosCubiertas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPlazasMenosCubiertas *FormPlazasMenosCubiertas;
//---------------------------------------------------------------------------
#endif
