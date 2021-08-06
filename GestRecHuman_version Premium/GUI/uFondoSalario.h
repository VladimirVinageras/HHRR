//---------------------------------------------------------------------------

#ifndef uFondoSalarioH
#define uFondoSalarioH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormFondoSalario : public TForm
{
__published:	// IDE-managed Components
	TRadioGroup *RadioGroup1;
	TPanel *Panel1;
	TStaticText *StaticText2;
	TStaticText *StaticText3;
	TStaticText *StaticText4;
	TStaticText *StaticText1;
	TBevel *Bevel1;
	TButton *btnCerrar;
	TComboBox *ComboBox1;
	TLabel *Label1;
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnCerrarClick(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormFondoSalario(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormFondoSalario *FormFondoSalario;
//---------------------------------------------------------------------------
#endif
