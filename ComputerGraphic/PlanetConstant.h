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
	/* 太阳和八大行星的自转速度 */
	const static float ROTATIONSPEED[PLANETCOUNT]; 
	/* 太阳和八大行星的公转速度 */
	const static float REVOLUTIONSPEED[PLANETCOUNT];
	/* 太阳和八大行星的大小尺寸 */
	const static float PLANETSIZE[PLANETCOUNT];
	/* 太阳和八大行星的位置 */
	const static Vertex POSITION[PLANETCOUNT];
	/* 太阳和八大行星的纹理贴图的文件位置 */
	const static char* FILEPATH[PLANETCOUNT];
};
#endif // !_PLANETCONSTANT_H_
