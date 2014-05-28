#ifndef _PLANET_H_
#define _PLANET_H_

#include "Common.h"
#include <windows.h>
#include <gl/GL.h>
#include <vector>
#include <gl/glut.h>
#include "Utility.h"

class Planet {
public :
	Planet();
	Planet(float size);
	void draw(float x, float y, float z);
	void init();
protected:
	float rotationalSpeed;
	float revolutionSpeed;
	const char* filepath;
	float size;
	GLuint textureName;
	GLuint listName;
	int angle;
private:
protected:
	std::vector<GLfloat> vertices;
	std::vector<GLfloat> normals;
	std::vector<GLfloat> texcoords;
	std::vector<GLushort> indices;
	void initSolidSphere(float radius, unsigned int rings, unsigned int sectors);
};

#endif // ! _PLANET_H_


