#include "PlanetConstant.h"

const float PlanetConstant::ROTATIONSPEED[PLANETCOUNT] = {
	0.0f,
	0.01724f,
	0.0041f,
	1.0f,
	0.9756f,
	2.6667f,
	2.4f,
	1.4118f,
	1.5f
};

const float PlanetConstant::REVOLUTIONSPEED[PLANETCOUNT] = {
	0.0f,
	1.0f,
	0.70f,
	0.60f,
	0.40f,
	0.20f,
	0.10f,
	0.08f,
	0.03f
};

const float PlanetConstant::PLANETSIZE[PLANETCOUNT] = {
	50.0f,
	5.0f,
	9.0f,
	9.0f,
	7.5f,
	35.0f,
	30.0f,
	13.0f,
	12.0f
};

const Vertex PlanetConstant::POSITION[PLANETCOUNT] = {
	Vertex(0, 0, 0),
	Vertex(60, 0, 60),
	Vertex(75, 0, 75),
	Vertex(100, 0, 100),
	Vertex(120, 0, 120),
	Vertex(190, 0, 190),
	Vertex(255, 0, 255),
	Vertex(290, 0, 290),
	Vertex(330, 0, 330)
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