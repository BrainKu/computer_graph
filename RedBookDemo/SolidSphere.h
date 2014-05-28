#ifndef _SOLIDSPHERE_H_
#define _SOLIDSPHERE_H_

#include <windows.h>
#include <vector>
#include <gl/glut.h>
#include <cmath>
#include <iostream>

#define M_PI 3.14
#define M_PI_2 1.57

class SolidSphere
{
protected:
	std::vector<GLfloat> vertices;
	std::vector<GLfloat> normals;
	std::vector<GLfloat> texcoords;
	std::vector<GLushort> indices;
private:
public:
	GLuint tetureName;
	static int ANGLE;
	//SolidSphere();
	SolidSphere(float radius, unsigned int rings, unsigned int sectors);
	void draw(GLfloat x, GLfloat y, GLfloat z);
	void init();
};
#endif