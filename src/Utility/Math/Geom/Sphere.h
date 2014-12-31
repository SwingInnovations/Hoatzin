#ifndef SPHERE_H_
#define SPHERE_H_

#include "Shape.h"
#include "../../Vertex.h"

class Sphere : public Shape{
public:
	Sphere(){
		mIndiciesSize = 0;
		mVerticiesSize = 0;
	}

	Sphere(unsigned int radius, unsigned int iteration){

	}

	Sphere(unsigned int xRadius, unsigned int yRadius, unsigned int iteration){

	}

	Sphere(Vector3f& pos, unsigned int radius, unsigned int iteration){

	}

	Sphere(Vector3f& pos, unsigned int xRadius, unsigned int yRadius, unsigned int iteration){

	}

	int* GetIndicies(){
		return &mIndicies[0];
	}

	Vertex* GetVerticies(){
		return &mVerticies[0];
	}

	void SetTransform(Transform& t){mTransform = t;}

private:
	int mIndiciesSize;
	int mVerticiesSize;
	Transform mTransform;
	std::vector<Vertex> mVerticies;
	std::vector<int> mIndicies;
};



#endif /* SPHERE_H_ */
