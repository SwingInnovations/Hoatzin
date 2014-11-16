#ifndef VERTEX_H_
#define VERTEX_H_

#include "Math/Vector.h"

class Vector3f;
class Vector2f;


class Vertex{
public:
	Vertex(const Vector3f& vert, const Vector2f& tex, const Vector3f& normal = Vector3f(0.0f, 0.0f, 0.0f)){
		useTexture = true;
		useAlpha = false;
		this->vertex = vert;
		this->texCoord = tex;
		this->normal = normal;
	}

	Vertex(const Vector3f& vert, int color, const Vector2f& normal = Vector3f(0.0f, 0.0f, 0.0f)){
		useTexture = false;

	}

	void print(){
		std::cout << "Vertex: ";
		vertex.print();
		std::cout << "TexCoord: ";
		texCoord.print();
		std::cout << "Normal: ";
		normal.print();
	}

	Vector3f* getVerticies(){return &this->vertex;}
	Vector2f* getTexCoord(){return &this->texCoord;}
	Vector3f* getNormal(){return &this->normal;}
	Vector3f* getColor(){return &this->color;}
private:
	bool useTexture;
	bool useAlpha;
	Vector3f vertex;
	Vector2f texCoord;
	Vector3f normal;
	Vector4f color;
	Vector4f determineColor(int color)const{
		Vector4f ret;
		switch(color){
		case 0:
			ret = Vector3f(1.0f, 1.0f, 1.0f);
			break;
		default:
			ret = Vector3f(1.0f, 1.0f, 1.0f);
		}
		return ret;
	}
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
