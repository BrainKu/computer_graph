#ifndef _NEPTUNE_H_
#define _NEPTUNE_H_

#include "Planet.h"

class Neptune : public Planet {
public:
	Neptune() {
		this->size = PlanetConstant::PLANETSIZE[NEPTUNE];
		this->rotationalSpeed = PlanetConstant::ROTATIONSPEED[NEPTUNE];
		this->revolutionSpeed = PlanetConstant::REVOLUTIONSPEED[NEPTUNE];
		this->filepath = PlanetConstant::FILEPATH[NEPTUNE];
		this->position = PlanetConstant::POSITION[NEPTUNE];
	};
};

#endif // !_NEPTUNE_H_
