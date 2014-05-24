#include "Utility.h"

/************************************************************************/
/* Load multiple BMP texture                                                                     */
/************************************************************************/
void Utility::loadBmps2TexArray(GLuint textureArray[], const char** fileArray, GLuint idArray[], int size) {
}

/************************************************************************/
/* load single BMP texture                                                                     */
/************************************************************************/
void Utility::loadSingleTex(GLuint texname, const char* filename) {
	if (NULL == filename) return;
	WCHAR temp[100];
	int length = strlen(filename) + 1;
	MultiByteToWideChar(0, 0, filename, length, temp, length);
	AUX_RGBImageRec* imageRec = auxDIBImageLoad(temp);
	if (NULL == imageRec) return;

	glGenTextures(1, &texname);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, texname);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, imageRec->sizeX, imageRec->sizeY, GL_RGB, GL_UNSIGNED_BYTE, imageRec->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}