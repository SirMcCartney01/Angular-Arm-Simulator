// This program is from the OpenGL Programming Guide.  It shows a robot arm
// that you can rotate by pressing the arrow keys.

#include <GL/glut.h>

static GLfloat red[] = { 1, 0, 0 }, green[] = { 0, 1, 0 }, blue[] = { 0, 0, 1 };
static int shoulderAngle = 135, elbowAngle = 100, baseAngle = 50;


void kb(unsigned char key, int, int)
{
    switch(key)
    {
        case 'a': (baseAngle += 5) %= 360; break;
        case 'd': (baseAngle -= 5) %= 360; break;
        default: return;
    }

    glutPostRedisplay();
}

void special(int key, int, int)
{
    switch (key)
    {
        case GLUT_KEY_LEFT: (elbowAngle += 5) %= 360; break;
        case GLUT_KEY_RIGHT: (elbowAngle -= 5) %= 360; break;
        case GLUT_KEY_UP: (shoulderAngle += 5) %= 360; break;
        case GLUT_KEY_DOWN: (shoulderAngle -= 5) %= 360; break;
        default: return;
    }

    glutPostRedisplay();
}

void solidBox(GLdouble width, GLdouble height, GLdouble depth)
{
    glPushMatrix();
    glScalef(width, height, depth);
    glutSolidCube(1.0);
    glPopMatrix();
}


void display()
{
    // baseAngle
    glColor3fv(blue);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef((GLfloat)baseAngle, 0.0, 1.0, 0.0);
    glTranslatef(0.0, 1.0, 0.0);
    solidBox(1.0, 1.0, 1.0);

    //shoulderAngle
    glColor3fv(red);
    glRotatef((GLfloat)shoulderAngle, 0.0, 0.0, 1.0);
    glTranslatef(2.0, 0.0, 0.0);
    solidBox(3.0, 0.4, 1.0);

    //elbowAngle
    glTranslatef(1.5, 0.0, 0.0);
    glRotatef((GLfloat)elbowAngle, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glColor3fv(green);
    solidBox(2.0, 0.4, 1.0);
    glPopMatrix();
    glFlush();
}

void reshape(GLint w, GLint h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, GLfloat(w) / GLfloat(h), 1.0, 20.0);
}


void init()
{
    glShadeModel(GL_FLAT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1,2,8, 0,0,0, 0,1,0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Robot Angular Arm");
    glutKeyboardFunc(kb);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(special);
    init();
    glutMainLoop();
}
