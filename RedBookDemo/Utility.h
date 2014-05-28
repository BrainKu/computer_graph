#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <windows.h>
#include <gl/glaux.h>
#include <gl/GL.h>

class Utility {
public:
	static void loadBmps2TexArray(GLuint textureArray[], const char* fileArray[], int size);
	static void loadSingleTex(GLuint& texname, const char* filename);
};
#endif