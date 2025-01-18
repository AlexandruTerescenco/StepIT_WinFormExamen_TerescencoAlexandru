//---------------------------------------------------------------------------

#ifndef URECEPTIEH
#define URECEPTIEH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFRECEPTIE : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TImage *Image1;
	TLabel *Label1;
	TImage *Image2;
	TLabel *Label2;
	TLabel *Label3;
	TPageControl *PageControl1;
	TTabSheet *MENIU;
	TTabSheet *FACTURA;
	TTabSheet *PRODUS;
	TTabSheet *UM;
	TTabSheet *EMITENT;
	TTabSheet *DATEFACTURA;
	TPanel *Panel3;
	TPanel *Panel4;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TBitBtn *BitBtn3;
	TBitBtn *BitBtn4;
	TBitBtn *BitBtn5;
	TBitBtn *BitBtn6;
	TTabSheet *CLIENT;
	TImage *Image3;
	TImage *Image4;
	TImage *Image5;
	TPanel *Panel6;
	TDBGrid *DBGrid1;
	TPanel *Panel7;
	TBitBtn *BitBtn9;
	TBitBtn *BitBtn10;
	TPanel *Panel8;
	TDBGrid *DBGrid2;
	TPanel *Panel9;
	TPanel *Panel10;
	TPanel *Panel13;
	TBitBtn *BitBtn15;
	TBitBtn *BitBtn16;
	TPanel *Panel15;
	TDBGrid *DBGrid5;
	TPanel *Panel5;
	TBitBtn *BitBtn7;
	TBitBtn *BitBtn8;
	TPanel *Panel16;
	TDBGrid *DBGrid6;
	TPanel *Panel18;
	TDBGrid *DBGrid7;
	TPanel *Panel11;
	TBitBtn *BitBtn13;
	TBitBtn *BitBtn14;
	TPanel *Panel17;
	TDBGrid *DBGrid4;
	TGroupBox *GroupBox1;
	TRadioButton *RB1;
	TRadioButton *RB2;
	TEdit *ECAUTA;
	TBitBtn *BitBtn17;
	TBitBtn *BitBtn18;
	TBitBtn *BitBtn19;
	TPanel *Panel12;
	TPanel *Panel14;
	TPanel *Panel19;
	TPageControl *PageControl2;
	TTabSheet *FMAIN;
	TTabSheet *FMENIU;
	TTabSheet *FINREGISTRARE;
	TTabSheet *FEDITARE;
	TEdit *EPRODUS;
	TEdit *EUM;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TEdit *ESTOC;
	TEdit *EPI;
	TEdit *EPV;
	TEdit *EADAOS;
	TComboBox *ETVA;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TEdit *EPV2;
	TEdit *EPI2;
	TComboBox *ETVA2;
	TEdit *EADAOS2;
	TEdit *ESTOC2;
	TEdit *EUM2;
	TSpeedButton *SpeedButton7;
	TEdit *EPRODUS2;
	TSpeedButton *SpeedButton8;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TEdit *ESERIA;
	TLabel *Label11;
	TDateTimePicker *EDATA;
	TLabel *Label12;
	TEdit *EEMITENT;
	TLabel *Label13;
	TButton *Button1;
	TButton *Button2;
	TDBGrid *DBGrid8;
	TSpeedButton *SpeedButton9;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton11;
	TSpeedButton *SpeedButton12;
	TSpeedButton *SpeedButton13;
	TDBGrid *DBGrid3;
	TCheckBox *CheckBox1;
	TEdit *Edit1;
	TCheckBox *CheckBox2;
	TDateTimePicker *D1;
	TDateTimePicker *D2;
	TEdit *Edit2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TEdit *Edit3;
	TButton *Button3;
	TPanel *Panel20;
	TStatusBar *StatusBar1;
	TEdit *Edit4;
	TCheckBox *CheckBox5;
	TButton *Button4;
	TButton *Button5;
	void __fastcall RB1Click(TObject *Sender);
	void __fastcall ECAUTAChange(TObject *Sender);
	void __fastcall BitBtn4Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall BitBtn15Click(TObject *Sender);
	void __fastcall BitBtn16Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall BitBtn13Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall BitBtn7Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall ETVAChange(TObject *Sender);
	void __fastcall SpeedButton12Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall SpeedButton11Click(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall EPI2Change(TObject *Sender);
	void __fastcall SpeedButton10Click(TObject *Sender);
	void __fastcall SpeedButton13Click(TObject *Sender);
	void __fastcall BitBtn3Click(TObject *Sender);
	void __fastcall BitBtn5Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall CheckBox3Click(TObject *Sender);
	void __fastcall CheckBox4Click(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall CheckBox5Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall DBGrid3DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFRECEPTIE(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFRECEPTIE *FRECEPTIE;
//---------------------------------------------------------------------------
#endif
