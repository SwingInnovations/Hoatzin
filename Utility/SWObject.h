#ifndef SWOBJECT_H_
#define SWOBJECT_H_

#include <vector>
#include <string>

#include "Math/Vector.h"
#include "Transform.h"
#include "Mesh.h"
#include "SWComponent.h"
#include "../Graphics/Shader.h"
#include "../Graphics/Texture.h"
#include "../Graphics/Graphics.h"

class Texture;
class Mesh;
class SWComponent;
class Shader;

class SWObject : public SWComponent{
public:
	SWObject();
	SWObject(const SWObject* other);
	SWObject(Mesh* mesh, Shader* shader, Texture* texture);
//		this->mesh = mesh;
//		this->shader = shader;
//		this->tex = texture;
//		hasChildren = false;
//	}

	void draw(Camera& cam){
		if(!uniforms.empty()){
			for(unsigned int i = 0; i < uniforms.size(); i++){
				if(uniforms.at(i).type == SWShader::INT){
					shader->update(uniforms.at(i).name, SWShader::toInt(uniforms.at(i).value));
					std::cout << "Setting Int Uniform" << std::endl;
				}else if(uniforms.at(i).type == SWShader::FLOAT){
					shader->update(uniforms.at(i).name, SWShader::toFloat(uniforms.at(i).value));
					std::cout << "Setting Float Uniform" << std::endl;
				}else if(uniforms.at(i).type == SWShader::VEC3){
					shader->update(uniforms.at(i).name, SWShader::toVector3f(uniforms.at(i).value));
					std::cout << "Setting Vec3 Uniform" << std::endl;
				}else if(uniforms.at(i).type == SWShader::VEC4){
					shader->update(uniforms.at(i).name, SWShader::toVector4f(uniforms.at(i).value));
					std::cout << "Setting Vec4 Uniform" << std::endl;
				}else{
					std::cout << "No Uniform present" << std::endl;
				}
			}
			std::cout << "Some Uniforms" << std::endl;
		}
		shader->update(*this->transform, cam);
		shader->bind();
		tex->bind(0);
		mesh->draw();
		if(hasChildren){
			for(unsigned int i = 0; i  < this->children.size(); i++){
				children[i]->draw(cam);
			}
		}
	}

	void draw(){
			if(!uniforms.empty()){
				for(unsigned int i = 0; i < uniforms.size(); i++){
					if(uniforms.at(i).type == SWShader::INT){
						shader->update(uniforms.at(i).name, SWShader::toInt(uniforms.at(i).value));
						std::cout << "Setting Int Uniform" << std::endl;
					}else if(uniforms.at(i).type == SWShader::FLOAT){
						shader->update(uniforms.at(i).name, SWShader::toFloat(uniforms.at(i).value));
						std::cout << "Setting Float Uniform" << std::endl;
					}else if(uniforms.at(i).type == SWShader::VEC3){
						shader->update(uniforms.at(i).name, SWShader::toVector3f(uniforms.at(i).value));
						std::cout << "Setting Vec3 Uniform" << std::endl;
					}else if(uniforms.at(i).type == SWShader::VEC4){
						shader->update(uniforms.at(i).name, SWShader::toVector4f(uniforms.at(i).value));
						std::cout << "Setting Vec4 Uniform" << std::endl;
					}else{
						std::cout << "No Uniform present" << std::endl;
					}
				}
				std::cout << "Some Uniforms" << std::endl;
			}
			shader->update(*this->transform);
			shader->bind();
			tex->bind(0);
			mesh->draw();
			if(!this->children.empty()){
				for(unsigned int i = 0; i < this->children.size(); i++){
					this->children[i]->draw();
				}
			}
	}


	Mesh* mesh;
	Texture* tex;
};

