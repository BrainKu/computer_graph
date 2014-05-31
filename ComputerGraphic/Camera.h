#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <windows.h>
#include <iostream>
#include <GL/GL.h>
#include <GL/glut.h>
#include "Common.h"

class Camera {
private:
	/* 观察者位置 */
	Vertex mEye;
	/* 观察中心 */
	Vertex mCenter;
	/* 观察的正方向 */
	Vertex mUp;
	/* 屏幕的高度 */
	int mSceneHeight;
	/* 屏幕的宽度 */
	int mSceneWidth;
	/* 上次鼠标移动的位置 */
	Point prePosition;
public:
	const static float STEP_LENGTH;
	const static float CAMERA_MOVE_SPEED;
	Camera();
	Camera(float eyeX, float eyeY, float eyeZ, 
		   float centerX, float centerY, float centerZ, 
		   float upX, float upY, float upZ);
	/* 在场景中设置相机 */
	void setCamera();
	/* 设置鼠标之前所在的点*/
	void setPrePosition(int x, int y);
	/* 设置相机的屏幕尺寸 */
	void setCameraScreenSize(int width, int height);
	/* 根据鼠标移动位置改变相机位置 */
	void moveByMouseMove(int x, int y);
	/* 根据输入的按键改变相机位置 */
	void moveByKeyPressed(unsigned char key, int x, int y);
	/* 旋转视角 */
	void rotateView(float x, float y, float z);
	/* 获取当前相机位置的右下角顶点位置 */
	Vertex getCameraRightCorner(int nearSide);
};

#endif // !_CAMERA_H_
