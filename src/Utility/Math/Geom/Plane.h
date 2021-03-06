#ifndef PLANE_H_
#define PLANE_H_

#include "Shape.h"
#include "../Vector.h"

class Plane : public Shape{
public:
	Plane(){

	}

	Plane(int width, int height, int depthPos){
		int centerWidth = width/2;
		int centerHeight = height/2;

		mVertices.reserve(4);
		mVertices.push_back(Vertex(Vector3f(centerWidth - centerWidth, centerHeight + centerHeight, depthPos), Vector2f(1.0, 0.0), Vector3f(0.0f, 1.0f, 0.0f)));
		mVertices.push_back(Vertex(Vector3f(centerWidth + centerWidth, centerHeight + centerHeight, depthPos), Vector2f(1.0, 1.0), Vector3f(0.0f, 1.0f, 0.0f)));
		mVertices.push_back(Vertex(Vector3f(centerWidth + centerWidth, centerHeight - centerHeight, depthPos), Vector2f(0.0, 1.0), Vector3f(0.0f, 1.0f, 0.0f)));
		mVertices.push_back(Vertex(Vector3f(centerWidth - centerWidth, centerHeight - centerHeight, depthPos), Vector2f(0.0, 0.0), Vector3f(0.0f, 1.0f, 0.0f)));

		mIndicies.reserve(6);
		mIndicies.push_back(0);
		mIndicies.push_back(1);
		mIndicies.push_back(2);
		mIndicies.push_back(3);
		mIndicies.push_back(2);
		mIndicies.push_back(0);

		mVerticesSize = 4;
		mIndicesSize = 6;
	}

	Plane(int width, int height){
		int centerWidth = width/2;
		int centerHeight = height/2;

		mVertices.reserve(4);
		mVertices.push_back(Vertex(Vector3f(centerWidth - centerWidth, centerHeight + centerHeight, 0.0), Vector2f(1.0, 0.0), Vector3f(0.0f, 1.0f, 0.0f)));
		mVertices.push_back(Vertex(Vector3f(centerWidth + centerWidth, centerHeight + centerHeight, 0.0), Vector2f(1.0, 1.0), Vector3f(0.0f, 1.0f, 0.0f)));
		mVertices.push_back(Vertex(Vector3f(centerWidth + centerWidth, centerHeight - centerHeight, 0.0), Vector2f(0.0, 1.0), Vector3f(0.0f, 1.0f, 0.0f)));
		mVertices.push_back(Vertex(Vector3f(centerWidth - centerWidth, centerHeight - centerHeight, 0.0), Vector2f(0.0, 0.0), Vector3f(0.0f, 1.0f, 0.0f)));

		mIndicies.reserve(6);
		mIndicies.push_back(0);
		mIndicies.push_back(1);
		mIndicies.push_back(2);
		mIndicies.push_back(3);
		mIndicies.push_back(2);
		mIndicies.push_back(0);

		mVerticesSize = 4;
		mIndicesSize = 6;
	}

	Plane(double width, double height){
			double centerWidth = width/2.0;
			double centerHeight = height/2.0;

			mVertices.reserve(4);
			mVertices.push_back(Vertex(Vector3f(centerWidth - centerWidth, centerHeight + centerHeight, 0.0), Vector2f(0.0, 0.0)));
			mVertices.push_back(Vertex(Vector3f(centerWidth + centerWidth, centerHeight + centerHeight, 0.0), Vector2f(0.0, 1.0)));
			mVertices.push_back(Vertex(Vector3f(centerWidth + centerWidth, centerHeight - centerHeight, 0.0), Vector2f(1.0, 1.0)));
			mVertices.push_back(Vertex(Vector3f(centerWidth - centerWidth, centerHeight - centerHeight, 0.0), Vector2f(1.0, 0.0)));

			mIndicies.reserve(6);
			mIndicies.push_back(0);
			mIndicies.push_back(1);
			mIndicies.push_back(2);
			mIndicies.push_back(3);
			mIndicies.push_back(2);
			mIndicies.push_back(0);

			mVerticesSize = 4;
			mIndicesSize = 6;

			std::cout << "Num of Vertices: " << centerWidth << std::endl;
			std::cout << "Num of Indicies: " << centerHeight << std::endl;
	}

	Plane(int x, int y, int width, int height){
		int centerWidth = width/2;
		int centerHeight = height/2;

		mVertices.reserve(4);
		mVertices.push_back(Vertex(Vector3f(x - centerWidth, y + centerHeight, 0.0), Vector2f(0.0, 0.0)));
		mVertices.push_back(Vertex(Vector3f(x + centerWidth, y + centerHeight, 0.0), Vector2f(0.0, 1.0)));
		mVertices.push_back(Vertex(Vector3f(x + centerWidth, y - centerHeight, 0.0), Vector2f(1.0, 1.0)));
		mVertices.push_back(Vertex(Vector3f(x - centerWidth, y - centerHeight, 0.0), Vector2f(1.0, 0.0)));

		mIndicies.reserve(6);
		mIndicies.push_back(0);
		mIndicies.push_back(1);
		mIndicies.push_back(2);
		mIndicies.push_back(2);
		mIndicies.push_back(3);
		mIndicies.push_back(0);

		mVerticesSize = 4;
		mIndicesSize = 6;
//
//		mVerticesSize = sizeof(mVertices)/sizeof(mVertices[0]);
//		mIndicesSize = sizeof(mIndicies)/sizeof(mIndicies[0]);
	}

	void SetTransform(Transform& t){mTransform = t;}
	int* GetIndicies(){
		int* ret = &mIndicies[0];
		return ret;
	}

	Vector2f topLeft(){
		Vector3f vert = mVertices.at(0).getVertex();
		return Vector2f(vert.getX(), vert.getY());
	}

	Vector2f topRight(){
		Vector3f vert = mVertices.at(1).getVertex();
		return Vector2f(vert.getX(), vert.getY());
	}

	Vertex* getVerticies(){
		Vertex* ret = &mVertices[0];
		return ret;
	}
	int GetVerticiesSize(){return mVerticesSize;}
	int getIndiciesSize(){return mIndicesSize;}
	virtual ~Plane(){

	}
	int mIndicesSize;
	int mVerticesSize;
	Transform mTransform;
	std::vector<Vertex> mVertices;
	std::vector<int> mIndicies;
};



#endif /* PLANE_H_ */
