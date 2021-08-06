//---------------------------------------------------------------------------

#ifndef uFormAcercaDeH
#define uFormAcercaDeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TFormAcercaDe : public TForm
{
__published:	// IDE-managed Components
	TBevel *Bevel1;
	TButton *btnOk;                         
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TImage *Image1;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TImage *Image2;
	TCheckBox *CheckBox1;
        TLabel *Label11;
	void __fastcall btnOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormAcercaDe(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAcercaDe *FormAcercaDe;
//---------------------------------------------------------------------------
#endif
