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

class Camera;

namespace SWShader{
	enum Type{
		INT = 0,
		FLOAT = 1,
		VEC3 = 2,
		VEC4 = 3,
		MAT4 = 4,
		STRING = 5
	};

	static std::string toString(int val){
		std::ostringstream buff;
		buff << val;
		return buff.str();
	}
	static std::string toString(float val){
		std::ostringstream buff;
		buff << val;
		return buff.str();
	}
	static std::string toString(Vector3f& val){
		std::ostringstream buff;
		buff << val.getX() << "/" << val.getY() << "/" << val.getZ();
		return buff.str();
	}
	static std::string toString(Vector4f& val){
		std::ostringstream buff;
		buff << val.getX() << "/" << val.getY() << "/" << val.getZ() << "/" << val.getW();
		return buff.str();
	}

	static int toInt(const std::string& value){
		return (int)atoi(value.c_str());
	}

	static float toFloat(const std::string& value){
		return (float)atof(value.c_str());
	}

	static Vector3f toVector3f(const std::string& value){
		float _x = 0.0f, _y = 0.0f, _z = 0.0f;
		std::string vX = value.substr(0, value.find('/'));
		std::string vY = value.substr(value.find('/')+1, value.find_last_of('/'));
		std::string vZ = value.substr(value.find_last_of('/')+1);
		_x = (float)atof(vX.c_str());
		_y = (float)atof(vY.c_str());
		_z = (float)atof(vZ.c_str());
		return Vector3f(_x, _y, _z);
	}

	static Vector4f toVector4f(const std::string& value){
		float _x = 0.0f, _y = 0.0f, _z = 0.0f, _w = 0.0f;
		std::string vX = value.substr(0, value.find('/'));
		std::string d1 = value.substr(value.find('/')+1);
		std::string vY = d1.substr(0, d1.find('/'));
		std::string d2 = d1.substr(d1.find('/')+1);
		std::string vZ = d2.substr(0, d2.find('/'));
		std::string vW = d2.substr(d2.find_last_of('/')+1);
		_x = (float)atof(vX.c_str());
		_y = (float)atof(vY.c_str());
		_z = (float)atof(vZ.c_str());
		_w = (float)atof(vW.c_str());
		Vector4f ret(_x, _y, _z, _w);
		ret.print();
		return Vector4f(_x, _y, _z, _w);
	}

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
	Shader(const std::string& vertShdrPath, const std::string& fragShdrPath);
	void bind();
	void update(Transform& trans);
	void update(Transform& trans, Camera& cam);
	void update(const std::string& name, int val);
	void update(const std::string& name, float val);
	void update(const std::string& name, Vector3f val);
	void update(const std::string& name, Vector4f val);
	virtual ~Shader();

private:
	static const unsigned int NUM_SHADER = 2;
	enum ShaderType{VERTEX_SHADER, FRAGMENT_SHADER};

	void checkShaderStatus(GLuint shaderID, GLuint flag, bool isProgram, const std::string& errorMessage);
	std::string loadShader(const std::string &filePath);
	GLuint createShader(const std::string &text, unsigned int type);
	GLuint mProgram;
	GLuint mShaders[NUM_SHADER];
	GLuint uniform[3];
};

#endif /* SHADER_H_ */
