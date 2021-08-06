//---------------------------------------------------------------------------

#ifndef uDBFH
#define uDBFH
//------------------------------------------------------------------------------
#include "UFile.h"
#include <dos.h>
#include <vcl.h>
//------------------------------------------------------------------------------
#define SIZE_HEADER     2
#define SIZE_NAME       11
#define RESERVED_HEADER 20
#define RESERVED_DES    14
typedef char FieldName[SIZE_NAME];
//----------------------------------------------------------------------------
//Encabezamiento general
typedef struct
{
	unsigned char  aIdent, //Identificador de dbf  (1 byte) (03H sin dbt) (83H con dbt)
		aYear,   //Fecha de la ultima actualizacion (3 bytes)
		aMonth,
		aDay;
	int            aRecCount; //Cantidad de records (número de 32 bits)
	unsigned short	aHeaderSize, //Longitud del encabezamiento (número 16 bits)
		aRecSize;  //Longitud del record (número de 16 bits)
	char           aReserved[RESERVED_HEADER];  //Zona reservada    (20 bytes)
} TSDbfGeneralHeader ;
//------------------------------------------------------------------------------
//Descripcitores de campos
typedef struct
{
	FieldName      aName;  //Nombre(11 bytes)
	unsigned char  aType;    //Tipo (C, N, D, L, M)(1 byte)
	int            aRelPosition; //Posición relativa dentro del record (número de 32 bits)
	unsigned char  aLong,    //Longitud del campo(1 byte)
		aDecimal;   //Longitud de la parte decimal (1 byte)
	char           aReserved[RESERVED_DES]; //Zona reservada                  (14 bytes)
} TSDbfFieldDescriptor ;
//------------------------------------------------------------------------------
struct TSDbfTrab
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
//------------------------------------------------------------------------------

class TDBF
{
protected:
	TFile* DbfFile;
	TSDbfGeneralHeader GeneralH;       //encabezamiento general
	TSDbfFieldDescriptor* FieldD;      //descriptores de campo
public:

	TDBF(AnsiString);    //constructor
	~TDBF();                  //destructor
	TFile* GetDbfFile(){return DbfFile;}   //GET
	void Close(){DbfFile->Close();}    //Cerrar
	void Open(); //abre el fichero
	bool IsDbf();   //devuelve verdadero si es DBF
	int GetFieldCount(void);
	void ReadHeader();    //leer el encabezamiento
	void WriteHeader();   //escribir el encabezamiento
	int GetRecSize(void); //tamano de los registros guardados
	void MoveToRec( int RecNo = 0);
	void ReadRec(char* pBuff,int RecSize);
	void WriteRec(char* pBuff,int RecSize);
	void Read (char* &pBuff);
	bool EndFileDBF();
	void UpdateHeader(int DelCount = 0, int AddRec = 0);
	void ReadRecInfo( int RecNo, char * pBuff, int RecSize);
	void DeleteRec( int RecNo); //Logical Erase
	void RemoveRec(int RecNo);
	void Write(char * pBuff);
	void WriteGH();
	void PosRead(int pos, char* &Buff);
	void AppendRec(char* Buff );
	void Create();
	/****/ void FillDescriptorWorker();
};
//------------------------------------------------------------------------------
#endif
