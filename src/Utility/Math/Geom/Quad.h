#ifndef QUAD_H_
#define QUAD_H_

#include "Shape.h"
#include "../Vector.h"


class Quad : public Shape{
public:
	Quad(){}
	Quad(int width, int height){
		int halfWidth = width/2;
		int halfHeight = height/2;

		mVertices.reserve(4);
		mVertices.push_back(Vertex(Vector3f(-halfWidth, -halfHeight, 0.0f), Vector2f(0.0f, 0.0f)));
		mVertices.push_back(Vertex(Vector3f(halfWidth, -halfHeight, 0.0f), Vector2f(1.0f, 0.0f)));
		mVertices.push_back(Vertex(Vector3f(halfWidth, halfHeight, 0.0f), Vector2f(1.0f, 1.0f)));
		mVertices.push_back(Vertex(Vector3f(-halfWidth, halfHeight, 0.0), Vector2f(0.0f, 1.0f)));

		mIndices.reserve(6);
		mIndices.push_back(0);
		mIndices.push_back(1);
		mIndices.push_back(2);
		mIndices.push_back(2);
		mIndices.push_back(3);
		mIndices.push_back(0);

		mVerticesSize = mVertices.size();
		mIndicesSize = mIndices.size();
	}

	int* GetIndices(){
		int *ret = &mIndices[0];
		return ret;
	}

	Vertex* getVertices(){
		Vertex* ret = &mVertices[0];
		return ret;
	}

	int mIndicesSize;
	int mVerticesSize;
	Transform mTransform;
	std::vector<Vertex> mVertices;
	std::vector<int> mIndices;
};


#endif /* QUAD_H_ */
