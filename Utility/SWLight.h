#ifndef SWLIGHT_H_
#define SWLIGHT_H_

#include "SWObject.h"
#include "../Graphics/Light.h"

class SWLight : public SWComponent{
public:
	void addDirectionalLight(Vector3f position, Vector3f intensity, float amb){
		light.position = Vector4f(position.getX(), position.getY(), position.getZ(), 0.0f);
		light.intensity = intensity;
		light.ambientCoefficient = amb;
		addLightUniforms(0, "position", SWShader::VEC4, SWShader::toString(light.position));
		addLightUniforms(0, "intensity", SWShader::VEC3, SWShader::toString(light.intensity));
		addLightUniforms(0, "ambientCoefficient", SWShader::FLOAT, SWShader::toString(light.ambientCoefficient));

	}

	void addSpotLight(Vector3f position, Vector3f intensity, float at, float amb, float coneAngle){
		light.position = Vector4f(position.getX(), position.getY(), position.getZ(), 1.0);
		light.intensity = intensity;
		light.attenuation = at;
		light.ambientCoefficient = amb;
		light.coneAngle = coneAngle;
		addLightUniforms(0, "position", SWShader::VEC4, SWShader::toString(light.position));
		addLightUniforms(0, "intensity", SWShader::VEC3, SWShader::toString(light.intensity));
		addLightUniforms(0, "ambientCoefficient", SWShader::FLOAT, SWShader::toString(light.ambientCoefficient));
	}

	void addLightUniforms(int num, const std::string& propertyName, int type, const std::string& propertyVal){
		std::ostringstream output;
		output << "SWLight[" << num << "]." << propertyName.c_str();
		std::string info = output.str();
		uniforms.push_back(SWShader::ShaderInfo(info, type, propertyVal));
	}

	Light light;
};



#endif /* SWLIGHT_H_ */
