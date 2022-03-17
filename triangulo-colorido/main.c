#include <GL/glut.h>

int init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0); // background color
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 200.0, 0.0, 150.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2i(100, 130);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2i(50, 20);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2i(150, 20);
    glEnd();

    glFlush();
}

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800,600);

    glutCreateWindow("Triangulo RGB");

    init();

    glutDisplayFunc(display);
    glutMainLoop();
}
