//---------------------------------------------------------------------------

#ifndef UAUTENTIFICAREH
#define UAUTENTIFICAREH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
class TFAUTENTIFICARE : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TImage *Image1;
	TComboBox *EFIRMA;
	TEdit *EOPERATOR;
	TEdit *EPAROLA;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall EFIRMAKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall EPAROLAKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TFAUTENTIFICARE(TComponent* Owner);
    int UTILIZATOR_ID;
};
//---------------------------------------------------------------------------
extern PACKAGE TFAUTENTIFICARE *FAUTENTIFICARE;
//---------------------------------------------------------------------------
#endif
