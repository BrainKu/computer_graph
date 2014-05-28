#ifndef _NEPTUNE_H_
#define _NEPTUNE_H_

#include "Planet.h"

class Neptune : public Planet {
public:
	Neptune() {
		this->size = 12.0f;
		this->rotationalSpeed = 1.0f;
		this->revolutionSpeed = 1.0f;
		this->filepath = "planets/Neptune.bmp";
		this->angle = 0;
		this->position = Vertex(300, 300, 300);
	};
};

#endif // !_NEPTUNE_H_
