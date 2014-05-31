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
	/* 行星参数的初始化 */
	void init();
	/* 在默认的位置绘制行星 */
	void draw();
	/* 在给定的位置x,y,z绘制行星 */
	virtual void draw(float x, float y, float z);
	/* 公转速度 */
	float revolutionSpeed;
	/* 公转角度 */
	float revolutionAngle;
	/* 获取行星的位置顶点 */
	Vertex getPosition() const;
protected:
	/* 行星大小 */
	float size;
	/* 自转速度 */
	float rotationalSpeed;
	/* 公转速度 */
	float rotationalAngle;
	/* 纹理映射 */
	GLuint textureName;
	/* 显示列表 */
	GLuint listName;
	/* 绘制中心 */
	Vertex position;
	/* 纹理路径 */
	const char* filepath;
private:
	std::vector<GLfloat> vertices;
	std::vector<GLfloat> normals;
	std::vector<GLfloat> texcoords;
	std::vector<GLushort> indices;
	/* 初始化行星的球体 */
	void initSolidSphere(float radius, unsigned int rings, unsigned int sectors);
};

#endif // ! _PLANET_H_


