#include "Light.h"

void Light::off() {
	glDisable(GL_LIGHTING);
};

void Light::on(){
	/* ��Դλ��Ϊ0�ĵ��Դ */
	GLfloat lightPosition[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat noLAmbient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat defaultLAmbient[] = { 0.1, 0.1, 0.1, 1 };
	GLfloat maxAmbient[] = { 1.0, 1.0, 1.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glShadeModel(GL_SMOOTH);							       //������ӰģʽΪ�⻬
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, defaultLAmbient);   //����ȫ�ֻ��������ģ��
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
