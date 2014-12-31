#ifndef BOX_H_
#define BOX_H_

#include "Shape.h"
#include "../Vector.h"

class Transform;

class Box : public Shape{
public:
	Box(){}

	Box(int width, int height, int depth){
		int centerWidth = width/2;
		int centerHeight = height/2;
		int centerDepth = depth/2;

		mVertices.reserve(8);
		mVertices.push_back(Vertex(Vector3f(centerWidth-centerWidth, centerHeight-centerHeight, centerDepth-centerDepth), Vector2f(0.25f, 0.0f)));
		mVertices.push_back(Vertex(Vector3f(centerWidth+centerWidth, centerHeight-centerHeight, centerDepth-centerDepth), Vector2f(0.75f, 0.0f)));
		mVertices.push_back(Vertex(Vector3f(centerWidth-centerWidth, centerHeight+centerHeight, centerDepth-centerDepth), Vector2f(0.25f, 0.25f)));
		mVertices.push_back(Vertex(Vector3f(centerWidth+centerWidth, centerHeight+centerHeight, centerDepth-centerDepth), Vector2f(0.75f, 0.25f)));
		mVertices.push_back(Vertex(Vector3f(centerWidth-centerWidth, centerHeight+centerHeight, centerDepth+centerDepth), Vector2f(0.25f, 0.50f)));
		mVertices.push_back(Vertex(Vector3f(centerWidth+centerWidth, centerHeight+centerHeight, centerDepth+centerDepth), Vector2f(0.75f, 0.50f)));
		mVertices.push_back(Vertex(Vector3f(centerWidth-centerWidth, centerHeight-centerHeight, centerDepth+centerDepth), Vector2f(0.25f, 0.75f)));
		mVertices.push_back(Vertex(Vector3f(centerWidth+centerWidth, centerHeight-centerHeight, centerDepth+centerDepth), Vector2f(0.75f, 0.25f)));

		mIndicies.reserve(36);
		mIndicies.push_back(0);
		mIndicies.push_back(1);
		mIndicies.push_back(2);
		mIndicies.push_back(2);
		mIndicies.push_back(3);
		mIndicies.push_back(1);
		mIndicies.push_back(2);
		mIndicies.push_back(4);
		mIndicies.push_back(5);
		mIndicies.push_back(5);
		mIndicies.push_back(3);
		mIndicies.push_back(2);
		mIndicies.push_back(4);
		mIndicies.push_back(6);
		mIndicies.push_back(7);
		mIndicies.push_back(7);
		mIndicies.push_back(5);
		mIndicies.push_back(4);
		mIndicies.push_back(6);
		mIndicies.push_back(0);
		mIndicies.push_back(7);
		mIndicies.push_back(7);
		mIndicies.push_back(1);
		mIndicies.push_back(0);
		mIndicies.push_back(0);
		mIndicies.push_back(2);
		mIndicies.push_back(4);
		mIndicies.push_back(4);
		mIndicies.push_back(6);
		mIndicies.push_back(0);
		mIndicies.push_back(1);
		mIndicies.push_back(3);
		mIndicies.push_back(5);
		mIndicies.push_back(5);
		mIndicies.push_back(7);
		mIndicies.push_back(1);
		mVerticesSize = 8;
		mIndiciesSize = 36;
	}

	Box(int posX, int posY, int posZ, int width, int height, int depth){
		int centerWidth = width/2;
		int centerHeight = height/2;
		int centerDepth = depth/2;

		mVertices.reserve(8);
		mVertices.push_back(Vertex(Vector3f(posX-centerWidth, posY-centerHeight, posZ-centerDepth), Vector2f(0.25f, 0.0f)));
		mVertices.push_back(Vertex(Vector3f(posX+centerWidth, posY-centerHeight, posZ-centerDepth), Vector2f(0.75f, 0.0f)));
		mVertices.push_back(Vertex(Vector3f(posX-centerWidth, posY+centerHeight, posZ-centerDepth), Vector2f(0.25f, 0.25f)));
		mVertices.push_back(Vertex(Vector3f(posX+centerWidth, posY+centerHeight, posZ-centerDepth), Vector2f(0.75f, 0.25f)));
		mVertices.push_back(Vertex(Vector3f(posX-centerWidth, posY+centerHeight, posZ+centerDepth), Vector2f(0.25f, 0.50f)));
		mVertices.push_back(Vertex(Vector3f(posX+centerWidth, posY+centerHeight, posZ+centerDepth), Vector2f(0.75f, 0.50f)));
		mVertices.push_back(Vertex(Vector3f(posX-centerWidth, posY-centerHeight, posZ+centerDepth), Vector2f(0.25f, 0.75f)));
		mVertices.push_back(Vertex(Vector3f(posX+centerWidth, posY-centerHeight, posZ+centerDepth), Vector2f(0.75f, 0.25f)));

		mIndicies.reserve(36);
		mIndicies.push_back(0);
		mIndicies.push_back(1);
		mIndicies.push_back(2);
		mIndicies.push_back(2);
		mIndicies.push_back(3);
		mIndicies.push_back(1);
		mIndicies.push_back(2);
		mIndicies.push_back(4);
		mIndicies.push_back(5);
		mIndicies.push_back(5);
		mIndicies.push_back(3);
		mIndicies.push_back(2);
		mIndicies.push_back(4);
		mIndicies.push_back(6);
		mIndicies.push_back(7);
		mIndicies.push_back(7);
		mIndicies.push_back(5);
		mIndicies.push_back(4);
		mIndicies.push_back(6);
		mIndicies.push_back(0);
		mIndicies.push_back(7);
		mIndicies.push_back(7);
		mIndicies.push_back(1);
		mIndicies.push_back(0);
		mIndicies.push_back(0);
		mIndicies.push_back(2);
		mIndicies.push_back(4);
		mIndicies.push_back(4);
		mIndicies.push_back(6);
		mIndicies.push_back(0);
		mIndicies.push_back(1);
		mIndicies.push_back(3);
		mIndicies.push_back(5);
		mIndicies.push_back(5);
		mIndicies.push_back(7);
		mIndicies.push_back(1);
		mVerticesSize = 8;
		mIndiciesSize = 36;
	}

