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
	transform = new Transform();
	setType("Object");
}

SWGameObject::SWGameObject(Mesh* mesh, SWMaterial* mat){
	this->mesh = mesh;
	this->mat = mat;
	shader = mat->getShader();
	transform = new Transform();
	setType("Object");
}

SWGameObject::~SWGameObject() {
	delete mesh;
	delete mat;
	delete shader;
	delete transform;
}

