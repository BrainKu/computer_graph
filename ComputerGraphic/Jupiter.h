#ifndef _JUPITER_H_
#define _JUPITER_H_

#include "Planet.h"

class Jupiter : public Planet {
public:
	Jupiter() {
		this->size = 30.0f;
		this->rotationalSpeed = 1.0f;
		this->revolutionSpeed = 1.0f;
		this->filepath = "planets/Jupiter.bmp";
		this->angle = 0;
		this->position = Vertex(52, 52, 52);
	};
};
#endif _JUPITER_H_