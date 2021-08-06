//---------------------------------------------------------------------------

#ifndef uFormVerEmpresaH
#define uFormVerEmpresaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormVerEmpresa : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TStaticText *StaticText1;
	TStaticText *StaticText4;
	TStaticText *StaticText5;
	TStaticText *StaticText2;
	TStaticText *StaticText3;
	TStaticText *StaticText6;
	TStaticText *StaticText7;
	TStaticText *StaticText8;
	TStaticText *StaticText9;
	TStaticText *StaticText10;
	TStaticText *StaticText11;
	TStaticText *StaticText12;
	TStaticText *StaticText13;
	TStaticText *StaticText14;
        TButton *btn;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormVerEmpresa(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormVerEmpresa *FormVerEmpresa;
//---------------------------------------------------------------------------
#endif
