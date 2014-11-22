#ifndef OBJMESH_H_
#define OBJMESH_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Math/Vector.h"
#include "Vertex.h"

class OBJMesh {
public:
	OBJMesh();
	OBJMesh(const std::string& fileName);
	virtual ~OBJMesh();

	Vertex* getVertices(){
		return &verticies[0];
	}

	int* getIndicies(){
		int* ret = &index[0];
		return ret;
	}

	int getVerticiesSize(){return verticies.size();}
	int getIndiciesSize(){return index.size();}
	std::vector<int> index;
	std::vector<Vertex> verticies;
private:
	std::vector<Vector3f> vertex;
	std::vector<Vector2f> texCoord;
	std::vector<Vector3f> normal;
	std::vector<int> indicies;

};

#endif /* OBJMESH_H_ */
