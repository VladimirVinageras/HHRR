//------------------------------------------------------------------------------
#pragma hdrstop
#include "uClases.h"
#include "uDBF.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------

//----------------------Daemons-------------------------------------------------

namespace Daemon
{
	bool D_BuscarCargo(void* cursor,void* pReference)
	{
		return(((TCargo*)cursor)->GetNombre()== *((AnsiString*)pReference));
	}
	//--------------------
	bool D_BuscarTrabajador(void* pCursor, void* pReference)
	{
		return(((TTrabajador*)pCursor)->GetNombre() == *((AnsiString*)pReference));
	}
	//--------------------
	bool D_BuscarTrabajadorID(void* pCursor, void* pReference)
	{
		return (((TTrabajador*)pCursor)->GetIdW() == *((AnsiString*)pReference));
	}
	//--------------------
	/***/void D_BuscarTrabajadorCargo(void* pCursor, void* pReference)
	{
                TSTrabajadoresEnCargo* TempStruct=(TSTrabajadoresEnCargo*)pReference;
	 	if(((TCargo*)(((TTrabajador*)pCursor)->GetCargo()))->GetNombre() == TempStruct->Cargo)
                        {
                                TNode* NewNode = new TNode((TTrabajador*)pCursor);
                                TempStruct->ListaOrdenada->Insert(NewNode);
                        }
       	}
       	//--------------------
	bool D_BuscarDepartamento(void* pCursor,void* pReference)
	{
		return(((TDepartamento*)pCursor)->GetNombre() == *((AnsiString*)pReference));
	}
	//--------------------
	bool D_BuscarDepartamentoID(void* pCursor,void* pReference)
	{
		return(((TDepartamento*)pCursor)->GetCodigo()==*((AnsiString*)pReference));
	}
	//--------------------
	bool D_BuscaDepartamentoTrabajador(void* pCursor,void* pReference)
	{
		TDepartamento* departamento = (TDepartamento*)pCursor;
		AnsiString id = (*(AnsiString*)pReference);
		return departamento->BuscarTrabajador(id);
	}
	//--------------------
	bool D_BuscarPosTrab(void* pCursor, void* pReference)
	{
		((TSPos*)pReference)->pos++;
		return(((TTrabajador*)pCursor)->GetIdW()==((TSPos*)pReference)->Id);
	}
	//--------------------
	void D_CalcularSalarioRealDpto(void* pCursor, void* pReference)
	{
		if(((TTrabajador*)pCursor)->GetResolucion())
			((TSSalarioTrab*)pReference)->salarioRes += ((TTrabajador*)pCursor)->GetSalarioRes();
		else
			((TSSalarioTrab*)pReference)->salarioCargo +=((TCargo*)((TTrabajador*)pCursor)->GetCargo())->GetSalario();
	}
	//--------------------
	void D_CalcularSalarioAproDpto(void* pCursor, void* pReference)
	{
		int plazas = ((TCargo*)pCursor)->GetPlazasApr();
		float salario = ((TCargo*)pCursor)->GetSalario();
		*((float*)pReference) += salario*plazas;
	}
	//--------------------
	void D_CalcSalarioAproEmp(void* pCursor, void* pReference)
	{
		TDepartamento* depart = ((TDepartamento*)pCursor);
		*((float*)pReference) += depart->FondoSalarioAprobadoDpto();
	}
	//--------------------
	void D_CalcSalarioRealEmp(void* pCursor, void* pReference)
	{
		TDepartamento* depart = ((TDepartamento*)pCursor);
		*((float*)pReference) += depart->FondoSalarioRealDpto();
	}
	//--------------------
	/***/void D_RecorrerDepartamentos(void* pCursor, void* pReference)
	{
		TGLinkedList* ListaCargos = ((TDepartamento*)pCursor)->GetListaCargos();
		int length = ListaCargos->Length();
		for(int i=0; i<length; i++)
		{
			TCargo* Cargo = (TCargo*)(ListaCargos->ItemInfo(i));
			TSCargoPlazas* structCargoPlazas = new TSCargoPlazas;
			structCargoPlazas->departamento = (TDepartamento*)pCursor; // <- por esto no puede ser otro demonio
			structCargoPlazas->cargo = Cargo;

			TNode* node = new TNode(structCargoPlazas);
                        int max = ((TGLinkedList*)pReference)->Length();
			int i = 0;
			bool insertado = false;
			while((i < max)&&(!insertado))
			{
				TSCargoPlazas* MyStruct = (TSCargoPlazas*)(((TGLinkedList*)pReference)->ItemInfo(i));
				if(structCargoPlazas->cargo->EstadoCargo() <= MyStruct->cargo->EstadoCargo())
				{
					if(structCargoPlazas->cargo->EstadoCargo()== MyStruct->cargo->EstadoCargo())
					{
						int cont = i;
						while ((structCargoPlazas->cargo->EstadoCargo() == MyStruct->cargo->EstadoCargo()) && (!insertado))
						{
							if(((structCargoPlazas->cargo->GetSalario()) >= (MyStruct->cargo->GetSalario())))
							{
								((TGLinkedList*)pReference)->Insert(node,cont);
								insertado = true;
							}
							else if((((TSCargoPlazas*)((TGLinkedList*)pReference)->ItemInfo(cont+1))->cargo->EstadoCargo() > structCargoPlazas->cargo->EstadoCargo()))
							{
								((TGLinkedList*)pReference)->Insert(node,cont+1);
								insertado = true;
							}
							else
							{
								cont++;
								MyStruct=(TSCargoPlazas*)(((TGLinkedList*)pReference)->ItemInfo(cont));
							}
						}
					}
					else
					{
						((TGLinkedList*)pReference)->Insert(node,i);
						insertado = true;
						i++;
					}
				}
				else
					i++;
			}
			if(!insertado)
				((TGLinkedList*)pReference)->Insert(node);
		}
	}
//-------------------
	bool D_BuscarPosCargo(void* pCursor, void* pReference)
	{
		((TSPos1*)pReference)->pos++;
		return(((TCargo*)pCursor)->GetNombre()==((TSPos1*)pReference)->nombre);
	}
	//-------------------
	void D_EliminarTrabsDelCargo(void* pCursor, void* pReference)
	{
		bool alta = ((TTrabajador*)pCursor)->GetAlta();
		if((alta) && (((TTrabajador*)pCursor)->GetCargo()->GetNombre()==((TCargo*)pReference)->GetNombre()))
			empresa->EliminarTrabajador(((TTrabajador*)pCursor));
	}
	//-------------------
	void D_EliminarCargoDepartamentos(void* pCursor, void* pReference)
	{
		((TDepartamento*)pCursor)->EliminarCargo((TCargo*)pReference);
	}
	//-------------------
	void D_EliminarTrabs(void* pCursor, void* pReference)
	{
		empresa->EliminarTrabajador((TTrabajador*)pCursor);
	}
	//-------------------
	bool D_BuscarPosDepartamento(void* pCursor, void* pReference)
	{
		((TSPos*)pReference)->pos++;
		return(((TDepartamento*)pCursor)->GetCodigo()==((TSPos*)pReference)->Id);
	}
      	//-------------------
        /***/void D_BusquedaEnCargos(void* pCursor, void* pReference)
        {
                TSNominaTrab* TempStruct = (TSNominaTrab*)pReference;
                TSTrabajadoresEnCargo* NewStruct = new TSTrabajadoresEnCargo;
                TGLinkedList* TempList = TempStruct->ListaTrab;
                NewStruct->ListaOrdenada=TempStruct->ListaOrdenada;
                NewStruct->Cargo = ((TCargo*)pCursor)->GetNombre();
                TempList->ForEach(Daemon::D_BuscarTrabajadorCargo,NewStruct);
        }
        //-------------------
        /***/void D_NominaDptos(void* pCursor,void* pReference)
        {
                ((TDepartamento*)pCursor)->NominaTrabajadores((TGLinkedList*)pReference);
        }
        //-------------------
        /***/void D_CalularHoraAusencias(void* pCursor,void* pReference)
        {
               (*(float*)pReference)+=((TTrabajador*)pCursor)->GetHorasAusencias();
        }
        //-------------------
        /***/void D_OrdenaDptos(void* pCursor, void* pReference)
        {
                bool inserted = false;
                int cont = 0;
                TNode* node = new TNode(((TDepartamento*)pCursor));
                if(((TGLinkedList*)pReference)->Empty())
                        ((TGLinkedList*)pReference)->Insert(node,0);
                else
                {
                        while(!inserted)
                        {
                                if(cont == ((TGLinkedList*)pReference)->Length())
                                {
                                        ((TGLinkedList*)pReference)->Insert(node);
                                        inserted = true;
                                }
                                else
                                {
                                        TDepartamento* TempDpto=((TDepartamento*)((TGLinkedList*)pReference)->ItemInfo(cont));
                                        if(TempDpto->CalcularPorcientoAusentismo() <= ((TDepartamento*)pCursor)->CalcularPorcientoAusentismo())
                                        {
                                                ((TGLinkedList*)pReference)->Insert(node,cont);
                                                inserted = true;
                                        }
                                        else
                                                cont++;
                                }
                        }
                }
        }
//-------------------
        void D_CambiarNombCargos(void* pCursor,void* pReference)
        {
                if(((TCargo*)pCursor)->GetNombre()==((TSCambiarNombre*)pReference)->NombreViejo)
                        ((TCargo*)pCursor)->SetNombre(((TSCambiarNombre*)pReference)->NombreNuevo);
                        ((TCargo*)pCursor)->SetSalario(((TSCambiarNombre*)pReference)->NuevoSalario);
        }
//-------------------
        void D_CambiarDatosCargosEnDpto(void* pCursor,void* pReference)
        {
                ((TDepartamento*)pCursor)->GetListaCargos()->ForEach(Daemon::D_CambiarNombCargos,pReference);
        }

};
//------------------------------------------------------------------------------
//-----------------End_Daemon---------------------------------------------------
//------------------------------------------------------------------------------
TEmpresa::TEmpresa(AnsiString pNombre)   //Constructor
{
	aNombre = pNombre;
	ListaCargosEmp = new TGLinkedList;
	ListaTrabEmp = new TGLinkedList;
	ListaDepartamentos = new TGLinkedList;
}
//------------------------------------------------------------------------------
TTrabajador::TTrabajador(AnsiString Nombre,AnsiString Id,AnsiString Telefono,AnsiString Direc,bool Resol,bool Alta,float SalResol,TCargo* pCargo,float pHorasExtras,float pHorasAusencias)
{
	aNombreW = Nombre;
	aIdW = Id;
	aDirParticular = Direc;
	aTelefono = Telefono;
	Cargo = pCargo;
	aResolucion = Resol;
	aSalarioRes = SalResol;
	alta = Alta;
	aHorasExtras = pHorasExtras;
	aHorasAusencias = pHorasAusencias;
}
//------------------------------------------------------------------------------
TDepartamento::~TDepartamento()  //Destructor
{
	ListaCargosDep->~TGLinkedList();  //OK
	ListaTrabDep->~TGLinkedList();    //OK
}
//------------------------------------------------------------------------------
TEmpresa::~TEmpresa()  //Destructor
{
	delete ListaCargosEmp;
	delete ListaTrabEmp;
	delete ListaDepartamentos;
}
//------------------------------------------------------------------------------
TCargo* TEmpresa::BuscarCargo(AnsiString pNombre)
{
	TCargo* carg = (TCargo*)ListaCargosEmp->FirstThat(Daemon::D_BuscarCargo,&pNombre);
	return carg;
}
//------------------------------------------------------------------------------
TTrabajador* TEmpresa::BuscarTrabajador(AnsiString pNombre)
{
	TTrabajador* trab = (TTrabajador*)ListaTrabEmp->FirstThat(Daemon::D_BuscarTrabajador,&pNombre);
	return trab;
}
//------------------------------------------------------------------------------
TTrabajador* TEmpresa::BuscarTrabajadorID(AnsiString pid)
{
	TTrabajador* trab = (TTrabajador*)ListaTrabEmp->FirstThat(Daemon::D_BuscarTrabajadorID,&pid);
	return trab;
}
//------------------------------------------------------------------------------
TDepartamento* TEmpresa::BuscarDepartamento(AnsiString pNombre)
{
	TDepartamento* Dpto = (TDepartamento*)ListaDepartamentos->FirstThat(Daemon::D_BuscarDepartamento,&pNombre);
	return Dpto;
}
//------------------------------------------------------------------------------
TDepartamento* TEmpresa::BuscarDepartamentoID(AnsiString pCodigo)
{
	TDepartamento* Dpto = (TDepartamento*)ListaDepartamentos->FirstThat(Daemon::D_BuscarDepartamentoID,&pCodigo);
	return Dpto;
}
//------------------------------------------------------------------------------
float TEmpresa::FondoSalarioAprobado()
{
	float salario = 0;
	ListaDepartamentos->ForEach(Daemon::D_CalcSalarioAproEmp, &salario);
	return salario;
}
//------------------------------------------------------------------------------
float TEmpresa::FondoSalarioReal()
{
	float salario = 0;
	ListaDepartamentos->ForEach(Daemon::D_CalcSalarioRealEmp, &salario);
	return salario;
}
//------------------------------------------------------------------------------
/***/void TEmpresa::EliminarCargo(TCargo* pCargo)
{
	TSPos1* structPos = new TSPos1;
	structPos->nombre = pCargo->GetNombre();
	structPos->pos = -1;
	if(ListaCargosEmp->FirstThat(Daemon::D_BuscarPosCargo,structPos))
	{
		ListaCargosEmp->Delete(structPos->pos);
		ListaDepartamentos->ForEach(Daemon::D_EliminarCargoDepartamentos,pCargo);
	}
}
//------------------------------------------------------------------------------
void TEmpresa::EliminarTrabsDelCargo(TCargo* pCargo)
{
	ListaTrabEmp->ForEach(Daemon::D_EliminarTrabsDelCargo,pCargo);
}
//------------------------------------------------------------------------------
/***/void TEmpresa::EliminarDepartamento(TDepartamento* dpto)
{
	TSPos* structPos = new TSPos;
	structPos->Id = dpto->GetCodigo();
	structPos->pos = -1;
	if(ListaDepartamentos->FirstThat(Daemon::D_BuscarPosDepartamento,structPos))
	{
                int cont=0;
		dpto->GetListaTrabDep()->ForEach(Daemon::D_EliminarTrabs,NULL);
                while(dpto->GetListaCargos()->Length()>cont)
                {
                        dpto->EliminarCargo((TCargo*)dpto->GetListaCargos()->ItemInfo(cont));
                        cont++;
                }
                ListaDepartamentos->Delete(structPos->pos);
		dpto->~TDepartamento();  /***/
	}
}
//------------------------------------------------------------------------------
void TEmpresa::EliminarTrabajador(TTrabajador* trab)
{
	AnsiString id = trab->GetIdW();
	TDepartamento* dpto = BuscaDepartamentoTrabajador(id);
	if(dpto)
		dpto->EliminarTrabajador(id);

	TSPos* structPos = new TSPos;
	structPos->Id = id;
	structPos->pos = -1;
	ListaTrabEmp->FirstThat(Daemon::D_BuscarPosTrab,structPos);
	ListaTrabEmp->Delete(structPos->pos);
}
//------------------------------------------------------------------------------
TDepartamento* TEmpresa::BuscaDepartamentoTrabajador(AnsiString id)
{
	return ((TDepartamento*)ListaDepartamentos->FirstThat(Daemon::D_BuscaDepartamentoTrabajador,&id));
}
//------------------------------------------------------------------------------
/***/ TGLinkedList* TEmpresa::PlazasMenosCubiertas()
{
	TGLinkedList* lista = new TGLinkedList();
	ListaDepartamentos->ForEach(Daemon::D_RecorrerDepartamentos,lista);
	return lista;
}
//------------------------------------------------------------------------------
/***/TGLinkedList* TEmpresa::NominaDeTrabajadores()
{
        TGLinkedList* Lista = new TGLinkedList();
        ListaDepartamentos->ForEach(Daemon::D_NominaDptos,Lista);
        return Lista;
}
//------------------------------------------------------------------------------
float TEmpresa::CalcularEstadoPlantilla()
{
	int max = ListaCargosEmp->Length();
	int totalreal = 0;
	int totalapr = 0;
	for (int i=0; i<max; i++)
	{
		TCargo* TempCargo =(TCargo*)ListaCargosEmp->ItemInfo(i);
		int real = TempCargo->GetPlazasReales();
		int aprob = TempCargo->GetPlazasApr();
		totalreal += real;
		totalapr += aprob;
	}
	return totalreal*100/totalapr;
}
//------------------------------------------------------------------------------
/***/TGLinkedList* TEmpresa::OrdenaListaDptos()
{
        TGLinkedList* lista=new TGLinkedList();
        ListaDepartamentos->ForEach(Daemon::D_OrdenaDptos,lista);
        return lista;
}
//------------------------------------------------------------------------------
float TCargo::EstadoCargo()
{
	return(aCantPlazasReal*100/aCantPlazasApr);
}

