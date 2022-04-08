#include <stdio.h>
#include <stdbool.h>

#include <GL/freeglut.h>

int init(void);
void display(void);
int main(int argc, char** argv);
void drawSquare(void);
void manageKeyboard(unsigned char key, int x, int y);
void manageSpecialKeyboard(unsigned char key, int x, int y);
int window;
bool flagR=false, flagT=false, flagS=false;

int main(int argc, char** argv) {
    glutInit(&argc,argv);                                     //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);               //configura o modo de display
    glutInitWindowPosition(400,300);
    glutInitWindowSize(0,100);                              //configura a largura e altura da janela de exibição
    window = glutCreateWindow("Atividade 1");           //cria a janela de exibição

    init();                          //executa função de inicialização
    glutDisplayFunc(display);        //estabelece a função "display" como a função callback de exibição.
    glutKeyboardFunc(manageKeyboard);
    glutSpecialFunc(manageSpecialKeyboard);
    glutMainLoop();                  //mostre tudo e espere
    return 0;
}

int init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);     //define a cor de fundo

    glMatrixMode(GL_PROJECTION);          //carrega a matriz de projeção
    gluOrtho2D(0,500,0,500);      //define projeção ortogonal 2D que mapeia  objetos da coordenada do mundo para coordenadas da tela
}


void drawSquare(void){
     glBegin(GL_POLYGON);                    //desenha o quadrado
         glVertex2f(0,0);
         glVertex2f(10,0);
         glVertex2f(10,10);
         glVertex2f(0,10);
    glEnd();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);              // Desenha objetos com a cor vermelha
    glMatrixMode(GL_MODELVIEW);           //carrega a matriz de modelo
    glLoadIdentity();                     // carrega a matriz identidade

    //utilizando o primeiro vértice da lista como ponto fixo
    //glTranslatef(110, 50, 0);             //move o ponto fixo para a posição original
    //glScalef(2.0,2.0,1.0);                //faz a escala
    //glTranslatef(-110, -50, 0);           //move o ponto fixo para a origem

    drawSquare();

    glFlush();                            //desenha os comandos não executados

}
/*
void manageTranslation(int key, int x, int y){
    if(key == GLUT_KEY_LEFT){
           win -= 20;
           glMatrixMode(GL_PROJECTION);
           glLoadIdentity();
           gluOrtho2D (-win, win, -win, win);
    }
    glutPostRedisplay();
}*/
void manageKeyboard(unsigned char key, int x, int y){
    switch(key){
        case 'R':   // rotação: ← e → alteram o ângulo de rotação
        case 'r':
            flagT = false;
            flagR = !flagR;
            flagS = false;
            glColor3f(0.0f,1.0f,0.0f);
            printf("teclou: %d\n", manageSpecialKeyboard);
            break;

        case 'T':   // translação: ←, →, ↑ e ↓ alteram os fatores de translação tx e ty
        case 't':
                flagT = !flagT;
                flagR = false;
                flagS = false;
            break;
        case 'S':   // escala uniforma: ↑ e ↓ alteram os fatores de escala
        case 's':
            flagT = false;
            flagR = false;
            flagS = !flagS;
            printf("teclou: %d\n", manageSpecialKeyboard);
            break;

        case 27:    // When Escape Is Pressed...
            // shut down our window
            glutDestroyWindow(window);
            // exit the program...normal termination.
            exit(0);
            break;          // Ready For Next Case

         default:                   // Now Wrap It Up
                break;
    }
    glutPostRedisplay();
}

void manageSpecialKeyboard(unsigned char key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:                   // Quando a seta para cima é teclada...
            if(flagT == 1){
                glutFullScreen ( );               // Vá para o modo tela cheia...
                printf("teclou seta pra cima\n");
            }

            break;

        case GLUT_KEY_DOWN:                 // Quando a seta para baixo for teclada...
            if(flagT == 1){
                glutReshapeWindow ( 640, 480 );   // Vá para modo em janela de 640 por 480
                printf("teclou seta pra baixo\n");
            }

            break;

        default:
          printf("teclou: %d\n", manageSpecialKeyboard);  // ...para ajudar você a debugar...
          break;
    }
    glutPostRedisplay();
}
