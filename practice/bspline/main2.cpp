#include "opengl_template.h"
#include "bspline.h"

int main(int argc,char *argv[])
{
    BSpline B({make_pair(1.0,4.5), make_pair(2.7,6), make_pair(5.3,3), make_pair(9,9)}, 0.001);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(200,200);
    glutCreateWindow("h_constante");
    gluOrtho2D(-1,10,-1,10);
    glutDisplayFunc(Redraw(B));
    glutMainLoop();
    return 0;
}