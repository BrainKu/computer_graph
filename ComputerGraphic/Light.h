#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "windows.h"
#include "gl/glut.h"

class Light {
public:
	static void off();
	static void on();
	static void enableShadow();
	static void enableMatrial();
};
#endif