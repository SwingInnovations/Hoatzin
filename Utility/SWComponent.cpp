#include "SWComponent.h"
#include "../Graphics/Shader.h"

void SWComponent::addUniform(const std::string& name, int value){
		uniforms.push_back(SWShader::ShaderInfo(name, SWShader::INT,SWShader::toString(value)));
}

void SWComponent::addUniform(const std::string& name, float value){
	uniforms.push_back(SWShader::ShaderInfo(name, SWShader::FLOAT, SWShader::toString(value)));
}

void SWComponent::addUniform(const std::string& name, Vector3f& value){
	uniforms.push_back(SWShader::ShaderInfo(name, SWShader::VEC3, SWShader::toString(value)));
}

void SWComponent::addUniform(const std::string& name, Vector4f& value){
	uniforms.push_back(SWShader::ShaderInfo(name, SWShader::VEC4, SWShader::toString(value)));
}
void SWComponent::setUniform(const std::string& name, int value){
	if(!uniforms.empty()){
		for(unsigned int i = 0; i < uniforms.size(); i++){
			if(uniforms[i].name == name){
				uniforms[i].value = SWShader::toString(value);
			}
		}
	}
}

void SWComponent::setUniform(const std::string& name, float value){
	if(!uniforms.empty()){
		for(unsigned int i = 0; i < uniforms.size(); i++){
			if(uniforms[i].name == name){
				uniforms[i].value = SWShader::toString(value);
			}
		}
	}
}

void SWComponent::setUniform(const std::string& name, Vector3f& value){
	if(!uniforms.empty()){
		for(unsigned int i = 0; i < uniforms.size(); i++){
			if(uniforms[i].name == name){
				uniforms[i].value = SWShader::toString(value);
			}
		}
	}
}

void SWComponent::setUniform(const std::string& name, Vector4f& value){
	if(!uniforms.empty()){
		for(unsigned int i = 0; i < uniforms.size(); i++){
			if(uniforms[i].name == name){
				uniforms[i].value = SWShader::toString(value);
			}
		}
	}
}
