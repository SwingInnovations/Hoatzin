#ifndef SHAPE_H_
#define SHAPE_H_

#include "../../Transform.h"
#include "../../Vertex.h"

class Shape{
public:
	virtual ~Shape(){}
	virtual void setVerticies(Vertex* vertices){}
	virtual void setTransform(Transform& t){}
	virtual bool intersects(Shape& other){return false;}
	virtual bool contains(Shape& other){return false;}
	virtual bool hasIntersected(Shape& other){return 0;}
	virtual int getVerticiesSize(){return 0;}
	virtual int getIndiciesSize(){return 0;}
	virtual Transform getTransform(){ return Transform();}
	virtual Vertex* getVerticies(){return 0;}
	virtual int* getIndicies(){return 0;}
};



#endif /* SHAPE_H_ */
