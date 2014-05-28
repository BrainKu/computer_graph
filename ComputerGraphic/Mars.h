#ifndef _MARS_H_
#define _MARS_H_

#include "Planet.h"

class Mars : public Planet{
public:
	Mars() {
		this->size = PlanetConstant::PLANETSIZE[MARS];
		this->rotationalSpeed = PlanetConstant::ROTATIONSPEED[MARS];
		this->revolutionSpeed = PlanetConstant::REVOLUTIONSPEED[MARS];
		this->filepath = PlanetConstant::FILEPATH[MARS];
		this->position = PlanetConstant::POSITION[MARS];
	};
};
#endif _MARS_H_