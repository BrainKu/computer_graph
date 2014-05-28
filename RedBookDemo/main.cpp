#include <gl/glew.h>
#include <gl/glut.h>
#include "Utility.h"
#include "SolidSphere.h"

GLuint solidShpere;
GLuint cube;
SolidSphere* s = new SolidSphere(0.75, 40, 40);

void init();
void display();
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'x':
		//glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glRotatef(30, 1.0, 0.0, 0.0);
		glPopMatrix();
		break;
	case 'y':
		glRotatef(30, 0.0, 1.0, 0.0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void init() {
	s->init();
	solidShpere = glGenLists(1);
	glNewList(solidShpere, GL_COMPILE);
	s->draw(0, 0, 0);
	glEndList();
	cube = glGenLists(1);
	glNewList(cube, GL_COMPILE);
	glutSolidCube(0.8);
	glEndList();

	GLfloat position[] = { 0, 1, 0, 0 };
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glShadeModel(GL_FLAT);

	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	//glCallList(solidShpere);
	glCallList(cube);
	//s->draw(0, 0, 0);
	//glutSolidCube(1);
	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30, (GLfloat)w / (GLfloat)h, 1.0, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(500, 500);
	glutCreateWindow("HEHE");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}