//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Project1PCH1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
TForm1 *Form1;

int GRUPA_ID,STUDENT_ID;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
	AUTENTIFICARE->TabVisible = true;
	STUDENT->TabVisible = false;
	GRUPA->TabVisible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
	GMAIN->TabVisible = false;
	GINSERARE->TabVisible = true;
	GEDITARE->TabVisible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
	if(!DataModule2->QGRUPA->IsEmpty())
	{
		GMAIN->TabVisible = false;
		GINSERARE->TabVisible = false;
		GEDITARE->TabVisible = true;

		Edit9->Text = DataModule2->QGRUPA->FieldByName("NUME")->AsString;
		CSpinEdit2->Value = DataModule2->QGRUPA->FieldByName("AN_FORMARE")->AsInteger;
		GRUPA_ID = DataModule2->QGRUPA->FieldByName("GRUPA_ID")->AsInteger;
	}
	else
	{
		MessageDlg("Nu sunt date de editat",mtError,TMsgDlgButtons()<<mbOK,1);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
{
	GMAIN->TabVisible = true;
	GINSERARE->TabVisible = false;
	GEDITARE->TabVisible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
	if((Edit1->Text != "") && (CSpinEdit1->Value >= 2000) )
	{
		DataModule2->QGINSERT->Close();
		DataModule2->QGINSERT->ParamByName("NUME")->AsString = Edit1->Text;
		DataModule2->QGINSERT->ParamByName("AN_FORMARE")->AsInteger = CSpinEdit1->Value;
		DataModule2->QGINSERT->ExecSQL();

		Edit1->Clear();

		GMAIN->TabVisible = true;
		GINSERARE->TabVisible = false;
		GEDITARE->TabVisible = false;

		DataModule2->QGRUPA->Close();
		DataModule2->QGRUPA->Open();

		MessageDlg("Inregistrare cu succes",mtInformation,TMsgDlgButtons()<<mbOK,1);
	}
	else
	{
		MessageDlg("Completeaza toate campurile",mtError,TMsgDlgButtons()<<mbOK,1);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton11Click(TObject *Sender)
{
	if((Edit9->Text != "") && (CSpinEdit2->Value >= 2000) )
	{
		DataModule2->QGEDIT->Close();
        DataModule2->QGEDIT->ParamByName("ID")->AsInteger = GRUPA_ID;
		DataModule2->QGEDIT->ParamByName("NUME")->AsString = Edit9->Text;
		DataModule2->QGEDIT->ParamByName("AN_FORMARE")->AsInteger = CSpinEdit2->Value;
		DataModule2->QGEDIT->ExecSQL();

		Edit9->Clear();

		GMAIN->TabVisible = true;
		GINSERARE->TabVisible = false;
		GEDITARE->TabVisible = false;

		DataModule2->QGRUPA->Close();
		DataModule2->QGRUPA->Open();

		MessageDlg("Editare cu succes",mtInformation,TMsgDlgButtons()<<mbOK,1);
	}
	else
	{
		MessageDlg("Completeaza toate campurile",mtError,TMsgDlgButtons()<<mbOK,1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
	try
	{
		DataModule2->QSDELETE->Close();
		DataModule2->QSDELETE->ParamByName("ID")->AsInteger = DataModule2->QSTUDENT->FieldByName("STUDENT_ID")->AsInteger;
		DataModule2->QSDELETE->ExecSQL();

		DataModule2->QSTUDENT->Close();
		DataModule2->QSTUDENT->Open();
        ShowMessage("S-a eliminat cu succes");
	}
	catch(...)
	{
		MessageDlg("Eliminarea a esuat", mtError, TMsgDlgButtons()<<mbOK, 0);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton14Click(TObject *Sender)
{
	SMAIN->TabVisible = false;
	SINSERARE->TabVisible = true;
	SEDITARE->TabVisible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton13Click(TObject *Sender)
{
	if(!DataModule2->QSTUDENT->IsEmpty())
	{
		SMAIN->TabVisible = false;
		SINSERARE->TabVisible = false;
		SEDITARE->TabVisible = true;
	   	//DataModule2->QSG->Open();

		STUDENT_ID = DataModule2->QSTUDENT->FieldByName("STUDENT_ID")->AsInteger;
		Edit11->Text = DataModule2->QSTUDENT->FieldByName("NUME")->AsString;
		Edit12->Text = DataModule2->QSTUDENT->FieldByName("PRENUME")->AsString;
		//Edit2->Text = DataModule2->QSG->ParamByName("ID")->AsString;
		DateTimePicker2->Date = DataModule2->QSTUDENT->FieldByName("DATA_NASTERII")->AsString;
		Edit10->Text = DataModule2->QSTUDENT->FieldByName("IDNP")->AsString;
		Edit8->Text = DataModule2->QSTUDENT->FieldByName("TELEFON")->AsString;
		ComboBox2->Text = DataModule2->QSTUDENT->FieldByName("GEN")->AsString;
		//DataModule2->QSG->ExecSQL();
	}
	else
	{
		MessageDlg("Nu sunt date de editat",mtError,TMsgDlgButtons()<<mbOK,1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton9Click(TObject *Sender)
{
	SMAIN->TabVisible = true;
	SINSERARE->TabVisible = false;
	SEDITARE->TabVisible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton8Click(TObject *Sender)
{
	if((Edit3->Text != "") && (Edit4->Text != "") && (Edit5->Text != "") && (Edit6->Text != "") && (Edit7->Text != "") && (ComboBox1->Text != "")  )
	{
		DataModule2->QSINSERT->Close();
		DataModule2->QSINSERT->ParamByName("NUME")->AsString = Edit3->Text;
		DataModule2->QSINSERT->ParamByName("PRENUME")->AsString = Edit4->Text;
		DataModule2->QSINSERT->ParamByName("GNUME")->AsString = Edit5->Text;
		DataModule2->QSINSERT->ParamByName("DATA_NASTERII")->AsDate = DateTimePicker1->Date;
		DataModule2->QSINSERT->ParamByName("GEN")->AsString = ComboBox1->Text;
		DataModule2->QSINSERT->ParamByName("IDNP")->AsString = Edit6->Text;
		DataModule2->QSINSERT->ParamByName("TELEFON")->AsString = Edit7->Text;
		DataModule2->QSINSERT->ExecSQL();

		SMAIN->TabVisible = true;
		SINSERARE->TabVisible = false;
		SEDITARE->TabVisible = false;

		DataModule2->QSTUDENT->Close();
		DataModule2->QSTUDENT->Open();

		MessageDlg("Inregistrare cu succes",mtInformation,TMsgDlgButtons()<<mbOK,1);
	}
	else
	{
		MessageDlg("Completeaza toate campurile",mtError,TMsgDlgButtons()<<mbOK,1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton18Click(TObject *Sender)
{
	if((Edit11->Text != "") && (Edit12->Text != "") && (Edit2->Text != "") && (Edit10->Text != "") && (Edit8->Text != "") && (ComboBox2->Text != "")  )
	{
		DataModule2->QSEDIT->Close();
		DataModule2->QSEDIT->ParamByName("ID")->AsInteger = STUDENT_ID;
		DataModule2->QSEDIT->ParamByName("NUME")->AsString = Edit11->Text;
		DataModule2->QSEDIT->ParamByName("PRENUME")->AsString = Edit12->Text;
		DataModule2->QSEDIT->ParamByName("GNUME")->AsString = Edit2->Text;
		DataModule2->QSEDIT->ParamByName("DATA_NASTERII")->AsDate = DateTimePicker2->Date;
		DataModule2->QSEDIT->ParamByName("GEN")->AsString = ComboBox2->Text;
		DataModule2->QSEDIT->ParamByName("IDNP")->AsString = Edit10->Text;
		DataModule2->QSEDIT->ParamByName("TELEFON")->AsString = Edit8->Text;
		DataModule2->QSEDIT->ExecSQL();

		SMAIN->TabVisible = true;
		SINSERARE->TabVisible = false;
		SEDITARE->TabVisible = false;

		DataModule2->QSTUDENT->Close();
		DataModule2->QSTUDENT->Open();

		MessageDlg("Editare cu succes",mtInformation,TMsgDlgButtons()<<mbOK,1);
	}
	else
	{
		MessageDlg("Completeaza toate campurile",mtError,TMsgDlgButtons()<<mbOK,1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton21Click(TObject *Sender)
{
	if( (Edit13->Text != "") && (Edit14->Text != "") )
	{

		DataModule2->QAUTENTIFICARE->Close();
		DataModule2->QAUTENTIFICARE->ParamByName("USERNAME")->AsString = Edit13->Text;
		DataModule2->QAUTENTIFICARE->ParamByName("PAROLA")->AsString = Edit14->Text;
		DataModule2->QAUTENTIFICARE->Open();

		if(!DataModule2->QAUTENTIFICARE->IsEmpty() )
		{
			AUTENTIFICARE->TabVisible = false;

			STUDENT->TabVisible = true;
			SMAIN->TabVisible = true;
			SINSERARE->TabVisible = false;
			SEDITARE->TabVisible = false;

			GRUPA->TabVisible = true;
			GMAIN->TabVisible = true;
			GINSERARE->TabVisible = false;
			GEDITARE->TabVisible = false;

			DataModule2->QGRUPA->Close();
			DataModule2->QGRUPA->Open();
			DataModule2->QSTUDENT->Close();
			DataModule2->QSTUDENT->Open();

			MessageDlg("Logare cu succes",mtInformation,TMsgDlgButtons()<<mbOK,1);
		}
		else
		{
			ShowMessage("Autentificare esuata");
		}
	}
	else
	{
		MessageDlg("Nu sunt indicate toate datele de autentificare",mtError,TMsgDlgButtons()<<mbOK,1);
    }
}
//---------------------------------------------------------------------------

