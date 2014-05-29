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
	rotatedAngle = 0.0f;
}

void Scence::init() {
	std::vector<Planet>::iterator i;
	for (i = planetList.begin(); i != planetList.end(); i++) {
		i->init();
	}
	mSkybox->init();
}

void Scence::draw(float x, float y, float z) {

	glMatrixMode(GL_MODELVIEW);
	mSkybox->drawSkyBox(0, 0, -100, 40, 40, 40);
	std::vector<Planet>::iterator i = planetList.begin();
	for (; i != planetList.end(); i++) {
		glPushMatrix();
		glTranslatef(x, y, z);
		rotatedAngle += i->revolutionSpeed;
		glRotatef(rotatedAngle, 0, 1, 0);
		i->draw();
		glPopMatrix();
	}
}

void Scence::addPlanets(Planet aPlanet) {
	planetList.push_back(aPlanet);
}