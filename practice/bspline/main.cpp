#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include "bspline.h"


static void Redraw(void)
{
    BSpline B({make_pair(1.0,4.5), make_pair(2.7,6), make_pair(5.3,3), make_pair(9,9)}, 0.001);

    vector<double> Px, Py;
    vector<double> Dx, Dy;
    vector<double> Rx, Ry;
    vector<double> Lx, Ly;
    B.CopyPVectors(Px, Py);
    B.CopyDVectors(Dx, Dy);
    B.CopyRVectors(Rx, Ry);
    B.CopyLVectors(Lx, Ly);


    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);

    
    for(int i = 0; i < Px.size(); i++)
        glVertex2d(Px[i],Py[i]);

    glEnd();

    glPointSize(6.0);
    glColor3f(1,0,0);
    glBegin(GL_POINTS);    

    for(int i = 0; i < Dx.size(); i++)
        glVertex2d(Dx[i],Dy[i]);
        
    glEnd();

    glColor3f(0.3,0.3,1);
    glPointSize(6);
    glBegin(GL_POINTS);
    for(int i = 0; i < Rx.size(); i++)
    {
        glVertex2d(Rx[i],Ry[i]);
        glVertex2d(Lx[i],Ly[i]);
    }
    glEnd();


    vector<double> points_x, points_y;
    B.CopyPoints(points_x, points_y);
    //drawing bspline
    glBegin(GL_LINE_STRIP);
    for(int i = 0; i < points_x.size();i++)
    {
        glVertex2d(points_x[i], points_y[i]);
    }
    glEnd();
    glFlush();
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(200,200);
    glutCreateWindow("h_constante");
    gluOrtho2D(-1,10,-1,10);
    glutDisplayFunc(Redraw);
    glutMainLoop();
    return 0;
}