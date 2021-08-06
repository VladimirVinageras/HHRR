//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFormModificarRegistros.h"
#include "uGlobal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormModificarRegistros *FormModificarRegistros;
//---------------------------------------------------------------------------
__fastcall TFormModificarRegistros::TFormModificarRegistros(TComponent* Owner)
: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormModificarRegistros::btnCerrarClick(TObject *Sender)
{
	FormModificarRegistros->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormModificarRegistros::FormShow(TObject *Sender)
{
        PageControl1->ActivePageIndex = 0;
        Edit1->Enabled = false;
        Edit1->Color = clWindow;
        Edit2->Enabled = false;
        Edit2->Color = clWindow;
        Label6->Visible=false;
        Label7->Visible=false;
        Edit6->Visible=false;
        ComboBox1->Visible=false;
        btnAceptarRadioGroup->Visible=false;
        btnCancelarDpto->Visible=false;
}
//---------------------------------------------------------------------------


void __fastcall TFormModificarRegistros::btnAceptarCargoClick(TObject *Sender)
{
        if(ListView1->Selected)
        {
                if(Edit1->Text != "" && Edit2->Text != "")
                {
                        if(Edit1->Text != ((TCargo*)(ListView1->Selected->Data))->GetNombre())
                        {
                                if(empresa->BuscarCargo(Edit1->Text)) //me aseguro que no se encuentre
			        {
						Application->MessageBoxA(LPWSTR("Ya existe un cargo con este nombre, por favor seleccione otro nombre."),LPWSTR("Error"),MB_OK);
							return;
			        }
                        }
                        ((TCargo*)(ListView1->Selected->Data))->SetNombre(Edit1->Text);
                        ((TCargo*)(ListView1->Selected->Data))->SetSalario(StrToFloat(Edit2->Text));
                        //Modificar el cargo en los departamentos
                         empresa->CambiarDatosCargosEnDpto(((TCargo*)(ListView1->Selected->Data))->GetNombre(),Edit1->Text,StrToFloat(Edit2->Text));

                        ListView1->Clear();
                        Edit1->Text = "";
                        Edit2->Text = "";
                        TGLinkedList* TempList=empresa->GetListaCargosEmp();
                        int max = TempList->Length();
                        for(int i=0;i<max;i++)
                        {
                                TListItem* item;
                                item = ListView1->Items->Add();
                                item->Caption = ((TCargo*)empresa->GetListaCargosEmp()->ItemInfo(i))->GetNombre();
                                item->SubItems->Add(((TCargo*)empresa->GetListaCargosEmp()->ItemInfo(i))->GetSalario());
                                item->Data = ((TCargo*)empresa->GetListaCargosEmp()->ItemInfo(i));
                        }
                }
                else
                {
						Application->MessageBoxA(LPWSTR("Debe llenar todos los campos."),LPWSTR("Información"),MB_OK);

				}
		}
		else
				Application->MessageBoxA(LPWSTR("Debe seleccionar el cargo que desea modificar."),LPWSTR("Información"),MB_OK);

}
//---------------------------------------------------------------------------

void __fastcall TFormModificarRegistros::btnAceptarClick(TObject *Sender)
{
        if(ListView2->Selected)
        {
                if((Edit3->Text != "") || (Edit4->Text != ""))
                {
                        if(Edit3->Text != "")
                                ((TDepartamento*)(ListView2->Selected->Data))->SetNombre(Edit3->Text);
                        if(Edit4->Text != "")
                                ((TDepartamento*)(ListView2->Selected->Data))->SetCodigo(Edit4->Text);

                        ListView2->Clear();
                        Edit3->Text = "";
                        Edit4->Text = "";
                        int max = empresa->GetListaDptos()->Length();
                        for(int i=0;i<max;i++)
                        {
                                TDepartamento* Dpto = (TDepartamento*)(empresa->GetListaDptos())->ItemInfo(i);
                                TListItem* item1;
                                item1 = ListView2->Items->Add();
                                item1->Caption = Dpto->GetNombre();
                                item1->SubItems->Add(Dpto->GetCodigo());
                                item1->Data = Dpto;
                        }
                }
                else
						Application->MessageBoxA(LPWSTR("Debe indicar al menos un campo a modificar."),LPWSTR("Informaciуn"),MB_OK);
        }
        else
				Application->MessageBoxA(LPWSTR("Debe seleccionar el departamento que desea modificar."),LPWSTR("Informaciуn"),MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TFormModificarRegistros::btnCancelarClick(TObject *Sender)
{
        Edit1->Clear();
        Edit2->Clear();
        ListView1->ItemIndex=-1;
}
//---------------------------------------------------------------------------

void __fastcall TFormModificarRegistros::RadioGroup1Click(TObject *Sender)
{
        if(ListView2->Selected)
        {
                if(RadioGroup1->ItemIndex == 0)
                {
                        Label6->Visible=true;
                        Edit6->Visible=true;
                        Label7->Visible=true;
                        Label7->Caption = "Cargos de la Empresa :";
                        ComboBox1->Visible=true;
                        ComboBox1->Clear();
                        Edit6->Text="";
                        btnAceptarRadioGroup->Visible=true;
                        btnCancelarDpto->Visible=true;

                        TGLinkedList* listaCargosEmp = empresa->GetListaCargosEmp();
        	        int length = listaCargosEmp->Length();
                	for(int i=1; i<length; i++)
	                {
        		        TCargo* tempCargo = (TCargo*)(listaCargosEmp->ItemInfo(i));
                		ComboBox1->AddItem(tempCargo->GetNombre(),(TObject*)tempCargo);
        	        }
                }
                else
                {
                        Label7->Visible=true;
                        Label7->Caption= "Cargos del Departamento :";
                        ComboBox1->Visible=true;
                        ComboBox1->Clear();                        
                        Edit6->Text="";
                        Label6->Visible=true;
                        Edit6->Visible=true;
                        btnCancelarDpto->Visible=true;
                        btnAceptarRadioGroup->Visible=true;
                        TGLinkedList* listaCargosDpto = ((TDepartamento*)ListView2->Selected->Data)->GetListaCargos();
        	        int length = listaCargosDpto->Length();
                	for(int i=1; i<length; i++)
	                {
		                TCargo* tempCargo = (TCargo*)(listaCargosDpto->ItemInfo(i));
                		ComboBox1->AddItem(tempCargo->GetNombre(),(TObject*)tempCargo);
	                }

                }

        }
        else
        {
				Application->MessageBoxA(LPWSTR("Debe selecionar un Departamento."),LPWSTR("Informaciуn"),MB_OK);
        }

}
//---------------------------------------------------------------------------

void __fastcall TFormModificarRegistros::btnAceptarRadioGroupClick(TObject *Sender)
{
        if(RadioGroup1->ItemIndex == 0)
        {
                if(Edit6->Text != "" && ComboBox1->Text!="")
                {
                TDepartamento* TempDpto =(TDepartamento*)ListView2->Selected->Data;
                TCargo* NuevoCargo = ((TCargo*)ComboBox1->Items->Objects[ComboBox1->ItemIndex]);
		int plazasApr = StrToInt(Edit6->Text);
                NuevoCargo->SetPlazasApr(NuevoCargo->GetPlazasApr() + plazasApr);
                TNode* node= new TNode(NuevoCargo);
                TempDpto->GetListaCargos()->Insert(node);
                ComboBox1->Clear();
                Edit6->Text="";
                }
        }
        else
        {
/***/           int newplazas =StrToInt(Edit6->Text);
                TCargo* TempCargo = ((TCargo*)ComboBox1->Items->Objects[ComboBox1->ItemIndex]);
                if(newplazas < TempCargo->GetPlazasApr())
                {
                        int comparador =TempCargo->GetPlazasReales()-newplazas;
                        if(comparador <= 0)
                                TempCargo->SetPlazasApr(newplazas);
                        else
                        {
                                TempCargo->SetPlazasApr(TempCargo->GetPlazasReales());
                                AnsiString Mensaje ="Quedaron "+IntToStr(comparador);
                                Mensaje =  Mensaje + " plazas sin disminuir. Si desea disminuir esta cantidad. Por favor aumente la cantidad de plazas disponibles del cargo selecionado eliminando los trabajadores necesarios o trasladandolos para otro cargo que tenga plazas disponibles.";
                                Application->MessageBoxA(LPWSTR(Mensaje.c_str()),LPWSTR("Informaciуn"),MB_OK);
                        }
                }
                else
                        TempCargo->SetPlazasApr(newplazas);

        }
}
//---------------------------------------------------------------------------


void __fastcall TFormModificarRegistros::ListView1Click(TObject *Sender)
{
        if(ListView1->Selected)
        {
                Edit1->Enabled = true;
                Edit1->Color = clWindow;
                Edit2->Enabled = true;
                Edit2->Color = clWindow;

                TCargo* TempCargo =(TCargo*)ListView1->Selected->Data;
                Edit1->Text = TempCargo->GetNombre();
                Edit2->Text = TempCargo->GetSalario();
                if(Edit1->Text=="Jefe de Departamento")
                {
                        Edit1->Enabled = false;
                        Edit1->Color = clWindow;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormModificarRegistros::ListView2Click(TObject *Sender)
{
        if(ListView2->Selected)
        {
                TDepartamento* MyDpto =(TDepartamento*)(ListView2->Selected->Data);
                Edit3->Text=MyDpto->GetNombre();
                Edit4->Text=MyDpto->GetCodigo();
        }

}
//---------------------------------------------------------------------------

void __fastcall TFormModificarRegistros::TabSheet1Show(TObject *Sender)
{
        ListView1->Clear();
        Edit1->Text = "";
        Edit2->Text = "";
        TGLinkedList* TempList=empresa->GetListaCargosEmp();
        int max = TempList->Length();
        for(int i=0;i<max;i++)
        {
                TListItem* item;
                item = ListView1->Items->Add();
                item->Caption = ((TCargo*)empresa->GetListaCargosEmp()->ItemInfo(i))->GetNombre();
                item->SubItems->Add(((TCargo*)empresa->GetListaCargosEmp()->ItemInfo(i))->GetSalario());
                item->Data = ((TCargo*)empresa->GetListaCargosEmp()->ItemInfo(i));
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormModificarRegistros::TabSheet2Show(TObject *Sender)
{
        ListView2->Clear();
        Edit3->Text = "";
        Edit4->Text = "";
        Edit6->Text = "";
        RadioGroup1->ItemIndex=-1;
        int max =empresa->GetListaDptos()->Length();
        for(int i=0;i<max;i++)
        {
                TDepartamento* Dpto = (TDepartamento*)(empresa->GetListaDptos())->ItemInfo(i);
                TListItem* item1;
                item1 = ListView2->Items->Add();
                item1->Caption = Dpto->GetNombre();
                item1->SubItems->Add(Dpto->GetCodigo());
                item1->Data = Dpto;
        }


}
//---------------------------------------------------------------------------

void __fastcall TFormModificarRegistros::ComboBox1Change(TObject *Sender)
{
        TCargo* TempCargo = ((TCargo*)ComboBox1->Items->Objects[ComboBox1->ItemIndex]);
        Edit6->Text = TempCargo->GetPlazasApr();
}
//---------------------------------------------------------------------------

void __fastcall TFormModificarRegistros::Edit3KeyPress(TObject *Sender,
      char &Key)
{
	if((Key!='\b' && Key!=' ')&&((Key<'A')||(Key>'Z'))&&((Key<'a')||(Key>'z')))
		Key = 0;
}
//---------------------------------------------------------------------------


void __fastcall TFormModificarRegistros::Edit1KeyPress(TObject *Sender,
      char &Key)
{
        if((Key!='\b' && Key!=' ')&&((Key<'A')||(Key>'Z'))&&((Key<'a')||(Key>'z')))
		Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormModificarRegistros::Edit2KeyPress(TObject *Sender,
      char &Key)
{
        if ((Key != '\b')&&(Key != pt)&&((Key < '0')||(Key > '9')))
		Key = 0;

}
//---------------------------------------------------------------------------

void __fastcall TFormModificarRegistros::Edit6KeyPress(TObject *Sender,
      char &Key)
{
	if ((Key != '\b')&&((Key< '0')||(Key > '9')))
		Key = 0;
}
//---------------------------------------------------------------------------

