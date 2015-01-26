/*
 * SWGameObject.cpp
 *
 *  Created on: Jan 25, 2015
 *      Author: Nathan_z400
 */

#include "SWGameObject.h"

SWGameObject::SWGameObject() {
	// TODO Auto-generated constructor stub
	mesh = 0;
	mat = 0;
}

SWGameObject::SWGameObject(Mesh* mesh, SWMaterial* mat){
	this->mesh = mesh;
	this->mat = mat;
	this->shader = mat->getShader();
}

SWGameObject::~SWGameObject() {
	// TODO Auto-generated destructor stub
}

