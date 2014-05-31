#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <windows.h>
#include <gl/glaux.h>
#include <gl/GL.h>
#include "Common.h"
#include <iostream>

/* 负责读取纹理的功能类 */
class Utility {
public: 
	/* 加载一组纹理图片，并将返回值绑定到指定数组上 */
	static void loadBmps2TexArray(GLuint textureArray[], const char* fileArray[], int size);
	/* 加载单张纹理图片，并将返回值绑定到指定变量上 */
	static void loadSingleTex(GLuint& texname, const char* filename);
};
#endif