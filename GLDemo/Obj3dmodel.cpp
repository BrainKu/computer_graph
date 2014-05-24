//#include "Obj3dmodel.h"
//
//#include<string>
//#include<iostream>
//#include<fstream>
//
//
//using namespace std;
//
//GLfloat color[] = {0.5, 0.0, 0.0,
//	0.0, 0.5, 0.0,
//	0.0, 0.0, 0.5,
//	1.0, 0.0, 0.0,
//	0.0, 1.0, 0.0,
//	0.0, 0.0, 1.0,
//	0.0, 0.5, 0.5,
//	0.5, 0.0, 0.5,
//	0.5, 0.5, 0.0,
//	1.0, 0.5, 0.5,
//	0.5, 1.0, 0.5,
//	0.5, 0.5, 1.0};
//
//Obj3dmodel::Obj3dmodel()
//{
//	verticesSum = 0;
//	texturesSum = 0;
//	normalsSum = 0;
//	polygonSum = 0;
//	triangleSum = 0;
//
//	verticesPointer = 0;
//	texturesPointer = 0;
//	normalsPointer = 0;
//	
//	polygonVerticesIndexPointer = 0;
//	triangleVerticesIndexPointer = 0;
//
//	polygonTexturesIndexPointer = 0;
//	triangleTexturesIndexPointer = 0;
//
//	polygonNormalsIndexPointer = 0;
//	triangleNormalsIndexPointer = 0;
//
//
//}
//
//void Obj3dmodel::parse(const char *filename)
//{
//
//    string s;
//	char tempChar;
//
//	verticesPointer = 0;
//	
//	texturesPointer = 0;
//	
//	polygonVerticesIndexPointer = 0;
//	triangleVerticesIndexPointer = 0;
//
//	polygonTexturesIndexPointer = 0;
//	triangleTexturesIndexPointer = 0;
//
//	polygonNormalsIndexPointer = 0;
//	triangleNormalsIndexPointer = 0;
//
//    ifstream fin(filename);
//
//    if(!fin)
//          return;
//
//    while(fin>>s)
//    {
//		if(s == "v")
//        {
//			fin >> vertices[verticesPointer] >> vertices[verticesPointer+1] >> vertices[verticesPointer+2];
//			verticesPointer += 3;
//			verticesSum ++;
//        }
//		else if(s =="f")
//		{
//			string line;
//			int judgeSide = -1;
//			int stringPointer = 0;
//			int tempArray[12] = {0};
//			int tempArrayPointer = -1;
//
//			getline(fin,line);
//		
//			while(line[stringPointer] != '\0')
//			{
//				if(line[stringPointer] == ' ')
//				{
//					stringPointer ++;
//					tempArrayPointer ++;
//					judgeSide ++;
//				}
//				else if(line[stringPointer] == '/')
//				{
//					stringPointer ++;
//					tempArrayPointer ++;
//				}
//				else
//				{
//					tempArray[tempArrayPointer] *= 10;
//					tempArray[tempArrayPointer] += (line[stringPointer] - '0');
//					stringPointer ++;
//				}
//			}
//			if(judgeSide == 3)
//			{
//				triangleSum ++;
//				for(int i = 0; i< judgeSide; i++)
//				{
//					triangleVerticesIndex[triangleVerticesIndexPointer] = tempArray[i*3] - 1;
//					triangleTexturesIndex[triangleTexturesIndexPointer] = tempArray[i*3+1] - 1;
//					triangleNormalsIndex[triangleNormalsIndexPointer] = tempArray[i*3+2] - 1;
//		
//					triangleVerticesIndexPointer ++;
//					triangleTexturesIndexPointer ++;
//					triangleNormalsIndexPointer ++;
//				}
//			}
//			else if(judgeSide == 4)
//			{
//				polygonSum ++;
//				for(int i = 0; i< judgeSide; i++)
//				{
//					polygonVerticesIndex[polygonVerticesIndexPointer] = tempArray[i*3] - 1;
//
//					polygonTexturesIndex[polygonTexturesIndexPointer] = tempArray[i*3+1] - 1;
//					polygonNormalsIndex[polygonNormalsIndexPointer] = tempArray[i*3+2] -1;
//
//					polygonVerticesIndexPointer ++;
//					polygonTexturesIndexPointer ++;
//					polygonNormalsIndexPointer ++;
//				}
//				
//
//			}
//		}
//		else if(s == "vn")
//		{
//			normalsSum ++;
//			fin >> normals[normalsPointer] >> normals[normalsPointer+1] >> normals[normalsPointer+2];
//			normalsPointer += 3;
//		}
//		else if(s == "vt")
//		{
//			texturesSum ++;
//			fin >> textures[texturesPointer] >> textures[texturesPointer+1] >> textures[texturesPointer+2];
//			texturesPointer +=3;
//		}
//	}
//	fin.close();
//}
//
//void Obj3dmodel::draw()
//{
//	if(polygonSum != 0)
//	{
//		for (int i = 0; i < polygonSum; i++)
//		{
//			glColor3fv(&color[(i*3)%12]);
//			/*glColor3f(0.0,0.0,1.0);*/
//			glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, &polygonVerticesIndex[i * 4]);
//		}
//	}
//
//	if(triangleSum != 0)
//	{
//		for (int i = 0; i < triangleSum; i++)
//		{
//			glColor3fv(&color[((polygonSum+i)*3)%12]);
//			/*glColor3f(0.0,0.0,1.0);*/
//			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &triangleVerticesIndex[i * 3]);
//		}
//	}		
//}