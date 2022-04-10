#include <stdio.h>
#include <stdbool.h>

#include <GL/freeglut.h>


// functions
int init(void);
void display(void);
int main(int argc, char** argv);
void drawSquare();
void manageKeyboard(unsigned char key, int x, int y);
void manageSpecialKeyboard(int key, int x, int y);
void moveSquare(int x, int y);
void rotateSquare(int rotationAngle);
void scaleSquare(int scale);


// vars
int window;
char flagKey = 't';
int squarePositionX = 0, squarePositionY = 0;
int squareSide = 10;
int squareRotationAngle = 0;
int squareScale = 1;

// FUNÇÕES PRINCIPAIS DO OPENGL
int main(int argc, char** argv) {
    glutInit(&argc,argv);                                     //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);               //configura o modo de display
    glutInitWindowSize(500,500);                              //configura a largura e altura da janela de exibição
    glutInitWindowPosition(400,300);
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
    gluOrtho2D(0,100,0,100);      //define projeção ortogonal 2D que mapeia  objetos da coordenada do mundo para coordenadas da tela
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);    // Desenha objetos com a cor vermelha
    glMatrixMode(GL_MODELVIEW);    //carrega a matriz de modelo
    glLoadIdentity();    // carrega a matriz identidade

    // printf("%d, %d\n",squarePositionX,squarePositionY);
    // funções para transladar, rotacionar e fazer escala do quadrado
    glTranslatef(squarePositionX, squarePositionY, 0);
    rotateSquare(squareRotationAngle);
    scaleSquare(squareScale);

    drawSquare();

    glFlush();                            //desenha os comandos não executados
}


// FUNÇÕES DA ATIVIDADE

void drawSquare(){
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glBegin(GL_POLYGON);                    //desenha o quadrado
        glVertex2f(0, 0);
        glVertex2f(squareSide, 0);
        glVertex2f(squareSide, squareSide);
        glVertex2f(0, squareSide);
    glEnd();
}

// gerencia as teclas não especiais do teclado (apenas r, s, t)
void manageKeyboard(unsigned char key, int x, int y){
    switch(key){
        case 'R':   // rotação: ← e → alteram o ângulo de rotação
        case 'r':
            flagKey = 'r';
            printf("teclou %c\n", flagKey);
            break;

        case 'T':   // translação: ←, →, ↑ e ↓ alteram os fatores de translação tx e ty
        case 't':
            flagKey = 't';
            printf("teclou %c\n", flagKey);
            break;

        case 'S':   // escala uniforma: ↑ e ↓ alteram os fatores de escala
        case 's':
            flagKey = 's';
            printf("teclou %c\n", flagKey);
            break;

        case 27:    // When Escape Is Pressed, shut down our window
            glutDestroyWindow(window);
            exit(0);    // exit the program...normal termination.
            break;

         default:
                break;
    }

    glutPostRedisplay();
}

// gerencia as teclas especiais do teclado (apenas flechas pra todas direções e ESC para fechar a janela opengl)
void manageSpecialKeyboard(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:   // Teclou seta pra cima
            if(flagKey == 't'){
                printf("fazendo translação pra cima\n");
                moveSquare(0, 1);
            }
            if(flagKey == 's'){
                printf("Aumentando tamanho do objeto\n");
                squareScale += 0.1;
            }

            break;

        case GLUT_KEY_DOWN:   // Teclou seta pra baixo
            if(flagKey == 't'){
                printf("fazendo translação pra baixo\n");
                moveSquare(0, -1);
            }
            if(flagKey == 's'){
                printf("diminuindo tamanho do objeto\n");
                squareScale -= 0.1;
            }

            break;

        case GLUT_KEY_LEFT:   // Teclou seta pra esquerda
            if(flagKey == 't'){
                printf("fazendo translação pra esquerda\n");
                moveSquare(-1, 0);

            }
            if(flagKey == 'r'){
                printf("fazendo rotação pra esquerda\n");
                squareRotationAngle += 5;
            }
            break;

        case GLUT_KEY_RIGHT:    // Teclou seta pra direita
            if(flagKey == 't'){
                printf("fazendo translação pra direita\n");
                moveSquare(1, 0);
            }
            if(flagKey == 'r'){
                printf("fazendo rotação pra esquerda\n");
                squareRotationAngle -= 5;
            }

            break;

        default:
          break;
    }

    glutPostRedisplay();
}

// Move o quadrado para direita, esquerda, cima ou baixo
// modificando a var global squarePosition X e Y
void moveSquare(int x, int y){
    squarePositionX += x;
    squarePositionY += y;
}

// Leva o quadrado para a origem (0,0) (não visivel para o usuário do
// programa), rotaciona e o devolve para a posição anterior
void rotateSquare(int rotationAngle){
    glTranslatef((squareSide / 2), (squareSide / 2), 0);
    glRotatef(rotationAngle, 0, 0, 1);
    glTranslatef((-squareSide / 2), (-squareSide / 2), 0);
}

// Leva o quadrado para a origem (0,0) (não visivel para o usuário do programa),
// aumenta/diminui seu tamanho e o devolve para a posição anterior
void scaleSquare(int scale){
    glTranslatef((squareSide / 2), (squareSide / 2), 0);
    glScalef(scale, scale, 1);
    glTranslatef((-squareSide / 2), (-squareSide / 2), 0);
}


