#ifndef _SATURN_H_
#define _SATURN_H_

#include "Planet.h"

class Saturn : public Planet{
public:
	Saturn() {
		this->size = 27.0f;
		this->rotationalSpeed = 1.0f;
		this->revolutionSpeed = 1.0f;
		this->filepath = "planets/Saturn.bmp";
		this->angle = 0;
	};
};
#endif _SATURN_H_