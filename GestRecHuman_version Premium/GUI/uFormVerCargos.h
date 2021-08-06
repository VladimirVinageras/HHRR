//---------------------------------------------------------------------------

#ifndef uFormVerCargosH
#define uFormVerCargosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormVerCargos : public TForm
{
__published:	// IDE-managed Components
	TListView *ListView1;
	TPanel *Panel1;
        TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormVerCargos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormVerCargos *FormVerCargos;
//---------------------------------------------------------------------------
#endif
