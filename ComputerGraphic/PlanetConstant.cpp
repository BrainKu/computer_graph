#include "PlanetConstant.h"

const float PlanetConstant::ROTATIONSPEED[PLANETCOUNT] = {
	0.0f,
	20.0f,
	10.0f,
	8.0f,
	4.0f,
	2.0f,
	1.0f,
	0.8f,
	0.3f
};

const float PlanetConstant::REVOLUTIONSPEED[PLANETCOUNT] = {
	//0.0f,
	//20.0f, 
	//10.0f,
	//8.0f, 
	//4.0f,
	//2.0f, 
	//1.0f,
	//0.8f, 
	//0.3f
	//0.0f,
	//1.0f, 1.0f,
	//1.0f, 1.0f,
	//1.0f, 1.0f,
	//1.0f, 1.0f
	0.0f,
	0.0f,
	0.0f,
	0.0f,
	0.0f,
	0.0f,
	0.0f,
	0.0f,
	0.0f
};

const float PlanetConstant::PLANETSIZE[PLANETCOUNT] = {
	20.0f,
	1.0f,
	3.0f,
	3.0f,
	1.5f,
	30.0f,
	27.0f,
	12.0f,
	12.0f
};

const Vertex PlanetConstant::POSITION[PLANETCOUNT] = {
	Vertex(0, 0, 0),
	Vertex(24, 0, 24),
	Vertex(27, 0, 27),
	Vertex(30, 0, 30),
	Vertex(35, 0, 35),
	Vertex(72, 0, 72),
	Vertex(105, 0, 105),
	Vertex(212, 0, 212),
	Vertex(320, 0, 320)
};

const char* PlanetConstant::FILEPATH[PLANETCOUNT] = {
	"planets/Sun.bmp",
	"planets/Mercury.bmp",
	"planets/Venus.bmp",
	"planets/Earth.bmp",
	"planets/Mars.bmp",
	"planets/Jupiter.bmp",
	"planets/Saturn.bmp",
	"planets/Uranus.bmp",
	"planets/Neptune.bmp"
};