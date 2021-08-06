//---------------------------------------------------------------------------

#ifndef uFormVerTrabajadoresH
#define uFormVerTrabajadoresH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormVerTrabajadores : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TListView *ListView1;
        TButton *Button1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormVerTrabajadores(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormVerTrabajadores *FormVerTrabajadores;
//---------------------------------------------------------------------------
#endif
