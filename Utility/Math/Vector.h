
#ifndef VECTOR_H_
#define VECTOR_H_

#include <math.h>

class Vector2f;

class Vector2f{
public:
	Vector2f(){
		x = 0;
		y = 0;
	}

	Vector2f(const float _x, const float _y){
		this->x = _x;
		this->y = _y;
	}

	void SetX(float _x){ x = _x; }
	void SetY(float _y){ y = _y; }

	float GetLengthF(){ return sqrtf(x * x + y * y);}
	double GetLength(){ return sqrt(x * x + y * y); }

	Vector2f Normalize(){
		x /= GetLength();
		y /= GetLength();
		return *this;
	}

	const float GetX(){ return x; }
	const float GetY(){ return y; }

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

class Vector3f{
public:
	Vector3f(){
		x = 0;
		y = 0;
		z = 0;
	}

	Vector3f(const float _x, const float _y, const float _z){
		this->x = _x;
		this->y = _y;
		this->z = _z;
	}

	float GetLengthF(){ return sqrtf(x * x + y * y + z * z); }
	float GetLength(){ return sqrt(x * x + y * y + z * z); }

	Vector3f Normalize(){
		x /= GetLength();
		y /= GetLength();
		z /= GetLength();
		return *this;
	}

	double Dot(const Vector3f& other){
		return x * other.x + y * other.y + z * other.z;
	}

	Vector3f cross(const Vector3f& other){
		float _x = this->y * other.z - this->z * other.y;
		float _y = this->z * other.x - this->x * other.z;
		float _z = this->x * other.y - this->y * other.x;
		return Vector3f(_x, _y, _z);
	}

	void SetX(const float _x){this->x = _x;}
	void SetY(const float _y){this->y = _y;}
	void SetZ(const float _z){this->z = _z;}

	float GetX(){ return x; }
	float GetY(){ return y; }
	float GetZ(){ return z; }

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

class Vector4f{
public:
    Vector4f(){
    	x = 0;
    	y = 0;
    	z = 0;
    	w = 0;
    }
    Vector4f(float _x, float _y, float _z, float _w)
    {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    }

    Vector4f(const Vector4f& vec)
    {
        x = vec.x;
        y = vec.y;
        z = vec.z;
        w = vec.w;
    }

    void setX(float _x){ x = _x; }
    void setY(float _y){ y = _y; }
    void setZ(float _z){ z = _z; }
    void setW(float _w){ w = _w; }

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

    float GetX(){ return x; }
    float GetY(){ return y; }
    float GetZ(){ return z; }
    float GetW(){ return w; }

private:
    float x;
    float y;
    float z;
    float w;
};

#endif /* VECTOR_H_ */
