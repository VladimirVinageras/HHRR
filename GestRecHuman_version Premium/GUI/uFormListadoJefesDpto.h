//---------------------------------------------------------------------------

#ifndef uFormListadoJefesDptoH
#define uFormListadoJefesDptoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormListadoJefesDpto : public TForm
{
__published:	// IDE-managed Components
        TBevel *Bevel1;
        TPanel *Panel1;
        TLabel *Label1;
        TButton *Button1;
        TListView *ListView1;
        TButton *btnCerrar;
        TCSpinEdit *CSpinEdit1;
        void __fastcall btnCerrarClick(TObject *Sender);
        void __fastcall CSpinEdit1Change(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormListadoJefesDpto(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormListadoJefesDpto *FormListadoJefesDpto;
//---------------------------------------------------------------------------
#endif
