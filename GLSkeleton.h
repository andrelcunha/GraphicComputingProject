//---------------------------------------------------------------------------
#ifndef GLSkeletonH
#define GLSkeletonH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <gl\gl.h>
#include <gl\glu.h>
//#include <gl\glut.h>  
//---------------------------------------------------------------------------
class TGL_window : public TForm
{
__published: 
    void __fastcall FormResize(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:
    HDC hdc;
    HGLRC hrc;
    float w,h;
    int PixelFormat;

   
public:
    __fastcall TGL_window(TComponent* Owner);
    void __fastcall IdleLoop(TObject*, bool&);
    void __fastcall RenderGLScene();
    void __fastcall SetPixelFormatDescriptor();
    void __fastcall DrawObjects();
    void __fastcall SetupLighting();
    
};
//---------------------------------------------------------------------------
extern PACKAGE TGL_window *GL_window;
//---------------------------------------------------------------------------
#endif
