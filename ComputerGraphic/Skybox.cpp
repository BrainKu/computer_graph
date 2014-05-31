#include "Skybox.h"
#include "Utility.h"
#include "Light.h"

void Skybox::init() {
	Utility::loadBmps2TexArray(texArray, skyFilename, SKYBOX_TEXTURE_COUNT);
	listName = glGenLists(1);
	glNewList(listName, GL_COMPILE);
	Light::enableMaterialEmission();
	drawSkybox(0, 0, 0, 1000, 1000, 1000);
	Light::disableMaterialEmission();
	glEndList();
};

void Skybox::draw() {
	glCallList(listName);
};

void Skybox::drawSkybox(float x, float y, float z, float width, float height, float length) {
	x = x - width / 2;
	y = y - height / 2;
	z = z - length / 2;

	glBindTexture(GL_TEXTURE_2D, texArray[SKYFRONT]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texArray[SKYBACK]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texArray[SKYLEFT]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texArray[SKYRIGHT]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texArray[SKYUP]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texArray[SKYDOWN]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z);
	glEnd();
}

const char* Skybox::skyFilename[SKYBOX_TEXTURE_COUNT] = {
	"universe/front.bmp",
	"universe/back.bmp",
	"universe/left.bmp",
	"universe/right.bmp",
	"universe/up.bmp",
	"universe/down.bmp"
};