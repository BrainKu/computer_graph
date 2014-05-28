#ifndef _VENUS_H_
#define _VENUS_H_

#include "Planet.h"

class Venus : public Planet{
public:
	Venus() {
		this->size = 3.0f;
		this->rotationalSpeed = 1.0f;
		this->revolutionSpeed = 1.0f;
		this->filepath = "planets/Venus.bmp";
		this->angle = 0;
		this->position = Vertex(7, 7, 7);
	};
};
#endif _VENUS_H_