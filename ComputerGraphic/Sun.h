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
};
#endif _SUN_H_