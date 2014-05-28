#include <gl/glut.h>
#include "Camera.h"
#include "Utility.h"
#include "Skybox.h"
#include "SolidSphere.h"
#include "SomePlanet.h"
#include "Planet.h"
#include "Scence.h"

void init();
void display();
void reshape(int w, int h);
void idleDisplay();

const static int FPS = 30;

Camera* mCamera = new Camera(0.0, 1.0, 4.0, 0.0, 2.0, 0.0, 0.0, 1.0, 0.0);
Skybox* skybox = new Skybox();
Planet* aPlanet = new Planet(1.0f);
Scence* scence = new Scence();

int preTime = 0;
int curTime = 0;

void init() {
	glShadeModel(GL_SMOOTH);
	glClearColor(0.5, 0.5, 0.5, 0.0);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	GLfloat lightPosition[] = { 2.0, 3.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	scence->init();
	//skybox->initTexture();
	//aPlanet->init();
}

void idleDisplay() {
	preTime = glutGet(GLUT_ELAPSED_TIME);
	display();
	curTime = glutGet(GLUT_ELAPSED_TIME);
	while ((curTime - preTime) * FPS - 1000 < 0) {
		curTime = glutGet(GLUT_ELAPSED_TIME);
	}
	preTime = curTime;
	glutPostRedisplay();
}	

void drawGrid()
{
	for (int i = -500; i <= 500; i += 5)
	{
		glBegin(GL_LINES);
		glColor3ub(150, 190, 150);
		glVertex3f(-500, 0, i);
		glVertex3f(500, 0, i);
		glVertex3f(i, 0, -500);
		glVertex3f(i, 0, 500);
		glEnd();
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	mCamera->setCamera();
	//drawGrid();
	//skybox->drawSkyBox(0, 0, 0, 1000, 1000, 1000);
	//aPlanet->draw(0, 2.0, 0);
	scence->draw(0, 0, 0);
	glFlush();
}

void moveSenceByMouseMotion(int x, int y) {
	mCamera->moveByMouseMove(x, y);
	glutPostRedisplay();
}

void reshape(int w, int h) {
	mCamera->setCameraScreenSize(w, h);
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (GLfloat)w / (GLfloat)h, 0.1, 1000.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("HEHE");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(moveSenceByMouseMotion);
	glutIdleFunc(idleDisplay);
	glutMainLoop();
	return 0;
}