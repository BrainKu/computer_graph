#ifndef _PLANET_H_
#define _PLANET_H_

#include "Common.h"
#include <windows.h>
#include <gl/GL.h>
#include <vector>
#include <gl/glut.h>
#include "Utility.h"
#include "PlanetConstant.h"
#include "Light.h"

class Planet {
public :
	Planet();
	Planet(float size);
	/* ���ǲ����ĳ�ʼ�� */
	void init();
	/* ��Ĭ�ϵ�λ�û������� */
	void draw();
	/* �ڸ�����λ��x,y,z�������� */
	virtual void draw(float x, float y, float z);
	/* ��ת�ٶ� */
	float revolutionSpeed;
	/* ��ת�Ƕ� */
	float revolutionAngle;
	/* ��ȡ���ǵ�λ�ö��� */
	Vertex getPosition() const;
protected:
	/* ���Ǵ�С */
	float size;
	/* ��ת�ٶ� */
	float rotationalSpeed;
	/* ��ת�ٶ� */
	float rotationalAngle;
	/* ����ӳ�� */
	GLuint textureName;
	/* ��ʾ�б� */
	GLuint listName;
	/* �������� */
	Vertex position;
	/* ����·�� */
	const char* filepath;
private:
	std::vector<GLfloat> vertices;
	std::vector<GLfloat> normals;
	std::vector<GLfloat> texcoords;
	std::vector<GLushort> indices;
	/* ��ʼ�����ǵ����� */
	void initSolidSphere(float radius, unsigned int rings, unsigned int sectors);
};

#endif // ! _PLANET_H_


