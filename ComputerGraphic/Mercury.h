#ifndef _MERCURY_H_
#define _MERCURY_H_

#include "Planet.h"

class Mercury : public Planet{
public:
	Mercury() {
		this->size = 1.0f;
		this->rotationalSpeed = 1.0f;
		this->revolutionSpeed = 1.0f;
		this->filepath = "planets/Mercury.bmp";
		this->angle = 0;
	};
};
#endif _MERCURY_H_