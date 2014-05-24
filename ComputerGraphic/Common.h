#ifndef _COMMON_H_
#define _COMMON_H_

struct Point {
	int x, y;
	Point() {};
	Point(int x0, int y0) { x = x0; y = y0; }
};

struct Vertex
{
	float x, y, z;
	Vertex(){};
	Vertex(float x0, float y0, float z0) { x = x0; y = y0; z = z0; }
	Vertex operator-(Vertex nVertex) { return Vertex(x - nVertex.x, y - nVertex.y, z - nVertex.z); }
};

#endif //!_COMMON_H_