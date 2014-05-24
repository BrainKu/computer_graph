#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <windows.h>
#include <iostream>
#include <GL/GL.h>
#include <GL/glut.h>
#include "Common.h"

class Camera {
private:
	Vertex mEye;
	Vertex mCenter;
	Vertex mUp;
	int mSceneHeight;
	int mSceneWidth;
	Point prePosition;
public:
	Camera(float eyeX, float eyeY, float eyeZ, 
		   float centerX, float centerY, float centerZ, 
		   float upX, float upY, float upZ);
	Vertex getEyeVertex() { return mEye; };
	Vertex getCenterVertex() { return mCenter; };
	Vertex getUpVertex() { return mUp; };
	void setCamera();
	void setCameraScreenSize(int width, int height);
	void moveByMouseMove(int x, int y);
	void moveByKeyPressed();
	void rotateView(float x, float y, float z);
};

#endif // !_CAMERA_H_
