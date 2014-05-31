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
	/* ̫���Ͱ˴����ǵ���ת�ٶ� */
	const static float ROTATIONSPEED[PLANETCOUNT]; 
	/* ̫���Ͱ˴����ǵĹ�ת�ٶ� */
	const static float REVOLUTIONSPEED[PLANETCOUNT];
	/* ̫���Ͱ˴����ǵĴ�С�ߴ� */
	const static float PLANETSIZE[PLANETCOUNT];
	/* ̫���Ͱ˴����ǵ�λ�� */
	const static Vertex POSITION[PLANETCOUNT];
	/* ̫���Ͱ˴����ǵ�������ͼ���ļ�λ�� */
	const static char* FILEPATH[PLANETCOUNT];
};
#endif // !_PLANETCONSTANT_H_
