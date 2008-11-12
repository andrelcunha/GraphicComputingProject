//---------------------------------------------------------------------------

#ifndef CmatrixH
#define CmatrixH
//---------------------------------------------------------------------------
#endif


class Cmatrix{
public:
	Cmatrix();
	 ~Cmatrix();
	double get_matrix(int,int);
	void set_matrix_value(double,int,int );
	void set_matrix(int,double,double);
	void print_matrix(void);
private:
	double matrix_core[3][3];
protected:
	// Cmatrix variables
	//methods
	void populating(void);
	void TRANS3f(double,double);
	void SCALE3f(double,double);
	void ROTAT2f(double);
	void SHEAR3f(double,double);
    void LOADIDENTITY(void);
};


