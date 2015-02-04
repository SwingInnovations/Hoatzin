#ifndef SWLIGHT_H_
#define SWLIGHT_H_

#include "../Graphics/Light.h"
#include "../Graphics/Color.h"

class Shader;
struct Light;

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

	virtual void update(){

	}

	void setShader(Shader* shader){
		this->shader = shader;
	}

	void setIndex(int i){
		index = i;
		uniforms.clear();
		addLightUniforms(index, "position", SWShader::VEC4, SWShader::toString(light.position));
		addLightUniforms(index, "intensity", SWShader::VEC3, SWShader::toString(light.intensity));
		addLightUniforms(index, "coneDirection", SWShader::VEC3, SWShader::toString(light.coneDirection));
		addLightUniforms(index, "attenuation", SWShader::FLOAT, SWShader::toString(light.attenuation));
		addLightUniforms(index, "ambientCoefficient", SWShader::FLOAT, SWShader::toString(light.ambientCoefficient));
		addLightUniforms(index, "coneAngle", SWShader::FLOAT, SWShader::toString(light.coneAngle));
	}

	void setPosition(Vector4f& vec){
		light.position = vec;
		updateProperty("position", light.position);
	}

	void setIntensity(Vector3f& vec){
		light.intensity = vec;
		updateProperty("intensity", light.intensity);
	}

	void setConeDirection(Vector3f& vec){
		light.coneDirection = vec;
		updateProperty("coneDirection", light.coneDirection);
	}

	void setAmbientCoefficient(float amb){
		light.ambientCoefficient = amb;
		updateProperty("ambientCoefficient", light.ambientCoefficient);
	}

	void setAttenuation(float at){
		light.attenuation = at;
		updateProperty("attenuation", light.attenuation);
	}

	void setConeAngle(float coneAngle){
		light.coneAngle = coneAngle;
		updateProperty("coneAngle", light.coneAngle);
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

	void addSpotLight(Vector3f& position, int color, Vector3f& coneDirection, float at, float amb, float coneAngle){
		light.position = Vector4f(position, 1.0);
		light.intensity = COLOR::Color(color);
		light.coneDirection = coneDirection;
		light.attenuation = at;
		light.ambientCoefficient = amb;
		light.coneAngle = coneAngle;
		addLightUniforms(index, "position", SWShader::VEC4, SWShader::toString(light.position));
		addLightUniforms(index, "intensity", SWShader::VEC3, SWShader::toString(light.intensity));
		addLightUniforms(index, "coneDirection", SWShader::VEC3, SWShader::toString(light.coneDirection));
		addLightUniforms(index, "attenuation", SWShader::FLOAT, SWShader::toString(light.attenuation));
		addLightUniforms(index, "ambientCoefficient", SWShader::FLOAT, SWShader::toString(light.ambientCoefficient));
		addLightUniforms(index, "coneAngle", SWShader::FLOAT, SWShader::toString(light.coneAngle));
	}

	void addSpotLight(Vector3f& position, Vector3f& intensity, Vector3f& coneDirection, float at, float amb, float coneAngle){
		light.position = Vector4f(position.getX(), position.getY(), position.getZ(), 1.0);
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

	void updateProperty(const std::string& propertyName, int value){
		std::ostringstream reference;
		reference << "SWLight[" << index <<"]."<< propertyName;
		std::string info = reference.str();
		for(unsigned int i = 0; i < uniforms.size(); i++){
			if(uniforms.at(i).name == propertyName){
				uniforms[i].value = SWShader::toString(value);
			}
		}
	}

	void updateProperty(const std::string& propertyName, float value){
		std::ostringstream reference;
		reference << "SWLight[" << index <<"]."<< propertyName;
		std::string info = reference.str();
		for(unsigned int i = 0; i < uniforms.size(); i++){
			if(uniforms.at(i).name == propertyName){
				uniforms[i].value = SWShader::toString(value);
			}
		}
	}

	void updateProperty(const std::string& propertyName, Vector3f& value){
		std::ostringstream reference;
		reference << "SWLight[" << index<<"]."<< propertyName;
		std::string info = reference.str();
		for(unsigned int i = 0; i < uniforms.size(); i++){
			if(uniforms.at(i).name == propertyName){
				uniforms[i].value = SWShader::toString(value);
			}
		}
	}

	void updateProperty(const std::string& propertyName, Vector4f& value){
		std::ostringstream reference;
		reference << "SWLight[" << index<<"]."<< propertyName;
		std::string info = reference.str();
		for(unsigned int i = 0; i < uniforms.size(); i++){
			if(uniforms.at(i).name == propertyName){
				uniforms[i].value = SWShader::toString(value);
			}
		}
	}

	void addLightUniforms(int num, const std::string& propertyName, int type, const std::string& propertyVal){
		std::ostringstream output;
		output << "SWLight[" << num << "]." << propertyName;
		std::string info = output.str();
		std::cout << info << std::endl;
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
		}
	}

	void draw(Shader* shdr){
		if(!uniforms.empty()){
			for(unsigned int i = 0; i < uniforms.size(); i++){
				if(uniforms.at(i).type == SWShader::INT){
					shdr->update(uniforms.at(i).name, SWShader::toInt(uniforms.at(i).value));
				}else if(uniforms.at(i).type == SWShader::FLOAT){
					shdr->update(uniforms.at(i).name, SWShader::toFloat(uniforms.at(i).value));
				}else if(uniforms.at(i).type == SWShader::VEC3){
					shdr->update(uniforms.at(i).name, SWShader::toVector3f(uniforms.at(i).value));
				}else if(uniforms.at(i).type == SWShader::VEC4){
					shdr->update(uniforms.at(i).name, SWShader::toVector4f(uniforms.at(i).value));
				}else{
					std::cout << "No Uniform present" << std::endl;
				}
			}
		}
	}

	Vector4f getPosition()const{ return light.position; }
	Vector3f getIntensity()const{ return light.intensity; }
	Vector3f getConeDirection()const{ return light.coneDirection; }
	float getConeAngle()const{return light.coneAngle;}
	float getAttenuation()const{return light.attenuation;}
	float getAmbientCoefficient()const{return light.ambientCoefficient;}

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

	SWDirectionalLight(Vector3f& position, Vector3f& intensity, float ambCoef){
		transform = new Transform();
		transform->setTranslate(position);
		addDirectionalLight(position, intensity, ambCoef);
	}

	SWDirectionalLight(Vector3f& position, Vector3f& intensity, float ambCoef, int i){
		index = i;
		transform = new Transform();
		transform->setTranslate(position);
		addDirectionalLight(position, intensity, ambCoef);
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
		//addSpotLight(light.position.toVec3(), light.intensity, light.coneDirection, light.attenuation, light.ambientCoefficient, light.coneAngle);
	}

	SWSpotLight(int i){
		transform = new Transform();
		light.position = Vector4f();
		light.intensity = Vector3f();
		light.attenuation = 0.0f;
		light.coneAngle = 0.0f;
		light.ambientCoefficient = 0.0f;
		index = i;
		//addSpotLight(light.position.toVec3(), light.intensity, light.coneDirection, light.attenuation, light.ambientCoefficient, light.coneAngle);
	}

	SWSpotLight(Vector3f& position, Vector3f& intensity, Vector3f& coneDirection, float att, float ambCoef, float coneAngle){
		transform = new Transform();
		transform->setTranslate(position);
		index = 0;
		addSpotLight(position, intensity, coneDirection, att, ambCoef, coneAngle);
	}

	SWSpotLight(Vector3f& position, Vector3f& intensity, Vector3f& coneDirection, float att, float ambCoef, float coneAngle, int index){
		this->index = index;
		transform = new Transform();
		addSpotLight(position, intensity, coneDirection, att, ambCoef, coneAngle);
	}

	SWSpotLight(Vector3f& position, int color, Vector3f& coneDirection, float att, float ambCoef, float coneAngle, int index){
		this->index = index;
		transform = new Transform();
		addSpotLight(position, color, coneDirection, att, ambCoef, coneAngle);
	}
};



#endif /* SWLIGHT_H_ */
