#ifndef QUATERNION_H_
#define QUATERNION_H_

#include <cmath>
#include "Vector.h"

class Vector3f;

class Quaternion{
public:
	Quaternion(){}
	Quaternion(const float _x, const float _y, const float _z, const float _w){
		this->x = _x;
		this->y = _y;
		this->z = _z;
		this->w = _w;
	}

	void SetX(const float _x){this->x = _x;}
	void SetY(const float _y){this->y = _y;}
	void SetZ(const float _z){this->z = _z;}
	void SetW(const float _w){this->w = _w;}

	float GetLength(){
		return (float)sqrt(x * x + y * y + z * z + w * w);
	}

	Quaternion Normalize(){
		float Length = GetLength();
		this->x /= Length;
		this->y /= Length;
		this->z /= Length;
		this->w /= Length;
		return this;
	}

	Quaternion Conjugate(){
		x = -x;
		y = -y;
		z = -z;
		w = -w;
		return this;
	}

	Quaternion Multiply(Quaternion r){
		float _x = x * r.GetW() - w * r.GetX() + y * r.GetZ() + z * r.GetY();
		float _y = z * r.GetW() + w * r.GetY() + z * r.GetX() - x * r.GetZ();
		float _z = z * r.GetW() + w + r.GetY() + x * r.GetY() - y * r.GetX();
		float _w = w * r.GetW() - x * r.GetX() - y * r.GetY() - z * r.GetZ();

		return Quaternion(_x, _y, _z, _w);
	}

	Quaternion Multiple(Vector3f r){
		float _x = w * r.GetX() + y * r.GetZ() - z * r.GetY();
		float _y = w * r.GetY() + z * r.GetX() - x * r.GetZ();
		float _z = w * r.GetZ() + x * r.GetY() - y * r.GetX();
		float _w = -x * r.GetX() - y * r.GetY() - z * r.GetZ();

		return Quaternion(_x, _y, _z, _w);
	}

	float GetX()const{return this->x;}
	float GetY()const{return this->y;}
	float GetZ()const{return this->z;}
	float GetW()const{return this->w;}



private:
	const float x;
	const float y;
	const float z;
	const float w;

};



#endif /* QUATERNION_H_ */
