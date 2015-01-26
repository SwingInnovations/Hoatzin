#ifndef SWGAMEOBJECT_H_
#define SWGAMEOBJECT_H_

#include <vector>
#include <string>

#include "../STechOne.h"

class SWGameObject : public SWComponent{
public:
	SWGameObject();

	SWGameObject(Mesh* mesh, SWMaterial* mat);

	virtual void update(){

	}

	void addPhysicsComponent(SWPhysicsComponent* comp){
		elements.push_back(comp);
	}

	void setMesh(Mesh* mesh){
		this->mesh = mesh;
	}
	void setShader(Shader* shdr){
		shader = shdr;
		mat->setShader(shdr);
	}
	void setMaterial(SWMaterial* mat){
		if(mat->getShader() != 0){
			this->mat = mat;
			shader = mat->getShader();
		}else{
			this->mat = mat;
			this->mat->setShader(shader);
		}
	}

	void draw(Camera* cam){
		updateUniforms();
		shader->update(*transform, *cam);
		shader->bind();
		mat->bind();
		mesh->draw();
		if(hasChildren){
			for(unsigned int i = 0; i < children.size(); i++){
				children.at(i)->draw(cam);
			}
		}
	}

	virtual ~SWGameObject();
private:
	Mesh* mesh;
	SWMaterial* mat;
};

#endif /* SWGAMEOBJECT_H_ */
