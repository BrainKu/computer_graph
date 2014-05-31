#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <windows.h>
#include <iostream>
#include <GL/GL.h>
#include <GL/glut.h>
#include "Common.h"

class Camera {
private:
	/* �۲���λ�� */
	Vertex mEye;
	/* �۲����� */
	Vertex mCenter;
	/* �۲�������� */
	Vertex mUp;
	/* ��Ļ�ĸ߶� */
	int mSceneHeight;
	/* ��Ļ�Ŀ�� */
	int mSceneWidth;
	/* �ϴ�����ƶ���λ�� */
	Point prePosition;
public:
	const static float STEP_LENGTH;
	const static float CAMERA_MOVE_SPEED;
	Camera();
	Camera(float eyeX, float eyeY, float eyeZ, 
		   float centerX, float centerY, float centerZ, 
		   float upX, float upY, float upZ);
	/* �ڳ������������ */
	void setCamera();
	/* �������֮ǰ���ڵĵ�*/
	void setPrePosition(int x, int y);
	/* �����������Ļ�ߴ� */
	void setCameraScreenSize(int width, int height);
	/* ��������ƶ�λ�øı����λ�� */
	void moveByMouseMove(int x, int y);
	/* ��������İ����ı����λ�� */
	void moveByKeyPressed(unsigned char key, int x, int y);
	/* ��ת�ӽ� */
	void rotateView(float x, float y, float z);
	/* ��ȡ��ǰ���λ�õ����½Ƕ���λ�� */
	Vertex getCameraRightCorner(int nearSide);
};

#endif // !_CAMERA_H_
