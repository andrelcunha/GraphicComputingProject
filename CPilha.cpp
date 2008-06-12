//---------------------------------------------------------------------------


#pragma hdrstop

#include "CPilha.h"
#include <iostream>
//---------------------------------------------------------------------------

#pragma package(smart_init)



using namespace std;
//---------------------------------------------------------------------------
void CPilha::push_value(int type, float x, float y){
  if (topo == MAXSTACK-1){
    // Pilha cheia
    cout << "The stack is full!" << endl;
    exit(1);
  }else{
    Cmatrix* matrix = new Cmatrix;
    matrix->set_matrix(type,x,y);
	items[++topo] = matrix;
  }
}
//---------------------------------------------------------------------------
void CPilha::push(float matrix_tmp[][3]){
  if (topo == MAXSTACK-1){
    // Pilha cheia
    cout << "The stack is full!" << endl;
    exit(1);
  }else{
    Cmatrix* matrix = new Cmatrix;
    set_matrix_full(matrix,matrix_tmp);
	items[++topo] = matrix;
  }
}
//---------------------------------------------------------------------------
Cmatrix* CPilha::pop(){
	//Cmatrix* tmp;
	if (empty())
		exit(1);
	return items[topo--];
}
//---------------------------------------------------------------------------
void CPilha::mult_matrix(void) //implement push and pop utilization.
{
	
	int I,J,count;
	Cmatrix *m_tmp;
	float mA[3][3],mB[3][3], mR[3][3], tmp=0;
	m_tmp=pop();
	get_matrix_full(m_tmp,mA);
	m_tmp=pop();
	get_matrix_full(m_tmp,mB);	
	for (I=0;I<3;I++){
		for(J=0;J<3;J++){
			tmp=0;
			for(count=0;count<3;count++){
				tmp=tmp+mA[I][count]*mB[count][J];
			}
			mR[I][J]=tmp;
		}
	}
	push(mR);
	m_tmp=items[topo];
	m_tmp->print_matrix();
	
}
//---------------------------------------------------------------------------
void CPilha::mult_points(float mA[][3],float mB[][3],float mR[][3])
{
	int I,J,count;
	float tmp=0;
	for (I=0;I<3;I++){
		for(J=0;J<3;J++){
			tmp=0;
			for(count=0;count<3;count++){
				tmp=tmp+mA[I][count]*mB[count][J];
			}
			mR[I][J]=tmp;
		}
	}
}
//---------------------------------------------------------------------------
void CPilha::get_matrix_full(Cmatrix *tmp, float matrix_tmp[][3])
{
	int i,j;
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			matrix_tmp[i][j]=tmp->get_matrix(i,j);
		}
	}
}
//---------------------------------------------------------------------------
void CPilha::set_matrix_full(Cmatrix *tmp, float matrix_tmp[][3])
{
	int i,j;
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			tmp->set_matrix_value(matrix_tmp[i][j],i,j);
		}
	}
}
//---------------------------------------------------------------------------
bool CPilha::empty(){
  return topo == -1;
}
//---------------------------------------------------------------------------
CPilha::~CPilha(){
  cout << "The object was destroid" << endl;
  cin.get();
}
//---------------------------------------------------------------------------