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

#endif /* LIGHT_H_ */
