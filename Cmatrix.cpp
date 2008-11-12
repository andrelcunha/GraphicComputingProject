//---------------------------------------------------------------------------


#pragma hdrstop

#include "Cmatrix.h"
#include <iostream>
#include <math.h>
#define PI 3.14159265
//---------------------------------------------------------------------------

#pragma package(smart_init)
using namespace std;



Cmatrix::Cmatrix(){
	LOADIDENTITY();
}
//---------------------------------------------------------------------------

Cmatrix::~Cmatrix(){
	// TODO: put destructor code here
}
//---------------------------------------------------------------------------
double Cmatrix::get_matrix(int i,int j){
	return matrix_core[i][j];
}
//---------------------------------------------------------------------------
void Cmatrix::set_matrix_value(double value,int i,int j){
	matrix_core[i][j]=value;
}
//---------------------------------------------------------------------------
void Cmatrix::set_matrix(int type,double x,double y){
    //try{
        switch (type){
            case 1 :		TRANS3f(x,y);//Translate
                            break;

            case 2 :		SCALE3f(x,y);//Scale
                            break;

            case 3 :		x=(x*PI/180);
                            ROTAT2f(x);//Rotate
                            break;

            case 4 :		SHEAR3f(x,y);//Shear
                            break;

            defaults:       //throw "Bad option! Try Again.";
              				break;
        }
    //}


}
//---------------------------------------------------------------------------

void Cmatrix::print_matrix(void){
	int i,j;
	cout << endl;
	for (i=0;i<3;i++){
		cout << "| ";
		for (j=0;j<3;j++){
			cout << matrix_core[i][j]<< " " ;
		}
		cout << "|" << endl;
	}
}
//---------------------------------------------------------------------------
void Cmatrix::populating(void){
	int i,j;
	double r;
	for(i=0,r=1;i<3;i++){
		for(j=0;j<3;j++,r++){
			matrix_core[i][j]=r;
		}
	}
}
//---------------------------------------------------------------------------

void Cmatrix::TRANS3f(double Dx,double Dy){
	LOADIDENTITY();
	matrix_core[2][0]=Dx;
	matrix_core[2][1]=Dy;
}
//---------------------------------------------------------------------------
void Cmatrix::SCALE3f(double Sx,double Sy){
	LOADIDENTITY();
	matrix_core[0][0]=Sx;
	matrix_core[1][1]=Sy;
}
//---------------------------------------------------------------------------
void Cmatrix::ROTAT2f(double RO)  //RO value is in radians.
{
	LOADIDENTITY();
	matrix_core[0][0]= cos(RO);
	matrix_core[0][1]= sin(RO);
	matrix_core[1][0]=-sin(RO);
	matrix_core[1][1]= cos(RO);
}
//---------------------------------------------------------------------------
void Cmatrix::SHEAR3f(double SHx,double SHy){
	LOADIDENTITY();
	matrix_core[0][1]=SHx;
	matrix_core[1][0]=SHy;
}
//---------------------------------------------------------------------------
void Cmatrix::LOADIDENTITY(void){
    int i, j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if (i==j)
				matrix_core[i][j]=1;
			else
				matrix_core[i][j]=0;
		}
	}
}
//---------------------------------------------------------------------------
