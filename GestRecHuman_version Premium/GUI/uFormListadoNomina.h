//---------------------------------------------------------------------------

#ifndef uFormListadoNominaH
#define uFormListadoNominaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormListadoNomina : public TForm
{
__published:	// IDE-managed Components
	TListView *ListView1;
	TButton *Button1;
        TPanel *Panel1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormListadoNomina(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormListadoNomina *FormListadoNomina;
//---------------------------------------------------------------------------
#endif
