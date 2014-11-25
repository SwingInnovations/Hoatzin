#ifndef SHADER_H_
#define SHADER_H_

#include <string>
#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include "../Utility/Transform.h"
#include "../Utility/Math/Matrix.h"
#include "Camera.h"

class SWObject;
class Camera;

class Shader {
public:
	Shader();
	Shader(const std::string& filePath);
	void bind();
	void update(Transform& trans);
	void update(Transform& trans, Camera& cam);
	virtual ~Shader();

private:
	static const unsigned int NUM_SHADER = 2;
	enum ShaderType{VERTEX_SHADER, FRAGMENT_SHADER};

	void checkShaderStatus(GLuint shaderID, GLuint flag, bool isProgram, const std::string& errorMessage);
	std::string loadShader(const std::string &filePath);
	GLuint createShader(const std::string &text, unsigned int type);
	GLuint mProgram;
	GLuint mShaders[NUM_SHADER];
	GLuint uniform[2];
};

#endif /* SHADER_H_ */
