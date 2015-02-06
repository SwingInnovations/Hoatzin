#ifndef VERTEX_H_
#define VERTEX_H_

#include "Math/Vector.h"
#include "../Graphics/Color.h"

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

	Vertex(const Vector3f& vert, int color, const Vector3f& normal = Vector3f(0.0f, 0.0f, 0.0f)){
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

	void setColor(int id){
		color = determineColor(id);
	}

	void setColor(Vector4f& vec){
		color = Vector4f(COLOR::assertCol(vec.getX()),
						 COLOR::assertCol(vec.getY()),
						 COLOR::assertCol(vec.getZ()),
						 COLOR::assertCol(vec.getW()));
	}

	void setAlpha(float val){
		color.setW(COLOR::assertCol(val));
	}

	Vector3f* getVerticies(){return &vertex;}
	Vector2f* getTexCoord(){return &texCoord;}
	Vector3f* getNormal(){return &normal;}
	Vector4f* getColor(){return &color;}
	Vector3f getVertex()const{return vertex;}
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
			ret = Vector4f(1.0f, 1.0f, 1.0f, 1.0f);
			break;
		default:
			ret = Vector4f(1.0f, 1.0f, 1.0f, 1.0f);
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
