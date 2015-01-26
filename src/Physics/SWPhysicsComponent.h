
#ifndef SWPHYSICSCOMPONENT_H_
#define SWPHYSICSCOMPONENT_H_

#include "../STechOne.h"

class SWPhysicsComponent : public SWComponent {

public:
	SWPhysicsComponent();

	virtual void update(){

	}

	void setBoundaries(){

	}

	bool isIntersected(SWPhysicsComponent* other){
		return false;
	}

	void setTransform(Transform* transform){
		this->transform = transform;
	}

	virtual ~SWPhysicsComponent();

private:

};

#endif /* SWPHYSICSCOMPONENT_H_ */
