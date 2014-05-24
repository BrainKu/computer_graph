//#include <iostream>
//#include <string.h>
//#include <math.h>
//#include <gl/glew.h>
//#include <gl/glut.h>
//#include "Utility.h"
//
//using namespace std;
//
//#define MAX_EMBOSS (GLfloat)0.01f // ͻ�����ֵ
//#define MAX_EXTENSION_SPACE 10240 // ��չ�ַ����ַ�
//#define MAX_EXTENSION_LENGHT 256 //  һ����չ������ַ�����
//
//bool g_emboss = false;        // �����������Ч��,����ʹ����ɫ
//bool g_bumps = true;            // ������͹����
//bool g_multitextureSupported = true;    // �ж��Ƿ�֧������Ҫ����չ
//bool g_useMultitexture = true;            // �Ƿ�ʹ����չ
//
//GLint g_maxTexelUnits = 1;        //;
//
//GLfloat    xrot = 0.0f;        // X Rotation
//GLfloat    yrot = 0.0f;        // Y Rotation
//GLfloat xspeed = 0.1f;        // X Rotation Speed
//GLfloat yspeed = 0.1f;        // Y Rotation Speed
//GLfloat    z = -5.0f;
//
//// 1 ʹ�� g_texture 2 ʹ��g_bump 3 ʹ�� g_invbump
//GLuint g_drawType = 0;        // ����ʹ�û��Ƶķ�ʽ��
//
//GLuint g_texture;    // �洢3������
//GLuint g_bump;        // 3�Ű�͹����
//GLuint g_invbump;        // ������
//
//GLuint g_glLogo;    // opengl logo
//GLuint g_multiLogo;
//
//GLfloat g_LightAmbient[] = { 0.2f, 0.2f, 0.2f };    // ������
//GLfloat g_LightDiffuse[] = { 1.0f, 1.0f, 1.0f };    // ������
//GLfloat g_LightPosition[] = { 0.0f, 0.0f, 2.0f };
//
//GLfloat g_Gray[] = { 0.5f, 0.5f, 0.5f, 1.0f };
//
//// ��������ݴ洢������������棬��ʽ��2�������㣬3������
//
//GLfloat g_data[] = {
//	// front
//	0.0f, 0.0f, -1.0f, -1.0f, 1.0f,
//	1.0f, 0.0f, +1.0f, -1.0f, 1.0f,
//	1.0f, 1.0f, +1.0f, 1.0f, 1.0f,
//	0.0f, 1.0f, -1.0f, 1.0f, 1.0f,
//	// back
//	1.0f, 0.0f, -1.0f, -1.0f, -1.0f,
//	1.0f, 1.0f, -1.0f, 1.0f, -1.0f,
//	0.0f, 1.0f, 1.0f, 1.0f, -1.0f,
//	0.0f, 0.0f, 1.0f, -1.0f, -1.0f,
//	// top
//	0.0f, 1.0f, -1.0f, 1.0f, -1.0f,
//	0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
//	1.0f, 0.0f, 1.0f, 1.0f, 1.0f,
//	1.0f, 1.0f, 1.0f, +1.0f, -1.0f,
//	// bottom
//	1.0f, 1.0f, -1.0f, -1.0f, -1.0f,
//	0.0f, 1.0f, 1.0f, -1.0f, -1.0f,
//	0.0f, 0.0f, 1.0f, -1.0f, 1.0f,
//	1.0f, 0.0f, -1.0f, -1.0f, 1.0f,
//	// right
//	1.0f, 0.0f, 1.0f, -1.0f, -1.0f,
//	1.0f, 1.0f, 1.0f, 1.0f, -1.0f,
//	0.0f, 1.0f, 1.0f, 1.0f, 1.0f,
//	0.0f, 0.0f, 1.0f, -1.0f, 1.0f,
//	// left
//	0.0f, 0.0f, -1.0f, -1.0f, -1.0f,
//	1.0f, 0.0f, -1.0f, -1.0f, 1.0f,
//	1.0f, 1.0f, -1.0f, 1.0f, 1.0f,
//	0.0f, 1.0f, -1.0f, 1.0f, -1.0f
//};
//
//// ��ʼ��
//void initLight(void)
//{
//	glLightfv(GL_LIGHT1, GL_AMBIENT, g_LightAmbient);
//	glLightfv(GL_LIGHT1, GL_DIFFUSE, g_LightDiffuse);
//	glLightfv(GL_LIGHT1, GL_POSITION, g_LightPosition);
//
//	glEnable(GL_LIGHT1);
//}
//
//
//
//// ͼƬ������ ������ �� ����
//struct Image
//{
//	unsigned long sizeX;
//	unsigned long sizeY;
//	char *data;
//};
//typedef struct Image Image;
//
//// ����������ת��ģ�Ͱ�
//float g_angle = 0;
//
///**
//* @brie �����Ŀ���Ǹ��ݵ�ǰ�Ķ��㣬���ߺ͵ƹ����������ƫ����
//* �����s t�Ǳ�����ǰ�����uv�ķ���,����ǰ��Ļ����� s(1,0,0) t(0,1,0)
//* @param n ��ǰ����ķ�����
//* @param c ����Ķ�������
//* @param l �ƹ��λ��
//* @param s s����
//* @param t t����
//*/
//void setupbumps(GLfloat *n, GLfloat *c, GLfloat *l, GLfloat *s, GLfloat *t)
//{
//	GLfloat v[3];
//	GLfloat lenq;
//
//	// ���ݵ�ǰ��������͵ƹ����������ƹ⵱�������������v
//	v[0] = l[0] - c[0];
//	v[1] = l[1] - c[1];
//	v[2] = l[2] - c[2];
//	// ��v�������й�һ��
//	lenq = (GLfloat)sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
//	v[0] /= lenq;
//	v[1] /= lenq;
//	v[2] /= lenq;
//
//	// ����������Ϊ0�󿴿�Ч����ʲô����
//	// ����������ƫ����
//	c[0] = (s[0] * v[0] + s[1] * v[1] + s[2] * v[2]) * MAX_EMBOSS;
//	c[1] = (t[0] * v[0] + t[1] * v[1] + t[2] * v[2]) * MAX_EMBOSS;
//	//c[0] = 0;
//	//c[1] = 0;
//
//}
//
//// ��ȡ bitmaps ��ת��������
//void LoadGLTextures1(const std::string& picname, GLuint& texture)
//{
//	Utility::loadSingleTex(texture, picname.c_str());
//}
//
//
//void loadGLTextures()
//{
//
//	Image *image1;
//	image1 = (Image*)malloc(sizeof(Image));
//
//	if (image1 == NULL)
//	{
//		printf("Error allocating space for image");
//		exit(0);
//	}
//
//	if (!ImageLoad("Data/Base.bmp", image1))
//		exit(1);
//
//	// ��������
//	glGenTextures(1, &g_texture);
//
//	// create  nearest filtered texture
//	glBindTexture(GL_TEXTURE_2D, g_texture); // ��2D����
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, image1->sizeX, image1->sizeY,
//		0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
//
//	free(image1);
//
//	// bump
//	image1 = (Image*)malloc(sizeof(Image));
//
//	if (image1 == NULL)
//	{
//		printf("Error allocating space for image");
//		exit(0);
//	}
//
//	if (!ImageLoad("Data/Bump.bmp", image1))
//		exit(1);
//
//	// ��������
//	glPixelTransferf(GL_RED_SCALE, 0.5f);    // �ı��ԭ����50%
//	glPixelTransferf(GL_GREEN_SCALE, 0.5f);
//	glPixelTransferf(GL_BLUE_SCALE, 0.5f);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
//	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, g_Gray);
//	glGenTextures(1, &g_bump);
//
//	// create  nearest filtered texture
//	glBindTexture(GL_TEXTURE_2D, g_bump); // ��2D����
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, image1->sizeX, image1->sizeY,
//		0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
//
//	// 
//	unsigned char * data = (unsigned char *)image1->data;
//	for (unsigned int i = 0; i < 3 * image1->sizeX * image1->sizeY; i++)
//		data[i] = 255 - data[i];
//
//	glGenTextures(1, &g_invbump);
//
//	// create  nearest filtered texture
//	glBindTexture(GL_TEXTURE_2D, g_invbump); // ��2D����
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, image1->sizeX, image1->sizeY,
//		0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
//
//	glPixelTransferf(GL_RED_SCALE, 1.0f);
//	glPixelTransferf(GL_GREEN_SCALE, 1.0f);
//	glPixelTransferf(GL_BLUE_SCALE, 1.0f);
//
//	free(image1);
//}
//// ��������Ͳ����������������
//void doCube()
//{
//	int i = 0;
//	glBegin(GL_QUADS);
//	// front 
//	glNormal3f(0.0f, 0.0f, 1.0f);
//	for (i = 0; i < 4; i++)
//	{
//		glTexCoord2f(g_data[5 * i], g_data[5 * i + 1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	// back 
//	glNormal3f(0.0f, 0.0f, -1.0f);
//	for (i = 4; i < 8; i++)
//	{
//		glTexCoord2f(g_data[5 * i], g_data[5 * i + 1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	// top 
//	glNormal3f(0.0f, 1.0f, 0.0f);
//	for (i = 8; i < 12; i++)
//	{
//		glTexCoord2f(g_data[5 * i], g_data[5 * i + 1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	// bottom 
//	glNormal3f(0.0f, -1.0f, 0.0f);
//	for (i = 12; i < 16; i++)
//	{
//		glTexCoord2f(g_data[5 * i], g_data[5 * i + 1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	// right 
//	glNormal3f(-1.0f, 0.0f, 0.0f);
//	for (i = 16; i < 20; i++)
//	{
//		glTexCoord2f(g_data[5 * i], g_data[5 * i + 1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	// left 
//	glNormal3f(1.0f, 0.0f, 0.0f);
//	for (i = 20; i < 24; i++)
//	{
//		glTexCoord2f(g_data[5 * i], g_data[5 * i + 1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	glEnd();
//
//}
//
//// ���ݱ仯�ľ�������ڶ�������ϵ�еƹ��λ��
//// v = vm, m is 4x4  v is 4dim row
///**
//* @brief �����Ǹ��ݻ�ȡ�ı任�ľ���m�͵�ǰ�ĵ����������任��ƹ��ڶ�������ϵ�е�λ������
//* @param m �任��ľ���
//* @param v �ƹ�����,�����������꽫������
//*
//*/
//void vmatmult(GLfloat *m, GLfloat *v)
//{
//	GLfloat res[3];
//	res[0] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3] * v[3];
//	res[1] = m[4] * v[0] + m[5] * v[1] + m[6] * v[2] + m[7] * v[3];
//	res[2] = m[8] * v[0] + m[9] * v[1] + m[10] * v[2] + m[11] * v[3];
//
//	v[0] = res[0];
//	v[1] = res[1];
//	v[2] = res[2];
//	v[3] = m[15];
//}
//
//
//// ��ʹ�ö�������
//// ʹ�÷�ʽ1�����а�͹ӳ��
//bool doMesh1TexelUnits(void)
//{
//	GLfloat c[4] = { 0.0f, 0.0f, 0.0f, 1.0f };                    // �洢��ǰ������ 
//	GLfloat n[4] = { 0.0f, 0.0f, 0.0f, 1.0f };                    // �洢��ǰ��ķ�����
//	GLfloat s[4] = { 0.0f, 0.0f, 0.0f, 1.0f };                    // ����s�ķ��򣬹�һ��
//	GLfloat t[4] = { 0.0f, 0.0f, 0.0f, 1.0f };                    // ����t�ķ��򣬹�һ��
//	GLfloat l[4];                                        // �洢ת��������ռ�ĵ�������
//	GLfloat Minv[16];                                    // �洢modelview�����þ���
//	int i;
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // �����ɫ����Ȼ�
//
//	// Build Inverse Modelview Matrix First. This Substitutes One Push/Pop With One glLoadIdentity();
//	// Simply Build It By Doing All Transformations Negated And In Reverse Order.
//	// ���ȴ���modelview �����þ��� ��������push/pop ʹ��glloadidentity()
//	// �򵥵Ĵ��������Ϊ�������ǿ������׿��Ʊ任����Ч����Ч(������һ���ܱ�������飬�����˼������)
//	glLoadIdentity();
//	glRotatef(-yrot, 0.0f, 1.0f, 0.0f);
//	glRotatef(-xrot, 1.0f, 0.0f, 0.0f);
//	glTranslatef(0.0f, 0.0f, -z);
//	glGetFloatv(GL_MODELVIEW_MATRIX, Minv);
//	glLoadIdentity();
//	glTranslatef(0.0f, 0.0f, z);
//
//	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
//	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
//
//	// Transform The Lightposition Into Object Coordinates:
//	// ת���ƹ����굽��������ϵ
//	l[0] = g_LightPosition[0];
//	l[1] = g_LightPosition[1];
//	l[2] = g_LightPosition[2];
//	l[3] = 1.0f;                                            // Homogenous Coordinate
//	vmatmult(Minv, l);
//
//	/*    PASS#1: Use Texture "Bump"
//	No Blend
//	No Lighting
//	No Offset Texture-Coordinates */
//	glBindTexture(GL_TEXTURE_2D, g_bump);
//	glDisable(GL_BLEND);
//	glDisable(GL_LIGHTING);
//	doCube();
//
//	/* PASS#2:    Use Texture "Invbump"
//	Blend GL_ONE To GL_ONE
//	No Lighting
//	Offset Texture Coordinates
//	*/
//	glBindTexture(GL_TEXTURE_2D, g_invbump);
//	glBlendFunc(GL_ONE, GL_ONE);
//	glDepthFunc(GL_LEQUAL);
//	glEnable(GL_BLEND);
//
//	glBegin(GL_QUADS);
//	// Front Face    
//	n[0] = 0.0f;        n[1] = 0.0f;        n[2] = 1.0f;
//	s[0] = 1.0f;        s[1] = 0.0f;        s[2] = 0.0f;
//	t[0] = 0.0f;        t[1] = 1.0f;        t[2] = 0.0f;
//	for (i = 0; i<4; i++) {
//		c[0] = g_data[5 * i + 2];
//		c[1] = g_data[5 * i + 3];
//		c[2] = g_data[5 * i + 4];
//		setupbumps(n, c, l, s, t);
//		glTexCoord2f(g_data[5 * i] + c[0], g_data[5 * i + 1] + c[1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	// Back Face    
//	n[0] = 0.0f;        n[1] = 0.0f;        n[2] = -1.0f;
//	s[0] = -1.0f;        s[1] = 0.0f;        s[2] = 0.0f;
//	t[0] = 0.0f;        t[1] = 1.0f;        t[2] = 0.0f;
//	for (i = 4; i<8; i++) {
//		c[0] = g_data[5 * i + 2];
//		c[1] = g_data[5 * i + 3];
//		c[2] = g_data[5 * i + 4];
//		setupbumps(n, c, l, s, t);
//		glTexCoord2f(g_data[5 * i] + c[0], g_data[5 * i + 1] + c[1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	// Top Face    
//	n[0] = 0.0f;        n[1] = 1.0f;        n[2] = 0.0f;
//	s[0] = 1.0f;        s[1] = 0.0f;        s[2] = 0.0f;
//	t[0] = 0.0f;        t[1] = 0.0f;        t[2] = -1.0f;
//	for (i = 8; i<12; i++) {
//		c[0] = g_data[5 * i + 2];
//		c[1] = g_data[5 * i + 3];
//		c[2] = g_data[5 * i + 4];
//		setupbumps(n, c, l, s, t);
//		glTexCoord2f(g_data[5 * i] + c[0], g_data[5 * i + 1] + c[1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	// Bottom Face
//	n[0] = 0.0f;        n[1] = -1.0f;        n[2] = 0.0f;
//	s[0] = -1.0f;        s[1] = 0.0f;        s[2] = 0.0f;
//	t[0] = 0.0f;        t[1] = 0.0f;        t[2] = -1.0f;
//	for (i = 12; i<16; i++) {
//		c[0] = g_data[5 * i + 2];
//		c[1] = g_data[5 * i + 3];
//		c[2] = g_data[5 * i + 4];
//		setupbumps(n, c, l, s, t);
//		glTexCoord2f(g_data[5 * i] + c[0], g_data[5 * i + 1] + c[1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	// Right Face    
//	n[0] = 1.0f;        n[1] = 0.0f;        n[2] = 0.0f;
//	s[0] = 0.0f;        s[1] = 0.0f;        s[2] = -1.0f;
//	t[0] = 0.0f;        t[1] = 1.0f;        t[2] = 0.0f;
//	for (i = 16; i<20; i++) {
//		c[0] = g_data[5 * i + 2];
//		c[1] = g_data[5 * i + 3];
//		c[2] = g_data[5 * i + 4];
//		setupbumps(n, c, l, s, t);
//		glTexCoord2f(g_data[5 * i] + c[0], g_data[5 * i + 1] + c[1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	// Left Face
//	n[0] = -1.0f;        n[1] = 0.0f;        n[2] = 0.0f;
//	s[0] = 0.0f;        s[1] = 0.0f;        s[2] = 1.0f;
//	t[0] = 0.0f;        t[1] = 1.0f;        t[2] = 0.0f;
//	for (i = 20; i<24; i++) {
//		c[0] = g_data[5 * i + 2];
//		c[1] = g_data[5 * i + 3];
//		c[2] = g_data[5 * i + 4];
//		setupbumps(n, c, l, s, t);
//		glTexCoord2f(g_data[5 * i] + c[0], g_data[5 * i + 1] + c[1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	glEnd();
//
//	/* PASS#3:    Use Texture "Base"
//	Blend GL_DST_COLOR To GL_SRC_COLOR (Multiplies By 2)
//	Lighting Enabled
//	No Offset Texture-Coordinates
//	*/
//	if (!g_emboss) {
//		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//		glBindTexture(GL_TEXTURE_2D, g_texture);
//		glBlendFunc(GL_DST_COLOR, GL_SRC_COLOR);
//		glEnable(GL_LIGHTING);
//		doCube();
//	}
//
//	xrot += xspeed;
//	yrot += yspeed;
//	if (xrot>360.0f) xrot -= 360.0f;
//	if (xrot<0.0f) xrot += 360.0f;
//	if (yrot>360.0f) yrot -= 360.0f;
//	if (yrot<0.0f) yrot += 360.0f;
//
//
//	return true;                                        // Keep Going
//}
//
//// ʹ�ö�������
//// ʹ�÷�ʽ2�����а�͹ӳ��
//bool doMesh2TexelUnits(void)
//{
//
//	GLfloat c[4] = { 0.0f, 0.0f, 0.0f, 1.0f };                    // holds current vertex
//	GLfloat n[4] = { 0.0f, 0.0f, 0.0f, 1.0f };                    // normalized normal of current surface        
//	GLfloat s[4] = { 0.0f, 0.0f, 0.0f, 1.0f };                    // s-texture coordinate direction, normalized
//	GLfloat t[4] = { 0.0f, 0.0f, 0.0f, 1.0f };                    // t-texture coordinate direction, normalized
//	GLfloat l[4];                                        // holds our lightposition to be transformed into object space
//	GLfloat Minv[16];                                    // holds the inverted modelview matrix to do so.
//	int i;
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // Clear The Screen And The Depth Buffer
//
//	// Build Inverse Modelview Matrix First. This Substitutes One Push/Pop With One glLoadIdentity();
//	// Simply Build It By Doing All Transformations Negated And In Reverse Order.
//	glLoadIdentity();
//	glRotatef(-yrot, 0.0f, 1.0f, 0.0f);
//	glRotatef(-xrot, 1.0f, 0.0f, 0.0f);
//	glTranslatef(0.0f, 0.0f, -z);
//	glGetFloatv(GL_MODELVIEW_MATRIX, Minv);
//	glLoadIdentity();
//	glTranslatef(0.0f, 0.0f, z);
//
//	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
//	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
//
//	// Transform The Lightposition Into Object Coordinates:
//	l[0] = g_LightPosition[0];
//	l[1] = g_LightPosition[1];
//	l[2] = g_LightPosition[2];
//	l[3] = 1.0f;                                            // Homogenous Coordinate
//	vmatmult(Minv, l);
//
//	/*    PASS#1: Texel-Unit 0:    Use Texture "Bump"
//	No Blend
//	No Lighting
//	No Offset Texture-Coordinates
//	Texture-Operation "Replace"
//	Texel-Unit 1:    Use Texture "Invbump"
//	No Lighting
//	Offset Texture Coordinates
//	Texture-Operation "Replace"
//	*/
//	// TEXTURE-UNIT #0        
//	glActiveTextureARB(GL_TEXTURE0_ARB);
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, g_bump);
//	glTexEnvf(GL_TEXTURE_ENV, (GLenum)GL_TEXTURE_ENV_MODE, GL_COMBINE_EXT);
//	glTexEnvf(GL_TEXTURE_ENV, (GLenum)GL_COMBINE_RGB_EXT, GL_REPLACE);
//	// TEXTURE-UNIT #1:
//	glActiveTextureARB(GL_TEXTURE1_ARB);
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, g_invbump);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_EXT);
//	glTexEnvf(GL_TEXTURE_ENV, (GLenum)GL_COMBINE_RGB_EXT, GL_ADD);
//	// General Switches:
//	glDisable(GL_BLEND);
//	glDisable(GL_LIGHTING);
//	glBegin(GL_QUADS);
//	// Front Face    
//	n[0] = 0.0f;        n[1] = 0.0f;        n[2] = 1.0f;
//	s[0] = 1.0f;        s[1] = 0.0f;        s[2] = 0.0f;
//	t[0] = 0.0f;        t[1] = 1.0f;        t[2] = 0.0f;
//	for (i = 0; i<4; i++) {
//		c[0] = g_data[5 * i + 2];
//		c[1] = g_data[5 * i + 3];
//		c[2] = g_data[5 * i + 4];
//		setupbumps(n, c, l, s, t);
//		glMultiTexCoord2fARB(GL_TEXTURE0_ARB, g_data[5 * i], g_data[5 * i + 1]);
//		glMultiTexCoord2fARB(GL_TEXTURE1_ARB, g_data[5 * i] + c[0], g_data[5 * i + 1] + c[1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	// Back Face    
//	n[0] = 0.0f;        n[1] = 0.0f;        n[2] = -1.0f;
//	s[0] = -1.0f;        s[1] = 0.0f;        s[2] = 0.0f;
//	t[0] = 0.0f;        t[1] = 1.0f;        t[2] = 0.0f;
//	for (i = 4; i<8; i++) {
//		c[0] = g_data[5 * i + 2];
//		c[1] = g_data[5 * i + 3];
//		c[2] = g_data[5 * i + 4];
//		setupbumps(n, c, l, s, t);
//		glMultiTexCoord2fARB(GL_TEXTURE0_ARB, g_data[5 * i], g_data[5 * i + 1]);
//		glMultiTexCoord2fARB(GL_TEXTURE1_ARB, g_data[5 * i] + c[0], g_data[5 * i + 1] + c[1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	// Top Face    
//	n[0] = 0.0f;        n[1] = 1.0f;        n[2] = 0.0f;
//	s[0] = 1.0f;        s[1] = 0.0f;        s[2] = 0.0f;
//	t[0] = 0.0f;        t[1] = 0.0f;        t[2] = -1.0f;
//	for (i = 8; i<12; i++) {
//		c[0] = g_data[5 * i + 2];
//		c[1] = g_data[5 * i + 3];
//		c[2] = g_data[5 * i + 4];
//		setupbumps(n, c, l, s, t);
//		glMultiTexCoord2fARB(GL_TEXTURE0_ARB, g_data[5 * i], g_data[5 * i + 1]);
//		glMultiTexCoord2fARB(GL_TEXTURE1_ARB, g_data[5 * i] + c[0], g_data[5 * i + 1] + c[1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	// Bottom Face
//	n[0] = 0.0f;        n[1] = -1.0f;        n[2] = 0.0f;
//	s[0] = -1.0f;        s[1] = 0.0f;        s[2] = 0.0f;
//	t[0] = 0.0f;        t[1] = 0.0f;        t[2] = -1.0f;
//	for (i = 12; i<16; i++) {
//		c[0] = g_data[5 * i + 2];
//		c[1] = g_data[5 * i + 3];
//		c[2] = g_data[5 * i + 4];
//		setupbumps(n, c, l, s, t);
//		glMultiTexCoord2fARB(GL_TEXTURE0_ARB, g_data[5 * i], g_data[5 * i + 1]);
//		glMultiTexCoord2fARB(GL_TEXTURE1_ARB, g_data[5 * i] + c[0], g_data[5 * i + 1] + c[1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	// Right Face    
//	n[0] = 1.0f;        n[1] = 0.0f;        n[2] = 0.0f;
//	s[0] = 0.0f;        s[1] = 0.0f;        s[2] = -1.0f;
//	t[0] = 0.0f;        t[1] = 1.0f;        t[2] = 0.0f;
//	for (i = 16; i<20; i++) {
//		c[0] = g_data[5 * i + 2];
//		c[1] = g_data[5 * i + 3];
//		c[2] = g_data[5 * i + 4];
//		setupbumps(n, c, l, s, t);
//		glMultiTexCoord2fARB(GL_TEXTURE0_ARB, g_data[5 * i], g_data[5 * i + 1]);
//		glMultiTexCoord2fARB(GL_TEXTURE1_ARB, g_data[5 * i] + c[0], g_data[5 * i + 1] + c[1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	// Left Face
//	n[0] = -1.0f;        n[1] = 0.0f;        n[2] = 0.0f;
//	s[0] = 0.0f;        s[1] = 0.0f;        s[2] = 1.0f;
//	t[0] = 0.0f;        t[1] = 1.0f;        t[2] = 0.0f;
//	for (i = 20; i<24; i++) {
//		c[0] = g_data[5 * i + 2];
//		c[1] = g_data[5 * i + 3];
//		c[2] = g_data[5 * i + 4];
//		setupbumps(n, c, l, s, t);
//		glMultiTexCoord2fARB(GL_TEXTURE0_ARB, g_data[5 * i], g_data[5 * i + 1]);
//		glMultiTexCoord2fARB(GL_TEXTURE1_ARB, g_data[5 * i] + c[0], g_data[5 * i + 1] + c[1]);
//		glVertex3f(g_data[5 * i + 2], g_data[5 * i + 3], g_data[5 * i + 4]);
//	}
//	glEnd();
//
//	// ��2����
//	//    ʹ�û�������Base.bmp
//	//    ʹ��GL_DST_COLOR ,GL_SRC_COLOR���л��
//	//    �����ƹ�
//	//    ��ƫ����������
//	glActiveTextureARB(GL_TEXTURE1_ARB);
//	glDisable(GL_TEXTURE_2D);
//	glActiveTextureARB(GL_TEXTURE0_ARB);
//	if (!g_emboss) {
//		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//		glBindTexture(GL_TEXTURE_2D, g_texture);
//		glBlendFunc(GL_DST_COLOR, GL_SRC_COLOR);
//		glEnable(GL_BLEND);
//		glEnable(GL_LIGHTING);
//		doCube();
//	}
//
//	xrot += xspeed;
//	yrot += yspeed;
//	if (xrot>360.0f) xrot -= 360.0f;
//	if (xrot<0.0f) xrot += 360.0f;
//	if (yrot>360.0f) yrot -= 360.0f;
//	if (yrot<0.0f) yrot += 360.0f;
//
//	return true;                                        // Keep Going
//}
//
//// ����ǲ�ʹ��Ҫͼӳ���
//bool doMeshNoBumps(void)
//{
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // Clear The Screen And The Depth Buffer
//	glLoadIdentity();                                    // Reset The View
//	glTranslatef(0.0f, 0.0f, z);
//
//	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
//	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
//	if (g_useMultitexture) {
//		glActiveTextureARB(GL_TEXTURE1_ARB);
//		glDisable(GL_TEXTURE_2D);
//		glActiveTextureARB(GL_TEXTURE0_ARB);
//	}
//	glDisable(GL_BLEND);
//	switch (g_drawType)
//	{
//	case 1:
//		glBindTexture(GL_TEXTURE_2D, g_texture);
//		break;
//	case 2:
//		glBindTexture(GL_TEXTURE_2D, g_bump);
//		break;
//	case 3:
//		glBindTexture(GL_TEXTURE_2D, g_invbump);
//		break;
//	}
//
//	glBlendFunc(GL_DST_COLOR, GL_SRC_COLOR);
//	glEnable(GL_LIGHTING);
//	doCube();
//
//	xrot += xspeed;
//	yrot += yspeed;
//	if (xrot>360.0f) xrot -= 360.0f;
//	if (xrot<0.0f) xrot += 360.0f;
//	if (yrot>360.0f) yrot -= 360.0f;
//	if (yrot<0.0f) yrot += 360.0f;
//
//	return true;                                        // Keep Going
//}
////===========================OpenGL ����=========================
//// ��ʼ��opengl��һЩ����
//void init()
//{
//	loadGLTextures();
//
//	glEnable(GL_TEXTURE_2D);
//	glShadeModel(GL_SMOOTH);
//	glClearColor(0.0f, 0.0f, 0.0f, 0.5f); // ��������ɫΪ��ɫ
//	glClearDepth(1.0);
//	glEnable(GL_DEPTH_TEST);
//	glDepthFunc(GL_LEQUAL);
//	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
//
//	initLight();
//}
//
//
//
//
////------------------------------------
//// ����ˢ��ʱ��
//void timer(int p)
//{
//	glutPostRedisplay();
//	glutTimerFunc(20, timer, 0);
//}
//
////-----------------------------------
//// ��ʾ����Ҫ���Ƶ�ģ��
//void display()
//{
//	if (g_bumps) {
//		if (g_useMultitexture && g_maxTexelUnits>1)
//			doMesh2TexelUnits();
//		else
//			doMesh1TexelUnits();
//	}
//	else
//	{
//		doMeshNoBumps();
//	}
//
//	glutSwapBuffers(); //˫����
//}
//
////-----------------------------------
//// �����ڱ仯��ʱ����������
//void reshape(int w, int h)
//{
//	/* �ӿ�����
//	* ����ǵ����ڷ�����С�仯��ʱ�����������ҿ����Լ�
//	* �����´��ھͿ��Կ�����һ���ĵط���
//	*/
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h); // �����ӿ�
//	glMatrixMode(GL_PROJECTION); // ���õ�ǰ����ΪͶӰ����
//	glLoadIdentity();
//
//	if (h == 0) h = 1; // ��ֹ��0���
//	gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.5f, -1000.0f);
//
//	glMatrixMode(GL_MODELVIEW); // ���õ�ǰ����Ϊģ�;���
//	glLoadIdentity();
//}
//
////-----------------------------------
////�����¼�
//void keyboard(unsigned char key, int x, int y)
//{
//	cout << "key=" << key << endl;
//	switch (key)
//	{
//	case 27: // �����¼��̵�esc����ʱ���˳�
//		exit(0);
//		break;
//	case 'j':
//	case 'J': // ����ǰ��3������ֱ���ʲô���ӵ� g_texture g_bump g_invbump
//		g_drawType++;
//		if (g_drawType > 3) g_drawType = 1;
//		break;
//	case 'k':
//	case 'K':    // �Ƿ���������
//		g_emboss = !g_emboss;
//		break;
//	case 'l':
//	case 'L':    // ʹ�����ָ������һ��
//		g_useMultitexture = ((!g_useMultitexture) && g_multitextureSupported);
//		break;
//	case 'H':
//	case 'h':    // �ж��Ƿ�ʹ�ø���Ч��
//		g_bumps = !g_bumps;
//		break;
//	}
//}
//
////------------------------------------
//// �������¼���
//void MouseEvent(int button, int state, int x, int y)
//{
//}
//
////-------------------------------------
//// ����ƶ��¼�
//void MotionMove(int x, int y)
//{
//}
//
//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(800, 600);
//	glutCreateWindow("OpenGLDemo");
//	init();
//	glutTimerFunc(20, timer, 0); // ���ø���ʱ��
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboard);
//	glutMouseFunc(MouseEvent);
//	glutMotionFunc(MotionMove);
//	glutMainLoop();
//
//	return 0;
//}