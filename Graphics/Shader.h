#ifndef SHADER_H_
#define SHADER_H_

#include <string>
#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "../Utility/Transform.h"
#include "../Utility/Math/Matrix.h"
#include "Camera.h"

class SWObject;
class Camera;

namespace SWShader{
	enum{
		INT,
		FLOAT,
		VEC3,
		VEC4,
		MAT4
	};

	inline std::string toString(int val){
		std::ostringstream buff;
		buff << val;
		return buff.str();
	}
	inline std::string toString(float val){
		std::ostringstream buff;
		buff << val;
		return buff.str();
	}
	inline std::string toString(Vector3f& val){
		std::ostringstream buff;
		buff << val.getX() << "/" << val.getY() << "/" << val.getZ();
		return buff.str();
	}
	inline std::string toString(Vector4f& val){
		std::ostringstream buff;
		buff << val.getX() << "/" << val.getY() << "/" << val.getZ() << "/" << val.getW();
		return buff.str();
	}

	inline int toInt(const std::string& value)const{
		return (int)atoi(value.c_str());
	}

	inline float toFloat(const std::string& value)const{
		return (float)atof(value.c_str());
	}

	static Vector3f

	struct ShaderInfo{
		ShaderInfo(const std::string n, int t, const std::string v){
			name = n;
			type = t;
			value = v;
		}
		std::string value;
		int type;
		std::string name;
	};
};


class Shader {
public:
	Shader();
	Shader(const std::string& filePath);
	void bind();
	void update(Transform& trans);
	void update(Transform& trans, Camera& cam);
	void update(const std::string& name, int val);
	void update(const std::string& name, float val);
	void update(const std::string& name, Vector3f& val);
	void update(const std::string& name, Vector4f& val);
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
