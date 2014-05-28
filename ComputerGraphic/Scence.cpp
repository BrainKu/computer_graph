#include "Scence.h"

Scence::Scence() {
	planetList.push_back(Sun());
	planetList.push_back(Mercury());
	planetList.push_back(Venus());
	planetList.push_back(Earth());
	planetList.push_back(Mars());
	planetList.push_back(Jupiter());
	planetList.push_back(Saturn());
	planetList.push_back(Uranus());
	planetList.push_back(Neptune());
	mSkybox = new Skybox();
	rotatedAngle = 0;
}

void Scence::init() {
	std::vector<Planet>::iterator i;
	int count = 1;
	for (i = planetList.begin(); i != planetList.end(); i++) {
		i->init();
		count++;
	}
	mSkybox->init();
}

void Scence::draw(float x, float y, float z) {

	mSkybox->drawSkyBox(0, 0, 0, 1000, 1000, 1000);

	glMatrixMode(GL_MODELVIEW);
	std::vector<Planet>::iterator i = planetList.begin();
	int count = 1;
	for (; i != planetList.end(); i++) {
		glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(rotatedAngle / i->revolutionSpeed, 0, 1, 0);
		i->draw(count * 20, 1, 10 * count + 20);
		glPopMatrix();
		count++;
	}
	rotatedAngle++;
}

void Scence::addPlanets(Planet aPlanet) {
	planetList.push_back(aPlanet);
}