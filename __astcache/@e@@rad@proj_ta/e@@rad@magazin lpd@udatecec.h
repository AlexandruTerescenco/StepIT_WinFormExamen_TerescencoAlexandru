//---------------------------------------------------------------------------

#ifndef UDATECECH
#define UDATECECH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFDATECEC : public TForm
{
__published:	// IDE-managed Components
	TPanel *UPPER;
	TPanel *MIDDLE;
	TPanel *LOWER;
	TDateTimePicker *DateTimePicker1;
	TDateTimePicker *DateTimePicker2;
	TComboBox *ComboBox1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *Button1;
	TButton *Button2;
	TPageControl *PageControl1;
	TTabSheet *LISTACEC;
	TTabSheet *DATECEC;
	TDBGrid *DBGrid1;
	TDBGrid *DBGrid2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TFDATECEC(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDATECEC *FDATECEC;
//---------------------------------------------------------------------------
#endif
