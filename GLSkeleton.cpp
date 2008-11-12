//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "main_form.h"
#include "GLSkeleton.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGL_window *GL_window;
//---------------------------------------------------------------------------
__fastcall TGL_window::TGL_window(TComponent* Owner)
	: TForm(Owner)
{
    Application->OnIdle = IdleLoop;
}
//---------------------------------------------------------------------------
void __fastcall TGL_window::IdleLoop(TObject*, bool& done)
{
    done= false;
    FormPaint(this);
    SwapBuffers(hdc);    // USADO PARA DOUBLE BUFFERING

}
//---------------------------------------------------------------------------
void __fastcall TGL_window::FormCreate(TObject *Sender)
{
    hdc = GetDC(Handle);
    SetPixelFormatDescriptor();
    hrc = wglCreateContext(hdc);
    if(hrc == NULL)
     ShowMessage("Deu pau na obtenção do hrc!!");
    if(wglMakeCurrent(hdc, hrc) == false)
     ShowMessage("Could not MakeCurrent");
    w = ClientWidth;
    h = ClientHeight;

    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //cor de limpeza
    //SetupLighting();     //comentar para desabilitar luzes
}
//---------------------------------------------------------------------------
//   SetPixelFormatDescriptor()
//---------------------------------------------------------------------------
// Descreve as características de pixel que o hdc utilizará no programa
// IMPORTANTE: Algumas implementações em hardware, especialmente as mais antigas
// podem não suportar este descriptor
//---------------------------------------------------------------------------
void __fastcall TGL_window::SetPixelFormatDescriptor()
{
    PIXELFORMATDESCRIPTOR pfd = {
     sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        24,   //Bit color; Mudar para 16 ou 32 dependendo da placa de vídeo
        0,0,0,0,0,0,
        0,0,
        0,0,0,0,0,
        16,   //tamanho do depth buffer; Usar 32 em placas modernas
        0,
        0,
        PFD_MAIN_PLANE,
        0,
        0,0,
    };
    PixelFormat = ChoosePixelFormat(hdc, &pfd); //retorna o resultado do pedido
                                        //sobre a disponibilidade do pixel format
    SetPixelFormat(hdc, PixelFormat, &pfd);//determina que hdc use &pdf
}
//---------------------------------------------------------------------------
// FormResize()
//---------------------------------------------------------------------------
//IMPORTANTE! NÃO MEXA SE NÃO SOUBER OQ ESTÁ FAZENDO
//---------------------------------------------------------------------------
void __fastcall TGL_window::FormResize(TObject *Sender)
{
    /*
    GLfloat nRange = 5.0;
    w = ClientWidth;
    h = ClientHeight;

    if(h == 0)
         h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h)
        glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
    else
 glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);/**/
    /*
    //Projecao perspectiva
    GLfloat aspect = (GLfloat)w/(GLfloat)h;
    gluPerspective(30.0f, aspect, 1.0, 50.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(40,60,100, 0,0,0, 0,1,0);  /**/
}
//---------------------------------------------------------------------------

void __fastcall TGL_window::DrawObjects()
{
  //COLOCAR CÒDIGO PARA DESENHO DE GEOMETRIA AQUI
  float degrade=0;
  int i;

  glBegin(GL_TRIANGLES);
  for(i=0;i<3;i++){
      glColor3f(1.0f,0.0f,0.0f);
      glVertex2f((Form1->get_triangleX(i)),(Form1->get_triangleY(i)));
  }
  glEnd();
  glFlush();
  glBegin(GL_POLYGON);
  glColor3f(0.0f,0.0f,0.0f);
  for(i=0;i<5;i++){
      glColor3f(0.0f,0.0f,degrade);
      glVertex2f((Form1->get_xcoord(i)),(Form1->get_ycoord(i)));
      degrade=+0.33334;
  }
  glEnd();
  glFlush();/**/
}

//---------------------------------------------------------------------------
void __fastcall TGL_window::FormPaint(TObject *Sender)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glFlush();
    DrawObjects();
}
//---------------------------------------------------------------------------
void __fastcall TGL_window::FormDestroy(TObject *Sender)
{

    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hrc);
}

//---------------------------------------------------------------------------
void __fastcall TGL_window::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_UP)
        glRotatef(-10, 2.0, 0.0, 0.0);
    if(Key == VK_DOWN)
        glRotatef(10, 2.0, 0.0, 0.0);
    if(Key == VK_LEFT)
        glRotatef(-10, 0.0, 2.0, 0.0);
    if(Key == VK_RIGHT)
        glRotatef(10, 0.0, 2.0, 0.0);
    if(Key == VK_ESCAPE)
        Hide();
    if(Key == VK_SPACE)
        Show();
}
//---------------------------------------------------------------------------
//  SetupLighting()
//---------------------------------------------------------------------------
// habilita e determina os parâmetros de uma fonte de luz
//---------------------------------------------------------------------------
/*void __fastcall TGL_window::SetupLighting()
{
    GLfloat MaterialAmbient[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat MaterialDiffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat MaterialSpecular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat MaterialShininess[] = {50.0};
    GLfloat AmbientLightPosition[] = {0.5, 1.0, 1.0, 0.0};
    GLfloat LightAmbient[] = {0.5, 0.5, 0.5, 1.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, MaterialSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, MaterialShininess);
    glLightfv(GL_LIGHT0, GL_POSITION, AmbientLightPosition);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LightAmbient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glShadeModel(GL_SMOOTH);
}*/
//---------------------------------------------------------------------------

