#include<vector>
#include<GL/glut.h>

//��󶥵���
#define vertexMaxSum 1000

//����ı�����
#define polygonMaxSum 1000

//�����������
#define triangleMaxSum 1000

//�����ͼ����
#define textureMaxSum 1000

//�������
#define normalMaxSum 1000

class Obj3dmodel
{
public:
	Obj3dmodel(void);

	void parse(const char* filename);
    void draw();


	unsigned int verticesSum;
	unsigned int texturesSum;
	unsigned int normalsSum;
	unsigned int polygonSum;
	unsigned int triangleSum;

	float vertices[vertexMaxSum*3];
	float textures[textureMaxSum*3];
	float normals[normalMaxSum*3];

	GLuint polygonVerticesIndex[polygonMaxSum*4];
	GLuint triangleVerticesIndex[triangleMaxSum*3];

	unsigned int polygonTexturesIndex[polygonMaxSum*4];
	unsigned int triangleTexturesIndex[triangleMaxSum];
	
	unsigned int polygonNormalsIndex[polygonMaxSum*4];
	unsigned int triangleNormalsIndex[triangleMaxSum*3];

private:
	
	unsigned int verticesPointer;
	unsigned int texturesPointer;
	unsigned int normalsPointer;
	
	unsigned int polygonVerticesIndexPointer;
	unsigned int triangleVerticesIndexPointer;

	unsigned int polygonTexturesIndexPointer;
	unsigned int triangleTexturesIndexPointer;

	unsigned int polygonNormalsIndexPointer;
	unsigned int triangleNormalsIndexPointer;

};