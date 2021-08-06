//---------------------------------------------------------------------------


#pragma hdrstop

#include "uDBF.h"

//------------------------------------------------------------------------------
char END_HEADER = 13;
//----------------------------------------------------------------------------
//Implementaciones de la clase TDBF ------------------------------------------
//----------------------------------------------------------------------------
//Constructor
TDBF::TDBF(AnsiString Name)
{
	DbfFile = new TFile(Name);
	UpdateHeader(0,0);
	GeneralH.aHeaderSize = sizeof(TSDbfGeneralHeader)+ 10 * sizeof(TSDbfFieldDescriptor)+ sizeof(END_HEADER);
	GeneralH.aIdent = 3;
	GeneralH.aRecCount= 0;
	GeneralH.aRecSize = sizeof(TSDbfTrab) + 1;
	FieldD = new TSDbfFieldDescriptor;
	FillDescriptorWorker();
}
//----------------------------------------------------------------------------
TDBF::~TDBF()
{
	Close();
	delete FieldD;
	delete DbfFile;
}
//------------------------------------------------------------------------------
/****/void TDBF::FillDescriptorWorker()
{
	DbfFile->Open("wb");  //Abro el fichero
	WriteGH();     //Escribo el encabezamiento

	//---------- Creo cada descriptor de campo -----------
	AnsiString numeroid = "Numero Id";  //id del trabajador
	strcpy(FieldD->aName,numeroid.c_str());
	FieldD->aType = 'C';
	FieldD->aRelPosition = 1;
	FieldD->aDecimal= 0;
	FieldD->aLong = 12;
	DbfFile->Write(FieldD,sizeof(TSDbfFieldDescriptor));

	AnsiString nombre = "Nombre";  //nombre del trab
	strcpy(FieldD->aName,nombre.c_str());
	FieldD->aType = 'C';
	FieldD->aRelPosition = 2;
	FieldD->aDecimal = 0;
	FieldD->aLong = 31;
	DbfFile->Write(FieldD,sizeof(TSDbfFieldDescriptor));

	AnsiString dir = "Direccion";  //direccion particular
	strcpy(FieldD->aName,dir.c_str());
	FieldD->aType = 'C';
	FieldD->aRelPosition = 3;
	FieldD->aDecimal = 0;
	FieldD->aLong = 51;
	DbfFile->Write(FieldD,sizeof(TSDbfFieldDescriptor));

	AnsiString telefono = "Telefono";  //telefono
	strcpy(FieldD->aName,telefono.c_str());
	FieldD->aType = 'C';
	FieldD->aRelPosition = 4;
	FieldD->aDecimal = 0;
	FieldD->aLong = 13;
	DbfFile->Write(FieldD,sizeof(TSDbfFieldDescriptor));

	AnsiString dpto = "Dpto"; //depto
	strcpy(FieldD->aName,dpto.c_str());
	FieldD->aType = 'C';
	FieldD->aRelPosition = 5;
	FieldD->aDecimal = 0;
	FieldD->aLong = 21;
	DbfFile->Write(FieldD,sizeof(TSDbfFieldDescriptor));

	AnsiString res = "Resolucion";  //si es o no resolucion
	strcpy(FieldD->aName,res.c_str());
	FieldD->aType = 'C';
	FieldD->aRelPosition = 6;
	FieldD->aDecimal = 0;
	FieldD->aLong = 1;
	DbfFile->Write(FieldD,sizeof(TSDbfFieldDescriptor));

	AnsiString cargo = "Cargo";  //nombre del cargo
	strcpy(FieldD->aName,cargo.c_str());
	FieldD->aType = 'C';
	FieldD->aRelPosition = 7;
	FieldD->aDecimal = 0;
	FieldD->aLong = 21;
	DbfFile->Write(FieldD,sizeof(TSDbfFieldDescriptor));


	AnsiString hextras = "H.Extras";  //horas extras
	strcpy(FieldD->aName,hextras.c_str());
	FieldD->aType = 'N';
	FieldD->aRelPosition = 8;
	FieldD->aDecimal = 2;
	FieldD->aLong = 7;
	DbfFile->Write(FieldD,sizeof(TSDbfFieldDescriptor));

	AnsiString hausencias = "H.Ausen";  //horas ausencias
	strcpy(FieldD->aName,hausencias.c_str());
	FieldD->aType = 'N';
	FieldD->aRelPosition = 9;
	FieldD->aDecimal = 2;
	FieldD->aLong = 7;
	DbfFile->Write(FieldD,sizeof(TSDbfFieldDescriptor));


	AnsiString salario = "Salario";  //si es o no resolucion
	strcpy(FieldD->aName,salario.c_str());
	FieldD->aType = 'N';
	FieldD->aRelPosition = 10;
	FieldD->aDecimal = 2;
	FieldD->aLong = 8;
	DbfFile->Write(FieldD,sizeof(TSDbfFieldDescriptor));

	//Fin de la creacion de los descriptores de campo
	DbfFile->Write(&END_HEADER,sizeof(END_HEADER));  //escribo la marca de fin de los descriptores de campo

	DbfFile->Close();
}

