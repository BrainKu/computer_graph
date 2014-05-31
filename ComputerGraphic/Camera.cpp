#include "Camera.h"

Camera::Camera(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ) {
	Vertex eye = Vertex(eyeX, eyeY, eyeZ);
	Vertex center = Vertex(centerX, centerY, centerZ);
	Vertex up = Vertex(upX, upY, upZ);

	mEye = eye;
	mCenter = center;
	mUp = up;

	prePosition = Point(-1, -1);
	mSceneWidth = -1;
	mSceneHeight = -1;
}

Camera::Camera() {
	mEye = Vertex(0, 50, 200);
	mCenter = Vertex(0, 0, 0);
	mUp = Vertex(0, 1, 0);

	prePosition = Point(-1, -1);
	mSceneWidth = -1;
	mSceneHeight = -1;
}

void Camera::setCamera() {
	gluLookAt(mEye.x, mEye.y, mEye.z, mCenter.x, mCenter.y, mCenter.z, mUp.x, mUp.y, mUp.z);
}

void Camera::setCameraScreenSize(int width, int height) {
	mSceneWidth = width;
	mSceneHeight = height;
};

const float Camera::STEP_LENGTH = 2.0f;
const float Camera::CAMERA_MOVE_SPEED = 0.05f;

void Camera::moveByKeyPressed(unsigned char key, int x, int y) {
	float dis = sqrt((mEye.x - mCenter.x) * (mEye.x - mCenter.x) + (mEye.y - mCenter.y) * (mEye.y - mCenter.y) + (mEye.z - mCenter.z) * (mEye.z - mCenter.z));
	float leveldis = sqrt((mEye.x - mCenter.x) * (mEye.x - mCenter.x) + (mEye.z - mCenter.z) * (mEye.z - mCenter.z));

	float xRate = (mEye.x - mCenter.x) / dis;
	float yRate = (mEye.y - mCenter.y) / dis;
	float zRate = (mEye.z - mCenter.z) / dis;

	float levelxRate = (mEye.x - mCenter.x) / leveldis;
	float levelzRate = (mEye.z - mCenter.z) / leveldis;
	switch (key)
	{
	case 's':
	case 'S':
		mEye.x += xRate * STEP_LENGTH;
		mEye.y += yRate * STEP_LENGTH;
		mEye.z += zRate * STEP_LENGTH;

		mCenter.x += xRate * STEP_LENGTH;
		mCenter.y += yRate * STEP_LENGTH;
		mCenter.z += zRate * STEP_LENGTH;
		break;
	case 'w':
	case 'W':
		mEye.x -= xRate * STEP_LENGTH;
		mEye.y -= yRate * STEP_LENGTH;
		mEye.z -= zRate * STEP_LENGTH;

		mCenter.x -= xRate * STEP_LENGTH;
		mCenter.y -= yRate * STEP_LENGTH;
		mCenter.z -= zRate * STEP_LENGTH;
		break;
	case 'a':
	case 'A':
		mEye.x -= levelzRate * STEP_LENGTH;
		mEye.z += levelxRate * STEP_LENGTH;
		mCenter.x -= levelzRate * STEP_LENGTH;
		mCenter.z += levelxRate * STEP_LENGTH;

		break;
	case 'd':
	case 'D':
		mEye.x += levelzRate * STEP_LENGTH;
		mEye.z -= levelxRate * STEP_LENGTH;
		mCenter.x += levelzRate * STEP_LENGTH;
		mCenter.z -= levelxRate * STEP_LENGTH;
		break;
	default:
		break;
	}
};

void Camera::rotateView(float x, float y, float z) {
	Vertex directionVctor = mCenter - mEye;

	if (x) {
		mCenter.z = (float)(mEye.z + sin(x)*directionVctor.y + cos(x)*directionVctor.z);
		mCenter.y = (float)(mEye.y + cos(x)*directionVctor.y - sin(x)*directionVctor.z);
	}
	if (y) {
		mCenter.z = (float)(mEye.z + sin(y)*directionVctor.x + cos(y)*directionVctor.z);
		mCenter.x = (float)(mEye.x + cos(y)*directionVctor.x - sin(y)*directionVctor.z);
	}
	if (z) {
		mCenter.x = (float)(mEye.x + sin(z)*directionVctor.y + cos(z)*directionVctor.x);
		mCenter.y = (float)(mEye.y + cos(z)*directionVctor.y - sin(z)*directionVctor.x);
	}
}

void Camera::setPrePosition(int x, int y) {
	prePosition = Point(x, y);
};

void Camera::moveByMouseMove(int x, int y) {
	if (mSceneHeight < 0 || mSceneWidth < 0) return;

	float angleY = 0.0f;
	float angleZ = 0.0f;

	angleY = ((float)(x - prePosition.x)) / mSceneWidth;
	angleZ = ((float)(y - prePosition.y)) / mSceneWidth;

	rotateView(angleZ, angleY, 0);
	prePosition.x = x;
	prePosition.y = y;
}

Vertex Camera::getCameraRightCorner(int nearSide ){
	/*
	根据摄像头的位置和中心的位置，利用向量方法获得视锥体前截面的位置。然后将位置按照前截面高度的一半移动到前截面的底部。
	先将摄像头的眼和中心的连线分解到y和xz方向上，然后将xz方向的分量分解到x和z方向上。
	*/
	float xyzDis = sqrt(pow(mEye.x - mCenter.x, 2) + pow(mEye.y - mCenter.y, 2) + pow(mEye.z - mCenter.z, 2));
	float xzDis = sqrt(pow(mEye.x - mCenter.x, 2) + pow(mEye.z - mCenter.z, 2));
	float y = xzDis / xyzDis * (nearSide);
	float xz = (mEye.y - mCenter.y) / xyzDis *(nearSide);
	float x = (mEye.x - mCenter.x) / xzDis * xz;
	float z = (mEye.z - mCenter.z) / xzDis * xz;

	Vertex temp = mCenter - mEye;
	temp.x = mEye.x + float((nearSide + 1) / xyzDis) * temp.x;
	temp.y = mEye.y + float((nearSide + 1) / xyzDis) * temp.y;
	temp.z = mEye.z + float((nearSide + 1) / xyzDis) * temp.z;

	temp.x += x;
	temp.y -= y;
	temp.z += z;

	return temp;
}