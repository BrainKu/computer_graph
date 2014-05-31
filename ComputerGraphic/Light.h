#ifndef _LIGHT_H_
#define _LIGHT_H_

#include <windows.h>
#include <gl/glut.h>

/* ���ƹ�Դ�����ʵĹ����� */
class Light {
public:
	/* ��������ģ�� */
	static void on();
	/* �رչ���ģ�� */
	static void off();
	/* ���ò����Է��� */
	static void enableMaterialEmission();
	/* �رղ����Է��� */
	static void disableMaterialEmission();
	/* ��������Ĳ������� */
	static void enablePlanetMaterial();
};
#endif