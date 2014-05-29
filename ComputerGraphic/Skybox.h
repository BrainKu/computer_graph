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
	Skybox(){};
	static const int SKYBOX_TEXTURE_COUNT = 6;
	void draw();
	void drawSkyBox(float x, float y, float z, float width, float height, float length);
	void init();
private:
	GLuint texArray[SKYBOX_TEXTURE_COUNT];
	GLuint listName;
	static const char* skyFilename[SKYBOX_TEXTURE_COUNT];
};
#endif