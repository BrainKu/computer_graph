#include <gl/glut.h>
#include "Camera.h"
#include "Utility.h"
#include "Scence.h"
#include "Light.h"

//文字显示列表数目
#define MAX_CHAR       128
/* 画面的刷新频率 */
const static int FPS = 30;
//定义摄像头视锥体的近截面
int nearSide = 50;
//记录鼠标是否被按下
bool isClick = false;

void display();
void reshape(int w, int h);
// 场景及各类参数的初始化 
void init();
// 循环渲染时调用的函数 
void idleDisplay();
// 绘制字符串
void drawString(const char* str);


Camera* mCamera = new Camera();
Scence* scence = new Scence();

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glDepthFunc(GL_LEQUAL);                                      //启用深度测试为Least or Equal

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //启用纹理与光照的融合效果
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);			 //启用透视矫正

	Light::on();				//开启光照
	scence->init();				//初始化场景
}

//控制刷新频率为FPS或以下
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
		lists = glGenLists(MAX_CHAR);  // 申请MAX_CHAR个连续的显示列表编号
		// 把每个字符的绘制命令都装到对应的显示列表中
		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
	}
	// 调用每个字符对应的显示列表，绘制每个字符
	for (; *str != '\0'; ++str) {
		glCallList(lists + *str);
	}
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	Vertex temp = mCamera->getCameraRightCorner(nearSide);

	glRasterPos3f(temp.x, temp.y, temp.z); //在视口的下面中心位置开始显示字体
	glColor3f(1.0f, 1.0f,1.0f);				//设置字体颜色
	drawString("Press W/S/A/D to move the Camera!");	 //输出的字符串
	glLoadIdentity();
	mCamera->setCamera();					//设置相机
	scence->draw(0, 0, 0);					//设置场景
	glFlush();
}

//鼠标点击时记录当前位置
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

//鼠标移动时调整相机
void moveSenceByMouseMotion(int x, int y) {
	if (isClick) {
		mCamera->moveByMouseMove(x, y);
		glutPostRedisplay();
	}
}

//按下键盘特定键时调整相机
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