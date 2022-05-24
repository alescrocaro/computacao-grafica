#include <GL/glut.h>

int width, height;
float spin = 0;

void Timer(int value);
void display(void);
void reshape(int w, int h);

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(800, 800);
  glutInitWindowPosition(500, 200);
  glutCreateWindow("Bule - Quatro projecoes");

  glClearColor(0.0, 0.0, 0.0, 0.0);

  glutDisplayFunc(display);

  glutTimerFunc(2,Timer, 1);

  glutReshapeFunc(reshape);

  glutMainLoop();
}

// função de callback de glutReshapeFunc
void reshape(int w, int h) {
  width = w;
  height = h;
}

// função de callback de glutTimerFunc
void Timer(int value){
  spin += 10.0f;
  glutPostRedisplay();
  glutTimerFunc(33, Timer, 1);
}



void display(void) {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);       // define a cor de fundo
  glClear(GL_COLOR_BUFFER_BIT);

  // -=-=-=-=-=- Viewport canto superior esquerdo -=-=-=-=-=-
  glViewport(0, height/2, width/2, height/2);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-3, 3, -3, 3, 1, 50);               // define uma projecao ortogonal

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0, 5, 0,
            0, 0, 0,
            0,  0,-1);

  glColor3f(1.0f, 0.0f, 0.0f);

  glutWireTeapot(2);                          // render a wireframe teapot



  // -=-=-=-=-=- Viewport canto superior direito -=-=-=-=-=-
  glViewport(width/2, height/2, width/2, height/2);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-3, 3, -3, 3, 1, 50);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(-5, 0, 0,
            0, 0, 0,
            0, 1, 0);

  glColor3f(1.0f, 0.0f, 0.0f);

  glutWireTeapot(2);



  // -=-=-=-=-=- Viewport canto inferior esquerdo -=-=-=-=-=-
  glViewport(0, 0, width/2, height/2);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-3, 3, -3, 3, 1, 50);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0, 0, 5,
            0, 0, 0,
            0, 1, 0);

  glColor3f(1.0f, 0.0f, 0.0f);

  glutWireTeapot(2);



  // -=-=-=-=-=- Viewport canto inferior direito -=-=-=-=-=-
  glViewport(width/2, 0, width/2, height/2);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, 1, 1, 50);               // define uma projecao perspectiva

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0, 0, 5,
            0, 0, 0,
            0, 1, 0);


  glRotatef(spin, 0, 0, 1);                 // rotaciona o objeto
  glRotatef(45, 1, 0, 0);                     // rotaciona o objeto

  glColor3f(1.0f, 0.0f, 0.0f);

  glutWireTeapot(2);



  glFlush();
}
