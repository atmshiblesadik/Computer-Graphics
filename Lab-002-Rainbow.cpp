#include<windows.h>
#include<GL/glut.h>
void rec(float first,float second,float R,float G,float B){
    glBegin(GL_POLYGON);
    glColor3ub(R,G,B);

    glVertex2f(-1.0f,first);
    glVertex2f(+1.0f,first);
    glVertex2f(+1.0f,second);
    glVertex2f(-1.0f,second);

    glEnd();
}
void display(){
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

//    glColor3ub(0.0f,0.0f,0.0f);
//    glBegin(GL_POLYGON);
//
//    glVertex2f(-1.0f,+0.7143f);
//    glVertex2f(+1.0f,+0.7143f);
//    glVertex2f(+1.0f,+1.0f);
//    glVertex2f(-1.0f,+1.0f);
//
//    glEnd();
    rec(+1.0f,+0.7143f,255.0f,0.0f,0.0f);
    rec(+0.7143f,+0.4286f,255.0f, 102.0f, 0.0f);
    rec(+0.4286f,+0.1429f,255.0f,255.0f,0.0f);
    rec(+0.1429f,-0.1428f,0.0f,153.0f,0.0f);
    rec(-0.1428f,-0.4285f,0.0f,0.0f,255.0f);
    rec(-0.4285f,-0.7143f,153.0f,0.0f,204.0f);
    rec(-0.7143f,-1.0f,0.0f,0.0f,0.0f);

    glFlush();
}
int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutCreateWindow("Title of Project Window");
    glutInitWindowSize(512,512);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
