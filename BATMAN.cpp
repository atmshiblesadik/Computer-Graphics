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

void display(){
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    DrawRectangle({-3,0},{3,0},{3,3},{-3,3},115, 115, 115);
    DrawRectangle({-4,1},{-3,1},{-3,2},{-4,2},115, 115, 115);
    DrawRectangle({3,1},{4,1},{4,2},{3,2},115, 115, 115);
    DrawRectangle({-2,1},{2,1},{2,2},{-2,2},13, 13, 13);
    DrawRectangle({-2,3},{2,3},{2,4},{-2,4},255, 153, 0); ///yellow
    DrawRectangle({-2,4},{2,4},{2,6},{-2,6},0, 0, 153); ///blue
    DrawRectangle({1,6},{2,6},{2,8},{1,8},0, 0, 153); ///blue
    DrawRectangle({-2,4},{-1,4},{-1,8},{-2,8},0, 0, 51); ///blue
    DrawRectangle({-4,0},{-3,0},{-3,1},{-4,1},255, 153, 0); ///yellow
    DrawRectangle({3,0},{4,0},{4,1},{3,1},255, 153, 0); ///yellow

    DrawRectangle({-4,0},{-3,0},{-3,-1},{-4,-1},0, 0, 102); ///blue
    DrawRectangle({3,0},{4,0},{4,-1},{3,-1},0, 0, 102); ///blue

    DrawRectangle({3,-1},{4,-1},{4,-4},{3,-4},0, 0, 0); ///black
    DrawRectangle({-4,0},{-3,0},{-3,-4},{-4,-4},0, 0, 0); ///black
    DrawRectangle({-1,-3},{1,-3},{1,-4},{-1,-4},0, 0, 0); ///black


    DrawRectangle({-3,-1},{3,-1},{3,0},{-3,0},255, 204, 0); ///yellow

    DrawRectangle({-3,-2},{-2,-2},{-2,-1},{-3,-1},0, 0, 51); ///blue

    DrawRectangle({-3,-6},{-2,-6},{-2,-5},{-3,-5},0, 0, 51); ///blue
    DrawRectangle({-2,-6},{-1,-6},{-1,-5},{-2,-5},0, 0, 153); ///blue
    DrawRectangle({1,-6},{2,-6},{2,-5},{1,-5},0, 0, 51); ///blue
    DrawRectangle({2,-6},{3,-6},{3,-5},{2,-5},0, 0, 153); ///blue


    DrawRectangle({2,-1},{3,-1},{3,-2},{2,-2},0, 0, 153); ///blue
    DrawRectangle({-2,-3},{2,-3},{2,-1},{-2,-1},0, 0, 153); ///blue


    DrawRectangle({-2,-5},{-1,-5},{-1,-3},{-2,-3},115, 115, 115);
    DrawRectangle({2,-5},{3,-5},{3,-1},{2,-1},115, 115, 115);

    DrawRectangle({-3,-5},{-2,-5},{-2,-1},{-3,-1},64, 64, 64);
    DrawRectangle({1,-5},{2,-5},{2,-3},{1,-3},64, 64, 64);



    glFlush();
}
int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutCreateWindow("Batman");
    glutInitWindowSize(500,500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
