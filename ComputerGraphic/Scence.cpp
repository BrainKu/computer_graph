#include "Scence.h"

Scence::Scence() {
	planetList.push_back(new Sun());
	planetList.push_back(new Mercury());
	planetList.push_back(new Venus());
	planetList.push_back(new Earth());
	planetList.push_back(new Mars());
	planetList.push_back(new Jupiter());
	planetList.push_back(new Saturn());
	planetList.push_back(new Uranus());
	planetList.push_back(new Neptune());
	mSkybox = new Skybox();
}

void Scence::init() {
	std::vector<Planet*>::iterator i;
	for (i = planetList.begin(); i != planetList.end(); i++) {
		(*i)->init();
	}
	mSkybox->init();
}

void Scence::draw(float x, float y, float z) {

	glMatrixMode(GL_MODELVIEW);
	mSkybox->draw();
	//mSkybox->drawSkybox(0, 0, 0, 1000, 1000, 1000);
	std::vector<Planet*>::iterator i;
	for (i = planetList.begin(); i != planetList.end(); i++) {
		glPushMatrix();
			glTranslatef(x, y, z);
			(*i)->revolutionAngle += (*i)->revolutionSpeed;
			glRotatef((*i)->revolutionAngle, 0, 1, 0);
			(*i)->draw();
		glPopMatrix();
	}
}

void Scence::addPlanets(Planet* aPlanet) {
	planetList.push_back(aPlanet);
}