	Box(Vector3f& pos, int width, int height, int depth){
		int posX = (int)pos.getX();
		int posY = (int)pos.getY();
		int posZ = (int)pos.getZ();
		int centerWidth = width/2;
		int centerHeight = height/2;
		int centerDepth = depth/2;

		mVertices.reserve(8);
		mVertices.push_back(Vertex(Vector3f(posX-centerWidth, posY-centerHeight, posZ-centerDepth), Vector2f(0.25f, 0.0f)));
		mVertices.push_back(Vertex(Vector3f(posX+centerWidth, posY-centerHeight, posZ-centerDepth), Vector2f(0.75f, 0.0f)));
		mVertices.push_back(Vertex(Vector3f(posX-centerWidth, posY+centerHeight, posZ-centerDepth), Vector2f(0.25f, 0.25f)));
		mVertices.push_back(Vertex(Vector3f(posX+centerWidth, posY+centerHeight, posZ-centerDepth), Vector2f(0.75f, 0.25f)));
		mVertices.push_back(Vertex(Vector3f(posX-centerWidth, posY+centerHeight, posZ+centerDepth), Vector2f(0.25f, 0.50f)));
		mVertices.push_back(Vertex(Vector3f(posX+centerWidth, posY+centerHeight, posZ+centerDepth), Vector2f(0.75f, 0.50f)));
		mVertices.push_back(Vertex(Vector3f(posX-centerWidth, posY-centerHeight, posZ+centerDepth), Vector2f(0.25f, 0.75f)));
		mVertices.push_back(Vertex(Vector3f(posX+centerWidth, posY-centerHeight, posZ+centerDepth), Vector2f(0.75f, 0.25f)));

		mIndicies.reserve(36);
		mIndicies.push_back(0);
		mIndicies.push_back(1);
		mIndicies.push_back(2);
		mIndicies.push_back(2);
		mIndicies.push_back(3);
		mIndicies.push_back(1);
		mIndicies.push_back(2);
		mIndicies.push_back(4);
		mIndicies.push_back(5);
		mIndicies.push_back(5);
		mIndicies.push_back(3);
		mIndicies.push_back(2);
		mIndicies.push_back(4);
		mIndicies.push_back(6);
		mIndicies.push_back(7);
		mIndicies.push_back(7);
		mIndicies.push_back(5);
		mIndicies.push_back(4);
		mIndicies.push_back(6);
		mIndicies.push_back(0);
		mIndicies.push_back(7);
		mIndicies.push_back(7);
		mIndicies.push_back(1);
		mIndicies.push_back(0);
		mIndicies.push_back(0);
		mIndicies.push_back(2);
		mIndicies.push_back(4);
		mIndicies.push_back(4);
		mIndicies.push_back(6);
		mIndicies.push_back(0);
		mIndicies.push_back(1);
		mIndicies.push_back(3);
		mIndicies.push_back(5);
		mIndicies.push_back(5);
		mIndicies.push_back(7);
		mIndicies.push_back(1);

		mVerticesSize = 8;
		mIndiciesSize = 36;
	}

	int* getIndicies(){
		int* ret = &mIndicies[0];
		return ret;
	}
	Vertex* getVertices(){
		Vertex* ret = &mVertices[0];
		return ret;
	}

	void setTransform(Transform& t){mTransform = t;}
	int getVerticiesSize(){ return 8;}
	int getIndiciesSize(){return mIndiciesSize;}

	virtual ~Box(){

	}

	int mIndiciesSize;
	int mVerticesSize;
	Transform mTransform;
	std::vector<Vertex> mVertices;
	std::vector<int> mIndicies;

};



#endif /* BOX_H_ */
