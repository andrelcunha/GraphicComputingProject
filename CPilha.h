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
  void push_value(int,double,double);
  void push(double [][3]);
  Cmatrix* pop();
  void mult_matrix(void);
  void mult_points(double mA[][3],double mB[][3],double mR[][3]);
  void get_matrix_full(Cmatrix *, double [][3]);
  void set_matrix_full(Cmatrix *, double [][3]);
  bool empty();
};

//---------------------------------------------------------------------------