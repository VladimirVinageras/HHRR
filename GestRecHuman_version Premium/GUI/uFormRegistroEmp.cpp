//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "uFormRegistroEmp.h"
#include "uFormAltasMovimientos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRegEmpresa *FormRegEmpresa;
//---------------------------------------------------------------------------
__fastcall TFormRegEmpresa::TFormRegEmpresa(TComponent* Owner)
: TForm(Owner)
{
	try
	{
		StrToFloat("0.0");
		pt = '.';
	}
	catch(...)
	{
		pt = ',';
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormRegEmpresa::FormShow(TObject *Sender)
{
	PageControl1->ActivePageIndex = 0;

	//de memoria externa a memoria interna
	ListView1->Clear();
	ListView2->Clear();
	ListView3->Clear();
	ComboBox1->Clear();

	//cargos
        if(!(empresa->GetListaCargosEmp()->Empty()))
	{
                TGLinkedList* listaCargosEmp = empresa->GetListaCargosEmp();
        	int length = listaCargosEmp->Length();
	        for(int i=0; i<length; i++)
        	{
	        	TCargo* tempCargo = (TCargo*)(listaCargosEmp->ItemInfo(i));
		        TListItem* item;
        		item = ListView1->Items->Add();
        		item->Caption = tempCargo->GetNombre();
	        	item->Data = tempCargo;
		        item->SubItems->Add("$ " + FloatToStr(tempCargo->GetSalario()));
                }
        }

	//trabajadores
        if(!(empresa->GetListaTrabEmp()->Empty()))
        {
                TGLinkedList* ListTrabEmp = empresa->GetListaTrabEmp();
        	int length1 = ListTrabEmp->Length();
	        for(int i=0; i<length1; i++)
        	{
	        	TTrabajador* tempTrab = (TTrabajador*)(ListTrabEmp->ItemInfo(i));
		        TListItem* item;
        		item = ListView2->Items->Add();
	        	item->Caption = tempTrab->GetNombre();
		        item->Data = tempTrab;
        	}
        }
	//departamentos
        if(!(empresa->GetListaDptos()->Empty()))
        {
	        TGLinkedList* ListDptos = empresa->GetListaDptos();
        	int length2 = ListDptos->Length();
        	for(int i=0; i<length2; i++)
	        {
		        TDepartamento* tempDpto = (TDepartamento*)(ListDptos->ItemInfo(i));
        		TListItem* item;
	        	item = ListView3->Items->Add();
		        item->Caption = tempDpto->GetNombre();
        		item->Data = tempDpto;
	        }
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormRegEmpresa::btnAdicionarCargosClick(TObject *Sender)
{
	if((Edit1->Text != "")&&(Edit2->Text != "")&&(Edit2->Text != "0"))
	{
		try
		{
			AnsiString name = Edit1->Text;
			if(empresa->BuscarCargo(name))   //me aseguro que no se encuentre
			{
				Application->MessageBoxA("Ya existe un cargo con este nombre, por favor seleccione otro nombre.","Error",MB_OK);
				Edit1->Clear();
				Edit1->SetFocus();
				return;
			}
			TCargo* cargo = new TCargo(name);
			cargo->SetSalario(StrToFloat(Edit2->Text)); //catch
			empresa->AdicionarCargo(cargo);

			ControlFile->SetGuardado(false);

			TListItem* item;
			item = ListView1->Items->Add();
			item->Caption = Edit1->Text;
			item->SubItems->Add( "$ " + Edit2->Text);
			item->Data = cargo;

			ComboBox1->AddItem(cargo->GetNombre(),(TObject*)cargo);
		}
		catch(...)
		{
			Application->MessageBoxA("Escriba correctamente el salario.","Error",MB_OK);
			Edit2->Clear();
			Edit2->SetFocus();
			return;
		}
	}
	else
	{
		Application->MessageBoxA("Debe entrar el cargo y su salario correspondiente.","Información",MB_OK);
		Edit1->SetFocus();
		return;
	}
	Edit1->Clear();
	Edit2->Clear();
	Edit1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TFormRegEmpresa::btnCargoJefeDptoClick(TObject *Sender)
{
	AnsiString nameJefeDpto = "Jefe de Departamento";
	if(Edit10->Text != "" && Edit10->Text != "0")
	{
		try
		{
			TCargo* cargo = new TCargo(nameJefeDpto);
			cargo->SetSalario(StrToFloat(Edit10->Text)); //catch
			empresa->AdicionarCargo(cargo);

			ControlFile->SetGuardado(false);

			TListItem* item;
			item = ListView1->Items->Add();
			item->Caption = nameJefeDpto;
			item->SubItems->Add("$ " + Edit10->Text);
			item->Data = cargo;

			ComboBox1->AddItem(cargo->GetNombre(),(TObject*)cargo);

			Edit10->Clear();
			Edit10->Enabled = false;
			Edit10->Color = clBtnFace;
			btnCargoJefeDpto->Enabled = false;
                        Edit1->Enabled = true;
                        Edit2->Enabled =true;
                        Edit1->Color=clWindow;
                        Edit2->Color=clWindow;
                        btnAdicionarCargos->Enabled= true;
			Edit1->SetFocus();

		}
		catch(...)
		{
			Application->MessageBoxA("Escriba correctamente el salario.","Error",MB_OK);
			Edit10->Clear();
			Edit10->SetFocus();
			return;
		}
	}
	else
	{
		Application->MessageBoxA("Debe insertar el salario, del cargo de Jefe de Departamento.","Información",MB_OK);
		Edit10->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormRegEmpresa::btnAdicionarTrabClick(TObject *Sender)
{
	AnsiString telef;
	if((Edit3->Text != "")&&(Edit4->Text != "")&&(Edit5->Text != ""))
	{
		AnsiString nombre = Edit3->Text;
		AnsiString id = Edit4->Text;
		TTrabajador* trab = empresa->BuscarTrabajadorID(id);
		if(trab) //me aseguro que no se encuentre
		{
			Application->MessageBoxA("Ya existe un trabajador con este número de identidad, por favor seleccione otro.","Error",MB_OK);
			Edit4->Clear();
			Edit4->SetFocus();
			return;
		}
		AnsiString direccion = Edit5->Text;
		if(Edit6->Text != "")
			telef = Edit6->Text;
		else
			telef = "0";

		TTrabajador* trabajador = new TTrabajador(nombre,id,direccion,telef);
		empresa->AdicionarTrab(trabajador);

		ControlFile->SetGuardado(false);

		TListItem* item;   //Actualizar ListView2
		item = ListView2->Items->Add();
		item->Caption = Edit3->Text;
		item->Data = trabajador;
	}
	else
	{
		Application->MessageBoxA("Debe llenar todos los campos.","Información",MB_OK);
		Edit3->SetFocus();
		return;
	}
	Edit3->Clear();
	Edit4->Clear();
	Edit5->Clear();
	Edit6->Clear();
	Edit3->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormRegEmpresa::btnCargoPlazasClick(TObject *Sender)
{
	if((ComboBox1->ItemIndex != -1)&&(Edit9->Text != "")&&(Edit9->Text != "0"))
	{
                Edit9->Enabled=true;
		TCargo* empresaCargo = ((TCargo*)ComboBox1->Items->Objects[ComboBox1->ItemIndex]);
		int plazasApr = StrToInt(Edit9->Text);

		AnsiString name = empresaCargo->GetNombre();
		int largo = ListCargosTemp->Length();
		int i=0;
		while(i<largo)
		{
			TCargo* DptCargo = (TCargo*)ListCargosTemp->ItemInfo(i);
			if(DptCargo->GetNombre() == name)
			{
				DptCargo->SetPlazasApr(DptCargo->GetPlazasApr()+ plazasApr);
				empresaCargo->SetPlazasApr(empresaCargo->GetPlazasApr() + plazasApr);  //Actualizar cargoEmpresa
				btnAdicionarDep->Enabled = true;
				ComboBox1->ItemIndex = -1;
				Edit9->Text = "";
				return;
			}
			else
				i++;
		}
		TCargo* cargo = new TCargo(empresaCargo->GetNombre(),plazasApr);
		float salario = empresaCargo->GetSalario();
		cargo->SetSalario(salario);
		TNode* nodo = new TNode(cargo);
		ListCargosTemp->Insert(nodo);
		empresaCargo->SetPlazasApr(empresaCargo->GetPlazasApr() + plazasApr);  //Actualizar cargoEmpresa

                ComboBox1->Clear();
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
		Application->MessageBoxA("Debe seleccionar el cargo e indicar la cantidad de plazas.","Información",MB_OK);
		return;
	}
	btnAdicionarDep->Enabled = true;
        ComboBox1->ItemIndex = -1;
	Edit9->Text = "";
        Edit9->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TFormRegEmpresa::btnAdicionarDepClick(TObject *Sender)
{
	if((Edit7->Text != "")&&(Edit8->Text != ""))
	{
		AnsiString nombre = Edit7->Text;
		AnsiString codigo = Edit8->Text;

		if(empresa->BuscarDepartamento(nombre))  //me aseguro que no se encuentre el name
		{
			Application->MessageBoxA("Ya existe un departamento con este nombre, por favor seleccione otro nombre.","Error",MB_OK);
			Edit7->Clear();
			Edit7->SetFocus();
			return;
		}
		if(empresa->BuscarDepartamentoID(codigo))  //me aseguro que no se encuentre el code
		{
			Application->MessageBoxA("Ya existe un departamento con este código, por favor seleccione otro código.","Error",MB_OK);
			Edit8->Clear();
			Edit8->SetFocus();
			return;
		}
                TDepartamento* departamento = new TDepartamento(nombre,codigo,ListCargosTemp);
		empresa->AdicionarDepart(departamento);

		TListItem* item;   //Actualizar ListView3
		item = ListView3->Items->Add();
		item->Caption = Edit7->Text;
		item->Data = departamento;

		ControlFile->SetGuardado(false);

		ListCargosTemp = new TGLinkedList;

		btnAdicionarDep->Enabled = false;

		Edit7->Clear();
		Edit8->Clear();
		Edit9->Clear();
		Edit7->SetFocus();
		ComboBox1->ItemIndex = -1;

	}
	else
	{
		Application->MessageBoxA("Asegurese de haber indicado nombre y codigo.","Informacion",MB_OK);
		return;
	}
        ComboBox1->Clear();
        TCargo* tempCargo = (TCargo*)(empresa->GetListaCargosEmp()->ItemInfo(0));
        ComboBox1->AddItem(tempCargo->GetNombre(),(TObject*)tempCargo);

}
//---------------------------------------------------------------------------

void __fastcall TFormRegEmpresa::btnCancelarTrabClick(TObject *Sender)
{
	Edit3->Clear();
	Edit4->Clear();
	Edit5->Clear();
	Edit6->Clear();
	Edit3->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TFormRegEmpresa::btnCerrarClick(TObject *Sender)
{
	FormRegEmpresa->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormRegEmpresa::Edit4KeyPress(TObject *Sender, char &Key)
{
	if ((Key != '\b')&&((Key< '0')||(Key > '9')))
		Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormRegEmpresa::Edit6KeyPress(TObject *Sender, char &Key)
{
	if ((Key != '\b')&&((Key< '0')||(Key > '9')))
		Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormRegEmpresa::Edit3KeyPress(TObject *Sender, char &Key)
{
	if((Key!='\b' && Key!=' ')&&((Key<'A')||(Key>'Z'))&&((Key<'a')||(Key>'z'))&&((Key<'À')||(Key>'ß'))&&((Key<'à')||(Key>'ÿ')))
		Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormRegEmpresa::TabSheet2Enter(TObject *Sender)
{
	Edit3->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TFormRegEmpresa::Edit9KeyPress(TObject *Sender, char &Key)
{
	if ((Key != '\b')&&((Key< '0')||(Key > '9')))
		Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormRegEmpresa::btnCancelarDepClick(TObject *Sender)
{
	Edit7->Clear();
	Edit8->Clear();
	Edit9->Clear();
	Edit7->SetFocus();
	ComboBox1->ItemIndex = -1;
	ListView3->ItemFocused = NULL;
	ListView3->ItemIndex = -1;
	btnAdicionarDep->Enabled = false;
        //ListCargosTemp->~TGLinkedList();
	ListCargosTemp = new TGLinkedList;
        Edit9->Color = clWindow;
}
//---------------------------------------------------------------------------
void __fastcall TFormRegEmpresa::Edit2KeyPress(TObject *Sender, char &Key)
{
	if ((Key != '\b')&&(Key != pt)&&((Key < '0')||(Key > '9')))
		Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormRegEmpresa::FormCreate(TObject *Sender)
{
	ListCargosTemp = new TGLinkedList;
}
//---------------------------------------------------------------------------

void __fastcall TFormRegEmpresa::Edit1KeyPress(TObject *Sender, char &Key)
{
	if((Key!='\b' && Key!=' ')&&((Key<'A')||(Key>'Z'))&&((Key<'a')||(Key>'z')))
		Key=0;
}
//---------------------------------------------------------------------------

void __fastcall TFormRegEmpresa::Edit10KeyPress(TObject *Sender, char &Key)
{
	if ((Key != '\b')&&(Key != pt)&&((Key < '0')||(Key > '9')))
		Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormRegEmpresa::Edit7KeyPress(TObject *Sender, char &Key)
{
	if((Key!='\b' && Key!=' ')&&((Key<'A')||(Key>'Z'))&&((Key<'a')||(Key>'z')))
		Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormRegEmpresa::ComboBox1Change(TObject *Sender)
{
        if(ComboBox1->Text == "Jefe de Departamento")
        {
                Edit9->Text = "1";
                Edit9->Enabled = false;
                Edit9->Color = clBtnFace;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormRegEmpresa::TabSheet1Show(TObject *Sender)
{
        if(empresa->GetListaCargosEmp()->Empty())
        {
                ListView1->Clear();
                Edit1->Enabled=false;
                Edit2->Enabled=false;
                btnAdicionarCargos->Enabled=false;
        }


}
//---------------------------------------------------------------------------

void __fastcall TFormRegEmpresa::TabSheet3Show(TObject *Sender)
{
        ComboBox1->Clear();
        if(!empresa->GetListaCargosEmp()->Empty())
        {
                TCargo* tempCargo = (TCargo*)(empresa->GetListaCargosEmp()->ItemInfo(0));
                ComboBox1->AddItem(tempCargo->GetNombre(),(TObject*)tempCargo);
        }
}
//---------------------------------------------------------------------------



