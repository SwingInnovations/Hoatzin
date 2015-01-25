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

	void setX(const float _x){this->x = _x;}
	void setY(const float _y){this->y = _y;}
	void setZ(const float _z){this->z = _z;}
	void setW(const float _w){this->w = _w;}

	float getLength(){
		return (float)sqrt(x * x + y * y + z * z + w * w);
	}

	void inverse(){

	}

	Quaternion normalize(){
		float Length = getLength();
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
		float _x = this->w*r.getX() + this->x*r.getW() + this->y*r.getZ() - this->z*r.getY();
		float _y = this->w*r.getY() - this->x*r.getZ() + this->y*r.getW() + this->z*r.getX();
		float _z = this->w*r.getZ() + this->x*r.getY() - this->y*r.getX() + this->z*r.getW();
		float _w = this->w*r.getW() - this->x*r.getX() - this->y*r.getY() - this->z*r.getZ();

		return Quaternion(_x, _y, _z, _w);
	}

	inline Vector3f toVector3f(){
		Vector3f ret(this->x, this->y, this->z);
		return ret;
	}

	inline Quaternion Multiply(Vector3f& r)const{
		float _x = (w * r.getX()) + (y * r.getZ()) - (z * r.getY());
		float _y = (w * r.getY()) + (z * r.getX()) - (x * r.getZ());
		float _z = (w * r.getZ()) + (x * r.getY()) - (y * r.getX());
		float _w = -(x * r.getX()) - (y * r.getY()) - (z * r.getZ());

		return Quaternion(_x, _y, _z, _w);
	}


	float getX()const{return this->x;}
	float getY()const{return this->y;}
	float getZ()const{return this->z;}
	float getW()const{return this->w;}



private:
	 float x;
	 float y;
	 float z;
	 float w;

};



#endif /* QUATERNION_H_ */
