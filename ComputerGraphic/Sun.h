#ifndef _SUN_H_
#define _SUN_H_

#include "Planet.h"

class Sun : public Planet {
public:
	Sun() {
		this->size = 50.0f;
		this->rotationalSpeed = 0.0f;
		this->revolutionSpeed = 0.0f;
		this->filepath = "planets/Sun.bmp";
		this->angle = 0;
		this->position = Vertex(0, 0, 0);
	};
};
#endif _SUN_H_