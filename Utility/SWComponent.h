#ifndef SWCOMPONENT_H_
#define SWCOMPONENT_H_

#include <vector>
#include <string>

#include "Math/Vector.h"
#include "Transform.h"
#include "../Graphics/Shader.h"
#include "../Graphics/Texture.h"
//#include "../Graphics/Camera.h"
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
	void addUniform(const std::string& name, int value){
		uniforms.push_back(SWShader::ShaderInfo(name, SWShader::INT, SWShader::toString(value)));
	}
	void addUniform(const std::string& name, float value){
		uniforms.push_back(SWShader::ShaderInfo(name, SWShader::FLOAT, SWShader::toString(value)));
	}
	void addUniform(const std::string& name, Vector3f& value){
		uniforms.push_back(SWShader::ShaderInfo(name, SWShader::VEC3, SWShader::toString(value)));
	}
	void addUniform(const std::string& name, Vector4f& value){
		uniforms.push_back(SWShader::ShaderInfo(name, SWShader::VEC4, SWShader::toString(value)));
	}
	void setUniform(const std::string& name, int value){
		if(!uniforms.empty()){
			for(unsigned int i = 0; i < uniforms.size(); i++){
				if(uniforms[i].name == name){
					uniforms[i].value = SWShader::toString(value);
				}
			}
		}
	}

	void setUniform(const std::string& name, float value){
		if(!uniforms.empty()){
			for(unsigned int i = 0; i < uniforms.size(); i++){
				if(uniforms[i].name == name){
					uniforms[i].value = SWShader::toString(value);
				}
			}
		}
	}

	void setUniform(const std::string& name, Vector3f& value){
		if(!uniforms.empty()){
			for(unsigned int i = 0; i < uniforms.size(); i++){
				if(uniforms[i].name == name){
					uniforms[i].value = SWShader::toString(value);
				}
			}
		}
	}

	void setUniform(const std::string& name, Vector4f& value){
		if(!uniforms.empty()){
			for(unsigned int i = 0; i < uniforms.size(); i++){
				if(uniforms[i].name == name){
					uniforms[i].value = SWShader::toString(value);
				}
			}
		}
	}

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
	virtual void draw(Camera& cam){;}
	virtual void draw(){;}

	Transform* transform;
	Shader* shader;
	std::vector<SWComponent*> children;
	std::vector<SWShader::ShaderInfo> uniforms;
	bool hasChildren;
};


#endif
