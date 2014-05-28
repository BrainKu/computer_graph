#include "Scence.h"

Scence::Scence() {
	for (int i = 0; i < 9; i++) {
		planetList.push_back(Planet(5));
	}
	mSkybox = new Skybox();
	rotatedAngle = 0;
}

void Scence::init() {
	std::vector<Planet>::iterator i;
	int count = 1;
	for (i = planetList.begin(); i != planetList.end(); i++) {
		i->init();
		std::cout <<"count number"<< count << std::endl;
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
		//std::cout << "angle:" << count << std::endl;
		i->draw(count * 10, 1, 4 * count + 20);
		glPopMatrix();
		count++;
	}
	rotatedAngle++;
}