//#include <GL/glut.h>
//#include <glaux.h>
//#include <gl/GL.h>
//
//void init();
//void reshape(int w, int h);
//void display();
//
//void init() {
//	GLfloat lightPosition[] = { 1.0, 1.0, 1.0, 0.0 };
//	GLfloat lightAmbition[] = { 1.0, 0.0, 1.0, 0.0 };
//
//	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
//	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbition);
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//
//	glDepthFunc(GL_LESS);
//	glEnable(GL_DEPTH_TEST);
//}
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glutSolidSphere(0.5, 50, 50);
//	glFlush();
//}
//void reshape(int w, int h) {
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	if (w <= h)
//		glOrtho(-1.5, 1.5, -1.5 * (GLfloat)w / (GLfloat)h, 1.5 * (GLfloat)w / (GLfloat)h, -10, 10);
//	else
//		glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w, 1.5 * (GLfloat)h / (GLfloat)w, -10, 10);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA | GLUT_SINGLE);
//	glutInitWindowSize(400, 400);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("HEHE");
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutMainLoop();
//	return 0;
//}