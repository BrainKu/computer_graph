#ifndef _URANUS_H_
#define _URANUS_H_

#include "Planet.h"

class Uranus : public Planet{
public:
	Uranus() {
		this->size = PlanetConstant::PLANETSIZE[URANUS];
		this->rotationalSpeed = PlanetConstant::ROTATIONSPEED[URANUS];
		this->revolutionSpeed = PlanetConstant::REVOLUTIONSPEED[URANUS];
		this->filepath = PlanetConstant::FILEPATH[URANUS];
		this->position = PlanetConstant::POSITION[URANUS];
	};
};
#endif _URANUS_H_