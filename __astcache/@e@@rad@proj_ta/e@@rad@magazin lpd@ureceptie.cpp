//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "URECEPTIE.h"
#include "UDM.h"
#include "UAUTENTIFICARE.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFRECEPTIE *FRECEPTIE;
int PAG = 1, PAGG = 1, PRODUS_ID, FACTURA_ID, RECEPTIE_ID, UM_ID, EMITENT_ID;
//---------------------------------------------------------------------------
__fastcall TFRECEPTIE::TFRECEPTIE(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFRECEPTIE::RB1Click(TObject *Sender)
{
    ECAUTA->Clear();
	if(RB1->Checked)
	{
		ECAUTA->TextHint = "DENUMIRE PRODUS";
		ECAUTA->NumbersOnly=0;
	}
	else
	{
		ECAUTA->TextHint = "COD PRODUS";
        ECAUTA->NumbersOnly=1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::ECAUTAChange(TObject *Sender)
{
	if(ECAUTA->Text!= "")
	{
		DM->QPRODUS->Close();
		DM->QPRODUS->SQL->Clear();
		DM->QPRODUS->SQL->Add("SELECT * FROM PRODUSE WHERE ");
		if(RB1->Checked)
			DM->QPRODUS->SQL->Add(" DENUMIRE LIKE '%"+ECAUTA->Text+"%' ");
		else
			DM->QPRODUS->SQL->Add(" COD_PRODUS LIKE '%"+ECAUTA->Text+"%' ");
        DM->QPRODUS->Open();
	}
	else
	{
		DM->QPRODUS->Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::BitBtn4Click(TObject *Sender)
{
    PAG=1;
	MENIU->TabVisible = 0;
	FACTURA->TabVisible = 0;
	PRODUS->TabVisible = 1;
	UM->TabVisible = 0;
	EMITENT->TabVisible = 0;
	DATEFACTURA->TabVisible = 0;
	CLIENT->TabVisible = 0;

    RB1->Checked = true;
	ECAUTA->Clear();
    DM->QPRODUS->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::FormShow(TObject *Sender)
{
	MENIU->TabVisible = 1;
	FACTURA->TabVisible = 0;
	PRODUS->TabVisible = 0;
	UM->TabVisible = 0;
	EMITENT->TabVisible = 0;
	DATEFACTURA->TabVisible = 0;
	CLIENT->TabVisible = 0;
}
//---------------------------------------------------------------------------


void __fastcall TFRECEPTIE::Button1Click(TObject *Sender)
{
	DM->QEMITENT->Close();
	DM->QEMITENT->Open();

    PAG = 2;
	MENIU->TabVisible = 0;
	FACTURA->TabVisible = 0;
	PRODUS->TabVisible = 0;
	UM->TabVisible = 0;
	EMITENT->TabVisible = 1;
	DATEFACTURA->TabVisible = 0;
	CLIENT->TabVisible = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::BitBtn15Click(TObject *Sender)
{
	if(!DM->QEMITENT->IsEmpty() )
	{
		EEMITENT->Text = DM->QEMITENTDENUMIRE->AsString;
		EMITENT_ID = DM->QEMITENTEMITENT_ID->AsInteger;
		BitBtn16->Click();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::BitBtn16Click(TObject *Sender)
{
	if(PAG == 1 )
	{
		MENIU->TabVisible = 1;
		FACTURA->TabVisible = 0;
	}
	else
	{
		MENIU->TabVisible = 0;
		FACTURA->TabVisible = 1;
	}

	PRODUS->TabVisible = 0;
	UM->TabVisible = 0;
	EMITENT->TabVisible = 0;
	DATEFACTURA->TabVisible = 0;
	CLIENT->TabVisible = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::SpeedButton1Click(TObject *Sender)
{
	PAG=2;
	MENIU->TabVisible = 0;
	FACTURA->TabVisible = 0;
	PRODUS->TabVisible = 1;
	UM->TabVisible = 0;
	EMITENT->TabVisible = 0;
	DATEFACTURA->TabVisible = 0;
	CLIENT->TabVisible = 0;

    RB1->Checked = true;
	ECAUTA->Clear();
	DM->QPRODUS->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::BitBtn13Click(TObject *Sender)
{
	if(!DM->QPRODUS->IsEmpty() )
	{
		EPRODUS->Text = DM->QPRODUSDENUMIRE->AsString;
		EPRODUS2->Text = DM->QPRODUSDENUMIRE->AsString;
		PRODUS_ID = DM->QPRODUSPRODUSE_ID->AsInteger;
		BitBtn16->Click();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::SpeedButton2Click(TObject *Sender)
{
	DM->QUM->Close();
	DM->QUM->Open();
	PAG = 2;

	MENIU->TabVisible = 0;
	FACTURA->TabVisible = 0;
	PRODUS->TabVisible = 0;
	UM->TabVisible = 1;
	EMITENT->TabVisible = 0;
	DATEFACTURA->TabVisible = 0;
	CLIENT->TabVisible = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::BitBtn7Click(TObject *Sender)
{
	if(!DM->QUM->IsEmpty() )
	{
		EUM->Text = DM->QUMABREVIERE->AsString;
		EUM2->Text = DM->QUMABREVIERE->AsString;
		UM_ID = DM->QUMUNIT_MASURA_ID->AsInteger;
        BitBtn16->Click();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::Button2Click(TObject *Sender)
{
	if((ESERIA->Text!="") && (EEMITENT->Text!="") )
	{
		DM->QLIBER->Close();
		DM->QLIBER->SQL->Clear();
		DM->QLIBER->SQL->Add("SELECT * FROM FACTURA_REC WHERE EMITENT_ID=:EID AND NR_FACTURA=:NR AND DATA_FACTURA=:DATAF");
		DM->QLIBER->ParamByName("EID")->AsInteger = EMITENT_ID;
		DM->QLIBER->ParamByName("NR")->AsString = ESERIA->Text;
		DM->QLIBER->ParamByName("DATAF")->AsDate = EDATA->Date;
		DM->QLIBER->Open();

		if(DM->QLIBER->IsEmpty() )//nu este factura inregistrata
		{
			DM->PFACTURA->Close();
			DM->PFACTURA->ParamByName("@E")->AsInteger = EMITENT_ID;
			DM->PFACTURA->ParamByName("@N")->AsString = ESERIA->Text;
			DM->PFACTURA->ParamByName("@D")->AsDate = EDATA->Date;
			DM->PFACTURA->ExecProc();
			FACTURA_ID = DM->PFACTURA->ParamByName("@RETURN_VALUE")->AsInteger;

			FINREGISTRARE->TabVisible = 1;
			FMENIU->TabVisible = 0;
		}
		else //deschidem factura
		{
			DM->QFACTURA->Close();
			DM->QFACTURA->ParamByName("ID")->AsInteger = DM->QLIBER->FieldByName("FACTURA_REC_ID")->AsInteger;
			DM->QFACTURA->Open();
			FACTURA_ID = DM->QLIBER->FieldByName("FACTURA_REC_ID")->AsInteger;

			FINREGISTRARE->TabVisible = 0;

			FMENIU->TabVisible = 1;
		}

		FMAIN->TabVisible = 0;
		FEDITARE->TabVisible = 0;
	}
	else
	{
        ShowMessage("Nu sunt indicate toate campurile necesare!!!");
    }
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::BitBtn2Click(TObject *Sender)
{
	FMAIN->TabVisible = 1;
	FMENIU->TabVisible = 0;
	FINREGISTRARE->TabVisible = 0;
	FEDITARE->TabVisible = 0;
    PAGG = 1;

	DM->QFACTURA->Close();
	ESERIA->Clear();
    EEMITENT->Clear();

	MENIU->TabVisible = 0;
	FACTURA->TabVisible = 1;
	PRODUS->TabVisible = 0;
	UM->TabVisible = 0;
	EMITENT->TabVisible = 0;
	DATEFACTURA->TabVisible = 0;
	CLIENT->TabVisible = 0;
}
//---------------------------------------------------------------------------


void __fastcall TFRECEPTIE::SpeedButton3Click(TObject *Sender)
{
	if((EPRODUS->Text != "") && (EUM->Text != "") && (EPV->Text != "") )
	{
		DM->QLIBER->Close();
		DM->QLIBER->SQL->Clear();
		DM->QLIBER->SQL->Add("INSERT INTO RECEPTIE(FACTURA_REC_ID,FIRMA_OPERATOR_ID,PRODUSE_ID,UNIT_MASURA_ID,STOCK1,PRET_INTRARE,PRET_VANZ,TVA)");
		DM->QLIBER->SQL->Add("VALUES(:FACTURA_REC_ID,:FIRMA_OPERATOR_ID,:PRODUSE_ID,:UNIT_MASURA_ID,:STOCK1,:PRET_INTRARE,:PRET_VANZ,:TVA)");
		DM->QLIBER->ParamByName("FACTURA_REC_ID")->AsInteger = FACTURA_ID;
		DM->QLIBER->ParamByName("FIRMA_OPERATOR_ID")->AsInteger = FAUTENTIFICARE->UTILIZATOR_ID;
		DM->QLIBER->ParamByName("PRODUSE_ID")->AsInteger = PRODUS_ID;
		DM->QLIBER->ParamByName("UNIT_MASURA_ID")->AsInteger = UM_ID;
		DM->QLIBER->ParamByName("STOCK1")->AsInteger = ESTOC->Text.ToInt();
		DM->QLIBER->ParamByName("PRET_INTRARE")->AsFloat = EPI->Text.ToDouble();
		DM->QLIBER->ParamByName("PRET_VANZ")->AsFloat = EPV->Text.ToDouble();
		DM->QLIBER->ParamByName("TVA")->AsInteger = ETVA->Text.ToInt();
		DM->QLIBER->ExecSQL();

		EPRODUS->Clear();
		EUM->Clear();
		ESTOC->Clear();
		EPI->Clear();
		EPV->Clear();
		EADAOS->Clear();
		ETVA->ItemIndex = -1;

		DM->QFACTURA->Close();
		DM->QFACTURA->ParamByName("ID")->AsInteger = FACTURA_ID;
		DM->QFACTURA->Open();

		ShowMessage("Inregistrare cu succes");
    }
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::ETVAChange(TObject *Sender)
{
	if((EPI->Text != "") && (EPI->Text.ToDouble() > 0 ) && (EADAOS->Text != "") && (EADAOS->Text.ToDouble() > 0 ) )
	{
		float a;
		a = EPI->Text.ToDouble()*(ETVA->Text.ToDouble()/100);
		EPV->Text = FloatToStr(EPI->Text.ToDouble()+a+EADAOS->Text.ToDouble() );
	}
	else
	{
		EPV->Clear();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::SpeedButton12Click(TObject *Sender)
{
	EPRODUS->Clear();
	EUM->Clear();
	ESTOC->Clear();
	EPI->Clear();
	EPV->Clear();
	EADAOS->Clear();
	ETVA->ItemIndex = -1;
	FMAIN->TabVisible = 0;
	FMENIU->TabVisible = 0;
	FINREGISTRARE->TabVisible = 1;
	FEDITARE->TabVisible = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::SpeedButton4Click(TObject *Sender)
{
	FMAIN->TabVisible = 0;
	FMENIU->TabVisible = 1;
	FINREGISTRARE->TabVisible = 0;
	FEDITARE->TabVisible = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::SpeedButton11Click(TObject *Sender)
{
	if(!DM->QFACTURA->IsEmpty())
	{
		EPRODUS2->Text = DM->QFACTURADENUMIRE->AsString;
		EUM2->Text = DM->QFACTURAABREVIERE->AsString;
		ESTOC2->Text = DM->QFACTURASTOCK1->AsString;
		EPI2->Text = DM->QFACTURAPRET_INTRARE->AsString;
		EPV2->Text = DM->QFACTURAPRET_VANZ->AsString;
		//EADAOS2->Text =
		ETVA2->Text = DM->QFACTURATVA->AsString;

		PRODUS_ID = DM->QFACTURAPRODUSE_ID->AsInteger;
        FACTURA_ID = DM->QFACTURAFACTURA_REC_ID->AsInteger;
        UM_ID = DM->QFACTURAUNIT_MASURA_ID->AsInteger;

		FMAIN->TabVisible = 0;
		FMENIU->TabVisible = 0;
		FINREGISTRARE->TabVisible = 0;
		FEDITARE->TabVisible = 1;
	}
	else ShowMessage("Nu sunt date de editat");
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::SpeedButton6Click(TObject *Sender)
{
	if((EPRODUS2->Text != "") && (EUM2->Text != "") && (EPV2->Text != "") )
	{
		DM->QLIBER->Close();
		DM->QLIBER->SQL->Clear();
		DM->QLIBER->SQL->Add("UPDATE RECEPTIE SET PRODUSE_ID =:PRODUSE_ID,UNIT_MASURA_ID =:UNIT_MASURA_ID,STOCK1 =:STOCK1,PRET_INTRARE =:PRET_INTRARE,PRET_VANZ =:PRET_VANZ,TVA =:TVA WHERE RECEPTIE_ID =:ID");
		DM->QLIBER->ParamByName("ID")->AsInteger = DM->QFACTURARECEPTIE_ID->AsInteger;
		DM->QLIBER->ParamByName("PRODUSE_ID")->AsInteger = PRODUS_ID;
		DM->QLIBER->ParamByName("UNIT_MASURA_ID")->AsInteger = UM_ID;
		DM->QLIBER->ParamByName("STOCK1")->AsInteger = ESTOC2->Text.ToInt();
		DM->QLIBER->ParamByName("PRET_INTRARE")->AsFloat = EPI2->Text.ToDouble();
		DM->QLIBER->ParamByName("PRET_VANZ")->AsFloat = EPV2->Text.ToDouble();
		DM->QLIBER->ParamByName("TVA")->AsInteger = ETVA2->Text.ToInt();
		DM->QLIBER->ExecSQL();

		DM->QFACTURA->Close();
		DM->QFACTURA->ParamByName("ID")->AsInteger = FACTURA_ID;
		DM->QFACTURA->Open();

		SpeedButton4->Click();

		ShowMessage("Inregistrare cu succes");
	}
	else
	{
        ShowMessage("Nu s-a introdus nimic");
    }
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::EPI2Change(TObject *Sender)
{
	if((EPI2->Text != "") && (EPI2->Text.ToDouble() > 0 ) && (EADAOS2->Text != "") && (EADAOS2->Text.ToDouble() > 0 ) )
	{
		float a;
		a = EPI2->Text.ToDouble()*(ETVA2->Text.ToDouble()/100);
		EPV2->Text = FloatToStr(EPI2->Text.ToDouble()+a+EADAOS2->Text.ToDouble() );
	}
	else
	{
		EPV2->Clear();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::SpeedButton10Click(TObject *Sender)
{
	if(!DM->QFACTURA->IsEmpty() )
	{
		DM->QLIBER->Close();
		DM->QLIBER->SQL->Clear();
		DM->QLIBER->SQL->Add("DELETE RECEPTIE WHERE RECEPTIE_ID =:ID");
		DM->QLIBER->ParamByName("ID")->AsInteger = DM->QFACTURARECEPTIE_ID->AsInteger;
		DM->QLIBER->ExecSQL();

		DM->QFACTURA->Close();
		DM->QFACTURA->ParamByName("ID")->AsInteger = FACTURA_ID;
		DM->QFACTURA->Open();

		ShowMessage("Eliminare cu succes");
	}
	else ShowMessage("Nu sunt date de eliminat");
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::SpeedButton13Click(TObject *Sender)
{
	if(PAGG == 2)
	{
		DATEFACTURA->TabVisible = 1;
		MENIU->TabVisible = 0;
        PAGG = 1;
	}
	else
	{
		DATEFACTURA->TabVisible = 0;
		MENIU->TabVisible = 1;
    }

	FACTURA->TabVisible = 0;
	PRODUS->TabVisible = 0;
	UM->TabVisible = 0;
	EMITENT->TabVisible = 0;
	CLIENT->TabVisible = 0;
}
//---------------------------------------------------------------------------


void __fastcall TFRECEPTIE::BitBtn3Click(TObject *Sender)
{
	DM->QEMITENT->Close();
	DM->QEMITENT->Open();

    PAG = 1;
	MENIU->TabVisible = 0;
	FACTURA->TabVisible = 0;
	PRODUS->TabVisible = 0;
	UM->TabVisible = 0;
	EMITENT->TabVisible = 1;
	DATEFACTURA->TabVisible = 0;
	CLIENT->TabVisible = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::BitBtn5Click(TObject *Sender)
{
	DM->QUM->Close();
	DM->QUM->Open();
	PAG = 1;

	MENIU->TabVisible = 0;
	FACTURA->TabVisible = 0;
	PRODUS->TabVisible = 0;
	UM->TabVisible = 1;
	EMITENT->TabVisible = 0;
	DATEFACTURA->TabVisible = 0;
	CLIENT->TabVisible = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::CheckBox1Click(TObject *Sender)
{
	if(CheckBox1->Checked)
	{
		Edit1->Enabled = true;
	}
	else Edit1->Enabled = false;

	Edit1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::CheckBox3Click(TObject *Sender)
{
	if(CheckBox3->Checked)
	{
		Edit2->Enabled = true;
	}
	else Edit2->Enabled = false;

	Edit2->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::CheckBox4Click(TObject *Sender)
{
	if(CheckBox4->Checked)
	{
		Edit3->Enabled = true;
	}
	else Edit3->Enabled = false;

	Edit3->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::BitBtn1Click(TObject *Sender)
{
	CheckBox1->Checked = false;
	CheckBox2->Checked = false;
	CheckBox3->Checked = false;
	CheckBox4->Checked = false;
	CheckBox5->Checked = false;

	DM->QDATEFACTURA->Close();
	MENIU->TabVisible = 0;
	FACTURA->TabVisible = 0;
	PRODUS->TabVisible = 0;
	UM->TabVisible = 0;
	EMITENT->TabVisible = 0;
	DATEFACTURA->TabVisible = 1;
	CLIENT->TabVisible = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::CheckBox2Click(TObject *Sender)
{
	if(CheckBox2->Checked)
	{
		D1->Enabled = true; D2->Enabled = true;
	}
	else
	{
        D1->Enabled = false;
		D2->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::CheckBox5Click(TObject *Sender)
{
	if(CheckBox5->Checked)
	{
		Edit4->Enabled = true;
	}
	else Edit4->Enabled = false;

	Edit4->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::Button3Click(TObject *Sender)
{
	AnsiString S1,S2,S3;

	S1 = " SELECT E.EMITENT_ID, E.DENUMIRE AS EMITENT,F.NR_FACTURA,F.DATA_FACTURA,COUNT(*) AS NR_POZ,SUM(R.PRET_INTRARE) AS PRET_INTRARE, ";
	S1 += " SUM(R.PRET_INTRARE*TVA/100.0) AS PRET_TVA,SUM(R.PRET_INTRARE)+SUM(R.PRET_INTRARE*TVA/100.0) AS PRET_TOT ";

	S3 = " SELECT COUNT(*) AS NR,SUM(R.PRET_INTRARE) AS PRET_INTRARE, ";
	S3 += " SUM(R.PRET_INTRARE*TVA/100.0) AS PRET_TVA,SUM(R.PRET_INTRARE)+SUM(R.PRET_INTRARE*TVA/100.0) AS PRET_TOT ";

	S2 = " FROM RECEPTIE R INNER JOIN PRODUSE P ON R.PRODUSE_ID = P.PRODUSE_ID ";
	S2 += "						 INNER JOIN UNIT_MASURA UM ON UM.UNIT_MASURA_ID = R.UNIT_MASURA_ID ";
	S2 += "						 INNER JOIN FACTURA_REC F ON F.FACTURA_REC_ID = R.FACTURA_REC_ID ";
	S2 += "						 INNER JOIN FIRMA_OPERATOR FO ON FO.FIRMA_OPERATOR_ID = R.FIRMA_OPERATOR_ID ";
	S2 += "						 INNER JOIN OPERATOR O ON O.OPERATOR_ID = FO.OPERATOR_ID ";
	S2 += "						 INNER JOIN EMITENT E ON E.EMITENT_ID = F.EMITENT_ID ";
	S2 += " WHERE R.ACTIV = 1 ";

	if(CheckBox1->Checked)//nr factura
	{
		S2 += " AND NR_FACTURA = " + Edit1->Text;
	}

	if(CheckBox2->Checked)//data factura
	{
		S2 += " AND DATA_FACTURA BETWEEN :D1 AND :D2 ";
	}

	if(CheckBox3->Checked)//operator
	{
		S2 += " AND (O.NUME LIKE '%" + Edit2->Text + "%' OR O.PRENUME LIKE '%" + Edit2->Text + "%')";
	}

	if(CheckBox4->Checked)//produs
	{
		S2 += " AND R.PRODUSE_ID IN (SELECT PRODUSE_ID FROM PRODUSE WHERE DENUMIRE LIKE '%" + Edit3->Text + "%')";
	}

	if(CheckBox5->Checked)//emitent
	{
		S2 += " AND E.DENUMIRE LIKE '%" + Edit4->Text + "%' ";
	}

	DM->QDATEFACTURA->Close();
	DM->QDATEFACTURA->SQL->Clear();
	DM->QDATEFACTURA->SQL->Add(S1+S2+" GROUP BY E.EMITENT_ID, E.DENUMIRE,F.NR_FACTURA,F.DATA_FACTURA ORDER BY F.DATA_FACTURA DESC");

	if(CheckBox2->Checked)//data factura
	{
		 DM->QDATEFACTURA->ParamByName("D1")->AsDate = D1->Date;
		 DM->QDATEFACTURA->ParamByName("D2")->AsDate = D2->Date;
	}
	DM->QDATEFACTURA->Open();

	DM->QLIBER->Close();
	DM->QLIBER->SQL->Clear();
	DM->QLIBER->SQL->Add(S3+S2);

	if(CheckBox2->Checked)//data factura
	{
		 DM->QLIBER->ParamByName("D1")->AsDate = D1->Date;
		 DM->QLIBER->ParamByName("D2")->AsDate = D2->Date;
	}
	DM->QLIBER->Open();

	StatusBar1->Panels->Items[0]->Text ="INREGISTRARI: " + DM->QLIBER->FieldByName("NR")->AsString;
	StatusBar1->Panels->Items[1]->Text = DM->QLIBER->FieldByName("PRET_INTRARE")->AsString;
	StatusBar1->Panels->Items[2]->Text = DM->QLIBER->FieldByName("PRET_TVA")->AsString;
	StatusBar1->Panels->Items[3]->Text = DM->QLIBER->FieldByName("PRET_TOT")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TFRECEPTIE::DBGrid3DblClick(TObject *Sender)
{
	ESERIA->Text = DM->QDATEFACTURANR_FACTURA->AsString;
	EDATA->Date = DM->QDATEFACTURADATA_FACTURA->AsString;
	EEMITENT->Text = DM->QDATEFACTURAEMITENT->AsString;
	EMITENT_ID = DM->QDATEFACTURAEMITENT_ID->AsInteger;

	MENIU->TabVisible = 0;
	FACTURA->TabVisible = 1;
	PRODUS->TabVisible = 0;
	UM->TabVisible = 0;
	EMITENT->TabVisible = 0;
	DATEFACTURA->TabVisible = 0;
	CLIENT->TabVisible = 0;
	PAGG = 2;

    Button2->Click();
}
//---------------------------------------------------------------------------

