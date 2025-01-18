//---------------------------------------------------------------------------

#ifndef UDMH
#define UDMH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <FireDAC.Phys.MSSQL.hpp>
#include <FireDAC.Phys.MSSQLDef.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE-managed Components
	TFDConnection *BAZA;
	TFDQuery *QAUTENTIFICARE;
	TFDQuery *QLIBER;
	TFDQuery *QUM;
	TDataSource *DSQUM;
	TFDQuery *QPRODUS;
	TDataSource *DSQPRODUS;
	TFDQuery *QEMITENT;
	TDataSource *DSQEMITENT;
	TFDQuery *QFACTURA;
	TDataSource *DSQFACTURA;
	TFDQuery *QDATEFACTURA;
	TDataSource *DSQDATEFACTURA;
	TFDAutoIncField *QAUTENTIFICAREFIRMA_ID;
	TStringField *QAUTENTIFICARENUME;
	TStringField *QAUTENTIFICARECOD_FISCAL;
	TStringField *QAUTENTIFICAREADRESA;
	TFDAutoIncField *QAUTENTIFICAREFIRMA_OPERATOR_ID;
	TIntegerField *QAUTENTIFICAREFIRMA_ID_1;
	TStringField *QAUTENTIFICARETIP_ACCES;
	TIntegerField *QAUTENTIFICAREOPERATOR_ID;
	TFDAutoIncField *QAUTENTIFICAREOPERATOR_ID_1;
	TStringField *QAUTENTIFICARENUME_1;
	TStringField *QAUTENTIFICAREPRENUME;
	TStringField *QAUTENTIFICAREFUNCTIA;
	TStringField *QAUTENTIFICAREUSERNAME;
	TStringField *QAUTENTIFICAREPASS;
	TStringField *QAUTENTIFICARECOD;
	TIntegerField *QAUTENTIFICARETIP_ACCES_1;
	TStringField *QAUTENTIFICAREFIRMA;
	TStringField *QAUTENTIFICAREOPERATOR;
	TStringField *QAUTENTIFICAREACCES;
	TFDAutoIncField *QUMUNIT_MASURA_ID;
	TStringField *QUMABREVIERE;
	TStringField *QUMNUME;
	TFDAutoIncField *QPRODUSPRODUSE_ID;
	TStringField *QPRODUSDENUMIRE;
	TStringField *QPRODUSCOD_PRODUS;
	TFDAutoIncField *QEMITENTEMITENT_ID;
	TStringField *QEMITENTDENUMIRE;
	TStringField *QEMITENTIDNO;
	TStringField *QEMITENTADRESA;
	TStringField *QFACTURAOPERATOR;
	TStringField *QFACTURAEMITENT;
	TBCDField *QFACTURADIF;
	TFMTBCDField *QFACTURAPROCENT_TVA;
	TFDAutoIncField *QFACTURARECEPTIE_ID;
	TIntegerField *QFACTURAPRODUSE_ID;
	TIntegerField *QFACTURAUNIT_MASURA_ID;
	TIntegerField *QFACTURAFACTURA_REC_ID;
	TIntegerField *QFACTURAFIRMA_OPERATOR_ID;
	TIntegerField *QFACTURASTOCK1;
	TIntegerField *QFACTURASTOCK2;
	TBCDField *QFACTURAPRET_INTRARE;
	TBCDField *QFACTURAPRET_VANZ;
	TIntegerField *QFACTURATVA;
	TBooleanField *QFACTURAACTIV;
	TFDAutoIncField *QFACTURAPRODUSE_ID_1;
	TStringField *QFACTURADENUMIRE;
	TStringField *QFACTURACOD_PRODUS;
	TFDAutoIncField *QFACTURAUNIT_MASURA_ID_1;
	TStringField *QFACTURAABREVIERE;
	TStringField *QFACTURANUME;
	TFDAutoIncField *QFACTURAFACTURA_REC_ID_1;
	TStringField *QFACTURANR_FACTURA;
	TDateField *QFACTURADATA_FACTURA;
	TStringField *QFACTURAEMITENT_1;
	TIntegerField *QFACTURAEMITENT_ID;
	TFDAutoIncField *QFACTURAFIRMA_OPERATOR_ID_1;
	TIntegerField *QFACTURAFIRMA_ID;
	TStringField *QFACTURATIP_ACCES;
	TIntegerField *QFACTURAOPERATOR_ID;
	TFDAutoIncField *QFACTURAOPERATOR_ID_1;
	TStringField *QFACTURANUME_1;
	TStringField *QFACTURAPRENUME;
	TStringField *QFACTURAFUNCTIA;
	TStringField *QFACTURAUSERNAME;
	TStringField *QFACTURAPASS;
	TStringField *QFACTURACOD;
	TIntegerField *QFACTURATIP_ACCES_1;
	TFDAutoIncField *QFACTURAEMITENT_ID_1;
	TStringField *QFACTURADENUMIRE_1;
	TStringField *QFACTURAIDNO;
	TStringField *QFACTURAADRESA;
	TStringField *QDATEFACTURAEMITENT;
	TStringField *QDATEFACTURANR_FACTURA;
	TDateField *QDATEFACTURADATA_FACTURA;
	TIntegerField *QDATEFACTURANR_POZ;
	TFMTBCDField *QDATEFACTURAPRET_INTRARE;
	TFMTBCDField *QDATEFACTURAPRET_TVA;
	TFMTBCDField *QDATEFACTURAPRET_TOT;
	TFDStoredProc *PFACTURA;
	TFDStoredProc *PCEK;
	TFDAutoIncField *QDATEFACTURAEMITENT_ID;
	TFDQuery *QVANZARE;
	TDataSource *DSQVANZARE;
	TFDQuery *QDATECEC;
	TDataSource *DSDATECEC;
private:	// User declarations
public:		// User declarations
	__fastcall TDM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
