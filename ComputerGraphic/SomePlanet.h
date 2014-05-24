#ifndef _SOMEPLANET_H_
#define _SOMEPLANET_H_

#include <windows.h>
#include <gl/glut.h>
#include "SolidSphere.h"

class SomePlanet {
public:
	SomePlanet(){
		for (int i = 0; i < 5; i++) {
			sphereList[i] = SolidSphere(2, 20, 20);
			sphereList[i].init();
		}
	};
	void draw(float x, float y, float z) {
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(Angle, 0.0, 1.0, 0.0);
		for (int i = 0; i < 5; i++) {
			sphereList[i].draw(i * 2, 2, 5 * i - 2);
		}
		Angle += 1;
		glPopMatrix();
	};
private:
	SolidSphere sphereList[5];
	static int Angle;
};
#endif