//------------------------------------------------------------------------------
float TDepartamento::CalcularEstadoPlantilla()
{
	int totalReal = 0;
	int totalApr = 0;
	int max = ListaCargosDep->Length();
	for (int i=0; i<max; i++)
	{
		TCargo* TempCargo = (TCargo*)ListaCargosDep->ItemInfo(i);
		int real = TempCargo->GetPlazasReales();
		int aprob = TempCargo->GetPlazasApr();
		totalReal += real;
		totalApr += aprob;
	}
	return totalReal*100/totalApr;
}
//------------------------------------------------------------------------------
bool TDepartamento::BuscarTrabajador(AnsiString id)
{
	return ListaTrabDep->FirstThat(Daemon::D_BuscarTrabajadorID,&id);
}
//------------------------------------------------------------------------------
float TDepartamento::FondoSalarioRealDpto()
{
	TSSalarioTrab* salario = new TSSalarioTrab;
	salario->salarioRes = 0;
	salario->salarioCargo = 0;
	ListaTrabDep->ForEach(Daemon::D_CalcularSalarioRealDpto, salario);
	float SalarioReal = salario->salarioRes + salario->salarioCargo;
	return SalarioReal;
}
//------------------------------------------------------------------------------
float TDepartamento::FondoSalarioAprobadoDpto()
{
	float salario = 0;
	ListaCargosDep->ForEach(Daemon::D_CalcularSalarioAproDpto, &salario);
	return salario;
}

