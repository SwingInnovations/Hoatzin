/*
 * SWPhysics.h
 *
 *  Created on: Mar 27, 2015
 *      Author: Nathan_z400
 */

#ifndef SWPHYSICS_H_
#define SWPHYSICS_H_

#include <btBulletCollisionCommon.h>
#include "../Utility/Transform.h"

class SWPhysics {
public:
	SWPhysics();
	virtual ~SWPhysics();
	static Transform toSWTransform(btTransform& o);
	static btTransform toBtTransform(Transform& o);
private:

};

#endif /* SWPHYSICS_H_ */
