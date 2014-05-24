//#include <iostream>
//#include <string.h>
//#include <math.h>
//#include <gl/glew.h>
//#include <gl/glut.h>
//#include "Utility.h"
//
//using namespace std;
//
//#define MAX_EMBOSS (GLfloat)0.01f // 突起最大值
//#define MAX_EXTENSION_SPACE 10240 // 扩展字符串字符
//#define MAX_EXTENSION_LENGHT 256 //  一个扩展的最大字符长度
//
//bool g_emboss = false;        // 这个是允许浮雕效果,还是使用颜色
//bool g_bumps = true;            // 开启凹凸纹理
//bool g_multitextureSupported = true;    // 判断是否支持我们要的扩展
//bool g_useMultitexture = true;            // 是否使用扩展
//
//GLint g_maxTexelUnits = 1;        //;
//
//GLfloat    xrot = 0.0f;        // X Rotation
//GLfloat    yrot = 0.0f;        // Y Rotation
//GLfloat xspeed = 0.1f;        // X Rotation Speed
//GLfloat yspeed = 0.1f;        // Y Rotation Speed
//GLfloat    z = -5.0f;
//
//// 1 使用 g_texture 2 使用g_bump 3 使用 g_invbump
//GLuint g_drawType = 0;        // 这里使用绘制的方式，
//
//GLuint g_texture;    // 存储3张纹理
//GLuint g_bump;        // 3张凹凸纹理
//GLuint g_invbump;        // 凹纹理
//
//GLuint g_glLogo;    // opengl logo
//GLuint g_multiLogo;
//
//GLfloat g_LightAmbient[] = { 0.2f, 0.2f, 0.2f };    // 环境光
//GLfloat g_LightDiffuse[] = { 1.0f, 1.0f, 1.0f };    // 漫反射
//GLfloat g_LightPosition[] = { 0.0f, 0.0f, 2.0f };
//
//GLfloat g_Gray[] = { 0.5f, 0.5f, 0.5f, 1.0f };
//
//// 下面的数据存储的是立方体的面，格式是2个纹理定点，3个坐标
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
//// 初始化
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
//// 图片的类型 包含宽 高 数据
//struct Image
//{
//	unsigned long sizeX;
//	unsigned long sizeY;
//	char *data;
//};
//typedef struct Image Image;
//
//// 我们用来旋转下模型吧
//float g_angle = 0;
//
///**
//* @brie 这里的目的是根据当前的顶点，法线和灯光计算出纹理的偏移量
//* 这里的s t是表明当前纹理的uv的方向,比如前面的话就是 s(1,0,0) t(0,1,0)
//* @param n 当前表面的法向量
//* @param c 当点的定点坐标
//* @param l 灯光的位置
//* @param s s方向
//* @param t t方向
//*/
//void setupbumps(GLfloat *n, GLfloat *c, GLfloat *l, GLfloat *s, GLfloat *t)
//{
//	GLfloat v[3];
//	GLfloat lenq;
//
//	// 根据当前顶点坐标和灯光坐标计算出灯光当顶点坐标的向量v
//	v[0] = l[0] - c[0];
//	v[1] = l[1] - c[1];
//	v[2] = l[2] - c[2];
//	// 对v向量进行归一化
//	lenq = (GLfloat)sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
//	v[0] /= lenq;
//	v[1] /= lenq;
//	v[2] /= lenq;
//
//	// 把这里设置为0后看看效果有什么区别
//	// 计算出纹理的偏移量
//	c[0] = (s[0] * v[0] + s[1] * v[1] + s[2] * v[2]) * MAX_EMBOSS;
//	c[1] = (t[0] * v[0] + t[1] * v[1] + t[2] * v[2]) * MAX_EMBOSS;
//	//c[0] = 0;
//	//c[1] = 0;
//
//}
//
//// 读取 bitmaps 并转化成纹理
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
//	// 创建纹理
//	glGenTextures(1, &g_texture);
//
//	// create  nearest filtered texture
//	glBindTexture(GL_TEXTURE_2D, g_texture); // 绑定2D纹理
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
//	// 创建纹理
//	glPixelTransferf(GL_RED_SCALE, 0.5f);    // 改变成原来的50%
//	glPixelTransferf(GL_GREEN_SCALE, 0.5f);
//	glPixelTransferf(GL_BLUE_SCALE, 0.5f);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
//	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, g_Gray);
//	glGenTextures(1, &g_bump);
//
//	// create  nearest filtered texture
//	glBindTexture(GL_TEXTURE_2D, g_bump); // 绑定2D纹理
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
//	glBindTexture(GL_TEXTURE_2D, g_invbump); // 绑定2D纹理
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
//// 根据纹理和材质坐标绘制立方体
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
//// 根据变化的矩阵计算在对象坐标系中灯光的位置
//// v = vm, m is 4x4  v is 4dim row
///**
//* @brief 这里是根据获取的变换的矩阵m和当前的当光坐标计算变换后灯光在对象坐标系中的位置坐标
//* @param m 变换后的矩阵
//* @param v 灯光坐标,计算后这个坐标将被设置
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
//// 不使用多重纹理
//// 使用方式1来进行凹凸映射
//bool doMesh1TexelUnits(void)
//{
//	GLfloat c[4] = { 0.0f, 0.0f, 0.0f, 1.0f };                    // 存储当前的坐标 
//	GLfloat n[4] = { 0.0f, 0.0f, 0.0f, 1.0f };                    // 存储当前面的法向量
//	GLfloat s[4] = { 0.0f, 0.0f, 0.0f, 1.0f };                    // 纹理s的方向，归一化
//	GLfloat t[4] = { 0.0f, 0.0f, 0.0f, 1.0f };                    // 纹理t的方向，归一化
//	GLfloat l[4];                                        // 存储转换当对象空间的当光坐标
//	GLfloat Minv[16];                                    // 存储modelview的逆置矩阵
//	int i;
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // 清楚颜色和深度缓
//
//	// Build Inverse Modelview Matrix First. This Substitutes One Push/Pop With One glLoadIdentity();
//	// Simply Build It By Doing All Transformations Negated And In Reverse Order.
//	// 首先创建modelview 的逆置矩阵， 它将代替push/pop 使用glloadidentity()
//	// 简单的创建这个是为了让我们可以容易控制变换的有效和无效(翻译是一个很悲剧的事情，大概意思就这样)
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
//	// 转换灯光坐标到对象坐标系
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
//// 使用多重纹理
//// 使用方式2来进行凹凸映射
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
//	// 第2部分
//	//    使用基本纹理Base.bmp
//	//    使用GL_DST_COLOR ,GL_SRC_COLOR进行混合
//	//    开启灯光
//	//    不偏移纹理坐标
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
//// 这个是不使用要图映射的
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
////===========================OpenGL 部分=========================
//// 初始化opengl的一些参数
//void init()
//{
//	loadGLTextures();
//
//	glEnable(GL_TEXTURE_2D);
//	glShadeModel(GL_SMOOTH);
//	glClearColor(0.0f, 0.0f, 0.0f, 0.5f); // 清理背景颜色为蓝色
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
//// 设置刷新时间
//void timer(int p)
//{
//	glutPostRedisplay();
//	glutTimerFunc(20, timer, 0);
//}
//
////-----------------------------------
//// 显示我们要绘制的模型
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
//	glutSwapBuffers(); //双缓冲
//}
//
////-----------------------------------
//// 当窗口变化的时候会调用这里
//void reshape(int w, int h)
//{
//	/* 视口设置
//	* 这个是当窗口发生大小变化的时候会调用这里，大家可以自己
//	* 拉伸下窗口就可以看到不一样的地方了
//	*/
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h); // 设置视口
//	glMatrixMode(GL_PROJECTION); // 设置当前矩阵为投影矩阵
//	glLoadIdentity();
//
//	if (h == 0) h = 1; // 防止除0情况
//	gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.5f, -1000.0f);
//
//	glMatrixMode(GL_MODELVIEW); // 设置当前矩阵为模型矩阵
//	glLoadIdentity();
//}
//
////-----------------------------------
////键盘事件
//void keyboard(unsigned char key, int x, int y)
//{
//	cout << "key=" << key << endl;
//	switch (key)
//	{
//	case 27: // 当按下键盘的esc键的时候退出
//		exit(0);
//		break;
//	case 'j':
//	case 'J': // 看当前的3中纹理分别是什么样子的 g_texture g_bump g_invbump
//		g_drawType++;
//		if (g_drawType > 3) g_drawType = 1;
//		break;
//	case 'k':
//	case 'K':    // 是否贴上纹理
//		g_emboss = !g_emboss;
//		break;
//	case 'l':
//	case 'L':    // 使用两种浮雕的那一种
//		g_useMultitexture = ((!g_useMultitexture) && g_multitextureSupported);
//		break;
//	case 'H':
//	case 'h':    // 判断是否使用浮雕效果
//		g_bumps = !g_bumps;
//		break;
//	}
//}
//
////------------------------------------
//// 鼠标鼠标事件·
//void MouseEvent(int button, int state, int x, int y)
//{
//}
//
////-------------------------------------
//// 鼠标移动事件
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
//	glutTimerFunc(20, timer, 0); // 设置更新时间
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboard);
//	glutMouseFunc(MouseEvent);
//	glutMotionFunc(MotionMove);
//	glutMainLoop();
//
//	return 0;
//}