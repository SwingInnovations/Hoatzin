#ifndef LIGHT_H_
#define LIGHT_H_

#include "../Utility/Math/Vector.h"

struct Light{
	Vector4f position;
	Vector3f intensity;
	float attenuation;
	float ambientCoefficient;
	float coneAngle;
	Vector3f coneDirection;
};

struct DirectionalLight : Light{
	DirectionalLight(Vector3f position, Vector3f intensity, float amb){
		this->position = Vector4f(position.getX(), position.getY(), position.getZ(), 0.0);
		this->intensity = intensity;
		this->ambientCoefficient = amb;
	}
};

struct SpotLight : Light{
	SpotLight(Vector3f position, Vector3f intensity, float at, float amb, float coneAngle, Vector3f coneDirection){
		this->position = Vector4f(position.getX(), position.getY(), position.getZ(), 1.0);
		this->intensity = intensity;
		this->attenuation = at;
		this->ambientCoefficient = amb;
		this->coneAngle = coneAngle;
		this->coneDirection = coneDirection;
	}
};



#endif /* LIGHT_H_ */
