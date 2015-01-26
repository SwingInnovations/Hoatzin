#ifndef SWOBJECT_H_
#define SWOBJECT_H_

#include <vector>
#include <string>

#include "Math/Vector.h"
#include "Transform.h"
#include "Mesh.h"
#include "../Graphics/Texture.h"
#include "../Graphics/Graphics.h"
#include "../Graphics/SWMaterial.h"

class SWComponent;
class Shader;

/*
 * To Be Deprecated, Avoid using
 * */

class SWObject : public SWComponent{
public:
	SWObject();
	SWObject(const SWObject* other);
	SWObject(Mesh* mesh, Shader* shader, Texture* texture);

	virtual void update(){

	}

	void draw(Camera* cam){
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
		shader->update(*this->transform, *cam);
		shader->bind();
		tex->bind(0);
		mesh->draw();
		if(hasChildren){
			for(unsigned int i = 0; i  < this->children.size(); i++){
				children[i]->draw(cam);
			}
		}
	}

	Mesh* mesh;
	Texture* tex;
	SWMaterial* mat;
};

#endif /* SWOBJECT_H_ */
