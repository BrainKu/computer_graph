#ifndef _SATURN_H_
#define _SATURN_H_

#include "Planet.h"

class Saturn : public Planet{
public:
	Saturn() {
		this->size = PlanetConstant::PLANETSIZE[SATURN];
		this->filepath = PlanetConstant::FILEPATH[SATURN];
		this->position = PlanetConstant::POSITION[SATURN];
		this->rotationalSpeed = PlanetConstant::ROTATIONSPEED[SATURN];
		this->revolutionSpeed = PlanetConstant::REVOLUTIONSPEED[SATURN];
	};
};
#endif _SATURN_H_