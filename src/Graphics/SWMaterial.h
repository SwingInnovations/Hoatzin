#ifndef SWMATERIAL_H_
#define SWMATERIAL_H_

#include <vector>

struct SWMaterial{
	SWMaterial(){
		textures = new Texture();
		shader = new Shader();
		initUniforms();
	}

	SWMaterial(Shader* shdr){
		shader = shdr;
		initUniforms();
		textures = new Texture();
	}

	void setShader(Shader* shader){this->shader = shader;}

	Shader* getShader(){return shader;}

	void addDiffuseMap(const std::string& fileName){
		textures->addTexture(fileName);
		uniforms.push_back(SWShader::ShaderInfo("SWMaterial.diffuseMap", SWShader::INT, SWShader::toString(0)));
	}

	void addSpecularMap(const std::string& fileName){
		textures->addTexture(fileName);
		uniforms.push_back(SWShader::ShaderInfo("SWMaterial.specularMap", SWShader::INT, SWShader::toString(1)));
	}

	void addNormalMap(const std::string& fileName){
		textures->addTexture(fileName);
		uniforms.push_back(SWShader::ShaderInfo("SWMaterial.normalMap", SWShader::INT, SWShader::toString(2)));
	}

	void update(){
		for(unsigned int i = 0; i < uniforms.size(); i++){
			if(uniforms.at(i).type == SWShader::INT){
				shader->update(uniforms[i].name, SWShader::toInt(uniforms[i].value));
			}else if(uniforms.at(i).type == SWShader::VEC3){
				shader->update(uniforms[i].name, SWShader::toVector3f(uniforms[i].value));
			}else{

			}
		}
	}

	void bind(){
		update();
		for(unsigned int i = 0; i < textures->getTextureCount(); i++){
			textures->bind(i);
		}
		shader->bind();
	}

	Vector3f getDiffuseColor(){return diffuseColor;}
	Vector3f getSpecularColor(){return specularColor;}
private:

	void initUniforms(){
		uniforms.push_back(SWShader::ShaderInfo("diffuseColor", SWShader::VEC3, SWShader::toString(diffuseColor)));
		uniforms.push_back(SWShader::ShaderInfo("specularColor", SWShader::VEC3, SWShader::toString(specularColor)));
	}

	void addMaterialColor(int num, const std::string& propertyName, int type, const std::string& propertyVal){

	}

	Shader* shader;
	Texture* textures;
	std::vector<SWShader::ShaderInfo> uniforms;
	Vector3f diffuseColor;
	Vector3f specularColor;
};


#endif /* SWMATERIAL_H_ */
