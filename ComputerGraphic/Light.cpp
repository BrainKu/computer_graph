#include "Light.h"

void Light::off() {

};

void Light::on(){

	GLfloat lightPosition[] = { 2.0, 3.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
};