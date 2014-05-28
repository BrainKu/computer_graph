#ifndef _EARTH_H_
#define _EARTH_H_

#include "Planet.h"

class Earth : public Planet{
public:
	Earth() {
		this->size = 3.0f;
		this->rotationalSpeed = 1.0f;
		this->revolutionSpeed = 1.0f;
		this->filepath = "planets/Earth.bmp";
		this->angle = 0;
		this->position = Vertex(10, 10, 10);
	};
};
#endif _EARTH_H_