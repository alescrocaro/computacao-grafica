#include <stdio.h>
#include <GL/glut.h>

int init(void);
void display(void);
void desenhaCasa(void);
int main(int argc, char** argv);


int main(int argc, char** argv) {
    glutInit(&argc,argv);                                     //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);               //configura o modo de display
    glutInitWindowPosition(200,0);
    glutInitWindowSize(400,300);                              //configura a largura e altura da janela de exibição
    glutCreateWindow("Ordem de Transformacoes 2");           //cria a janela de exibição

    init();                          //executa função de inicialização
    glutDisplayFunc(display);        //estabelece a função "display" como a função callback de exibição.
    glutMainLoop();                  //mostre tudo e espere
    return 0;
}

int init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);     //define a cor de fundo

    glMatrixMode(GL_PROJECTION);          //carrega a matriz de projeção
    glLoadIdentity();                     //carrega a matriz identidade
    gluOrtho2D(0.0,200.0,0.0,150.0);      //define projeção ortogonal 2D que mapeia  objetos da coordenada do mundo para coordenadas da tela
}

void desenhaCasa(void){
    glBegin(GL_POLYGON);                    //desenha uma casa
         glVertex2f(110,50);
         glVertex2f(110,70);
         glVertex2f(100,80);
         glVertex2f(90,70);
         glVertex2f(90,50);
    glEnd();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);              // Desenha objetos com a cor vermelha
    glMatrixMode(GL_MODELVIEW);           //carrega a matriz de modelo
    glLoadIdentity();                     //carrega a matriz identidade


    glTranslatef(110, 50, 0);            //move o ponto fixo para a posição original
    glRotatef(90, 0, 0, 1);               //rotaciono
    glTranslatef(-110, -50, 0);       //move o ponto fixo para a origem
    glTranslatef(50, 0, 0);               //faço a translação

    desenhaCasa();

    glFlush();                            //desenha os comandos não executados
}
