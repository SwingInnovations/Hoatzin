#ifndef VERTEX_H_
#define VERTEX_H_

#include "Math/Vector.h"

class Vector3f;
class Vector2f;

class Vertex2D_UV{
public:
	Vertex2D_UV(const Vector3f& vert, const Vector2f& tex){
		this->vertices = vert;
		this->texCoord = tex;
	}

	Vector3f* GetVertices(){ return &this->vertices; }
	Vector2f* GetTexCoord(){ return &this->texCoord; }

private:
	Vector3f vertices;
	Vector2f texCoord;
};

class Vertex2D{
public:
	Vertex2D(const Vector3f& vert){
		vertices = vert;
	}

private:
	Vector3f vertices;
};

#endif /* VERTEX_H_ */