//----------------------------------------------------------------------------
bool TDBF::IsDbf()
{
	DbfFile->SeekTo(0);
	DbfFile->Read(&GeneralH,sizeof(TSDbfGeneralHeader));
	if(GeneralH.aIdent != 3 && GeneralH.aIdent != 131)
	{
		DbfFile->Close();
		return false;
	}
	return true;
}
//----------------------------------------------------------------------------
void TDBF::Open()
{
	DbfFile->Open("rb+");
}
//----------------------------------------------------------------------------
bool TDBF::EndFileDBF()
{
	return DbfFile->Eof();
}
//----------------------------------------------------------------------------
int TDBF::GetRecSize(void)
{
	return GeneralH.aRecSize;
}
//----------------------------------------------------------------------------
int TDBF::GetFieldCount(void)
{
	return (GeneralH.aHeaderSize - sizeof(TSDbfGeneralHeader))/sizeof(TSDbfFieldDescriptor);
}
//----------------------------------------------------------------------------
void TDBF::ReadHeader()
{
	if(!IsDbf())
		return;
	DbfFile->SeekTo(0);
	DbfFile->Read(&GeneralH,sizeof(TSDbfGeneralHeader));
	int FieldDescCount = GetFieldCount();
	//int FieldDescCount = 7;
	FieldD = new TSDbfFieldDescriptor[FieldDescCount];
	DbfFile->Read(FieldD,sizeof(TSDbfFieldDescriptor),FieldDescCount);
	DbfFile->Read(&END_HEADER,sizeof(END_HEADER));
}
//----------------------------------------------------------------------------
void TDBF::WriteHeader()
{
	if(!IsDbf())
		return;
	DbfFile->SeekTo(0);
	DbfFile->Write(&GeneralH,sizeof(TSDbfGeneralHeader));
	int FieldDescCount = GetFieldCount();
	DbfFile->Write(FieldD,sizeof(TSDbfFieldDescriptor),FieldDescCount);
	DbfFile->Write(&END_HEADER,sizeof(END_HEADER));
}
//----------------------------------------------------------------------------
void TDBF::MoveToRec(int RecNo)
{
	int pos = GeneralH.aHeaderSize;
	pos = pos + (GetRecSize() * RecNo);
	DbfFile->SeekTo(pos);
}
//----------------------------------------------------------------------------
void TDBF::ReadRec(char* pBuff,int RecSize)
{
	DbfFile->Read(pBuff,sizeof(char),RecSize);
}
//----------------------------------------------------------------------------
void TDBF::WriteRec(char* pBuff,int RecSize)
{
	DbfFile->Write(pBuff,sizeof(char),RecSize);
}
//----------------------------------------------------------------------------
void TDBF::PosRead(int pos, char* &Buff)
{
	MoveToRec(pos);
	Read(Buff);
}
//----------------------------------------------------------------------------
void TDBF::UpdateHeader(int DelCount, int AddRec)
{
	unsigned char d,m,a;
	struct date dt;
	getdate(&dt);
	d = dt.da_day;
	m = dt.da_mon;
	a = (char)(dt.da_year - 2000);
	//actualizo
	GeneralH.aDay = d;
	GeneralH.aMonth = m;
	GeneralH.aYear = a;
	GeneralH.aRecCount -= DelCount;
	GeneralH.aRecCount += AddRec;
}
//----------------------------------------------------------------------------
void TDBF::Read (char* &pBuff)
{
	char * Buff = new char[GeneralH.aRecSize];
	memset(Buff,32,GeneralH.aRecSize);
	memset(pBuff,32,GeneralH.aRecSize);
	ReadRec(Buff,GeneralH.aRecSize);
	memcpy(pBuff,Buff + 1,GeneralH.aRecSize-1);
}
//----------------------------------------------------------------------------
void TDBF::ReadRecInfo( int RecNo, char * pBuff, int RecSize)
{
	MoveToRec(RecNo);
	ReadRec(pBuff,RecSize);
}
//----------------------------------------------------------------------------
void TDBF::DeleteRec( int RecNo) //Logical Erase//
{
	char * Buff = new char[GetRecSize()];
	if(!IsDbf())
		return;
	ReadRecInfo(RecNo,Buff,GetRecSize());
	Buff[0] = '*';
	MoveToRec(RecNo);
	WriteRec(Buff,GetRecSize());
}
//----------------------------------------------------------------------------
void TDBF::WriteGH()
{
	DbfFile->SeekTo(0);
	DbfFile->Write(&GeneralH,sizeof(TSDbfGeneralHeader));
}
//----------------------------------------------------------------------------
void TDBF::Write(char * pBuff)
{
	char * Buff = new char[GeneralH.aRecSize];
	memset(Buff,32,GeneralH.aRecSize);
	memcpy(Buff + 1,pBuff,GeneralH.aRecSize-1);
	WriteRec(Buff,GeneralH.aRecSize);
	delete Buff;
}
//----------------------------------------------------------------------------
void TDBF::RemoveRec(int RecNo)
{
	if(RecNo >= 0 && RecNo < GeneralH.aRecCount)
		DeleteRec(RecNo);
}
//----------------------------------------------------------------------------
void TDBF::AppendRec(char* Buff)
{
	MoveToRec(GeneralH.aRecCount);
	Write(Buff);
	UpdateHeader(0,1);
	WriteGH();
}
//------------------------------------------------------------------------------

#pragma package(smart_init)
