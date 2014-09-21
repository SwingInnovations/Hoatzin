#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include "cmath"
#include "Vector.h"

#define ToRadian(x) (float)(((x) * M_PI / 180.0f))
#define ToDegree(x) (float)(((x) * 180.0f / M_PI))

class Vector3f;
class Vector4f;

class Matrix4f{
public:
    Matrix4f(){
        for(unsigned int i = 0; i < 4; i++){
        	for(unsigned int j = 0; j < 4; j++){
        		this->m[i][j] = 0.0;
        	}
        }
    }

    Matrix4f(Matrix4f& other)
    {
        this->m[4][4] = other.m[4][4];
    }

    Matrix4f(Vector3f& vec)
    {
        m[0][0] = vec.GetX(); m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 0.0;
        m[1][0] = 0.0; m[1][1] = vec.GetY(); m[1][2] = 0.0; m[1][3] = 0.0;
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = vec.GetZ(); m[2][3] = 0.0;
        m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
    }

    Matrix4f(Vector4f& vec)
    {
        m[0][0] = vec.GetX(); m[0][1] = 0; m[0][2] = 0.0; m[0][3] = 0.0;
        m[1][0] = 0.0; m[1][1] = vec.GetY(); m[1][2] = 0.0; m[1][3] = 0.0;
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = vec.GetZ(); m[2][3] = 0.0;
        m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = vec.GetW();
    }

    void InitIdentity(){
    	m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 0.0;
    	m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = 0.0;
    	m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = 0.0;
    	m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
    }

    void InitTranslation(float x, float y, float z)
    {
        m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = x;
        m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = y;
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = z;
        m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
    }

    void InitTranslation(Vector3f& vec)
    {
        m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = vec.GetX();
        m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = vec.GetY();
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = vec.GetZ();
        m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
    }

    void InitRotation(float angle, float u, float v, float w){
        float L = (u * u + v * v + w * w);
        angle = angle * 3.1415 / 180.0; //convert to radian
        float u2 = u * u;
        float v2 = v * v;
        float w2 = w * w;

        m[0][0] = (u2 + (v2 + w2) * cos((double)angle))/ L;
        m[0][1] = (u * v * (1 - cos((double)angle)) - w * sqrt(L) * sin((double)angle)) / L;
        m[0][2] = (u * w * (1 - cos((double)angle)) + v * sqrt(L) * sin((double)angle)) / L;
        m[0][3] = 0.0;

        m[1][0] = (u * v * (1 - cos((double)angle)) + w * sqrt(L) * sin((double)angle)) / L;
        m[1][1] = (v2 + (u2 + w2) * cos((double)angle)) / L;
        m[1][2] = (v * w * (1 - cos((double)angle)) - u * sqrt(L) * sin((double)angle)) / L;
        m[1][3] = 0.0;

        m[2][0] = (u * w * (1 - cos((double)angle)) - v * sqrt(L) * sin((double)angle)) / L;
        m[2][1] = (v * w * (1 - cos((double)angle)) + u * sqrt(L) * sin((double)angle)) / L;
        m[2][2] = (w2 + (u2 + v2) * cos((double)angle)) / L;
        m[2][3] = 0.0;

        m[3][0] = 0.0;
        m[3][1] = 0.0;
        m[3][2] = 0.0;
        m[3][3] = 1.0;
    }

    void InitRotation(float angle, Vector3f* vec){
        float L = (vec->GetX() * vec->GetX() + vec->GetY() * vec->GetY() + vec->GetZ() * vec->GetZ());
        angle = angle * 3.1315 / 180.0;

        float u = vec->GetX();
        float v = vec->GetY();
        float w = vec->GetZ();

        float u2 = vec->GetX() * vec->GetX();
        float v2 = vec->GetY() * vec->GetY();
        float w2 = vec->GetZ() * vec->GetZ();

        m[0][0] = (u2 + (v2 + w2) * cos((double)angle))/ L;
        m[0][1] = (u * v * (1 - cos((double)angle)) - w * sqrt(L) * sin((double)angle)) / L;
        m[0][2] = (u * w * (1 - cos((double)angle)) + v * sqrt(L) * sin((double)angle)) / L;
        m[0][3] = 0.0;

        m[1][0] = (u * v * (1 - cos((double)angle)) + w * sqrt(L) * sin((double)angle)) / L;
        m[1][1] = (v2 + (u2 + w2) * cos((double)angle)) / L;
        m[1][2] = (v * w * (1 - cos((double)angle)) - u * sqrt(L) * sin((double)angle)) / L;
        m[1][3] = 0.0;

        m[2][0] = (u * w * (1 - cos((double)angle)) - v * sqrt(L) * sin((double)angle)) / L;
        m[2][1] = (v * w * (1 - cos((double)angle)) + u * sqrt(L) * sin((double)angle)) / L;
        m[2][2] = (w2 + (u2 + v2) * cos((double)angle)) / L;
        m[2][3] = 0.0;

        m[3][0] = 0.0;
        m[3][1] = 0.0;
        m[3][2] = 0.0;
        m[3][3] = 1.0;
    }

