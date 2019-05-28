#include<windows.h>
#include<GL/glut.h>

void display(){
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
///X-Axis
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(1.0f,0.0f);
    glVertex2f(-1.0f,0.0f);
    glEnd();
///Y-Axis
    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f,1.0f);
    glVertex2f(-0.0f,-1.0f);
    glEnd();
///First
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);

    glVertex2f(-0.1f,0.1f);
    glVertex2f(-0.5f,0.9f);

    glVertex2f(-0.5f,0.9f);
    glVertex2f(-0.9f,0.1f);

    glVertex2f(-0.9f,0.1f);
    glVertex2f(-0.1f,0.1f);

    glEnd();
///Second
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);

    glVertex2f(0.8f,0.2f);
    glVertex2f(0.8f,0.8f);

    glVertex2f(0.8f,0.8f);
    glVertex2f(0.2f,0.8f);

    glVertex2f(0.2f,0.8f);
    glVertex2f(0.2f,0.2f);

    glVertex2f(0.2f,0.2f);
    glVertex2f(0.8f,0.2f);

    glEnd();
///Third
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.3f,-0.8f);
    glVertex2f(-0.2f,-0.7f);
    glVertex2f(-0.2f,-0.3f);
    glVertex2f(-0.3f,-0.2f);
    glVertex2f(-0.7f,-0.2f);
    glVertex2f(-0.8f,-0.3f);
    glVertex2f(-0.8f,-0.7f);
    glVertex2f(-0.7f,-0.8f);
    glEnd();
///Fourth
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.1f,-0.1f);
    glVertex2f(0.9f,-0.1f);
    glVertex2f(0.5f,-0.9f);
    glEnd();

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
