//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDATECEC.h"
#include "UMAIN.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFDATECEC *FDATECEC;
//---------------------------------------------------------------------------
__fastcall TFDATECEC::TFDATECEC(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFDATECEC::Button1Click(TObject *Sender)
{
	DM->QDATECEC->Close();
	DM->QDATECEC->ParamByName("D1")->AsDate = DateTimePicker1->Date;
	DM->QDATECEC->ParamByName("D2")->AsDate = DateTimePicker2->Date;
	DM->QDATECEC->Open();

	PageControl1->ActivePageIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TFDATECEC::DBGrid1DblClick(TObject *Sender)
{
	if(!DM->QDATECEC->IsEmpty())
	{
		DM->QVANZARE->Close();
		DM->QVANZARE->ParamByName("CEC_ID")->AsInteger = DM->QDATECEC->FieldByName("CEC_ID")->AsInteger;
		DM->QVANZARE->Open();
        PageControl1->ActivePageIndex=1;
	}
	else ShowMessage("Nu sunt date");
}
//---------------------------------------------------------------------------
void __fastcall TFDATECEC::FormClose(TObject *Sender, TCloseAction &Action)
{
    DM->QVANZARE->Close();
}
//---------------------------------------------------------------------------
