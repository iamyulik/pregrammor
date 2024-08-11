#include <glut.h>
#include <cmath>

int a=10;
double x,y,t=0;
void Draw()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3d(0.0, 0.0, 0.0); //Выбираем белый цвет
glLineWidth(3);
glBegin(GL_LINE_STRIP);
static const float r = 0.1f;
static const float pi = 3.1415926535897932384626433832795029f;
for(float angle = 0.0f; angle < (pi * 2.0f); angle += 0.05f)
{
float x = 2.0f * r * cos(angle) * (1.0f - cos(angle));
float y = 2.0f * r * sin(angle) * (1.0f - cos(angle));
glVertex3f(x, y, 0.0f);
}

glEnd();
glColor3d(1.0,0.0,0.0);
glLineWidth(1);
glBegin(GL_LINES);
glVertex2d(0.0,1.0);
glVertex2d(0.0,-1.0);
glVertex2d(1.0,0.0);
glVertex2d(-1.0,0.0);
glEnd();
glFinish();
}
void main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB);
glutInitWindowSize(600,600); //Указываем размер окна
glutInitWindowPosition(200,200); //Позиция окна
glutCreateWindow("кривая"); //Имя окна
glClearColor(1.0, 1.0, 1.0, 1.0); //Вызов функции Initialize
glutDisplayFunc(Draw); //Вызов функции отрисовки
glutMainLoop();

}