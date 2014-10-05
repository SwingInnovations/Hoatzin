#ifndef QUATERNION_H_
#define QUATERNION_H_

#include <cmath>
#include "Vector.h"

class Vector3f;

class Quaternion{
public:
	Quaternion(){
		this->x = 0.0;
		this->y = 0.0;
		this->z = 0.0;
		this->w = 1.0;
	}

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

	void Inverse(){

	}

	Quaternion Normalize(){
		float Length = GetLength();
		this->x /= Length;
		this->y /= Length;
		this->z /= Length;
		this->w /= Length;
		return *this;
	}

	Quaternion Conjugate(){
		Quaternion ret(-x, -y, -z, w);
		return ret;
	}

	inline Quaternion Multiply(Quaternion r)const{
		float _x = this->w*r.GetX() + this->x*r.GetW() + this->y*r.GetZ() - this->z*r.GetY();
		float _y = this->w*r.GetY() - this->x*r.GetZ() + this->y*r.GetW() + this->z*r.GetX();
		float _z = this->w*r.GetZ() + this->x*r.GetY() - this->y*r.GetX() + this->z*r.GetW();
		float _w = this->w*r.GetW() - this->x*r.GetX() - this->y*r.GetY() - this->z*r.GetZ();

		return Quaternion(_x, _y, _z, _w);
	}

	inline Vector3f toVector3f(){
		Vector3f ret(this->x, this->y, this->z);
		return ret;
	}

	inline Quaternion Multiply(Vector3f& r)const{
		float _x = (w * r.GetX()) + (y * r.GetZ()) - (z * r.GetY());
		float _y = (w * r.GetY()) + (z * r.GetX()) - (x * r.GetZ());
		float _z = (w * r.GetZ()) + (x * r.GetY()) - (y * r.GetX());
		float _w = -(x * r.GetX()) - (y * r.GetY()) - (z * r.GetZ());

		return Quaternion(_x, _y, _z, _w);
	}


	float GetX()const{return this->x;}
	float GetY()const{return this->y;}
	float GetZ()const{return this->z;}
	float GetW()const{return this->w;}



private:
	 float x;
	 float y;
	 float z;
	 float w;

};



#endif /* QUATERNION_H_ */
