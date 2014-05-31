#include "Light.h"

void Light::off() {
	glDisable(GL_LIGHTING);
};

void Light::on(){
	/* 光源位置为0的点光源 */
	GLfloat lightPosition[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat noLAmbient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat defaultLAmbient[] = { 0.1, 0.1, 0.1, 1 };
	GLfloat maxAmbient[] = { 1.0, 1.0, 1.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glShadeModel(GL_SMOOTH);							       //开启阴影模式为光滑
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, defaultLAmbient);   //设置全局环境光光照模型
};

void Light::enableMaterialEmission() {
	GLfloat matEmission[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat matShinness[] = { 128 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, matEmission);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matShinness);
}

void Light::disableMaterialEmission() {
	GLfloat defaultMatEmission[] = { 0.2, 0.2, 0.2, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, defaultMatEmission);
}

void Light::enablePlanetMaterial() {
	GLfloat matAmbDiff[] = { 1.0, 1.0, 1.0, 0.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, matAmbDiff);
}
