#ifndef _SCENCE_H_
#define _SCENCE_H_

#include <windows.h>
#include <iostream>
#include <vector>
#include "Planet.h"
#include "Skybox.h"
#include "Earth.h"
#include "Jupiter.h"
#include "Mars.h"
#include "Mercury.h"
#include "Neptune.h"
#include "Saturn.h"
#include "Sun.h"
#include "Uranus.h"
#include "Venus.h"

class Scence {
public:
	Scence();
	~Scence() {
		std::vector<Planet*>::iterator i;
		for (i = planetList.begin(); i != planetList.end(); i++) {
			delete *i;
		}
		delete mSkybox; 
	};
	/* �����ĳ�ʼ�� */
	void init();
	/* �ڸ�����λ��x, y ,z���Ƴ���*/
	void draw(float x, float y, float z);
	/* �ڳ�����������ǣ�δʹ�ã� */
	void addPlanets(Planet* aPlanet);
private:
	/* �����������б� */
	std::vector<Planet*> planetList;
	/* �����е���պ� */
	Skybox* mSkybox;
};
#endif