#ifndef _PLANET_H_
#define _PLANET_H_
#include "Common.h"
#include <windows.h>
#include <gl/GL.h>
#include <gl/glut.h>

class Planet {
public :
	void drawPlanet(float x, float y, float z, float size);
	void initTexure() {};
private:
	static const float rotateSpeed;
	Vertex center;
};

#endif // ! _PLANET_H_


