#ifndef _SUN_H_
#define _SUN_H_

#include "Planet.h"

class Sun : public Planet {
public:
	Sun() {
		this->size = PlanetConstant::PLANETSIZE[SUN];
		this->rotationalSpeed = PlanetConstant::ROTATIONSPEED[SUN];
		this->revolutionSpeed = PlanetConstant::REVOLUTIONSPEED[SUN];
		this->filepath = PlanetConstant::FILEPATH[SUN];
		this->position = PlanetConstant::POSITION[SUN];
	};

	virtual void draw(float x, float y, float z) {
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glTranslatef(x, y, z);
		if (rotationalAngle > 360) rotationalAngle -= 360;
		glRotatef(rotationalAngle, 0.0, 0.8, 0.0);
		rotationalAngle += rotationalSpeed;
		Light::enableMaterialEmission();
		glCallList(listName);
		Light::disableMaterialEmission();
		glPopMatrix();
	};
};
#endif _SUN_H_