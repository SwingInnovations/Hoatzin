#include "Vector.h"
#include "Quaternion.h"

void Vector3f::Rotate(float angle, Vector3f& axis){
	float halfSinF = sinf(ToRadian(angle/2));
	float halfCosF = cosf(ToRadian(angle/2));

	const float rX = axis.GetX() * halfSinF;
	const float rY = axis.GetY() * halfSinF;
	const float rZ = axis.GetZ() * halfSinF;
	const float rW = halfCosF;
	Quaternion RotateQ(rX, rY, rZ, rW);
	Quaternion ConjQ, W;
	ConjQ = RotateQ.Conjugate();
	W = RotateQ.Multiply(*this).Multiply(ConjQ);

	this->x = W.GetX();
	this->y = W.GetY();
	this->z = W.GetZ();
}



