#ifndef OPENGEXMESH_H_
#define OPENGEXMESH_H_

#include <vector>
#include <string.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Math/Vector.h"
#include "Vertex.h"
#include "Transform.h"

/*
 * Manages loading OpenGEX based files.
 * */

class OpenGEXMesh {
public:
	OpenGEXMesh();
	OpenGEXMesh(const std::string& fileName);
	virtual ~OpenGEXMesh();

	Vertex* getVertices(){ return &m_Verticies[0]; }
	int* getIndices(){ return &m_Indices[0]; }

private:
	std::vector<Vertex> m_Verticies;
	std::vector<Vector3f> m_Vertex;
	std::vector<Vector2f> m_TexCoord;
	std::vector<Vector3f> m_Normal;
	Transform m_Transform;
	std::string m_ObjName;
	std::vector<int> m_Indices;
};

#endif /* OPENGEXMESH_H_ */
