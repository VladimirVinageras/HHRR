//---------------------------------------------------------------------------

#ifndef uFormEstadoPlantillaH
#define uFormEstadoPlantillaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>                              
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormEstadoPlantilla : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *RadioGroup1;
        TComboBox *ComboBox1;
        TLabel *Label1;
        TListView *ListView1;
        TBevel *Bevel1;
        TPanel *Panel1;
        TStaticText *StaticText1;
        TStaticText *StaticText2;
        TButton *btnCerrar;
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall btnCerrarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormEstadoPlantilla(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEstadoPlantilla *FormEstadoPlantilla;
//---------------------------------------------------------------------------
#endif