    void InitScale(float x, float y, float z)
    {
        m[0][0] = x; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 0.0;
        m[1][0] = 0.0; m[1][1] = y; m[1][2] = 0.0; m[1][3] = 0.0;
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = z; m[2][3] = 0.0;
        m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
    }

    void InitScale(Vector3f& vec)
    {
        m[0][0] = vec.GetX(); m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 0.0;
        m[1][0] = 0.0; m[1][1] = vec.GetY(); m[1][2] = 0.0; m[1][3] = 0.0;
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = vec.GetZ(); m[2][3] = 0.0;
        m[3][0] = 0.0; m[3][1] = 0; m[3][2] = 0.0; m[3][3] = 1.0;
    }

    void InitPerspectiveProjection(float FOV, float WIDTH, float HEIGHT, float zNear, float zFar){
    	const float ar = WIDTH / HEIGHT;
    	const float tanHalfFOV = tanf(ToRadian(FOV/2.0));

    	m[0][0] = 1.0f / (tanHalfFOV * ar); m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 0.0;
    	m[1][0] = 0.0; m[1][1] = 1.0f / tanHalfFOV; m[1][2] = 0.0; m[1][3] = 0.0;
    	m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = -zFar/(zFar-zNear); m[2][3] = -zFar * zNear/(zFar - zNear);
    	m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = -1.0f; m[3][3] = 0.0;
    }

    void InitOrthographicProjection(){

    }

    void InitCamera(const Vector3f& target, const Vector3f& up){
    	Vector3f N = target;
    	N = N.Normalize();
    	Vector3f U = up;
    	U = U.Normalize();
    	U = U.cross(N);
    	Vector3f V;
    	V = N.cross(U);

    	m[0][0] = U.GetX(); m[0][1] = U.GetY(); m[0][2] = U.GetZ(); m[0][3] = 0.0;
    	m[1][0] = V.GetX(); m[1][1] = V.GetY(); m[1][2] = V.GetZ(); m[1][3] = 0.0;
    	m[2][0] = N.GetX(); m[2][1] = N.GetY(); m[2][2] = N.GetZ(); m[2][3] = 0.0;
    	m[3][0] = 0.0; 		m[3][1] = 0.0;		m[3][2] = 0.0; 		m[3][3] = 1.0;
    }

    Matrix4f Normalize(){
    	Matrix4f ret;
    	float length[4];
    	length[0] = m[0][0] + m[1][0] + m[2][0] + m[3][0];
    	length[1] = m[0][1] + m[1][1] + m[2][1] + m[3][1];
    	length[2] = m[0][2] + m[1][2] + m[2][2] + m[3][2];
    	length[3] = m[0][3] + m[1][3] + m[2][3] + m[3][3];

    	ret.m[0][0] = this->m[0][0]/length[0]; ret.m[0][1] = this->m[0][1]/length[1]; ret.m[0][2] = this->m[0][2]/length[2]; ret.m[0][3] = this->m[0][3]/length[3];
    	ret.m[1][0] = this->m[1][0]/length[0]; ret.m[1][1] = this->m[1][1]/length[1]; ret.m[1][2] = this->m[1][2]/length[2]; ret.m[1][3] = this->m[1][3]/length[3];
    	ret.m[2][0] = this->m[2][0]/length[0]; ret.m[2][1] = this->m[2][1]/length[1]; ret.m[2][2] = this->m[2][2]/length[2]; ret.m[2][3] = this->m[2][3]/length[3];
    	ret.m[3][0] = this->m[3][0]/length[0]; ret.m[3][1] = this->m[3][1]/length[1]; ret.m[3][2] = this->m[3][2]/length[2]; ret.m[3][3] = this->m[3][3]/length[3];

    	return ret;
    }

    float get(int x, int y)
    {
        return m[x][y];
    }

    void Print(){
    	for(unsigned int i = 0; i < 4; i++){
    		for(unsigned int j = 0; j < 4; j++){
    			std::cout << m[i][j] << " ";
    		}
    		std::cout << " " << std::endl;
    	}
    }

    Vector4f ToVector4f() const
    {
        const float _x = m[0][0] * 1 + m[0][1] * 1 + m[0][2] * 1 + m[0][3] * 1;
        const float _y = m[1][0] * 1 + m[1][1] * 1 + m[1][2] * 1 + m[1][3] * 1;
        const float _z = m[2][0] * 1 + m[2][1] * 1 + m[2][2] * 1 + m[2][3] * 1;
        const float _w = m[3][0] * 1 + m[3][1] * 1 + m[3][2] * 1 + m[3][3] * 1;
        return Vector4f(_x, _y, _z, _w);
    }

    inline Matrix4f operator*(const Matrix4f &right) const
    {
        Matrix4f Ret;

        for(unsigned int i = 0; i < 4; i++)
        {
            for(unsigned int j = 0; j < 4; j++)
            {
                 Ret.m[i][j] = m[i][0] * right.m[0][j] +
                               m[i][1] * right.m[1][j] +
                               m[i][2] * right.m[2][j] +
                               m[i][3] * right.m[3][j];
            }
        }
        return Ret;
    }

    float m[4][4];
};


#endif /* MATRIX_H_ */
