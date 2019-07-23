#include <windows.h>
#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
const double cor = 1.0/20.0;
const double deg = 2.0 * acos(-1.0)/180;
const double PI = 2.0 * acos(-1.0)/180;
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
    radius *= cor;
    xy.first *= cor;
    xy.second *= cor;
    glColor3ub(R, G, B);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xy.first, xy.second);
    for (double angle=1.0;angle<=180.0;angle+=1.0){
        XY.first = xy.first+sin(angle)*radius;
        XY.second = xy.second+cos(angle)*radius;
        glVertex2f(XY.first, XY.second);
    }
    glEnd();
}

GLfloat ship1X = 1.0f;
GLfloat ship1Y = 0.0f*cor;
GLfloat ship1Speed = 0.1f;
void update(int value) {
    if(ship1X > 1.0)
        ship1X = -1.0f;
    ship1X += ship1Speed;

	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    /// Water
    rec({-20, -4}, {-20, -20}, {20, -20}, {20, -4}, 0, 0, 210);
    /// Sky
    rec({-20, -4}, {-20, 20}, {20, 20}, {20, -4}, 121, 230, 231);

    /// Sun
    DrawCircle(3, {-5.0, 15}, 244, 223, 0);

    /// Cloud
    DrawCircle(2, {-12.0, 8}, 255, 255, 255);
    DrawCircle(2, {-8.0, 8}, 255, 255, 255);
    DrawCircle(2, {-10.0, 8}, 255, 255, 255);
    DrawCircle(2, {-10.0, 10}, 255, 255, 255);
    /// Cloud 2
    DrawCircle(2, {4.0, 9}, 255, 255, 255);
    DrawCircle(2, {8.0, 9}, 255, 255, 255);
    DrawCircle(2, {6.0, 9}, 255, 255, 255);
    DrawCircle(2, {6, 11}, 255, 255, 255);
    /// ship 1
    glPushMatrix();
    glTranslatef(ship1X,ship1Y,0.0f);
    rec({-18, -1}, {-16, -5}, {-8, -5}, {-5, -1}, 138, 53, 26);
    rec({-16, -1}, {-8, -1}, {-8, 3}, {-16, 3}, 121, 148, 157);
    rec({-15, 0}, {-9, 0}, {-9, 1}, {-15, 1}, 43, 210, 241);
    glPopMatrix();
    /// End ship 1
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
