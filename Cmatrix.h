//---------------------------------------------------------------------------

#ifndef CmatrixH
#define CmatrixH
//---------------------------------------------------------------------------
#endif


class Cmatrix{
public:
	Cmatrix();
	 ~Cmatrix();
	float get_matrix(int,int);
	void set_matrix_value(float,int,int );
	void set_matrix(int,float,float);
	void print_matrix(void);
private:
	float matrix_core[3][3];
protected:
	// Cmatrix variables
	//methods
	void populating(void);
	void TRANS3f(float,float);
	void SCALE3f(float,float);
	void ROTAT2f(float);
	void SHEAR3f(float,float);
    void LOADIDENTITY(void);
};


