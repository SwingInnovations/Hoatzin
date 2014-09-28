#ifndef VERTEX_H_
#define VERTEX_H_

#include "Math/Vector.h"

class Vector3f;
class Vector2f;


class Vertex{
public:
	Vertex(const Vector3f& vert, const Vector2f& tex, const Vector3f& normal = Vector3f(0.0f, 0.0f, 0.0f)){
		this->vertex = vert;
		this->texCoord = tex;
		this->normal = normal;
	}

	void Print(){
		std::cout << "Vertex: ";
		vertex.Print();
		std::cout << "TexCoord: ";
		texCoord.Print();
		std::cout << "Normal: ";
		normal.Print();
	}

	Vector3f* GetVertices(){return &this->vertex;}
	Vector2f* GetTexCoord(){return &this->texCoord;}
	Vector3f* GetNormal(){return &this->normal;}

private:
	Vector3f vertex;
	Vector2f texCoord;
	Vector3f normal;
};

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
