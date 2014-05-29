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
	Vertex direction;
	int mSceneHeight;
	int mSceneWidth;
	Point prePosition;
public:
	const static float STEP_LENGTH;
	const static float CAMERA_MOVE_SPEED;
	Camera(float eyeX, float eyeY, float eyeZ, 
		   float centerX, float centerY, float centerZ, 
		   float upX, float upY, float upZ);
	void setCamera();
	void setCameraScreenSize(int width, int height);
	void moveByMouseMove(int x, int y);
	void moveByKeyPressed(unsigned char key, int x, int y);
	void rotateView(float x, float y, float z);
	void changeDirection(Vertex nDirection);
};

#endif // !_CAMERA_H_
