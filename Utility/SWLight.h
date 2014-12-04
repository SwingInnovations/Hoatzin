#ifndef SWLIGHT_H_
#define SWLIGHT_H_

#include "SWObject.h"
#include "../Graphics/Light.h"

class SWLight : public SWComponent{
public:
	SWLight(){
		transform = new Transform();
		light.position = Vector4f();
		light.intensity = Vector3f();
		light.attenuation = 0.0f;
		light.coneAngle = 0.0f;
		light.ambientCoefficient = 0.0f;
		index = 0;
	}

	SWLight(int i){
		transform = new Transform();
		light.position = Vector4f();
		light.intensity = Vector3f();
		light.attenuation = 0.0f;
		light.coneAngle = 0.0f;
		light.ambientCoefficient = 0.0f;
		index = i;
	}

	void setIndex(int i){
		index = i;
	}

	void addDirectionalLight(Vector3f position, Vector3f intensity, float amb){
		light.position = Vector4f(position.getX(), position.getY(), position.getZ(), 0.0f);
		transform->setTranslate(position);
		light.intensity = intensity;
		light.ambientCoefficient = amb;
		addLightUniforms(index, "position", SWShader::VEC4, SWShader::toString(light.position));
		addLightUniforms(index, "intensity", SWShader::VEC3, SWShader::toString(light.intensity));
		addLightUniforms(index, "ambientCoefficient", SWShader::FLOAT, SWShader::toString(light.ambientCoefficient));

	}

	void addSpotLight(Vector3f& position, Vector3f& intensity, Vector3f& coneDirection, float at, float amb, float coneAngle){
		light.position = Vector4f(position.getX(), position.getY(), position.getZ(), 1.0);
		transform->setTranslate(position);
		light.intensity = intensity;
		light.attenuation = at;
		light.ambientCoefficient = amb;
		light.coneAngle = coneAngle;
		light.coneDirection = coneDirection;
		addLightUniforms(index, "position", SWShader::VEC4, SWShader::toString(light.position));
		addLightUniforms(index, "intensity", SWShader::VEC3, SWShader::toString(light.intensity));
		addLightUniforms(index, "coneDirection", SWShader::VEC3, SWShader::toString(light.coneDirection));
		addLightUniforms(index, "ambientCoefficient", SWShader::FLOAT, SWShader::toString(light.ambientCoefficient));
		addLightUniforms(index, "attenuation", SWShader::FLOAT, SWShader::toString(light.attenuation));
		addLightUniforms(index, "coneAngle", SWShader::FLOAT, SWShader::toString(light.coneAngle));
	}

	void addLightUniforms(int num, const std::string& propertyName, int type, const std::string& propertyVal){
		std::ostringstream output;
		output << "SWLight[" << num << "]." << propertyName.c_str();
		std::string info = output.str();
		uniforms.push_back(SWShader::ShaderInfo(info, type, propertyVal));
	}

	void draw(){
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
			std::cout << "Some Uniforms" << std::endl;
		}
	}

	void draw(Shader* shdr){
		shader = shdr;
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
			std::cout << "Some Uniforms" << std::endl;
		}
	}

	Light light;
	int index;
};

class SWDirectionalLight : public SWLight{
public:
	SWDirectionalLight(){
		transform = new Transform();
		light.position = Vector4f();
		light.intensity = Vector3f();
		light.attenuation = 0.0f;
		light.coneAngle = 0.0f;
		light.ambientCoefficient = 0.0f;
		index = 0;
	}

	SWDirectionalLight(int i){
		transform = new Transform();
		light.position = Vector4f();
		light.intensity = Vector3f();
		light.attenuation = 0.0f;
		light.coneAngle = 0.0f;
		light.ambientCoefficient = 0.0f;
		index = i;
	}

	SWDirectionalLight(Vector3f& position, Vector3f& intensity, float ambCoef, int i){
		index = i;
		transform = new Transform();
		transform->setTranslate(position);
		addDirectionalLight(position, intensity, ambCoef);
	}

	void setIndex(int i){
		index = i;
	}
};

class SWSpotLight : public SWLight{
public:
	SWSpotLight(){
		transform = new Transform();
		light.position = Vector4f();
		light.intensity = Vector3f();
		light.attenuation = 0.0f;
		light.coneAngle = 0.0f;
		light.ambientCoefficient = 0.0f;
		index = 0;
	}

	SWSpotLight(int i){
		transform = new Transform();
		light.position = Vector4f();
		light.intensity = Vector3f();
		light.attenuation = 0.0f;
		light.coneAngle = 0.0f;
		light.ambientCoefficient = 0.0f;
		index = i;
	}

	SWSpotLight(Vector3f& position, Vector3f& intensity, Vector3f& coneDirection, float att, float ambCoef, float coneAngle, int index){
		this->index = index;
		transform = new Transform();
		addSpotLight(position, intensity, coneDirection, att, ambCoef, coneAngle);
	}
};



#endif /* SWLIGHT_H_ */
