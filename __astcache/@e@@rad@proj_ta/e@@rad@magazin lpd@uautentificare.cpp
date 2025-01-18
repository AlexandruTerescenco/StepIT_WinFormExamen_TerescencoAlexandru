//---------------------------------------------------------------------------

#include <vcl.h>
#include "IniFiles.hpp"
#pragma hdrstop

#include "UAUTENTIFICARE.h"
#include "UDM.h"
#include "UMAIN.h"
#include "URECEPTIE.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFAUTENTIFICARE *FAUTENTIFICARE;
TIniFile *INI = new TIniFile(GetCurrentDir()+"/options.ini");
//---------------------------------------------------------------------------
__fastcall TFAUTENTIFICARE::TFAUTENTIFICARE(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFAUTENTIFICARE::FormShow(TObject *Sender)
{
	DM->QLIBER->Close();
	DM->QLIBER->SQL->Clear();
	DM->QLIBER->SQL->Add("SELECT * FROM FIRMA");
	DM->QLIBER->Open();

	while(!DM->QLIBER->Eof)
	{
		EFIRMA->Items->Add(DM->QLIBER->FieldByName("NUME")->AsString);
        DM->QLIBER->Next();
	}

	EFIRMA->Text = INI->ReadString("AUTENTIFICARE","FIRMA","");
	EOPERATOR->Text = INI->ReadString("AUTENTIFICARE","UTILIZATOR","");
}
//---------------------------------------------------------------------------

void __fastcall TFAUTENTIFICARE::EFIRMAKeyPress(TObject *Sender, System::WideChar &Key)

{
    Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFAUTENTIFICARE::SpeedButton2Click(TObject *Sender)
{
	if(MessageDlg("Doriti intr-adevar sa inchideti sistemul?", mtInformation,TMsgDlgButtons() <<mbOK <<mbNo,0 ) == mrOk )
	{
		Application->Terminate();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFAUTENTIFICARE::SpeedButton1Click(TObject *Sender)
{
	if((EFIRMA->Text!= "") && (EOPERATOR->Text!= "") && (EPAROLA->Text!= "") )
	{
		DM->QAUTENTIFICARE->Close();
		DM->QAUTENTIFICARE->ParamByName("USERNAME")->AsString = EOPERATOR->Text;
		DM->QAUTENTIFICARE->ParamByName("PASS")->AsString = EPAROLA->Text;
		DM->QAUTENTIFICARE->ParamByName("NUME")->AsString = EFIRMA->Text;
		DM->QAUTENTIFICARE->Open();

		if(!DM->QAUTENTIFICARE->IsEmpty() )
		{
			INI->WriteString("AUTENTIFICARE","FIRMA",EFIRMA->Text);
            INI->WriteString("AUTENTIFICARE","UTILIZATOR",EOPERATOR->Text);
			Close();
			FMAIN->Label2->Caption = DM->QAUTENTIFICAREOPERATOR->AsString;
			FMAIN->Label3->Caption = DM->QAUTENTIFICAREFUNCTIA->AsString;
			FMAIN->Label19->Caption = DM->QAUTENTIFICAREFIRMA->AsString;
			FRECEPTIE->Label2->Caption = DM->QAUTENTIFICAREOPERATOR->AsString;
			FRECEPTIE->Label3->Caption = DM->QAUTENTIFICAREFUNCTIA->AsString;
            UTILIZATOR_ID = DM->QAUTENTIFICAREFIRMA_OPERATOR_ID->AsInteger;
			FMAIN->AlphaBlend = false;
		}
		else
		{
            ShowMessage("Autentificare esuata");
        }
	}
	else
	{
		ShowMessage("Nu sunt indicate toate datele de autentificare");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFAUTENTIFICARE::EPAROLAKeyPress(TObject *Sender, System::WideChar &Key)

{
    if(Key == 13) SpeedButton1->Click();
}
//---------------------------------------------------------------------------

