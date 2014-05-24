#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <windows.h>
#include <gl/glaux.h>
#include <gl/GL.h>

class Utility {
public:
	static void loadBmps2TexArray(GLuint textureArray[], const char** fileArray, GLuint idArray[], int size);
	static void loadSingleTex(GLuint texname, const char* filename);
	static void loadSingleTexForMulitpleMap(GLuint texname, const char* filename);
};
#endif