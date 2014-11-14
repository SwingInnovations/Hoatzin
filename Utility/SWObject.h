#ifndef SWOBJECT_H_
#define SWOBJECT_H_

#include <vector>

#include "Math/Vector.h"
#include "Transform.h"
#include "Mesh.h"
#include "../Graphics/Shader.h"
#include "../Graphics/Texture.h"
#include "../Graphics/Graphics.h"

class Texture;
class Mesh;
class Shader;

class SWObject{
public:
	Vector3f *Position(){return &this->position;}
	Vector3f position;
	Transform* transform;
	Mesh* mesh;
	Shader* shader;
	Texture* tex;
	std::vector<SWObject*> children;
	bool hasChildren;

	SWObject();
	SWObject(Mesh* mesh, Shader* shader, Texture* texture);
	virtual ~SWObject(){}

	void addChild(SWObject* child){hasChildren = true; children.push_back(child);}
	SWObject* getChild(int i){return children.at(i);}

	void setTranslate(Vector3f& vec){
		if(!hasChildren){
			transform->setTranslate(vec);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->setTranslate(vec);
				children[i]->transform->setTranslate(vec);
			}
		}
	}
	void setTranslateX(float _x){
		if(!hasChildren){
			transform->setTranslateX(_x);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->setTranslateX(_x);
				children[i]->transform->setTranslateX(_x);
			}
		}
	}
	void setTranslateY(float _y){
		if(!hasChildren){
			transform->setTranslateY(_y);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->setTranslateY(_y);
				children[i]->transform->setTranslateY(_y);
			}
		}
	}
	void setTranslateZ(float _z){
		if(!hasChildren){
			transform->setTranslateZ(_z);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->setTranslateZ(_z);
				children[i]->transform->setTranslateZ(_z);
			}
		}
	}

	void setRotate(Vector3f& vec){
		if(!hasChildren){
			transform->setRotate(vec);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->setRotate(vec);
				children[i]->transform->setRotate(vec);
			}
		}
	}
	void setRotateX(float _x){
		if(!hasChildren){
			transform->setRotateX(_x);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->setRotateX(_x);
				children[i]->transform->setRotateX(_x);
			}
		}
	}
	void setRotateY(float _y){
		if(!hasChildren){
			transform->setRotateY(_y);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->setRotateY(_y);
				children[i]->transform->setRotateY(_y);
			}
		}
	}
	void setRotateZ(float _z){
		if(!hasChildren){
			transform->setRotateZ(_z);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->setRotateZ(_z);
				children[i]->transform->setRotateZ(_z);
			}
		}
	}

	void setScale(Vector3f& vec){
		if(!hasChildren){
			transform->setScale(vec);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->setScale(vec);
				children[i]->setScale(vec);
			}
		}
	}
	void setScaleX(float _x){
		if(!hasChildren){
			transform->setScaleX(_x);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->setScaleX(_x);
				children[i]->setScaleX(_x);
			}
		}
	}
	void setScaleY(float _y){
		if(!hasChildren){
			transform->setScaleY(_y);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->setScaleY(_y);
				children[i]->transform->setScaleY(_y);
			}
		}
	}
	void setScaleZ(float _z){
		if(!hasChildren){
			transform->setScaleZ(_z);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->setScaleZ(_z);
				children[i]->transform->setScaleZ(_z);
			}
		}
	}

	void draw(Camera& cam){
		shader->update(*transform, cam);
		shader->bind();
		tex->bind(0);
		mesh->draw();
		if(hasChildren){
			for(unsigned int i = 0; i < children.size(); i++){
				children[i]->draw(cam);
			}
		}
	}

	void draw(){
		shader->update(*transform);
		shader->bind();
		tex->bind(0);
		mesh->draw();
		if(hasChildren){
			for(unsigned int i = 0; i < children.size(); i++){
				children[i]->draw();
			}
		}
	}
};




#endif /* SWOBJECT_H_ */
