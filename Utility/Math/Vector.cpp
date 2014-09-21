#include "Vector.h"
#include "Quaternion.h"

void Vector3f::Rotate(float angle, Vector3f& axis){
	float halfSinF = sinf(ToRadian(angle/2));
	float halfCosF = cosf(ToRadian(angle/2));

	const float rX = axis.x * halfSinF;
	const float rY = axis.y * halfSinF;
	const float rZ = axis.z * halfSinF;
	const float rW = halfCosF;
	Quaternion RotateQ(rX, rY, rZ, rW);
	Quaternion ConjQ, W;
	ConjQ = RotateQ.Conjugate();
	W = RotateQ.Multiply((*this)).Multiply(ConjQ);

	x = W.GetX();
	y = W.GetY();
	z = W.GetZ();
}



