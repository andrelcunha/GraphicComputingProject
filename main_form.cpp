//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string.h>
#include <vector>
#include "main_form.h"
#include "CPilha.h"
#include "GLSkeleton.h"
using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
CPilha operations;
Cmatrix *tmp;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::save_buttonClick(TObject *Sender)
{
    set_xcoord(0,StrToFloat(Edit1_x->Text));
    set_ycoord(0,StrToFloat(Edit1_y->Text));

    set_xcoord(1,StrToFloat(Edit2_x->Text));
    set_ycoord(1,StrToFloat(Edit2_y->Text));

    set_xcoord(2,StrToFloat(Edit3_x->Text));
    set_ycoord(2,StrToFloat(Edit3_y->Text));

    set_xcoord(3,StrToFloat(Edit4_x->Text));
    set_ycoord(3,StrToFloat(Edit4_y->Text));

    set_xcoord(4,StrToFloat(Edit5_x->Text));
    set_ycoord(4,StrToFloat(Edit5_y->Text));

    GL_window = new TGL_window(Application);
    GL_window->ShowModal();

    /*
    int i, j;
    AnsiString array_str[3][3];
    array_str[0][0]=Edit->Text;
    array_str[0][1]=Edit0_1->Text;
    array_str[0][2]=Edit0_2->Text;
    array_str[1][0]=Edit1_0->Text;
    array_str[1][1]=Edit1_1->Text;
    array_str[1][2]=Edit1_2->Text;
    array_str[2][0]=Edit2_0->Text;
    array_str[2][1]=Edit2_1->Text;
    array_str[2][2]=Edit2_2->Text;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            result_grid->Cells[j][i]=array_str[i][j];
        }
    }
    */
}
//---------------------------------------------------------------------------
void __fastcall TForm1::add_buttonClick(TObject *Sender)
{
    if (op_combo->Text!=""&&op_parm1_edit->Text!=""&&op_parm2_edit->Text!="") {

        op_list->Items->Add(op_combo->Text);
        op_parm1_list->Items->Add(op_parm1_edit->Text);
        op_parm2_list->Items->Add(op_parm2_edit->Text);
        op_combo->ClearSelection();
        op_parm1_edit->Clear();
        op_parm2_edit->Clear();
        if(op_list->Count==5){
            add_button->Enabled=false;
        }
    }
    else{
        Application->MessageBoxA("Selecione um item","Erro",0);
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::calc_buttonClick(TObject *Sender)
{
//    op_combo->Text=op_list->Items->Strings[0];

    int i,j;
    for (i=1;i<op_list->Count+1;i++) {
        try{
            if (i>4) {
                throw "Bad option ("+IntToStr(i)+")";
            }
            else
                operations.push_value(i,
                    StrToFloat(op_parm1_list->Items->Strings[i-1]),
                    StrToFloat(op_parm2_list->Items->Strings[i-1])
                );
        }catch (char * str){
            Application->MessageBoxA(str,"Erro",0);
            exit(1);
        }
    }
    for(i=0;i<op_list->Count-1;i++){
        operations.mult_matrix();
    }
    tmp=operations.pop();
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            result_grid->Cells[j][i]=FloatToStr(tmp->get_matrix(i,j));
        }
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::rem_buttonClick(TObject *Sender)
{
    op_parm1_list->Items->Delete(op_list->ItemIndex);
    op_parm2_list->Items->Delete(op_list->ItemIndex);
    op_list->DeleteSelected();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::op_comboChange(TObject *Sender)
{
    op_parm2_edit->Text="";
    op_parm2_edit->Text="";
    op_parm2_edit->Enabled=true;
    if (op_combo->Text=="Rotação") {
        op_parm2_edit->Text="---";
        op_parm2_edit->Enabled=false;
    }
    if(op_list->Count<5){
            add_button->Enabled=true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::render_buttonClick(TObject *Sender)
{
    GL_window = new TGL_window(Application);
    
    GL_window->ShowModal();
}
//---------------------------------------------------------------------------

void TForm1::set_xcoord(int x, float value)
{
    try{
        Xcoordinates[x]=value;
    }
    catch(...){
        Application->MessageBoxA("Caugh an exception","Erro",0);
    }
}
//---------------------------------------------------------------------------

void TForm1::set_ycoord(int y, float value)
{
    try{
        Ycoordinates[y]=value;
    }
    catch(...){
        Application->MessageBoxA("Caugh an exception","Erro",0);
    }
}
//---------------------------------------------------------------------------
float TForm1::get_xcoord(int x){
    return Xcoordinates[x];
}
//---------------------------------------------------------------------------
 float TForm1::get_ycoord(int y)
{
    return Ycoordinates[y];
}
//---------------------------------------------------------------------------
