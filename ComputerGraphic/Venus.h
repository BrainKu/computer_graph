#ifndef _VENUS_H_
#define _VENUS_H_

#include "Planet.h"

class Venus : public Planet{
public:
	Venus() {
		this->size = PlanetConstant::PLANETSIZE[VENUS];
		this->rotationalSpeed = PlanetConstant::ROTATIONSPEED[VENUS];
		this->revolutionSpeed = PlanetConstant::REVOLUTIONSPEED[VENUS];
		this->filepath = PlanetConstant::FILEPATH[VENUS];
		this->position = PlanetConstant::POSITION[VENUS];
	};
};
#endif _VENUS_H_