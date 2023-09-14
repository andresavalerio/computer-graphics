#include <stdio.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

float posX = 0.0;
float posY = 0.0;

void mouseInt(int button, int state, int x, int y) {
  switch (button) {
    case GLUT_LEFT_BUTTON:
      if(state==GLUT_DOWN)
        printf("CLICK: (%i, %i)\n",x,y);
        posX = -1.0 + 2.0 * x / WINDOW_WIDTH;
        posY = 1.0 - 2.0 * y / WINDOW_HEIGHT;
      break;

    default:
        break;
    }
  glutPostRedisplay();
}

void drawPoint(){
  glBegin(GL_POINTS);
  printf("DISPLAY: (%.2f, %.2f)\n", posX, posY);
  glVertex2f(posX, posY);
  glEnd();
}

void display(){
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0,0.0,1.0);
  glPointSize(5.0);
  drawPoint(); 
  glFlush();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(50, 50);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutCreateWindow("Exercicio 1 - Clique");
  glutDisplayFunc(display);
  glutMouseFunc(mouseInt);
  glutMainLoop();
  return 0;
}