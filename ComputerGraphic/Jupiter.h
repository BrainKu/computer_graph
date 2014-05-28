#ifndef _JUPITER_H_
#define _JUPITER_H_

#include "Planet.h"

class Jupiter : public Planet {
public:
	Jupiter() {
		this->size = PlanetConstant::PLANETSIZE[JUPITER];
		this->rotationalSpeed = PlanetConstant::ROTATIONSPEED[JUPITER];
		this->revolutionSpeed = PlanetConstant::REVOLUTIONSPEED[JUPITER];
		this->filepath = PlanetConstant::FILEPATH[JUPITER];
		this->position = PlanetConstant::POSITION[JUPITER];
	};
};
#endif _JUPITER_H_