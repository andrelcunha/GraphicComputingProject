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
    GL_window = new TGL_window(Application);
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
    mass_center();
    GL_window-> Show();


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
void TForm1::calcula_pontos(int position){
    double op[3][3];
    int count, i, j;
    Cmatrix *result;
    for ( i=0;i<3;i++) {
        for ( j=0; j<3 ;j++){
            op[i][j]=StrToFloat(result_grid->Cells[j][i]);
        }
    }
    operations.push(op);
    operations.push_value(2,get_xcoord(position),get_ycoord(position));
    operations.mult_matrix();
    result=operations.pop();
    set_xcoord(position,result->get_matrix(0,0));
    set_ycoord(position,result->get_matrix(1,1));
           /* TODO : Verificar calculo correto
           da resultante sobre pontos -- escala ok */
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
        op_parm2_edit->Text="0";
        op_parm2_edit->Enabled=false;
    }
    if(op_list->Count<5){
            add_button->Enabled=true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::render_buttonClick(TObject *Sender){
    int i,j, op;
    for (i=1;i<op_list->Count+1;i++) {
        for(j=0;j<4;j++){
            if(op_list->Items->Strings[i-1]==op_combo->Items->Strings[j])
                op=j+1;
        }
        operations.push_value(
            op,
            StrToFloat(op_parm1_list->Items->Strings[i-1]),
            StrToFloat(op_parm2_list->Items->Strings[i-1])
        );
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
    for(i=0;i<5;i++){
         points_multiplication(i);
    }
    //GL_window = new TGL_window(Application);
    GL_window->Show();
    //---- cálculo ok!
}
//---------------------------------------------------------------------------

void TForm1::set_xcoord(int x, double value){
    try{
        Xcoordinates[x]=value;
    }
    catch(...){
        Application->MessageBoxA("Caugh an exception","Erro",0);
    }
}
//---------------------------------------------------------------------------

void TForm1::set_ycoord(int y, double value){
    try{
        Ycoordinates[y]=value;
    }
    catch(...){
        Application->MessageBoxA("Caugh an exception","Erro",0);
    }
}
//---------------------------------------------------------------------------
double TForm1::get_xcoord(int x){
    return Xcoordinates[x];
}
//---------------------------------------------------------------------------
 double TForm1::get_ycoord(int y){
    return Ycoordinates[y];
}
//---------------------------------------------------------------------------
void TForm1::points_multiplication(int position){
    double  tmp=0, op[3][3], point[1][3], mR[1][3];
    int count, i, j;
    point[0][0]=get_xcoord(position);
    point[0][1]=get_ycoord(position);
    point[0][2]=1;
    for ( i=0;i<3;i++) {
        for ( j=0; j<3 ;j++){
            op[i][j]=StrToFloat(result_grid->Cells[j][i]);
        }
    }
    for (i=0;i<1;i++){
		for(j=0;j<3;j++){
			tmp=0;
			for(count=0;count<3;count++){
				tmp=tmp+point[i][count]*op[count][j];
			}
			mR[i][j]=tmp;
		}
	}
    set_xcoord(position,mR[0][0]);
    set_ycoord(position,mR[0][1]);
}
//---------------------------------------------------------------------------
void TForm1::mass_center(void)
{

    int current;
    for(int i=0;i<3;i++){
        if (i==0)current=0;
        if (i==1)current=2;
        if (i==2)current=3;
        triangle[i][0]=Xcoordinates[0];
        triangle[i][1]=Ycoordinates[0];
        for (int j=0;j<2;j++){
                triangle[i][0]=+Xcoordinates[current+j];
                triangle[i][1]=+Ycoordinates[current+j];
        }
        triangle[i][0]=triangle[i][0]/3;
        triangle[i][1]=triangle[i][1]/3;
    }
    center_point[0]=0;
    center_point[1]=0;
    for(int i=0;i<3;i++){
        center_point[0]=+triangle[i][0];
        center_point[1]=+triangle[i][1];
    }
    center_point[0]=center_point[0]/3;
    center_point[1]=center_point[1]/3;
}
 //---------------------------------------------------------------------------
double TForm1::get_triangleX(int i){
    return triangle[i][0];
}
//---------------------------------------------------------------------------
double TForm1::get_triangleY(int i){
    return triangle[i][1];
}
//---------------------------------------------------------------------------
 double TForm1::get_point(int i){
    return center_point[i];
}
//---------------------------------------------------------------------------

