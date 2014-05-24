//#include <glaux.h>
//#include <GL/GL.h>
//#include <gl/glut.h>
//#include <stdio.h>
//#include "Obj3dmodel.h"
//
//static GLuint texName;
//
//AUX_RGBImageRec* loadBmp(const char* aFile) {
//	WCHAR aName[100];
//	FILE* file = NULL;
//	int length = strlen(aFile) + 1;
//	if (NULL == aFile) {
//		return NULL;
//	}
//	fopen_s(&file, aFile, "r");
//	if (NULL != file) {
//		MultiByteToWideChar(0, 0, aFile, length, aName, length);
//		fclose(file);
//		return auxDIBImageLoad(aName);
//	}
//	else {
//		printf("Read file failed\n");
//		fclose(file);
//		return NULL;
//	}
//}
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//	glEnable(GL_DEPTH_TEST);
//
//	AUX_RGBImageRec * imageRec = loadBmp("hehua.bmp");
//	if (!imageRec)
//		exit(EXIT_FAILURE);
//
//	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//
//	glGenTextures(1, &texName);
//	glBindTexture(GL_TEXTURE_2D, texName);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageRec->sizeX, imageRec->sizeX,
//		0, GL_RGB, GL_UNSIGNED_BYTE, imageRec->data);
//
//}
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_TEXTURE_2D);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
//	glBindTexture(GL_TEXTURE_2D, texName);
//
//	glBegin(GL_QUADS);
//	glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -1.0, 0.0);
//	glTexCoord2f(0.0, 1.0); glVertex3f(-2.0, 1.0, 0.0);
//	glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 1.0, 0.0);
//	glTexCoord2f(1.0, 0.0); glVertex3f(0.0, -1.0, 0.0);
//
//	glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
//	glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
//	glTexCoord2f(1.0, 1.0); glVertex3f(2.41421, 1.0, -1.41421);
//	glTexCoord2f(1.0, 0.0); glVertex3f(2.41421, -1.0, -1.41421);
//	glEnd();
//	glFlush();
//	glDisable(GL_TEXTURE_2D);
//}
//
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 30.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glTranslatef(0.0, 0.0, -3.6);
//}
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(400, 400);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(argv[0]);
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutMainLoop();
//	return 0;
//}
