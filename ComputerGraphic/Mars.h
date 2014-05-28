#ifndef _MARS_H_
#define _MARS_H_

#include "Planet.h"

class Mars : public Planet{
public:
	Mars() {
		this->size = 1.5f;
		this->rotationalSpeed = 1.0f;
		this->revolutionSpeed = 1.0f;
		this->filepath = "planets/Mars.bmp";
		this->angle = 0;
		this->position = Vertex(15, 15, 15);
	};
};
#endif _MARS_H_