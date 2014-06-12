#ifndef SWOBJECT_H_
#define SWOBJECT_H_

#include "Math/Vector.h"
#include "Transform.h"

class SWObject{
public:
	SWObject(){}
	virtual ~SWObject(){}
	Vector3f *Position(){return &this->position;}
	Vector3f position;
	Transform transform;
};



#endif /* SWOBJECT_H_ */
