#include <windows.h>
#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
const double cor = 1.0/30.0;
const double deg= 2.0 * acos(-1.0)/180;
void line(pair<double,double> a,pair<double,double> b,double R,double G,double B){
    glBegin(GL_LINES);
    glColor3ub(R,G,B);
    glVertex2d(a.first*cor,a.second*cor);
    glVertex2d(b.first*cor,b.second*cor);
    glEnd();
}
void rec(pair<double,double> a,pair<double,double> b,pair<double,double> c,pair<double,double> d,double R,double G,double B){
    glBegin(GL_POLYGON);
    glColor3ub(R,G,B);
    glVertex2d(a.first*cor,a.second*cor);
    glVertex2d(b.first*cor,b.second*cor);
    glVertex2d(c.first*cor,c.second*cor);
    glVertex2d(d.first*cor,d.second*cor);
    glEnd();
}
void DrawCircle(double radius, pair<double,double> xy, double R, double G, double B){
    pair<double,double> XY;
    glColor3ub(R, G, B);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xy.first, xy.second);
    for (double angle=1.0;angle<361.0;angle+=0.2){
        XY.first = xy.first+sin(angle)*radius;
        XY.second = xy.second+cos(angle)*radius;
        glVertex2f(XY.first, XY.second);
    }
    glEnd();
}
GLfloat car1X = 1.0f;
GLfloat car2X = -1.0f;
GLfloat car1Y = 3.5f*cor;
GLfloat car2Y = -3.5f*cor;
GLfloat car1Speed = 0.1f;
GLfloat car2Speed = 0.1f;
void update(int value) {
    if(car1X <-1.0)
        car1X = 1.0f;
    car1X -= car1Speed;

    if(car2X > 1.0)
        car2X = -1.0f;
    car2X += car2Speed;
	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    /// Road
    rec({-30, 30}, {30, 30}, {30, -30} , {-30, -30}, 44, 165, 13);
    rec({-30, 3.2}, {30, 3.2}, {30, -5.5} , {-30, -5.5}, 153, 153, 153);
    rec({-30, 0}, {-20, 0}, {-20, -1.5} , {-30, -1.5}, 255, 255, 255);
    rec({-10, 0}, {0, 0}, {0, -1.5} , {-10, -1.5}, 255, 255, 255);
    rec({10, 0}, {20, 0}, {20, -1.5} , {10, -1.5}, 255, 255, 255);
    /// Car 1
    glPushMatrix();
    glTranslatef(car1X,car1Y,0.0f);
    rec({-5.0, 0}, {-5.0, -1.1}, {4, -1.1}, {4, 0}, 255, 0, 0);
    rec({0, 0}, {0, 1.5}, {-2.5, 1.5}, {-3.8, 0}, 51, 102, 153);
    rec({0, 0}, {2.5, 0}, {2.0, 1.5}, {0, 1.5}, 51, 102, 153);
    rec({-0.2, 0}, {0.2, 0}, {0.2, 1.5}, {-0.2, 1.5}, 255, 0, 0);
    DrawCircle(0.6*cor, {-2*cor, -1*cor}, 0, 0, 0);
    DrawCircle(0.6*cor, {2*cor, -1*cor}, 0, 0, 0);
    glPopMatrix();
    /// End Car 1
    /// Car 2
    glPushMatrix();
    glTranslatef(car2X,car2Y,0.0f);
    rec({-5.0, 0}, {-5.0, -1.1}, {4, -1.1}, {4, 0}, 255, 0, 0);
    rec({0, 0}, {0, 1.5}, {-2.5, 1.5}, {-3.8, 0}, 51, 102, 153);
    rec({0, 0}, {2.5, 0}, {2.0, 1.5}, {0, 1.5}, 51, 102, 153);
    rec({-0.2, 0}, {0.2, 0}, {0.2, 1.5}, {-0.2, 1.5}, 255, 0, 0);
    DrawCircle(0.6*cor, {-2*cor, -1*cor}, 0, 0, 0);
    DrawCircle(0.6*cor, {2*cor, -1*cor}, 0, 0, 0);
    glPopMatrix();
    /// End Car 2
    glFlush();
}
int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(150, 150);
   glutCreateWindow("Translation Animation");
   glutDisplayFunc(display);
   init();
   glutTimerFunc(100, update, 0);
   glutMainLoop();
   return 0;
}
