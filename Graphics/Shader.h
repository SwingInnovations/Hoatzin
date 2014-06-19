#ifndef SHADER_H_
#define SHADER_H_

#include <string>
#include <GL/glew.h>
#include <fstream>
#include <iostream>

class Shader {
public:
	Shader();
	Shader(const std::string& filePath);
	void Bind();
	virtual ~Shader();

private:
	static const unsigned int NUM_SHADER = 2;
	enum ShaderType{VERTEX_SHADER, FRAGMENT_SHADER};

	void CheckShaderStatus(GLuint shaderID, GLuint flag, bool isProgram, const std::string& errorMessage);
	std::string LoadShader(const std::string &filePath);
	GLuint CreateShader(const std::string &text, unsigned int type);
	GLuint mProgram;
	GLuint mShaders[NUM_SHADER];
};

#endif /* SHADER_H_ */
