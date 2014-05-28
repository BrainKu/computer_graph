#include "Camera.h"

Camera::Camera(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ) {
	Vertex eye = Vertex(eyeX, eyeY, eyeZ);
	Vertex center = Vertex(centerX, centerY, centerZ);
	Vertex up = Vertex(upX, upY, upZ);

	mEye = eye;
	mCenter = center;
	mUp = up;
	prePosition = Point(-1, -1);
	setCameraScreenSize(-1, -1);
}

void Camera::setCamera() {
	gluLookAt(mEye.x, mEye.y, mEye.z,mCenter.x, mCenter.y, mCenter.z,mUp.x, mUp.y, mUp.z);
}

void Camera::setCameraScreenSize(int width, int height) {
	mSceneWidth = width;
	mSceneHeight = height;
};

const float Camera::STEP_LENGTH = 1.0f;

void Camera::moveByKeyPressed(unsigned char key, int x, int y) {
	switch (key)
	{
	case 's':
	case 'S':
		mEye.z -= STEP_LENGTH;
		break;
	case 'w':
	case 'W':
		mEye.z += STEP_LENGTH;
		break;
	case 'a':
	case 'A':
		mEye.x += STEP_LENGTH;
		break;
	case 'd':
	case 'D':
		mEye.x -= STEP_LENGTH;
		break;
	default:
		break;
	}
};

void Camera::rotateView(float x, float y, float z) {
	Vertex directionVctor = mEye - mCenter;

	if (y) {
		mEye.z = (float)(mCenter.z + sin(y)*directionVctor.x + cos(y)*directionVctor.z);
		mEye.x = (float)(mCenter.x + cos(y)*directionVctor.x - sin(y)*directionVctor.z);
	}
}

void Camera::moveByMouseMove(int x, int y) {
	if (mSceneHeight < 0 || mSceneWidth < 0) return;
	if (prePosition.x == -1 && prePosition.y == -1) {
		prePosition.x = x;
		prePosition.y = y;
		return;
	}

	float angleY = 0.0f;
	float angleZ = 0.0f;
	angleY = 45 * ((float)(prePosition.x - x)) / mSceneWidth;
	angleZ = 45 * ((float)(prePosition.y - y)) / mSceneWidth;
	
	mEye.y -= angleZ * 2;
	if ((mEye.y - mCenter.y) > 8) mEye.y = mCenter.y + 8;
	if ((mEye.y - mCenter.y) < -8) mEye.y = mCenter.y - 8;

	rotateView(0, -angleY, 0);
	prePosition.x = x;
	prePosition.y = y;
}
