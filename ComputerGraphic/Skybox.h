#ifndef _SKYBOX_H_
#define _SKYBOX_H_

#include <windows.h>
#include <gl/GL.h>
#include <gl/glut.h>

#define SKYFRONT 0
#define SKYBACK  1
#define SKYLEFT  2
#define SKYRIGHT 3
#define SKYUP    4
#define SKYDOWN  5

class Skybox {
public:
	const static int SKYBOX_TEXTURE_COUNT = 6;
	void drawSkyBox(float x, float y, float z, float width, float height, float length);
	void initTexture();
private:
	GLuint texArray[SKYBOX_TEXTURE_COUNT];
	static const char* skyFilename[SKYBOX_TEXTURE_COUNT];
};
#endif