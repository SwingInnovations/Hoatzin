/*
 * Shader.cpp
 *
 *  Created on: Jun 12, 2014
 *      Author: Nathan_z400
 */

#include "Shader.h"

Shader::Shader() {
	// TODO Auto-generated constructor stub

}

Shader::Shader(const std::string& filePath){
	mProgram = glCreateProgram();
	mShaders[0] = createShader(loadShader(filePath + ".vsh"), GL_VERTEX_SHADER);
	mShaders[1] = createShader(loadShader(filePath + ".fsh"), GL_FRAGMENT_SHADER);

	for(unsigned int i = 0; i < NUM_SHADER; i++){
		glAttachShader(mProgram, mShaders[i]);
	}

	glBindAttribLocation(mProgram, 0, "position");
	glBindAttribLocation(mProgram, 1, "texCoord");
	glBindAttribLocation(mProgram, 2, "normal");

	glLinkProgram(mProgram);
	checkShaderStatus(mProgram, GL_LINK_STATUS, true, "Error Linking Shader Program");

	glValidateProgram(mProgram);
	checkShaderStatus(mProgram, GL_LINK_STATUS, true, "Invalid shader program!");

	uniform = glGetUniformLocation(mProgram, "MVP");
}

Shader::~Shader() {
	for(unsigned int i = 0; i < NUM_SHADER; i++){
		glDeleteShader(mShaders[i]);
	}
	glDeleteProgram(mProgram);
}

void Shader::bind(){
	glUseProgram(mProgram);
}

void Shader::update(Transform& trans){
	Matrix4f transform;

	transform = trans.getModel();

	glUniformMatrix4fv(uniform, 1, GL_TRUE, &transform.m[0][0]);
}

void Shader::update(Transform& trans, Camera& cam){
	Matrix4f transform, camera, ret;
	transform = trans.getModel();
	camera = cam.getViewProjection();
	ret = camera * transform;
	glUniformMatrix4fv(uniform, 1, GL_TRUE, &ret.m[0][0]);
}

void Shader::checkShaderStatus(GLuint shaderID, GLuint flag, bool isProgram, const std::string& errorMessage){
	GLint success = 0;
	GLchar error[1024] = {0};

	if(isProgram){
		glGetProgramiv(shaderID, flag, &success);
	}else{
		glGetShaderiv(shaderID, flag, &success);
	}

	if(success == GL_FALSE){
		if(isProgram){
			glGetProgramInfoLog(shaderID, sizeof(error), NULL, error);
		}else{
			glGetShaderInfoLog(shaderID, sizeof(error), NULL, error);
		}

		std::cerr << errorMessage << " : " << error << "'" << std::endl;
	}
}

std::string Shader::loadShader(const std::string &filePath){
	std::ifstream file;
	file.open(filePath.c_str());

	if(!file.good()){
		std::cout << "Failed to load File" << std::endl;
	}

	std::string output;
	std::string line;

	if(file.is_open()){
		while(file.good()){
			std::getline(file, line);
			output.append(line + "\n");
		}
	}

	return output;
}

GLuint Shader::createShader(const std::string &text, unsigned int type){
	GLuint shader = glCreateShader(type);
	if(shader == 0){
		std::cerr << "Error creating Shader type: " << type << std::endl;
	}

	const GLchar* p[1];
	p[0] = text.c_str();
	GLint length[1];
	length[0] = text.length();

	glShaderSource(shader, 1, p, length);
	glCompileShader(shader);
	return shader;

}
