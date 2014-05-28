#ifndef _PLANETCONSTANT_H_
#define _PLANETCONSTANT_H_

#define SUN 0
#define MERCURY 1
#define VENUS 2
#define EARTH 3
#define MARS 4
#define JUPITER 5
#define SATURN 6
#define URANUS 7
#define NEPTUNE 8
#define PLANETCOUNT 9
#include "Common.h"

class PlanetConstant {
public:
	const static float ROTATIONSPEED[PLANETCOUNT];
	const static float REVOLUTIONSPEED[PLANETCOUNT];
	const static float PLANETSIZE[PLANETCOUNT];
	const static char* FILEPATH[PLANETCOUNT];
	const static Vertex POSITION[PLANETCOUNT];
};
#endif // !_PLANETCONSTANT_H_
