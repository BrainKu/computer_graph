#ifndef _URANUS_H_
#define _URANUS_H_

#include "Planet.h"

class Uranus : public Planet{
public:
	Uranus() {
		this->size = 12.0f;
		this->rotationalSpeed = 1.0f;
		this->revolutionSpeed = 1.0f;
		this->filepath = "planets/Uranus.bmp";
		this->angle = 0;
		this->position = Vertex(192, 192, 192);
	};
};
#endif _URANUS_H_