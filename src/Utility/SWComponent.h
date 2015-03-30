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

	virtual void update() = 0;
	void addComponent(SWComponent* comp){
		elements.push_back(comp);
	}
	void updateComponentElements(){
		if(!elements.empty()){
			for(unsigned int i = 0; i < elements.size(); i++){
				elements.at(i)->update();
			}
		}
	}

	void updateUniforms(){
		if(!uniforms.empty()){
			for(unsigned int i = 0; i < uniforms.size(); i++){
				if(uniforms.at(i).type == SWShader::INT){
					shader->update(uniforms.at(i).name, SWShader::toInt(uniforms.at(i).value));
				}else if(uniforms.at(i).type == SWShader::FLOAT){
					shader->update(uniforms.at(i).name, SWShader::toFloat(uniforms.at(i).value));
				}else if(uniforms.at(i).type == SWShader::VEC3){
					shader->update(uniforms.at(i).name, SWShader::toVector3f(uniforms.at(i).value));
				}else if(uniforms.at(i).type == SWShader::VEC4){
					shader->update(uniforms.at(i).name, SWShader::toVector4f(uniforms.at(i).value));
				}else{
					std::cout << "No Uniform present" << std::endl;
				}
			}
		}
	}
	void addUniform(const std::string& name, int value);
	void addUniform(const std::string& name, float value);
	void addUniform(const std::string& name, Vector3f& value);
	void addUniform(const std::string& name, Vector4f& value);
	void setUniform(const std::string& name, int value);
	void setUniform(const std::string& name, float value);
	void setUniform(const std::string& name, Vector3f& value);
	void setUniform(const std::string& name, Vector4f& value);

	void setType(char* t){ m_Type = std::string(t); }
	std::string getType(){ return m_Type; }

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

	Transform* getTransform(){return transform;}

	void addChild(SWComponent* child){hasChildren = true; children.push_back(child);}
	SWComponent* getChild(int i){return children.at(i);}

	virtual void draw(Camera* cam){}

	Transform* transform;
	Shader* shader;
	std::vector<SWComponent*> elements;
	std::vector<SWComponent*> children;
	std::vector<SWShader::ShaderInfo> uniforms;
	std::string m_Type;
	bool hasChildren;
};


#endif
