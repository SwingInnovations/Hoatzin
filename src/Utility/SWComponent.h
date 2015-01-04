#ifndef SWCOMPONENT_H_
#define SWCOMPONENT_H_

#pragma once

#include <vector>
#include <string>
#include "../Graphics/Shader.h"

class Vector3f;
class Vector4f;
class Camera;


class SWComponent{
public:
	SWComponent(){
		transform = new Transform();
		shader = 0;
		hasChildren = false;
	}
	virtual ~SWComponent(){
		delete transform;
		delete shader;
	}
	void addUniform(const std::string& name, int value);
	void addUniform(const std::string& name, float value);
	void addUniform(const std::string& name, Vector3f& value);
	void addUniform(const std::string& name, Vector4f& value);
	void setUniform(const std::string& name, int value);
	void setUniform(const std::string& name, float value);
	void setUniform(const std::string& name, Vector3f& value);
	void setUniform(const std::string& name, Vector4f& value);

	void setTranslate(Vector3f& vec){
		transform->setTranslate(vec);
		if(hasChildren){
			for(unsigned int i = 0; i < children.size(); i++){
				children[i]->setTranslate(vec);
			}
		}
	}

	void setTranslateX(float _x){
		transform->setTranslateX(_x);
		if(hasChildren){
			for(unsigned int i = 0; i < children.size(); i++){
				children[i]->setTranslateX(_x);
			}
		}
	}

	void setTranslateY(float _y){
		transform->setTranslateY(_y);
		if(hasChildren){
			for(unsigned int i = 0; i < children.size(); i++){
				children[i]->setTranslateY(_y);
			}
		}
	}

	void setTranslateZ(float _z){
		transform->setTranslateZ(_z);
		if(hasChildren){
			for(unsigned int i = 0; i < children.size(); i++){
				children[i]->setTranslateZ(_z);
			}
		}
	}

	void setRotate(Vector3f& vec){
		transform->setRotate(vec);
		if(hasChildren){
			for(unsigned int i = 0; i < children.size(); i++){
				children[i]->setRotate(vec);
			}
		}
	}

	void setRotateX(float _x){
		transform->setRotateX(_x);
		if(hasChildren){
			for(unsigned int i = 0; i < children.size(); i++){
				children[i]->setRotateX(_x);
			}
		}
	}

	void setRotateY(float _y){
		transform->setRotateY(_y);
		if(hasChildren){
			for(unsigned int i = 0; i < children.size(); i++){
				children[i]->setRotateY(_y);
			}
		}
	}

	void setRotateZ(float _z){
		transform->setRotateZ(_z);
		for(unsigned int i = 0; i < children.size(); i++){
			children[i]->setRotateZ(_z);
		}
	}

	void setScale(Vector3f& vec){
		transform->setScale(vec);
		for(unsigned int i = 0; i < children.size(); i++){
			children[i]->setScale(vec);
		}
	}

	void setScaleX(float _x){
		transform->setScaleX(_x);
		for(unsigned int i = 0; i < children.size(); i++){
			children[i]->setScaleX(_x);
		}
	}

	void setScaleY(float _y){
		transform->setScaleY(_y);
		for(unsigned int i = 0; i < children.size(); i++){
			children[i]->setScaleY(_y);
		}
	}

	void setScaleZ(float _z){
		transform->setScaleY(_z);
		for(unsigned int i = 0; i < children.size(); i++){
			children[i]->setScaleY(_z);
		}
	}

	void addChild(SWComponent* child){hasChildren = true; children.push_back(child);}
	SWComponent* getChild(int i){return children.at(i);}

	virtual void draw(Camera* cam){}

	Transform* transform;
	Shader* shader;
	std::vector<SWComponent*> children;
	std::vector<SWShader::ShaderInfo> uniforms;
	bool hasChildren;
};


#endif