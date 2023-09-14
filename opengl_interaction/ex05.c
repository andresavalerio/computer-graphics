#include <stdio.h>
#include <GL/glut.h>
#include <stdbool.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

float lFstX = 0.0;
float lFstY = 0.0;
float lSndX = 0.0;
float lSndY = 0.0;

float tFstX = 0.0;
float tFstY = 0.0;
float tSndX = 0.0;
float tSndY = 0.0;
float tTrdX = 0.0;
float tTrdY = 0.0;

float red = 0.0;
float green = 0.0;
float blue = 1.0;

int clicks = 0;
bool isLine = true;

void lineClicks(int x, int y){
  if(clicks == 1){
    printf("FIRST LINE CLICK: (%i, %i)\n",x,y);
    lFstX = -1.0 + 2.0 * x / WINDOW_WIDTH;
    lFstY = 1.0 - 2.0 * y / WINDOW_HEIGHT;
  } 
  else {
    printf("SECOND LINE CLICK: (%i, %i)\n",x,y);
    lSndX = -1.0 + 2.0 * x / WINDOW_WIDTH;
    lSndY = 1.0 - 2.0 * y / WINDOW_HEIGHT;
    glutPostRedisplay();
  }
}
 
void triangleClicks(int x, int y){
  if(clicks == 1){
    printf("FIRST TRIANGLE CLICK: (%i, %i)\n",x,y);
    tFstX = -1.0 + 2.0 * x / WINDOW_WIDTH;
    tFstY = 1.0 - 2.0 * y / WINDOW_HEIGHT;
  } 
  else if (clicks == 2){
    printf("SECOND TRIANGLE CLICK: (%i, %i)\n",x,y);
    tSndX = -1.0 + 2.0 * x / WINDOW_WIDTH;
    tSndY = 1.0 - 2.0 * y / WINDOW_HEIGHT;
  } else {
    printf("THIRD TRIANGLE CLICK: (%i, %i)\n",x,y);
    tTrdX = -1.0 + 2.0 * x / WINDOW_WIDTH;
    tTrdY = 1.0 - 2.0 * y / WINDOW_HEIGHT;
    glutPostRedisplay();
  }
}

void mouseInt(int button, int state, int x, int y) {
  switch (button) {
    case GLUT_LEFT_BUTTON:
      if (state==GLUT_DOWN){
        clicks++;
        if (isLine){
          lineClicks(x,y);
        } else {
          triangleClicks(x,y);
        }
      }   
      break;
    
    default:
        break;
    }
}

void keyboardInt(unsigned char number, int x, int y){
    switch (number) {
      case '0':
        printf("CASE %c\n", number);
        red = 0.0;
        green = 0.0;
        blue = 1.0;
        break;
      case '1':
        printf("CASE %c\n", number);
        red = 0.0;
        green = 1.0;
        blue = 0.0;
        break;
      case '2':
        printf("CASE %c\n", number);
        red = 1.0;
        green = 0.0;
        blue = 0.0;
        break;
      case '3':
        printf("CASE %c\n", number);
        red = 1.0;
        green = 0.0;
        blue = 1.0;
        break;
      case '4':
        printf("CASE %c\n", number);
        red = 0.0;
        green = 1.0;
        blue = 1.0;
        break;
      case '5':
        printf("CASE %c\n", number);
        red = 1.0;
        green = 1.0;
        blue = 0.0;
        break;
      case '6':
        printf("CASE %c\n", number);
        red = 1.0;
        green = 1.0;
        blue = 1.0;
        break;
      case '7':
        printf("CASE %c\n", number);
        red = 1.0;
        green = 0.5;
        blue = 1.0;
        break;
      case '8':
        printf("CASE %c\n", number);
        red = 0.5;
        green = 0.5;
        blue = 0.5;
        break;
      case '9':
        printf("CASE %c\n", number);
        red = 1.0;
        green = 0.5;
        blue = 0.0;
        break;
      case 'R':
      case 'r':
        isLine = true;
        break;
      case 'T':
      case 't':
        isLine = false;
        break;
      default:
        break;
    }
    glutPostRedisplay();
}

void drawLine(){
  glBegin(GL_LINES);
    printf("DRAW: from (%f, %f) to (%f, %f)\n", 
      lFstX, lFstY, 
      lSndX, lSndY);
    glVertex2f(lFstX, lFstY);
    glVertex2f(lSndX, lSndY);
  glEnd();
}

void drawTriangle(){
  glBegin(GL_TRIANGLES);
      printf("TRIANGLE: (%.2f, %.2f) (%.2f, %.2f) (%.2f, %.2f)\n", 
        tFstX, tFstY,
        tSndX, tSndY,
        tTrdX, tTrdY);
      glVertex2f(tFstX, tFstY);
      glVertex2f(tSndX, tSndY);
      glVertex2f(tTrdX, tTrdY);
    glEnd();
}

void display(){
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(red,green,blue);
  glPointSize(5.0);
  if (isLine)
    drawLine();
  else
    drawTriangle();
  clicks = 0;
  glFlush();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(50, 50);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutCreateWindow("Exercicio 5 - Linha e Triângulo");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboardInt);
  glutMouseFunc(mouseInt);
  glutMainLoop();
  return 0;
}