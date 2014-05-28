#include "Utility.h"

/************************************************************************/
/* load multiple bmp texture                                                                     */
/************************************************************************/
void Utility::loadbmps2texarray(gluint texturearray[], const char** filearray, gluint idarray[], int size) {
}

/************************************************************************/
/* load single bmp texture                                                                     */
/************************************************************************/
void utility::loadsingletex(gluint texname, const char* filename) {
	if (null == filename) return;
	wchar temp[100];
	int length = strlen(filename) + 1;
	multibytetowidechar(0, 0, filename, length, temp, length);
	aux_rgbimagerec* imagerec = auxdibimageload(temp);
	if (null == imagerec) return;

	glgentextures(1, &texname);
	glpixelstorei(gl_unpack_alignment, 1);
	glbindtexture(gl_texture_2d, texname);
	glubuild2dmipmaps(gl_texture_2d, 3, imagerec->sizex, imagerec->sizey, gl_rgb, gl_unsigned_byte, imagerec->data);
	gltexparameteri(gl_texture_2d, gl_texture_mag_filter, gl_nearest);
	gltexparameteri(gl_texture_2d, gl_texture_min_filter, gl_linear);
}