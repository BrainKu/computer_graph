//#include <iostream>
//using namespace std;
//
//struct HE_vert {
//	float x;
//	float y;
//	float z;
//	HE_edge* edge; //the start vertex
//};
//
//struct HE_edge {
//		HE_vert* vert; //vertex at the start of edge
//		HE_edge* pair; //oppositely edge
//		HE_face* face; //face the half-edge border
//		HE_edge* next; //next half edge
//		HE_edge* prev; //prev half edge
//	};
//
//	struct HE_face {
//		HE_edge* edge;//the edge face belong to
//	};
//
//
//	void readObjFileIntoHE(string filepath);
//
//	int main() {
//		cout << "hello" << endl;
//	}
