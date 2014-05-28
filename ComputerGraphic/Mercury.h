#ifndef _MERCURY_H_
#define _MERCURY_H_

#include "Planet.h"

class Mercury : public Planet{
public:
	Mercury() {
		this->size = PlanetConstant::PLANETSIZE[MERCURY];
		this->rotationalSpeed = PlanetConstant::ROTATIONSPEED[MERCURY];
		this->revolutionSpeed = PlanetConstant::REVOLUTIONSPEED[MERCURY];
		this->filepath = PlanetConstant::FILEPATH[MERCURY];
		this->position = PlanetConstant::POSITION[MERCURY];
	};
};
#endif _MERCURY_H_