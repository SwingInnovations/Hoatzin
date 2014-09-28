#ifndef SHAPE_H_
#define SHAPE_H_

#include "../../Transform.h"
#include "../../Vertex.h"

class Shape{
public:
	virtual ~Shape(){}
	virtual void SetVertices(Vertex* vertices){}
	virtual void SetTransform(Transform& t){}
	virtual bool HasIntersected(Shape& other){return 0;}
	virtual int GetVerticiesSize(){return 0;}
	virtual int GetIndiciesSize(){return 0;}
	virtual Transform GetTransform(){}
	virtual Vertex* GetVertices(){return 0;}
	virtual int* GetIndicies(){return 0;}
};



#endif /* SHAPE_H_ */
