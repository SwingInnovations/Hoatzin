/*
 * SWPhysics.cpp
 *
 *  Created on: Mar 27, 2015
 *      Author: Nathan_z400
 */

#include "SWPhysics.h"

SWPhysics::SWPhysics() {
	// TODO Auto-generated constructor stub

}

SWPhysics::~SWPhysics() {
	// TODO Auto-generated destructor stub
}

Transform SWPhysics::toSWTransform(btTransform& o){
	Transform ret;
	Vector3f trans(o.getOrigin().getX(), o.getOrigin().getY(), o.getOrigin().getZ());
	Vector3f rot(o.getRotation().getX(), o.getRotation().getY(), o.getOrigin().getZ());
	Vector3f scal(1);
	ret.setTranslate(trans);
	ret.setRotate(rot);
	ret.setScale(scal);
	return ret;
}

btTransform SWPhysics::toBtTransform(Transform& o){
	btTransform ret;
	btVector3 trans(o.getTranslate().getX(), o.getTranslate().getY(), o.getTranslate().getZ());
	btQuaternion rot(o.getRotate().getX(), o.getRotate().getY(), o.getRotate().getZ(), 1.0);
	ret.setOrigin(trans);
	ret.setRotation(rot);
	return ret;
}

