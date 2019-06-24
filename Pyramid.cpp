#include<bits/stdc++.h>
#include<windows.h>
#include<stdlib.h>
#include<GL/glut.h>
using namespace std;
const double cor = 1.0/10.0;
const double pi = 2*acos(0.0);
void DrawRectangle(pair<double,double> a,pair<double,double> b,pair<double,double> c,pair<double,double> d,double R,double G,double B){
    glBegin(GL_POLYGON);
    glColor3ub(R,G,B);
    glVertex2d(a.first*cor,a.second*cor);
    glVertex2d(b.first*cor,b.second*cor);
    glVertex2d(c.first*cor,c.second*cor);
    glVertex2d(d.first*cor,d.second*cor);
    glEnd();
}
void DrawHexa(pair<double,double> a,pair<double,double> b,pair<double,double> c,pair<double,double> d,pair<double,double> e,pair<double,double> f,double R,double G,double B){
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
void DrawTriangle(pair<double,double> a,pair<double,double> b,pair<double,double> c,double R,double G,double B){
    glBegin(GL_POLYGON);
    glColor3ub(R,G,B);
    glVertex2d(a.first*cor,a.second*cor);
    glVertex2d(b.first*cor,b.second*cor);
    glVertex2d(c.first*cor,c.second*cor);
    glEnd();
}
void DrawLine(pair<double,double> a,pair<double,double> b,double R,double G,double B){
    glBegin(GL_LINES);
    glColor3ub(R,G,B);
    glVertex2d(a.first*cor,a.second*cor);
    glVertex2d(b.first*cor,b.second*cor);
    glEnd();
}
void DrawTree(pair<double,double> xy){
    DrawRectangle({xy.first-0.1,xy.second},{xy.first+0.1,xy.second},{xy.first+0.1,xy.second+1.5},{xy.first-0.1,xy.second+1.5},132, 21, 3);
    DrawHexa({xy.first-0.5,xy.second+1.5},{xy.first+0.5,xy.second+1.5},{xy.first+0.8,xy.second+1.9},{xy.first+0.5,xy.second+2.3},{xy.first-0.5,xy.second+2.3},{xy.first-0.8,xy.second+1.9},20, 160, 62);
}
void DrawPyramid(pair<double,double> xy){
    DrawRectangle({xy.first-2.0,xy.second},{xy.first+4.0,xy.second},{xy.first,xy.second+4},{xy.first-2.0-2.0,xy.second+1.5}, 229, 164, 0);
    DrawRectangle({xy.first-0.5,xy.second+3.0},{xy.first+1.0,xy.second+3.0},{xy.first,xy.second+4},{xy.first-1.3,xy.second+3.2}, 137, 98, 0);
    DrawLine({xy.first-2.0,xy.second},{xy.first,xy.second+4.0}, 255 , 255, 255);
    for(double x1=1.75,x2=3.5,y=0.5,x3=3.55,y2=1.75,i=0.04;y<3.0;y+=0.5,x1-=0.25,x2-=0.5,x3-=0.40,y2+=0.25,i+=0.02){
        DrawLine({xy.first-x1,xy.second+y},{xy.first+x2,xy.second+y}, 255 , 255, 255);
        DrawLine({xy.first-x1,xy.second+y},{xy.first-x3,xy.second+y2+i}, 255 , 255, 255);
    }
}
void display(){
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    DrawRectangle({-10,0},{10,0},{10,-10},{-10,-10}, 247, 222, 160);
    DrawRectangle({-10,0},{10,0},{10,10},{-10,10},40, 217, 252);

    DrawTree({0,0});
    DrawPyramid({5,-3});

    glTranslated(-0.5,0.0,0);
    glScaled(1.4,1.4,0);
    DrawPyramid({5,-3});

    glTranslated(-0.5,-0.1,0);
    glScaled(1.25,1.25,0);
    DrawPyramid({5,-3});

    glTranslated(+0.6,0.05,0);
    glScaled(0.8,0.8,0);
    DrawTree({0,0});

    glFlush();
}
int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutCreateWindow("Pyramid");
    glutInitWindowSize(500,500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
