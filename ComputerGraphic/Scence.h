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
	/* 场景的初始化 */
	void init();
	/* 在给定的位置x, y ,z绘制场景*/
	void draw(float x, float y, float z);
	/* 在场景中添加行星（未使用） */
	void addPlanets(Planet* aPlanet);
private:
	/* 场景中行星列表 */
	std::vector<Planet*> planetList;
	/* 场景中的天空盒 */
	Skybox* mSkybox;
};
#endif