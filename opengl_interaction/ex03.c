#include <stdio.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

float fstX = 0.0;
float fstY = 0.0;
float sndX = 0.0;
float sndY = 0.0;

float red = 0.0;
float green = 0.0;
float blue = 1.0;

int clicks = 0;

void mouseInt(int button, int state, int x, int y) {
  switch (button) {
    case GLUT_LEFT_BUTTON:
      if(state==GLUT_DOWN){
        clicks++;
        if(clicks % 2 == 1){
          printf("FIRST CLICK: (%i, %i)\n",x,y);
          fstX = -1.0 + 2.0 * x / WINDOW_WIDTH;
          fstY = 1.0 - 2.0 * y / WINDOW_HEIGHT;
        } 
        else {
          printf("SECOND CLICK: (%i, %i)\n",x,y);
          sndX = -1.0 + 2.0 * x / WINDOW_WIDTH;
          sndY = 1.0 - 2.0 * y / WINDOW_HEIGHT;
          glutPostRedisplay();
        }
      }
      break;

    default:
        break;
    }
}

void colorChange(unsigned char number, int x, int y){
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
      default:
        break;
    }
    glutPostRedisplay();
}

void drawLine(){
  glBegin(GL_LINES);
    printf("DRAW: from (%f, %f) to (%f, %f)\n", 
      fstX, fstY, 
      sndX, sndY);
    glVertex2f(fstX, fstY);
    glVertex2f(sndX, sndY);
  glEnd();
}

void display(){
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(red,green,blue);
  glPointSize(5.0);
  if (clicks != 0)
    drawLine();
  glFlush();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(50, 50);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutCreateWindow("Exercicio 3 - Linha");
  glutDisplayFunc(display);
  glutKeyboardFunc(colorChange);
  glutMouseFunc(mouseInt);
  glutMainLoop();
  return 0;
}