//---------------------------------------------------------------------------
#ifndef uClasesH
#define uClasesH
#include <vcl.h>
#include "string.h"
#include "EstructuraListas.h"
#include "UFile.h"
#include "uDBF.h"
//---------------------------------------------------------------------------
struct TSPos
{
	AnsiString Id;
	int pos;
};
struct TSPos1
{
	AnsiString nombre;
	int pos;
};

struct TSSalarioTrab
{
	float salarioRes;
	float salarioCargo;
};

struct TSOrdenaCargos
{
	int cantelem;
	TGLinkedList* ListaTemp;
};
struct TSNominaTrab
{
	TGLinkedList* ListaTrab;
	TGLinkedList* ListaOrdenada;
};

struct TSTrabajadoresEnCargo
{
        TGLinkedList* ListaOrdenada;
        AnsiString Cargo;

};
struct TSCambiarNombre  //void CambiarDatosCargosEnDpto()
{
        AnsiString NombreViejo;
        AnsiString NombreNuevo;
        float NuevoSalario;
};

struct TSCambiarSalario
{
        AnsiString Nombre;
        float SalNuevo;
};
//---------------------------------------------------------------------------
//Estructuras para fichero
struct StructCargoEnDpto
{
	int PosFicheroCargos;
	int CantPlazasApr;
	int CantPlazasReal;
};

struct StructCargo
{
	char Nombre[20];
	int CantPlazasApr;
	int CantPlazasReal;
	float Salario;
};

struct StructTrabajador
{
	char Nombre[30];
	char Id[12];
	char DirPart[50];
	char Telefono[13];
	char Resolucion; //F o V del bool correspondiente
	float SalarioRes;
	char alta;
	char NombreDpto[20];
	int PosFichCargo;
	float HorasAusencias;
	float HorasExtras;
};

