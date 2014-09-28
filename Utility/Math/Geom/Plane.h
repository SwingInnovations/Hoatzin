#ifndef PLANE_H_
#define PLANE_H_

#include "Shape.h"
#include "../Vector.h"

class Plane : public Shape{
public:
	Plane(){

	}

	Plane(int width, int height){
		int centerWidth = width/2;
		int centerHeight = height/2;

		mVertices.reserve(4);
		mVertices.push_back(Vertex(Vector3f(centerWidth - centerWidth, centerHeight + centerHeight, 0.0), Vector2f(0.0, 0.0)));
		mVertices.push_back(Vertex(Vector3f(centerWidth + centerWidth, centerHeight + centerHeight, 0.0), Vector2f(0.0, 1.0)));
		mVertices.push_back(Vertex(Vector3f(centerWidth + centerWidth, centerHeight - centerHeight, 0.0), Vector2f(1.0, 0.0)));
		mVertices.push_back(Vertex(Vector3f(centerWidth - centerWidth, centerHeight - centerHeight, 0.0), Vector2f(1.0, 1.0)));

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
		mIndicies.push_back(3);
		mIndicies.push_back(2);
		mIndicies.push_back(0);

		mVerticesSize = sizeof(mVertices)/sizeof(mVertices[0]);
		mIndicesSize = sizeof(mIndicies)/sizeof(mIndicies[0]);
	}

	//void SetVertices(Vertex* vertices){ mVertices = vertices; mVerticesSize = (sizeof(mVertices)/sizeof(mVertices[0]));}
	void SetTransform(Transform& t){mTransform = t;}
	int* GetIndicies(){
		int* ret = &mIndicies[0];
		return ret;
	}
	Vertex* GetVertices(){
		Vertex* ret = &mVertices[0];
		return ret;
	}
	int GetVerticiesSize(){return mVerticesSize;}
	int GetIndiciesSize(){return mIndicesSize;}
	virtual ~Plane(){

	}
	int mIndicesSize;
	int mVerticesSize;
	Transform mTransform;
	std::vector<Vertex> mVertices;
	std::vector<int> mIndicies;
};



#endif /* PLANE_H_ */
