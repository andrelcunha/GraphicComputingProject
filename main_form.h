//---------------------------------------------------------------------------

#ifndef main_formH
#define main_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
using namespace std;


//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TButton *save_button;
    TButton *clean_button;
    TComboBox *op_combo;
    TButton *add_button;
    TStringGrid *result_grid;
    TEdit *Edit1_x;
    TEdit *Edit2_y;
    TEdit *Edit2_x;
    TEdit *Edit3_x;
    TEdit *Edit5_x;
    TEdit *Edit4_x;
    TEdit *Edit4_y;
    TEdit *Edit3_y;
    TEdit *Edit1_y;
    TListBox *op_list;
    TEdit *Edit5_y;
    TLabel *Label1;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label11;
    TButton *rem_button;
    TButton *render_button;
    TEdit *op_parm1_edit;
    TEdit *op_parm2_edit;
    TListBox *op_parm1_list;
    TLabel *Label12;
    TListBox *op_parm2_list;
    TLabel *Label13;
    TLabel *Label14;
    void __fastcall save_buttonClick(TObject *Sender);
    void __fastcall add_buttonClick(TObject *Sender);
    void __fastcall rem_buttonClick(TObject *Sender);
    void __fastcall op_comboChange(TObject *Sender);
    void __fastcall render_buttonClick(TObject *Sender);
   

private:	// User declarations
    double Xcoordinates[5];
    double Ycoordinates[5];
    double center_point[2];
    double triangle[3][2];
    void mass_center();


public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
    double get_xcoord(int);
    double get_ycoord(int);
    double get_triangleX(int);
    double get_triangleY(int);
    double get_point(int);
    void set_xcoord(int,double);
    void set_ycoord(int,double);
    void calcula_pontos(int);
    void points_multiplication(int);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
