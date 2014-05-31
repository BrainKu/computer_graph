#include <gl/glut.h>
#include "Camera.h"
#include "Utility.h"
#include "Scence.h"
#include "Light.h"

//������ʾ�б���Ŀ
#define MAX_CHAR       128
/* �����ˢ��Ƶ�� */
const static int FPS = 30;
//��������ͷ��׶��Ľ�����
int nearSide = 50;
//��¼����Ƿ񱻰���
bool isClick = false;

void display();
void reshape(int w, int h);
// ��������������ĳ�ʼ�� 
void init();
// ѭ����Ⱦʱ���õĺ��� 
void idleDisplay();
// �����ַ���
void drawString(const char* str);


Camera* mCamera = new Camera();
Scence* scence = new Scence();

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glDepthFunc(GL_LEQUAL);                                      //������Ȳ���ΪLeast or Equal

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //������������յ��ں�Ч��
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);			 //����͸�ӽ���

	Light::on();				//��������
	scence->init();				//��ʼ������
}

//����ˢ��Ƶ��ΪFPS������
void idleDisplay() {
	int preTime, curTime;
	preTime = glutGet(GLUT_ELAPSED_TIME);
	display();
	curTime = glutGet(GLUT_ELAPSED_TIME);
	while ((curTime - preTime) * FPS - 1000 < 0) {
		curTime = glutGet(GLUT_ELAPSED_TIME);
	}
	preTime = curTime;
	glutPostRedisplay();
}

void drawString(const char* str)
{
	static int isFirstCall = 1;
	static GLuint lists;

	if (isFirstCall) {
		isFirstCall = 0;
		lists = glGenLists(MAX_CHAR);  // ����MAX_CHAR����������ʾ�б���
		// ��ÿ���ַ��Ļ������װ����Ӧ����ʾ�б���
		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
	}
	// ����ÿ���ַ���Ӧ����ʾ�б�����ÿ���ַ�
	for (; *str != '\0'; ++str) {
		glCallList(lists + *str);
	}
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	Vertex temp = mCamera->getCameraRightCorner(nearSide);

	glRasterPos3f(temp.x, temp.y, temp.z); //���ӿڵ���������λ�ÿ�ʼ��ʾ����
	glColor3f(1.0f, 1.0f,1.0f);				//����������ɫ
	drawString("Press W/S/A/D to move the Camera!");	 //������ַ���
	glLoadIdentity();
	mCamera->setCamera();					//�������
	scence->draw(0, 0, 0);					//���ó���
	glFlush();
}

//�����ʱ��¼��ǰλ��
void mouseClick(int button, int state, int x, int y) {
	switch (state) {
	case GLUT_DOWN:
		isClick = true;
		mCamera->setPrePosition(x, y);
		break;
	case GLUT_UP:
		isClick = false;
		break;
	}
};

//����ƶ�ʱ�������
void moveSenceByMouseMotion(int x, int y) {
	if (isClick) {
		mCamera->moveByMouseMove(x, y);
		glutPostRedisplay();
	}
}

//���¼����ض���ʱ�������
void moveScenceByKeyPressed(unsigned char key, int x, int y) {
	mCamera->moveByKeyPressed(key, x, y);
	glutPostRedisplay();
}

void reshape(int w, int h) {
	mCamera->setCameraScreenSize(w, h);		
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, (GLfloat)w / (GLfloat)h, nearSide, 2000.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Solar System");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseClick);
	glutMotionFunc(moveSenceByMouseMotion);
	glutKeyboardFunc(moveScenceByKeyPressed);
	glutIdleFunc(idleDisplay);
	glutMainLoop();
	return 0;
}