//class SWComponent{
//public:
//	Vector3f *Position(){return &this->position;}
//	Vector3f position;
//	Transform* transform;
//	Mesh* mesh;
//	Shader* shader;
//	Texture* tex;
//	std::vector<SWComponent*> children;
//	std::vector<SWShader::ShaderInfo> shaderInfo;
//	bool hasChildren;
//
//	SWComponent();
//	SWComponent(const SWComponent* other);
//	SWComponent(Mesh* mesh, Shader* shader, Texture* texture);
//	virtual ~SWComponent(){
//		children.clear();
//		shaderInfo.clear();
//		delete mesh;
//		delete shader;
//		delete tex;
//		delete transform;
//		mesh = NULL;
//		shader = NULL;
//		tex = NULL;
//	}
//
//	void addChild(SWComponent* child){hasChildren = true; children.push_back(child);}
//	SWComponent* getChild(int i){return children.at(i);}
//
//	void addUniform(const std::string name, int value){
//		shaderInfo.push_back(SWShader::ShaderInfo(name, SWShader::INT, SWShader::toString(value)));
//	}
//
//	void addUniform(const std::string name, float value){
//		shaderInfo.push_back(SWShader::ShaderInfo(name, SWShader::FLOAT, SWShader::toString(value)));
//	}
//
//	void addUniform(const std::string name, Vector3f& value){
//		shaderInfo.push_back(SWShader::ShaderInfo(name, SWShader::VEC3, SWShader::toString(value)));
//	}
//
//	void addUniform(const std::string name, Vector4f& value){
//		shaderInfo.push_back(SWShader::ShaderInfo(name, SWShader::VEC4, SWShader::toString(value)));
//	}
//
//	void setUniform(const std::string name, int value){
//		if(!shaderInfo.empty()){
//			for(unsigned int i = 0; i < shaderInfo.size(); i++){
//				if(shaderInfo.at(i).name == name){
//					shaderInfo[i].value = SWShader::toString(value);
//				}
//			}
//		}
//	}
//
//	void setUniform(const std::string name, float value){
//		if(!shaderInfo.empty()){
//			for(unsigned int i = 0; i < shaderInfo.size(); i++){
//				if(shaderInfo.at(i).name == name){
//					shaderInfo[i].value = SWShader::toString(value);
//				}
//			}
//		}
//	}
//
//	void setUniform(const std::string name, Vector3f& value){
//		if(!shaderInfo.empty()){
//			for(unsigned int i = 0; i < shaderInfo.size(); i++){
//				if(shaderInfo.at(i).name == name){
//					shaderInfo[i].value = SWShader::toString(value);
//				}
//			}
//		}
//	}
//
//	void setUniform(const std::string name, Vector4f& value){
//		if(!shaderInfo.empty()){
//			for(unsigned int i = 0; i < shaderInfo.size(); i++){
//				if(shaderInfo.at(i).name == name){
//					shaderInfo[i].value = SWShader::toString(value);
//				}
//			}
//		}
//	}
//
//	void setTranslate(Vector3f& vec){
//		if(!hasChildren){
//			transform->setTranslate(vec);
//		}else{
//			for(unsigned int i = 0; i < children.size(); i++){
//				transform->setTranslate(vec);
//				children[i]->transform->setTranslate(vec);
//			}
//		}
//	}
//	void setTranslateX(float _x){
//		if(!hasChildren){
//			transform->setTranslateX(_x);
//		}else{
//			for(unsigned int i = 0; i < children.size(); i++){
//				transform->setTranslateX(_x);
//				children[i]->transform->setTranslateX(_x);
//			}
//		}
//	}
//	void setTranslateY(float _y){
//		if(!hasChildren){
//			transform->setTranslateY(_y);
//		}else{
//			for(unsigned int i = 0; i < children.size(); i++){
//				transform->setTranslateY(_y);
//				children[i]->transform->setTranslateY(_y);
//			}
//		}
//	}
//	void setTranslateZ(float _z){
//		if(!hasChildren){
//			transform->setTranslateZ(_z);
//		}else{
//			for(unsigned int i = 0; i < children.size(); i++){
//				transform->setTranslateZ(_z);
//				children[i]->transform->setTranslateZ(_z);
//			}
//		}
//	}
//
//	void setRotate(Vector3f& vec){
//		if(!hasChildren){
//			transform->setRotate(vec);
//		}else{
//			for(unsigned int i = 0; i < children.size(); i++){
//				transform->setRotate(vec);
//				children[i]->transform->setRotate(vec);
//			}
//		}
//	}
//	void setRotateX(float _x){
//		if(!hasChildren){
//			transform->setRotateX(_x);
//		}else{
//			for(unsigned int i = 0; i < children.size(); i++){
//				transform->setRotateX(_x);
//				children[i]->transform->setRotateX(_x);
//			}
//		}
//	}
//	void setRotateY(float _y){
//		if(!hasChildren){
//			transform->setRotateY(_y);
//		}else{
//			for(unsigned int i = 0; i < children.size(); i++){
//				transform->setRotateY(_y);
//				children[i]->transform->setRotateY(_y);
//			}
//		}
//	}
//	void setRotateZ(float _z){
//		if(!hasChildren){
//			transform->setRotateZ(_z);
//		}else{
//			for(unsigned int i = 0; i < children.size(); i++){
//				transform->setRotateZ(_z);
//				children[i]->transform->setRotateZ(_z);
//			}
//		}
//	}
//
//	void setScale(Vector3f& vec){
//		if(!hasChildren){
//			transform->setScale(vec);
//		}else{
//			for(unsigned int i = 0; i < children.size(); i++){
//				transform->setScale(vec);
//				children[i]->transform->setScale(vec);
//			}
//		}
//	}
//	void setScaleX(float _x){
//		if(!hasChildren){
//			transform->setScaleX(_x);
//		}else{
//			for(unsigned int i = 0; i < children.size(); i++){
//				transform->setScaleX(_x);
//				children[i]->transform->setScaleX(_x);
//			}
//		}
//	}
//	void setScaleY(float _y){
//		if(!hasChildren){
//			transform->setScaleY(_y);
//		}else{
//			for(unsigned int i = 0; i < children.size(); i++){
//				transform->setScaleY(_y);
//				children[i]->transform->setScaleY(_y);
//			}
//		}
//	}
//	void setScaleZ(float _z){
//		if(!hasChildren){
//			transform->setScaleZ(_z);
//		}else{
//			for(unsigned int i = 0; i < children.size(); i++){
//				transform->setScaleZ(_z);
//				children[i]->transform->setScaleZ(_z);
//			}
//		}
//	}
//
//	void draw(Camera& cam){
//		if(!shaderInfo.empty()){
//			for(unsigned int i = 0; i < shaderInfo.size(); i++){
//				if(shaderInfo.at(i).type == SWShader::INT){
//					shader->update(shaderInfo.at(i).name, SWShader::toInt(shaderInfo.at(i).value));
//				}else if(shaderInfo.at(i).type == SWShader::FLOAT){
//					shader->update(shaderInfo.at(i).name, SWShader::toFloat(shaderInfo.at(i).value));
//				}else if(shaderInfo.at(i).type == SWShader::VEC3){
//					shader->update(shaderInfo.at(i).name, SWShader::toVector3f(shaderInfo.at(i).value));
//				}else if(shaderInfo.at(i).type == SWShader::VEC4){
//					shader->update(shaderInfo.at(i).name, SWShader::toVector4f(shaderInfo.at(i).value));
//				}else{
//					std::cout << "No Uniform present" << std::endl;
//				}
//			}
//		}
//		shader->update(*transform, cam);
//		shader->bind();
//		tex->bind(0);
//		mesh->draw();
//		if(hasChildren){
//			for(unsigned int i = 0; i < children.size(); i++){
//				children[i]->draw(cam);
//			}
//		}
//	}
//
//	void draw(){
//		if(!shaderInfo.empty()){
//			for(unsigned int i = 0; i < shaderInfo.size(); i++){
//				if(shaderInfo.at(i).type == SWShader::INT){
//					shader->update(shaderInfo.at(i).name, SWShader::toInt(shaderInfo.at(i).value));
//					std::cout << "Setting Int Uniform" << std::endl;
//				}else if(shaderInfo.at(i).type == SWShader::FLOAT){
//					shader->update(shaderInfo.at(i).name, SWShader::toFloat(shaderInfo.at(i).value));
//					std::cout << "Setting Float Uniform" << std::endl;
//				}else if(shaderInfo.at(i).type == SWShader::VEC3){
//					shader->update(shaderInfo.at(i).name, SWShader::toVector3f(shaderInfo.at(i).value));
//					std::cout << "Setting Vec3 Uniform" << std::endl;
//				}else if(shaderInfo.at(i).type == SWShader::VEC4){
//					shader->update(shaderInfo.at(i).name, SWShader::toVector4f(shaderInfo.at(i).value));
//					std::cout << "Setting Vec4 Uniform" << std::endl;
//				}else{
//					std::cout << "No Uniform present" << std::endl;
//				}
//			}
//			std::cout << "Some Uniforms" << std::endl;
//		}
//
//		shader->update(*transform);
//		shader->bind();
//		tex->bind(0);
//		mesh->draw();
//		if(hasChildren){
//			for(unsigned int i = 0; i < children.size(); i++){
//				children[i]->draw();
//			}
//		}
//	}
//};
//
//
//

#endif /* SWOBJECT_H_ */
