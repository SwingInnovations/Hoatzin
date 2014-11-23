#ifndef VECTOR_H_
#define VECTOR_H_

#include <cmath>
#include <iostream>

class Quaternion;
class Vector2f;

#define ToRadian(x) (float)(((x)* M_PI / 180.f))

class Vector2f{
public:
	Vector2f(){
		x = 0.0;
		y = 0.0;
	}

	Vector2f(const float _x, const float _y){
		this->x = _x;
		this->y = _y;
	}

	void setX(float _x){ x = _x; }
	void setY(float _y){ y = _y; }

	float getLengthF(){ return sqrtf(x * x + y * y);}
	double getLength(){ return sqrt(x * x + y * y); }

	Vector2f normalize(){
		x /= getLength();
		y /= getLength();
		return *this;
	}

	void print(){
		std::cout << "X: " << this->x << std::endl;
		std::cout << "Y: " << this->y << std::endl;
	}

	const float getX(){ return x; }
	const float getY(){ return y; }

	const Vector2f operator+(const Vector2f& vec){
		float _x = this->x + vec.x;
		float _y = this->y + vec.y;
		return Vector2f(_x, _y);
	}

	const Vector2f operator-(const Vector2f& vec){
			float _x = this->x - vec.x;
			float _y = this->y - vec.y;
			return Vector2f(_x, _y);
	}

	const Vector2f operator*(const Vector2f& vec){
			float _x = this->x * vec.x;
			float _y = this->y * vec.y;
			return Vector2f(_x, _y);
	}

	const Vector2f operator/(const Vector2f& vec){
			float _x = this->x / vec.x;
			float _y = this->y / vec.y;
			return Vector2f(_x, _y);
	}

private:
	float x;
	float y;
};

class Quaternion;

class Vector3f{
public:
	Vector3f(){
		x = 0.0;
		y = 0.0;
		z = 0.0;
	}

	Vector3f(const float _x, const float _y, const float _z){
		this->x = _x;
		this->y = _y;
		this->z = _z;
	}

	float getLengthF(){ return sqrtf(x * x + y * y + z * z); }
	double GetLength(){ return sqrt(x * x + y * y + z * z); }

	Vector3f normalize(){
		x /= GetLength();
		y /= GetLength();
		z /= GetLength();
		return *this;
	}

	double dot(const Vector3f& other){
		return x * other.x + y * other.y + z * other.z;
	}

	Vector3f cross(const Vector3f& other){
		float _x = (this->y * other.z) - (this->z * other.y);
		float _y = (this->z * other.x) - (this->x * other.z);
		float _z = (this->x * other.y) - (this->y * other.x);
		return Vector3f(_x, _y, _z);
	}

	void rotate(float angle, Vector3f& axis);

	void print(){
		std::cout << "X: " << this->x << std::endl;
		std::cout << "Y: " << this->y << std::endl;
		std::cout << "Z: " << this->z << std::endl;
	}

	void setX(const float _x){this->x = _x;}
	void setY(const float _y){this->y = _y;}
	void setZ(const float _z){this->z = _z;}

	float getX(){ return this->x; }
	float getY(){ return this->y; }
	float getZ(){ return this->z; }

	const Vector3f operator+(const Vector3f& vec){
		const float _x = this->x + vec.x;
		const float _y = this->y + vec.y;
		const float _z = this->z + vec.z;
		return Vector3f(_x, _y, _z);
	}

	const Vector3f operator-(const Vector3f& vec){
		const float _x = this->x - vec.x;
		const float _y = this->y - vec.y;
		const float _z = this->z - vec.z;
		return Vector3f(_x, _y, _z);
	}

	const Vector3f operator*(const Vector3f& vec){
		const float _x = this->x * vec.x;
		const float _y = this->y * vec.y;
		const float _z = this->z * vec.z;
		return Vector3f(_x, _y, _z);
	}

	const Vector3f operator/(const Vector3f& vec){
		const float _x = this->x / vec.x;
		const float _y = this->y / vec.y;
		const float _z = this->z / vec.z;
		return Vector3f(_x, _y, _z);
	}

private:
	float x;
	float y;
	float z;
};

class Vector3i{
public:
	Vector3i(){
		x = 0;
		y = 0;
		z = 0;
	}

	Vector3i(int _x, int _y, int _z){
		x = _x;
		y = _y;
		z = _z;
	}

	Vector3f toVector3f()const{
		return Vector3f(x, y, z);
	}

private:
	int x;
	int y;
	int z;
};

class Vector4f{
public:
    Vector4f(){
    	x = 0.0;
    	y = 0.0;
    	z = 0.0;
    	w = 0.0;
    }
    Vector4f(float _x, float _y, float _z, float _w)
    {
        this->x = _x;
        this->y = _y;
        this->z = _z;
        this->w = _w;
    }

    Vector4f(const Vector4f& vec)
    {
        this->x = vec.x;
        this->y = vec.y;
        this->z = vec.z;
        this->w = vec.w;
    }

	void print(){
		std::cout << "X: " << this->x << std::endl;
		std::cout << "Y: " << this->y << std::endl;
		std::cout << "Z: " << this->z << std::endl;
		std::cout << "W: " << this->w << std::endl;
	}

    void setX(float _x){ this->x = _x; }
    void setY(float _y){ this->y = _y; }
    void setZ(float _z){ this->z = _z; }
    void setW(float _w){ this->w = _w; }

    double Dot(const Vector4f& other)
    {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }

    double getLength(){ return sqrt(x * x + y * y + z * z + w * w); }

    Vector4f normalize()
    {
        x /= getLength();
        y /= getLength();
        z /= getLength();
        w /= getLength();

        return *this;
    }

    Vector3f toVec3()
    {
        return Vector3f(x, y, z);
    }

    Vector4f operator*(const Vector4f& vec)
    {
        const float _x = this->x * vec.x;
        const float _y = this->y * vec.y;
        const float _z = this->z * vec.z;
        const float _w = this->w * vec.w;
        return Vector4f(_x, _y, _z, _w);
    }

    float getX(){ return x; }
    float getY(){ return y; }
    float getZ(){ return z; }
    float getW(){ return w; }

private:
    float x;
    float y;
    float z;
    float w;
};

#endif /* VECTOR_H_ */
