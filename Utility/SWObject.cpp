#include "SWObject.h"

SWObject::SWObject(){
	mesh = 0;
	shader = 0;
	tex = 0;
	transform = new Transform();
	hasChildren = false;
}

SWObject::SWObject(Mesh* mesh, Shader* shader, Texture* texture){
	transform = new Transform();
	this->mesh = mesh;
	std::cout << "Assigned mesh" << std::endl;
	this->shader = shader;
	std::cout << "Assigned shader" << std::endl;
	this->tex = texture;
	std::cout << "Assigned Texture" << std::endl;
	hasChildren = false;
}


