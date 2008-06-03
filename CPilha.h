//---------------------------------------------------------------------------

#ifndef CPilhaH
#define CPilhaH
//---------------------------------------------------------------------------
#endif
#define MAXSTACK 5
#include "Cmatrix.h"

class CPilha{
private:
  Cmatrix* items[MAXSTACK];
  int topo;
public:
  CPilha(){topo = -1;}
  ~CPilha();
  void push_value(int,float,float);
  void push(float [][3]);
  Cmatrix* pop();
  void mult_matrix(void);
  void mult_points(float mA[][3],float mB[][3],float mR[][3]);
  void get_matrix_full(Cmatrix *, float [][3]);
  void set_matrix_full(Cmatrix *, float [][3]);
  bool empty();
};

//---------------------------------------------------------------------------