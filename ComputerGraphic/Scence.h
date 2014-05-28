#ifndef _SCENCE_H_
#define _SCENCE_H_

#include <windows.h>
#include <iostream>
#include <vector>
#include "Planet.h"
#include "Skybox.h"

class Scence {
public:
	Scence();
	~Scence() { delete mSkybox; };
	void init();
	void draw(float x, float y, float z);
	void addPlanets(Planet aPlanet);
private:
	Skybox* mSkybox;
	std::vector<Planet> planetList;
	int rotatedAngle;
};
#endif