#ifndef _LIGHT_H_
#define _LIGHT_H_

#include <windows.h>
#include <gl/glut.h>

/* 控制光源及材质的功能类 */
class Light {
public:
	/* 开启光照模型 */
	static void on();
	/* 关闭光照模型 */
	static void off();
	/* 启用材质自发光 */
	static void enableMaterialEmission();
	/* 关闭材质自发光 */
	static void disableMaterialEmission();
	/* 启用星球的材质设置 */
	static void enablePlanetMaterial();
};
#endif