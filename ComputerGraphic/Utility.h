#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <windows.h>
#include <gl/glaux.h>
#include <gl/GL.h>
#include "Common.h"
#include <iostream>

/* �����ȡ����Ĺ����� */
class Utility {
public: 
	/* ����һ������ͼƬ����������ֵ�󶨵�ָ�������� */
	static void loadBmps2TexArray(GLuint textureArray[], const char* fileArray[], int size);
	/* ���ص�������ͼƬ����������ֵ�󶨵�ָ�������� */
	static void loadSingleTex(GLuint& texname, const char* filename);
};
#endif