//------------------------------------------------------------------------------
void TDepartamento::EliminarTrabajador(AnsiString id)
{
	TSPos* StructPos = new TSPos;
	StructPos->Id = id;
	StructPos->pos = -1;
	ListaTrabDep->FirstThat(Daemon::D_BuscarPosTrab,StructPos);
	ListaTrabDep->Delete(StructPos->pos);
}

//------------------------------------------------------------------------------
/***/void TDepartamento::NominaTrabajadores(TGLinkedList* pLista)
{
	TSNominaTrab* MyStruct = new TSNominaTrab();
	MyStruct->ListaTrab=ListaTrabDep;
	MyStruct->ListaOrdenada=pLista;
	ListaCargosDep->ForEach(Daemon::D_BusquedaEnCargos,MyStruct);
}

//------------------------------------------------------------------------------
/***/void TDepartamento::EliminarCargo(TCargo* pCargo)
{
	TSPos1* structPos = new TSPos1;
	structPos->nombre = pCargo->GetNombre();
	structPos->pos = -1;

        TSPos1* structPos1 = new TSPos1;
	structPos1->nombre = pCargo->GetNombre();
	structPos1->pos = -1;

	if(ListaCargosDep->FirstThat(Daemon::D_BuscarPosCargo,structPos))
	{
		empresa->EliminarTrabsDelCargo(pCargo);    /***/
                TGLinkedList* lista = empresa->GetListaCargosEmp();
                if(lista->FirstThat(Daemon::D_BuscarPosCargo,structPos1))
                {
                        TCargo* cargo = ((TCargo*)lista->ItemInfo(structPos1->pos));
                        cargo->SetPlazasApr((cargo->GetPlazasApr())-(pCargo->GetPlazasApr()));
                        cargo->SetPlazasReales((cargo->GetPlazasReales())-(pCargo->GetPlazasReales()));
                }
                ListaCargosDep->Delete(structPos->pos);

	}
}
//------------------------------------------------------------------------------
/***/float TDepartamento::CalcularPorcientoAusentismo()
{
        float Cont = CalcularHorasAusentismo();
        return (Cont*100)/(190.6*(ListaTrabDep->Length()));
}
//------------------------------------------------------------------------------
/***/float TDepartamento::CalcularHorasAusentismo()
{
        float Cont=0;
        ListaTrabDep->ForEach(Daemon::D_CalularHoraAusencias,&Cont);
        return Cont;
}
//------------------------------------------------------------------------------
/***/float TTrabajador::CalcularSalarioCobro()
{
        if(GetResolucion())
                return (aSalarioRes + ((aSalarioRes/190.6)*(aHorasExtras-aHorasAusencias)));
        else
                return ((Cargo->GetSalario())+(((Cargo->GetSalario())/190.6)*(aHorasExtras-aHorasAusencias)));
}
//------------------------------------------------------------------------------
void TEmpresa::CambiarDatosCargosEnDpto(AnsiString pNombreViejo,AnsiString pNombreNuevo, float pNuevoSalario)
{
        TSCambiarNombre* MyStruct = new TSCambiarNombre;
        MyStruct->NombreViejo = pNombreViejo;
        MyStruct->NombreNuevo = pNombreNuevo;
        MyStruct->NuevoSalario = pNuevoSalario;
        ListaDepartamentos->ForEach(Daemon::D_CambiarDatosCargosEnDpto, MyStruct);
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//---------------------------Fichero--------------------------------------------
//------------------------------------------------------------------------------
//Guardar
//------------------------------------------------------------------------------
TControlFile::TControlFile()
{
	FicheroCargo = new TFile(".\\Files\\DatosDRH.crg");
	FicheroTrab = new TFile(".\\Files\\DatosDRH.trb");
	FicheroDpto = new TFile(".\\Files\\DatosDRH.drh");
	aGuardado = true;
	aNombreFichEmp = "DatosDRH";
}
//------------------------------------------------------------------------------
TControlFile::TControlFile(AnsiString CrgNameFile,AnsiString TrbNameFile,AnsiString EmpNameFile)
{
	FicheroCargo = new TFile(CrgNameFile);
	FicheroTrab = new TFile(TrbNameFile);
	FicheroDpto = new TFile(EmpNameFile);
	aGuardado = false;
	aNombreFichEmp = EmpNameFile;
}
//------------------------------------------------------------------------------
StructCargo TControlFile::ConvierteClaseAEstructuraC(TCargo* pCargo)
{
	StructCargo newCargo;
	newCargo.Salario = pCargo->GetSalario();
	newCargo.CantPlazasApr = pCargo->GetPlazasApr();
	newCargo.CantPlazasReal = pCargo->GetPlazasReales();
	strcpy(newCargo.Nombre,pCargo->GetNombre().c_str());
	return newCargo;
}
//------------------------------------------------------------------------------

StructTrabajador TControlFile::ConvierteClaseAEstructuraT(TTrabajador* pTrabajador)
{
	AnsiString NoPosee = "No Posee";
	StructTrabajador newTrabajador;

	strcpy(newTrabajador.Nombre,pTrabajador->GetNombre().c_str());
	strcpy(newTrabajador.DirPart,pTrabajador->GetDirParticular().c_str());
	strcpy(newTrabajador.Id,pTrabajador->GetIdW().c_str());
	strcpy(newTrabajador.Telefono,pTrabajador->GetTelefono().c_str());
	newTrabajador.SalarioRes = pTrabajador->GetSalarioRes();
	newTrabajador.HorasAusencias = pTrabajador->GetHorasAusencias();
	newTrabajador.HorasExtras = pTrabajador->GetHorasExtras();
	if(pTrabajador->GetCargo())
	{
		int Pos = PosCargo(pTrabajador->GetCargo()->GetNombre());
		newTrabajador.PosFichCargo = Pos;
		TDepartamento* Dep;
		Dep = empresa->BuscaDepartamentoTrabajador(pTrabajador->GetIdW());
		strcpy(newTrabajador.NombreDpto,Dep->GetNombre().c_str());
	}
	else
	{
		strcpy(newTrabajador.NombreDpto,NoPosee.c_str());
		newTrabajador.PosFichCargo = -1;
	}
	if(pTrabajador->GetResolucion())
		newTrabajador.Resolucion = 'V';
	else
		newTrabajador.Resolucion = 'F';

	if(pTrabajador->GetAlta())
		newTrabajador.alta = 'V';
	else
		newTrabajador.alta = 'F';

	return newTrabajador;
}
//-------------------------------------------------------------------------------

StructDpto TControlFile::ConvierteClaseAEstructuraD(TDepartamento* Dpto)
{
	AnsiString NoPosee = "No Posee";
	StructDpto newDpto;
	strcpy(newDpto.CodigoDpto,Dpto->GetCodigo().c_str());

	if(Dpto->GetJefeDepartamento())
		strcpy(newDpto.IdJefeDpto,Dpto->GetJefeDepartamento()->GetIdW().c_str());
	else
		strcpy(newDpto.IdJefeDpto,NoPosee.c_str());

	strcpy(newDpto.NombreDpto,Dpto->GetNombre().c_str()); //se puede mejorar
	newDpto.CantCargos = Dpto->GetListaCargos()->Length();
	newDpto.CantTrab = Dpto->GetListaTrabDep()->Length();
	int i = 0;
	while(i < Dpto->GetListaCargos()->Length())
	{
		StructCargoEnDpto StrCargoEnDpto;
		TCargo* pCargo;
		pCargo = ((TCargo*)((TDepartamento*)Dpto)->GetListaCargos()->ItemInfo(i));
		StrCargoEnDpto.PosFicheroCargos = PosCargo(pCargo->GetNombre());
		StrCargoEnDpto.CantPlazasApr = pCargo->GetPlazasApr();
		StrCargoEnDpto.CantPlazasReal = pCargo->GetPlazasReales();
		newDpto.aArrCargos[i] = StrCargoEnDpto;
		i++;
	}
	int k = 0;
	while(k < Dpto->GetListaTrabDep()->Length())
	{
		TTrabajador* pTrab;
		pTrab = ((TTrabajador*)((TDepartamento*)Dpto)->GetListaTrabDep()->ItemInfo(k));
		int Posicion = PosTrabajador(pTrab->GetIdW());
		newDpto.ArrPuntTrab[k] = Posicion;
		k++;
	}
	return newDpto;
}
//------------------------------------------------------------------------------
void TControlFile::GuardarFicheroCargo()
{
	int i = 0;
	StructCargo StrCargo;
	FicheroCargo->Open("wb+");
	while(i < empresa->GetListaCargosEmp()->Length())
	{
		TCargo* pCargo;
		pCargo = ((TCargo*)((TEmpresa*)empresa)->GetListaCargosEmp()->ItemInfo(i));
		StrCargo = ConvierteClaseAEstructuraC(pCargo);
		FicheroCargo->Write(&StrCargo,sizeof(StructCargo));
		i++;
	}
	FicheroCargo->Close();
}
//------------------------------------------------------------------------------
void TControlFile::GuardarFicheroTrab()
{
	int i = 0;
	StructTrabajador StrTrabajador;
	FicheroTrab->Open("wb+");
	while(i < empresa->GetListaTrabEmp()->Length())
	{
		TTrabajador* pTrabajador;
		pTrabajador = ((TTrabajador*)((TEmpresa*)empresa)->GetListaTrabEmp()->ItemInfo(i));
		StrTrabajador = ConvierteClaseAEstructuraT(pTrabajador);
		FicheroTrab->Write(&StrTrabajador,sizeof(StructTrabajador));
		i++;
	}
	FicheroTrab->Close();
}
//------------------------------------------------------------------------------
void TControlFile::GuardarFicheroDpto()
{
	int i = 0;
	StructDpto StrDpto;
	FicheroDpto->Open("wb+");
	while(i < empresa->GetListaDptos()->Length())
	{
		TDepartamento* pDepartamento;
		pDepartamento = ((TDepartamento*)((TEmpresa*)empresa)->GetListaDptos()->ItemInfo(i));
		StrDpto = ConvierteClaseAEstructuraD(pDepartamento);
		FicheroDpto->Write(&StrDpto,sizeof(StructDpto));
		i++;
	}
	FicheroDpto->Close();
}
//------------------------------------------------------------------------------
void TControlFile::GuardarFicheros()
{
	GuardarFicheroCargo();
	GuardarFicheroTrab();
	GuardarFicheroDpto();
	aGuardado = true;
}
//------------------------------------------------------------------------------
int TControlFile::PosCargo(AnsiString NombreCargo)
{
	FicheroCargo->Open("rb");
	StructCargo StrCargo;
	FicheroCargo->Read(&StrCargo,sizeof(StructCargo));
	int Posicion = 0;
	bool Find = false;
	while(!FicheroCargo->Eof() && !Find)
	{
		if(strcmp(StrCargo.Nombre,NombreCargo.c_str()) == 0)
		{
			Find = true;
		}
		else
		{
			Posicion ++;
			FicheroCargo->Read(&StrCargo,sizeof(StructCargo));
		}
	}
	FicheroCargo->Close();
	return Posicion;
}
//------------------------------------------------------------------------------
int TControlFile::PosTrabajador(AnsiString pId)
{
	FicheroTrab->Open("rb");
	StructTrabajador StrTrab;
	FicheroTrab->Read(&StrTrab,sizeof(StructTrabajador));
	int Posicion = 0;
	bool Find = false;
	while(!FicheroTrab->Eof() && !Find)
	{
		if(strcmp(StrTrab.Id,pId.c_str()) == 0)
		{
			Find = true;
		}
		else
		{
			Posicion ++;
			FicheroTrab->Read(&StrTrab,sizeof(StructTrabajador));
		}
	}
	FicheroTrab->Close();
	return Posicion;
}
//------------------------------------------------------------------------------
//Abrir
//------------------------------------------------------------------------------
TCargo* TControlFile::ConvierteEstructuraAClaseC(StructCargo StrCargo)
{
	AnsiString Name = StrCargo.Nombre;
	int PlazasAprob = StrCargo.CantPlazasApr;
	int PlazasReales = StrCargo.CantPlazasReal;
	float Salario = StrCargo.Salario;
	TCargo* pCargo = new TCargo(Name,PlazasAprob,PlazasReales,Salario);
	return pCargo;
}
//------------------------------------------------------------------------------
TTrabajador* TControlFile::ConvierteEstructuraAClaseT(StructTrabajador StrTrab)
{
	bool Alta;
	TCargo* pCargo;
	bool Resolucion;
	AnsiString Name = StrTrab.Nombre;
	AnsiString Id = StrTrab.Id;
	AnsiString Telefono = StrTrab.Telefono;
	AnsiString DireccionPart = StrTrab.DirPart;
	float SalRes = StrTrab.SalarioRes;
	float HExtras = StrTrab.HorasExtras;
	float HAusencias = StrTrab.HorasAusencias;

	if(StrTrab.Resolucion == 'V')
		Resolucion = true;

	else
		Resolucion = false;

	if(StrTrab.alta == 'V')
		Alta = true;
	else
		Alta = false;

	int Pos = StrTrab.PosFichCargo;
	if(Pos != -1)
		pCargo = ((TCargo*)((TEmpresa*)empresa)->GetListaCargosEmp()->ItemInfo(Pos));
	else
		pCargo = NULL;

	TTrabajador* Trabajador = new TTrabajador(Name,Id,Telefono,DireccionPart,Resolucion,Alta,SalRes,pCargo,HExtras,HAusencias);
	return Trabajador;
}
//------------------------------------------------------------------------------
TDepartamento* TControlFile::ConvierteEstructuraAClaseD(StructDpto StrDpto)
{
	TTrabajador* trab;
	TNode* pNode;
	TGLinkedList* CargosList = new TGLinkedList();
	TGLinkedList* TrabList = new TGLinkedList();

	AnsiString Nombre = StrDpto.NombreDpto;
	AnsiString Codigo = StrDpto.CodigoDpto;
	AnsiString IdJefeDpto = StrDpto.IdJefeDpto;

	if(IdJefeDpto != "No Posee")
        {
		trab = ((TTrabajador*)((TEmpresa*)empresa)->GetListaTrabEmp()->FirstThat(Daemon::D_BuscarTrabajadorID,&IdJefeDpto));
        }
	else
		trab = NULL;

	TCargo* TempCargo;
	int i = 0;
	while(i < StrDpto.CantCargos)
	{
		StructCargoEnDpto StrCargoEnDpto;
		StrCargoEnDpto = StrDpto.aArrCargos[i];
		TempCargo = ((TCargo*)((TEmpresa*)empresa)->GetListaCargosEmp()->ItemInfo(StrCargoEnDpto.PosFicheroCargos));
		TCargo* pCargo = new TCargo(TempCargo->GetNombre(),StrCargoEnDpto.CantPlazasApr,StrCargoEnDpto.CantPlazasReal,TempCargo->GetSalario());
		pNode = new TNode(pCargo);
		CargosList->Insert(pNode);
		i ++;
	}
	int k = 0;
	while(k < StrDpto.CantTrab)
	{
		TTrabajador* pTrabajador;
		int Pos = StrDpto.ArrPuntTrab[k];
		pTrabajador = ((TTrabajador*)((TEmpresa*)empresa)->GetListaTrabEmp()->ItemInfo(Pos));
		pNode = new TNode(pTrabajador);
		TrabList->Insert(pNode);
		k ++;
	}
	TDepartamento* NewDep = new TDepartamento(Nombre,Codigo,trab,CargosList,TrabList);
	return NewDep;
}
//------------------------------------------------------------------------------
void TControlFile::AbrirFicheroCargo()
{
	StructCargo StrCargo;
	FicheroCargo->Open("rb");
	FicheroCargo->Read(&StrCargo,sizeof(StructCargo));
	while(!FicheroCargo->Eof())
	{
		TCargo* pCargo = ConvierteEstructuraAClaseC(StrCargo);
		empresa->AdicionarCargo(pCargo);
		FicheroCargo->Read(&StrCargo,sizeof(StructCargo));
	}
	FicheroCargo->Close();
}
//------------------------------------------------------------------------------
void TControlFile::AbrirFicheroTrab()
{
	StructTrabajador StrTrabajador;
	FicheroTrab->Open("rb");
	FicheroTrab->Read(&StrTrabajador,sizeof(StructTrabajador));
	while(!FicheroTrab->Eof())
	{
		TTrabajador* pTrabajador = ConvierteEstructuraAClaseT(StrTrabajador);
		empresa->AdicionarTrab(pTrabajador);
		FicheroTrab->Read(&StrTrabajador,sizeof(StructTrabajador));
	}
	FicheroTrab->Close();
}
//------------------------------------------------------------------------------
void TControlFile::AbrirFicheroDpto()
{
	StructDpto StrDep;
	FicheroDpto->Open("rb");
	FicheroDpto->Read(&StrDep,sizeof(StructDpto));
	while(!FicheroDpto->Eof())
	{
		TDepartamento* NewDep = ConvierteEstructuraAClaseD(StrDep);
		empresa->AdicionarDepart(NewDep);
		FicheroDpto->Read(&StrDep,sizeof(StructDpto));
	}
	FicheroDpto->Close();
}
//------------------------------------------------------------------------------
void TControlFile::AbrirFicheros()
{
	AbrirFicheroCargo();
	AbrirFicheroTrab();
	AbrirFicheroDpto();
}
//------------------------------------------------------------------------------
void TControlFile::GenerarArchivoDBF(AnsiString nombreFichero)
{
	TDBF* MyDbf = new TDBF(nombreFichero);
	MyDbf->Open();
	StrDbfTrab mystruct;
	AnsiString NoPosee = "No Posee";
	int Length = empresa->GetListaTrabEmp()->Length();
	for(int k = 0; k < Length; k++)
	{
		mystruct = ConvierteClaseaEstructuraDBF((TTrabajador*)empresa->GetListaTrabEmp()->ItemInfo(k));
		if(!(strcmp(mystruct.Cargo,NoPosee.c_str())==0))
		{
			MyDbf->AppendRec(((char*)&mystruct));
		}
	}
	MyDbf->Close();
}

//----------------------------------------------------------------------------
StrDbfTrab TControlFile::ConvierteClaseaEstructuraDBF(TTrabajador* pTrab)
{
	AnsiString NoPosee = "No Posee";
	TDepartamento* Dep;
	StrDbfTrab newTrabajador;

	if(pTrab->GetAlta())
	{
		Dep = empresa->BuscaDepartamentoTrabajador(pTrab->GetIdW());
		StrCopy(newTrabajador.NombreDpto,Dep->GetNombre().c_str());
		StrCopy(newTrabajador.Cargo,(pTrab->GetCargo()->GetNombre()).c_str());
		StrCopy(newTrabajador.HorasExtras,(FloatToStr(pTrab->GetHorasExtras())).c_str());
		StrCopy(newTrabajador.HorasAusencias,(FloatToStr(pTrab->GetHorasAusencias())).c_str());
		StrCopy(newTrabajador.Nombre,pTrab->GetNombre().c_str());
		StrCopy(newTrabajador.DirPart,pTrab->GetDirParticular().c_str());
		StrCopy(newTrabajador.Id,pTrab->GetIdW().c_str());
		StrCopy(newTrabajador.Telefono,pTrab->GetTelefono().c_str());

		if(!pTrab->GetResolucion())
		{
			StrCopy(newTrabajador.Salario,(FloatToStr(pTrab->GetCargo()->GetSalario())).c_str());
			newTrabajador.Resolucion = 'F';
		}
		else
		{
			StrCopy(newTrabajador.Salario,(FloatToStr(pTrab->GetSalarioRes())).c_str());
			newTrabajador.Resolucion = 'V';
		}
		return newTrabajador;
	}
	else
	{
		strcpy(newTrabajador.Cargo,NoPosee.c_str());
		return newTrabajador;
	}
};

//------------------------------------------------------------------------------



//------------------------------------------------------------------------------

