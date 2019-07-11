#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
const double cor = 0.2;
const double deg=acos(-1.0)/180;

void rec(pair<double,double> a,pair<double,double> b,pair<double,double> c,pair<double,double> d,double R,double G,double B){
        glBegin(GL_POLYGON);
        glColor3ub(R,G,B);
        glVertex2d(a.first*cor,a.second*cor);
        glVertex2d(b.first*cor,b.second*cor);
        glVertex2d(c.first*cor,c.second*cor);
        glVertex2d(d.first*cor,d.second*cor);
        glEnd();
}
void hexa(pair<double,double> a,pair<double,double> b,pair<double,double> c,pair<double,double> d,pair<double,double> e,pair<double,double> f,double R,double G,double B){
        glBegin(GL_POLYGON);
        glColor3ub(R,G,B);
        glVertex2d(a.first*cor,a.second*cor);
        glVertex2d(b.first*cor,b.second*cor);
        glVertex2d(c.first*cor,c.second*cor);
        glVertex2d(d.first*cor,d.second*cor);
        glVertex2d(e.first*cor,e.second*cor);
        glVertex2d(f.first*cor,f.second*cor);
        glEnd();
}
void tri(pair<double,double> a,pair<double,double> b,pair<double,double> c,double R,double G,double B){
        glBegin(GL_POLYGON);
        glColor3ub(R,G,B);
        glVertex2d(a.first*cor,a.second*cor);
        glVertex2d(b.first*cor,b.second*cor);
        glVertex2d(c.first*cor,c.second*cor);
        glEnd();
}
void line(pair<double,double> a,pair<double,double> b,double R,double G,double B){
        glBegin(GL_LINES);
        glColor3ub(R,G,B);
        glVertex2d(a.first*cor,a.second*cor);
        glVertex2d(b.first*cor,b.second*cor);
        glEnd();
}
void circle(double radius,double R,double G,double B){
        glBegin(GL_LINE_LOOP);
        glColor3ub(R,G,B);
        for(int i=0;i<360;i++){
                glVertex2f(cos(i*deg)*radius,sin(i*deg)*radius);
        }
        glEnd();
}

void display(){
        glClearColor(1.0f,1.0f,1.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        rec({-5,-2},{5,-2},{5,1},{-5,1},51, 102, 255);

        tri({-5,1},{-1,1},{-3,4},153, 51, 0);
        tri({-1,1},{3,1},{1,4},153, 51, 0);
        tri({3,1},{5,1},{4,2},153, 51, 0);

        rec({-5,-5},{5,-5},{5,-2},{-5,-2},51, 153, 51);


        rec({0,-4},{3,-4},{3,-1},{0,-1},204, 0, 0);
        rec({1,-4},{2,-4},{2,-3},{1,-3},100, 51, 51);
        tri({0,-1},{3,-1},{1.5,0.5},100, 51, 51);


        rec({-4,-3},{-3.7,-3},{-3.7,-1},{-4,-1},153, 102, 51);
        hexa({-4.2,-1.5},{-3.6,-1.5},{-3.3,-1},{-3.6,-0.5},{-4.2,-0.5},{-4.5,-1},102, 255, 153);


//        circle(.1,0,0,0);

        glTranslated(.2,.2,0);
        rec({-4,-3},{-3.7,-3},{-3.7,-1},{-4,-1},153, 102, 51);
        hexa({-4.2,-1.5},{-3.6,-1.5},{-3.3,-1},{-3.6,-0.5},{-4.2,-0.5},{-4.5,-1},102, 255, 153);

        glTranslated(-.35,-.6,0);
        glScaled(.4,.4,0);
        rec({-4,-3},{-3.7,-3},{-3.7,-1},{-4,-1},153, 102, 51);
        hexa({-4.2,-1.5},{-3.6,-1.5},{-3.3,-1},{-3.6,-0.5},{-4.2,-0.5},{-4.5,-1},102, 255, 153);

        glTranslated(1.0,.6,0);
        glScaled(2.8,2.9,0);
        rec({-4,-3},{-3.7,-3},{-3.7,-1},{-4,-1},153, 102, 51);
        hexa({-4.2,-1.5},{-3.6,-1.5},{-3.3,-1},{-3.6,-0.5},{-4.2,-0.5},{-4.5,-1},102, 255, 153);

        glFlush();
}
int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutCreateWindow("D-Building");
    glutInitWindowSize(1024,1024);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
