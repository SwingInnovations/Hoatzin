#include "Shader.h"
#include "Camera.h"

Shader::Shader() {
	mProgram = glCreateProgram();
	mShaders[0] = createShader(loadShader("standardShader.vsh"), GL_VERTEX_SHADER);
	mShaders[1] = createShader(loadShader("standardShader.fsh"), GL_FRAGMENT_SHADER);
	for(unsigned int i = 0; i < NUM_SHADER; i++){
		glAttachShader(mProgram, mShaders[i]);
	}

	glBindAttribLocation(mProgram, 0, "position");
	glBindAttribLocation(mProgram, 1, "texCoord");
	glBindAttribLocation(mProgram, 2, "normal");
	glBindAttribLocation(mProgram, 3, "tangent");
	glBindAttribLocation(mProgram, 4, "biTangent");

	glLinkProgram(mProgram);
	checkShaderStatus(mProgram, GL_LINK_STATUS, true, "Error Linking Shader Program");

	glValidateProgram(mProgram);
	checkShaderStatus(mProgram, GL_LINK_STATUS, true, "Invalid Shader Program");

	uniform[0] = glGetUniformLocation(mProgram, "model");
	uniform[1] = glGetUniformLocation(mProgram, "camera");
	uniform[2] = glGetUniformLocation(mProgram, "cameraPosition");
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
	glBindAttribLocation(mProgram, 3, "tangent");
	glBindAttribLocation(mProgram, 4, "biTangent");

	glLinkProgram(mProgram);
	checkShaderStatus(mProgram, GL_LINK_STATUS, true, "Error Linking Shader Program");

	glValidateProgram(mProgram);
	checkShaderStatus(mProgram, GL_LINK_STATUS, true, "Invalid shader program!");

	uniform[0] = glGetUniformLocation(mProgram, "model");
	uniform[1] = glGetUniformLocation(mProgram, "camera");
	uniform[2] = glGetUniformLocation(mProgram, "cameraPosition");
}

Shader::Shader(const std::string& vertShdrPath, const std::string& fragShdrPath){
	mProgram = glCreateProgram();
	mShaders[0] = createShader(loadShader(vertShdrPath + ".vsh"), GL_VERTEX_SHADER);
	mShaders[1] = createShader(loadShader(fragShdrPath + ".fsh"), GL_FRAGMENT_SHADER);

	for(unsigned int i = 0; i < NUM_SHADER; i++){
		glAttachShader(mProgram, mShaders[i]);
	}

	glBindAttribLocation(mProgram, 0, "position");
	glBindAttribLocation(mProgram, 1, "texCoord");
	glBindAttribLocation(mProgram, 2, "normal");
	glBindAttribLocation(mProgram, 3, "tangent");
	glBindAttribLocation(mProgram, 4, "biTangent");

	glLinkProgram(mProgram);
	checkShaderStatus(mProgram, GL_LINK_STATUS, true, "Error Linking Shader Program");

	glValidateProgram(mProgram);
	checkShaderStatus(mProgram, GL_LINK_STATUS, true, "Invalid shader program!");

	uniform[0] = glGetUniformLocation(mProgram, "model");
	uniform[1] = glGetUniformLocation(mProgram, "camera");
	uniform[2] = glGetUniformLocation(mProgram, "cameraPosition");
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

	glUniformMatrix4fv(uniform[0], 1, GL_TRUE, &transform.m[0][0]);
}

void Shader::update(Camera& cam){
	Matrix4f camera;
	camera = cam.getViewProjection();
	glUniformMatrix4fv(uniform[1], 1, GL_TRUE, &camera.m[0][0]);
}

void Shader::update(Transform& trans, Camera& cam){
	Matrix4f transform, camera;
	transform = trans.getModel();
	camera = cam.getViewProjection();
	Vector3f cameraPosition = cam.getTransform().getTranslate();

	glUniformMatrix4fv(uniform[0], 1, GL_TRUE, &transform.m[0][0]);
	glUniformMatrix4fv(uniform[1], 1, GL_TRUE, &camera.m[0][0]);
	glUniform3f(uniform[2], cameraPosition.getX(), cameraPosition.getY(), cameraPosition.getZ());
}

void Shader::update(const std::string& name, int val){
	glUniform1i(glGetUniformLocation(mProgram, name.c_str()), val);
}

void Shader::update(const std::string& name, float val){
	glUniform1f(glGetUniformLocation(mProgram, name.c_str()), val);
}

void Shader::update(const std::string& name, Vector3f val){
	glUniform3f(glGetUniformLocation(mProgram, name.c_str()), val.getX(), val.getY(), val.getZ());
}

void Shader::update(const std::string& name, Vector4f val){
	glUniform4f(glGetUniformLocation(mProgram, name.c_str()), val.getX(), val.getY(), val.getZ(), val.getW());
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
