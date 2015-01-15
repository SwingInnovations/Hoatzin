#ifndef SWMATERIAL_H_
#define SWMATERIAL_H_

#include <vector>

struct SWMaterial{
	SWMaterial(){
		shader = new Shader();
	}
	void setShader(Shader* shader){this->shader = shader;}

	Shader* getShader(){return shader;}

	void bind(){
		for(unsigned int i = 0; i < textures.size(); i++){
			textures[i]->bind(i);
		}
		shader->bind();
	}

	Vector3f getDiffuseColor(){return diffuseColor;}
private:

	void initUniforms(){
		uniforms.push_back(SWShader::ShaderInfo("diffuseColor", SWShader::VEC3, SWShader::toString(diffuseColor)));
		uniforms.push_back(SWShader::ShaderInfo("specularColor", SWShader::VEC3, SWShader::toString(specularColor)));
	}

	void addMaterialColor(int num, const std::string& propertyName, int type, const std::string& propertyVal){

	}

	Shader* shader;
	std::vector<Texture*> textures;
	std::vector<SWShader::ShaderInfo> uniforms;
	Vector3f diffuseColor;
	Vector3f specularColor;
};


#endif /* SWMATERIAL_H_ */
