#ifndef _SOMEPLANET_H_
#define _SOMEPLANET_H_

#include "SolidSphere.h"
#include <windows.h>
#include <gl/glut.h>
#include <vector>

class SomePlanet {
public:
	SomePlanet(){
		for (int i = 0; i < 5; i++) {
			planets.push_back(SolidSphere(2, 20, 20));
		}
	};
	void init() {
		std::vector<SolidSphere>::iterator i;
		for (i = planets.begin(); i != planets.end(); i++) {
			i->init();
		}
	};
	void draw(float x, float y, float z) {
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glTranslatef(x, y, z);
		std::vector<SolidSphere>::iterator i;
		int count = 1;
		glRotatef(count, 0.0, 1.0, 0.0);
		for ( i = planets.begin(); i != planets.end();i++) {
			i->draw(8 * count, 1 , 10);
			count++;
		}

		Angle += 1;
		glPopMatrix();
	};
private:
	std::vector<SolidSphere> planets;
	static int Angle;
};
#endif