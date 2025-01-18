//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include "cspin.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *AUTENTIFICARE;
	TTabSheet *STUDENT;
	TTabSheet *GRUPA;
	TPanel *Panel1;
	TPanel *Panel2;
	TPageControl *PageControl2;
	TTabSheet *GMAIN;
	TTabSheet *GINSERARE;
    TTabSheet *GEDITARE;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	TEdit *Edit1;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton7;
	TDBGrid *DBGrid1;
	TPanel *Panel3;
	TPanel *Panel4;
	TPageControl *PageControl3;
	TTabSheet *SMAIN;
	TTabSheet *SINSERARE;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TSpeedButton *SpeedButton8;
	TSpeedButton *SpeedButton9;
	TDateTimePicker *DateTimePicker1;
	TComboBox *ComboBox1;
	TTabSheet *SEDITARE;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton11;
	TEdit *Edit9;
	TDBGrid *DBGrid2;
	TCSpinEdit *CSpinEdit1;
	TCSpinEdit *CSpinEdit2;
	TSpeedButton *SpeedButton12;
	TSpeedButton *SpeedButton13;
	TSpeedButton *SpeedButton14;
	TSpeedButton *SpeedButton15;
	TSpeedButton *SpeedButton16;
	TEdit *Edit2;
	TEdit *Edit8;
	TEdit *Edit10;
	TSpeedButton *SpeedButton17;
	TEdit *Edit11;
	TComboBox *ComboBox2;
	TDateTimePicker *DateTimePicker2;
	TSpeedButton *SpeedButton18;
	TEdit *Edit12;
	TPanel *Panel5;
	TEdit *Edit13;
	TEdit *Edit14;
	TSpeedButton *SpeedButton21;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall SpeedButton11Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton14Click(TObject *Sender);
	void __fastcall SpeedButton13Click(TObject *Sender);
	void __fastcall SpeedButton9Click(TObject *Sender);
	void __fastcall SpeedButton8Click(TObject *Sender);
	void __fastcall SpeedButton18Click(TObject *Sender);
	void __fastcall SpeedButton21Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
