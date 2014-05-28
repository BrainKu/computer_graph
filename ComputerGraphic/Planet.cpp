#include "Planet.h"

Planet::Planet() {
	this->size = 2.0;
	this->angle = 0;
	this->rotationalSpeed = 1.0f;
	this->revolutionSpeed = 1.0f;
	this->filepath = "planets/Uranus.bmp";
	this->position = Vertex(0, 0, 0);
}

Planet::Planet(float size = 5.0f) {
	this->size = size;
	this->angle = 0;
	this->rotationalSpeed = 1.0f;
	this->revolutionSpeed = 1.0f;
	this->filepath = "planets/Uranus.bmp";
}

void Planet::init() {
	Utility::loadSingleTex(textureName, filepath);
	initSolidSphere(size, 40, 40);
	listName = glGenLists(1);
	glNewList(listName, GL_COMPILE);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
	glNormalPointer(GL_FLOAT, 0, &normals[0]);
	glTexCoordPointer(2, GL_FLOAT, 0, &texcoords[0]);
	glBindTexture(GL_TEXTURE_2D, textureName);
	glDrawElements(GL_QUADS, indices.size(), GL_UNSIGNED_SHORT, &indices[0]);

	glEndList();
}

void Planet::draw(float x, float y, float z) {

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(x, y, z);
	if (angle > 360) angle -= 360;
	glRotatef(angle, 0.0, 0.8, 0.0);
	angle += rotationalSpeed;
	glCallList(listName);
	glPopMatrix();
}

void Planet::draw() {
	draw(position.x, position.y, position.z);
}

Vertex Planet::getPosition() const{
	return position;
}
void Planet::initSolidSphere(float radius = 2.0f, unsigned int rings = 20, unsigned int sectors = 40)
{
	float const R = 1. / (float)(rings - 1);
	float const S = 1. / (float)(sectors - 1);
	unsigned int r, s;

	vertices.resize(rings * sectors * 3);
	normals.resize(rings * sectors * 3);
	texcoords.resize(rings * sectors * 2);
	std::vector<GLfloat>::iterator v = vertices.begin();
	std::vector<GLfloat>::iterator n = normals.begin();
	std::vector<GLfloat>::iterator t = texcoords.begin();
	for (r = 0; r < rings; r++) for (s = 0; s < sectors; s++) {
		float const y = sin(-M_PI_2 + M_PI * r * R);
		float const x = cos(2 * M_PI * s * S) * sin(M_PI * r * R);
		float const z = sin(2 * M_PI * s * S) * sin(M_PI * r * R);

		*t++ = s*S;
		*t++ = r*R;

		*v++ = x * radius;
		*v++ = y * radius;
		*v++ = z * radius;

		*n++ = x;
		*n++ = y;
		*n++ = z;
	}

	indices.resize(rings * sectors * 4);
	std::vector<GLushort>::iterator i = indices.begin();
	for (r = 0; r < rings - 1; r++) for (s = 0; s < sectors - 1; s++) {
		*i++ = r * sectors + s;
		*i++ = r * sectors + (s + 1);
		*i++ = (r + 1) * sectors + (s + 1);
		*i++ = (r + 1) * sectors + s;
	}
};