struct StructDpto
{
	char NombreDpto[20];
	char CodigoDpto[11];
	char IdJefeDpto[11];
	StructCargoEnDpto aArrCargos[30];
	int CantCargos;
	int ArrPuntTrab[20];
	int CantTrab;
};
struct StrDbfTrab
{
	char Id[12];
	char Nombre[31];
	char DirPart[51];
	char Telefono[13];
	char NombreDpto[21];
	char Resolucion; //F o V del bool correspondiente
	char Cargo[21];
	char HorasExtras[7];//era float
	char HorasAusencias[7];//era float
	char Salario[8];//era float 6
};
//---------------------------------------------------------------------------
class TCargo
{
private:
	AnsiString aNombre;
	int aCantPlazasApr;
	int aCantPlazasReal;
	float aSalario;

public:
	TCargo(AnsiString pNombre):aNombre(pNombre),aCantPlazasApr(0),aCantPlazasReal(0),aSalario(0){}
	TCargo(AnsiString pNombre,int pCantPlazasApr):aNombre(pNombre),aCantPlazasApr(pCantPlazasApr),aCantPlazasReal(0),aSalario(0){}
	TCargo(AnsiString pNombre,int PlazasAprobadas,int PlazasReales,float pSalario):aNombre(pNombre),aCantPlazasApr(PlazasAprobadas),aCantPlazasReal(PlazasReales),aSalario(pSalario){}
	void SetNombre(AnsiString pNombre){aNombre = pNombre;}
	AnsiString GetNombre(){return aNombre;}
	void SetSalario(float pSalario){aSalario = pSalario;}
	float GetSalario(){return aSalario;}
	void SetPlazasApr(int pCantPlazasApr){aCantPlazasApr = pCantPlazasApr;}
	int GetPlazasApr(){return aCantPlazasApr;}
	int GetPlazasReales(){return aCantPlazasReal;}
	void SetPlazasReales(int PlazasReales){aCantPlazasReal = PlazasReales;}
	void IncPlazasReales(){aCantPlazasReal++;}
	void DecPlazasReales(){aCantPlazasReal--;}
	int PlazasDisponibles(){return aCantPlazasApr - aCantPlazasReal;}
	float EstadoCargo();
};
//---------------------------------------------------------------------------
class TTrabajador
{
private:
	AnsiString aNombreW;
	AnsiString aIdW;
	AnsiString aDirParticular;
	AnsiString aTelefono;
	TCargo* Cargo;
	bool aResolucion;
	float aSalarioRes;
	bool alta;
	float aHorasExtras;
	float aHorasAusencias;

public:
	TTrabajador(AnsiString pNombreW,AnsiString pIdW,AnsiString pDirParticular,AnsiString pTelefono)
	{
		aNombreW = pNombreW;
		aIdW = pIdW;
		aDirParticular = pDirParticular;
		aTelefono = pTelefono;
		Cargo = NULL;
		aResolucion = false;
		aSalarioRes = 0;
		alta = false;
		aHorasExtras = 0;
		aHorasAusencias = 0;
	}
	TTrabajador(AnsiString,AnsiString,AnsiString,AnsiString,bool,bool,float,TCargo*,float,float);
	void  SetNombre(AnsiString pNombre){aNombreW = pNombre;}
	AnsiString GetNombre(){return aNombreW;}
	void  SetIdW(AnsiString pIdW){aIdW = pIdW;}
	AnsiString GetIdW(){return aIdW;}
	void SetDirParticular(AnsiString pDir){aDirParticular = pDir;}
	AnsiString GetDirParticular(){return aDirParticular;}
	void SetTelefono(AnsiString pTelef){aTelefono = pTelef;}
	AnsiString GetTelefono(){return aTelefono;}
	void SetResolucion(bool pResolucion){aResolucion = pResolucion;}
	bool GetResolucion(){return aResolucion;}
	void SetSalarioRes(float pSalarioRes){aSalarioRes = pSalarioRes;}
	float GetSalarioRes(){return aSalarioRes;}
	void SetAltaTrue(){alta = true;}
	bool GetAlta(){return alta;}
	void SetCargo(TCargo* pCargo){Cargo = pCargo;}
	TCargo* GetCargo(){return Cargo;}
	float GetHorasExtras(){return aHorasExtras;}
	void SetHorasExtras(float pHorasExtras){aHorasExtras=pHorasExtras;}
	void SetHorasAusencias(float pHorasAusencias){aHorasAusencias = pHorasAusencias;}
	float GetHorasAusencias(){return aHorasAusencias;}
        float CalcularSalarioCobro();

};
//---------------------------------------------------------------------------
class TDepartamento
{
private:
	AnsiString aNombreDpto;
	AnsiString aCodigoDpto;
	TTrabajador* JefeDepartamento; //está a NULL al principio
	TGLinkedList* ListaTrabDep;
	TGLinkedList* ListaCargosDep;
public:
	TDepartamento(AnsiString pNombreDpto,AnsiString pCodigoDpto,TGLinkedList* pListaCargos)
	{
		aNombreDpto = pNombreDpto;
		aCodigoDpto = pCodigoDpto;
		JefeDepartamento = NULL;
		ListaCargosDep = pListaCargos;
		ListaTrabDep = new TGLinkedList;
	}
	TDepartamento(AnsiString pNombreDpto,AnsiString pCodigoDpto,TTrabajador* pJefeDepart,
		TGLinkedList* pListaCargos,TGLinkedList* pListaTrab)
	{
		aNombreDpto = pNombreDpto;
		aCodigoDpto = pCodigoDpto;
		JefeDepartamento = pJefeDepart;
		ListaCargosDep = pListaCargos;
		ListaTrabDep = pListaTrab;
	}
	~TDepartamento();
        void SetNombre(AnsiString pNombreDpto){aNombreDpto = pNombreDpto;}
	AnsiString GetNombre(){return aNombreDpto;}
        void SetCodigo(AnsiString pCodigoDpto){aCodigoDpto = pCodigoDpto;}
	AnsiString GetCodigo(){return aCodigoDpto;}
	TGLinkedList* GetListaCargos(){return ListaCargosDep;}
	void SetJefeDepartamento(TTrabajador* pJefeDepart){JefeDepartamento = pJefeDepart;}
	TTrabajador* GetJefeDepartamento(){return JefeDepartamento;}
	TGLinkedList* GetListaTrabDep(){return ListaTrabDep;}
	void AdicionarTrab(TTrabajador* ptrab){TNode* node =  new TNode(ptrab); ListaTrabDep->Insert(node);}
	float CalcularEstadoPlantilla();
	bool BuscarTrabajador(AnsiString id);
	void EliminarTrabajador(AnsiString id);
	float FondoSalarioAprobadoDpto();
	float FondoSalarioRealDpto();
	void EliminarCargo(TCargo* pCargo);
	/***/void NominaTrabajadores(TGLinkedList* pLista);
        /***/float CalcularPorcientoAusentismo();
        /***/float CalcularHorasAusentismo();
};
//---------------------------------------------------------------------------
struct TSCargoPlazas   //PlazasMenosCubiertas()
{
	TDepartamento* departamento;
	TCargo* cargo;
};
//---------------------------------------------------------------------------
class TEmpresa
{
private:
	AnsiString aNombre;
	TGLinkedList* ListaDepartamentos;
	TGLinkedList* ListaTrabEmp;
	TGLinkedList* ListaCargosEmp;

public:
	TEmpresa(AnsiString);
	~TEmpresa();
	AnsiString GetNombre(){return aNombre;}
	TGLinkedList* GetListaDptos(){return ListaDepartamentos;}
	TGLinkedList* GetListaCargosEmp(){return ListaCargosEmp;}
	TGLinkedList* GetListaTrabEmp(){return ListaTrabEmp;}
	void AdicionarCargo(TCargo* pcargo){TNode* node = new TNode(pcargo);ListaCargosEmp->Insert(node);}
	void AdicionarTrab(TTrabajador* ptrab){TNode* node = new TNode(ptrab);ListaTrabEmp->Insert(node);}
	void AdicionarDepart(TDepartamento* pdepart){TNode* node = new TNode(pdepart);ListaDepartamentos->Insert(node);}
	TTrabajador* BuscarTrabajador(AnsiString pNombre);
	TTrabajador* BuscarTrabajadorID(AnsiString pid);
	TCargo* BuscarCargo(AnsiString pNombre);
	TDepartamento* BuscarDepartamento(AnsiString pNombre);
	TDepartamento* BuscarDepartamentoID(AnsiString pCodigo);
	float CalcularEstadoPlantilla();
	TDepartamento* BuscaDepartamentoTrabajador(AnsiString id);
	float FondoSalarioAprobado();
	float FondoSalarioReal();
        void CambiarDatosCargosEnDpto(AnsiString pNombreViejo,AnsiString pNombreNuevo,float pNuevoSalario);
	/***/ TGLinkedList* PlazasMenosCubiertas();
        /***/ TGLinkedList* NominaDeTrabajadores();
        /***/ TGLinkedList* OrdenaListaDptos();
	void EliminarTrabajador(TTrabajador* trab);
	void EliminarTrabsDelCargo(TCargo* pCargo);
	void EliminarCargo(TCargo* pCargo);
	void EliminarDepartamento(TDepartamento* dpto);

};
//------------------------------------------------------------------------------
class TControlFile
{
private:
	TFile* FicheroCargo;
	TFile* FicheroTrab;
	TFile* FicheroDpto;
	bool aGuardado;
	AnsiString aNombreFichEmp;
public:
	TControlFile();
	TControlFile(AnsiString,AnsiString,AnsiString);
	~TControlFile(){};
	TFile* GetFiheroCargo(){return FicheroCargo;}
	TFile* GetFiheroTrab(){return FicheroTrab;}
	TFile* GetFiheroDpto(){return FicheroDpto;}
	bool GetGuardado(){return aGuardado;}
	void SetGuardado(bool Estado){aGuardado = Estado;}
	AnsiString GetNombreFichEmp(){return aNombreFichEmp;}
	void Set(AnsiString pNombreFichEmp){aNombreFichEmp = pNombreFichEmp;}

	//metodos que convierten de P2 a fichero;
	StructCargo ConvierteClaseAEstructuraC(TCargo*);
	StructTrabajador ConvierteClaseAEstructuraT(TTrabajador*);
	StructDpto ConvierteClaseAEstructuraD(TDepartamento*);
	StrDbfTrab ConvierteClaseaEstructuraDBF(TTrabajador*);
	void GuardarFicheroCargo();
	void GuardarFicheroTrab();
	void GuardarFicheroDpto();
	void GuardarFicheros();
	void GenerarArchivoDBF(AnsiString nombreFichero);
	int PosCargo(AnsiString);
	int PosTrabajador(AnsiString);

	//metodos que convirten de fichero a P2
	TCargo* ConvierteEstructuraAClaseC(StructCargo);
	TTrabajador* ConvierteEstructuraAClaseT(StructTrabajador);
	TDepartamento* ConvierteEstructuraAClaseD(StructDpto);
	void AbrirFicheroTrab();
	void AbrirFicheroCargo();
	void AbrirFicheroDpto();
	void AbrirFicheros();
};
//------------------------------------------------------------------------------
#include "uGlobal.h"
//------------------------------------------------------------------------------
#endif

