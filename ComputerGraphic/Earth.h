#ifndef _EARTH_H_
#define _EARTH_H_

#include "Planet.h"

class Earth : public Planet{
public:
	Earth() {
		this->size = PlanetConstant::PLANETSIZE[EARTH];
		this->rotationalSpeed = PlanetConstant::ROTATIONSPEED[EARTH];
		this->revolutionSpeed = PlanetConstant::REVOLUTIONSPEED[EARTH];
		this->filepath = PlanetConstant::FILEPATH[EARTH];
		this->position = PlanetConstant::POSITION[EARTH];
	};
};
#endif _EARTH_H_