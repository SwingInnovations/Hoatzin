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
        m[0][0] = vec.getX(); m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 0.0;
        m[1][0] = 0.0; m[1][1] = vec.getY(); m[1][2] = 0.0; m[1][3] = 0.0;
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = vec.getZ(); m[2][3] = 0.0;
        m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
    }

    Matrix4f(Vector4f& vec)
    {
        m[0][0] = vec.getX(); m[0][1] = 0; m[0][2] = 0.0; m[0][3] = 0.0;
        m[1][0] = 0.0; m[1][1] = vec.getY(); m[1][2] = 0.0; m[1][3] = 0.0;
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = vec.getZ(); m[2][3] = 0.0;
        m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = vec.getW();
    }

    void initIdentity(){
    	m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 0.0;
    	m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = 0.0;
    	m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = 0.0;
    	m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
    }

    void initTranslation(float x, float y, float z)
    {
        m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = x;
        m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = y;
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = z;
        m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
    }

    void initTranslation(Vector3f& vec)
    {
        m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = vec.getX();
        m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = vec.getY();
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = vec.getZ();
        m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
    }

    void initRotation(float angle, float u, float v, float w){
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

    void initRotation(float angle, Vector3f* vec){
        float L = (vec->getX() * vec->getX() + vec->getY() * vec->getY() + vec->getZ() * vec->getZ());
        angle = angle * 3.1315 / 180.0;

        float u = vec->getX();
        float v = vec->getY();
        float w = vec->getZ();

        float u2 = vec->getX() * vec->getX();
        float v2 = vec->getY() * vec->getY();
        float w2 = vec->getZ() * vec->getZ();

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

    void initScale(float x, float y, float z)
    {
        m[0][0] = x; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 0.0;
        m[1][0] = 0.0; m[1][1] = y; m[1][2] = 0.0; m[1][3] = 0.0;
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = z; m[2][3] = 0.0;
        m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
    }

    void initScale(Vector3f& vec)
    {
        m[0][0] = vec.getX(); m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 0.0;
        m[1][0] = 0.0; m[1][1] = vec.getY(); m[1][2] = 0.0; m[1][3] = 0.0;
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = vec.getZ(); m[2][3] = 0.0;
        m[3][0] = 0.0; m[3][1] = 0; m[3][2] = 0.0; m[3][3] = 1.0;
    }

    void initPerspectiveProjection(float FOV, float WIDTH, float HEIGHT, float zNear, float zFar){
    	const float ar = WIDTH / HEIGHT;
    	const float tanHalfFOV = tanf(ToRadian(FOV/2.0));

    	m[0][0] = 1.0f / (tanHalfFOV * ar); m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 0.0;
    	m[1][0] = 0.0; m[1][1] = 1.0f / tanHalfFOV; m[1][2] = 0.0; m[1][3] = 0.0;
    	m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = -zFar/(zFar-zNear); m[2][3] = -zFar * zNear/(zFar - zNear);
    	m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = -1.0f; m[3][3] = 0.0;
    }

    void initOrthographicProjection(){

    }

    void initCamera(const Vector3f& target, const Vector3f& up){
    	Vector3f N = target;
    	N.normalize();
    	Vector3f U = up;
    	U.normalize();
    	U = U.cross(N);
    	Vector3f V;
    	V = N.cross(U);

    	m[0][0] = U.getX(); m[0][1] = U.getY(); m[0][2] = U.getZ(); m[0][3] = 0.0;
    	m[1][0] = V.getX(); m[1][1] = V.getY(); m[1][2] = V.getZ(); m[1][3] = 0.0;
    	m[2][0] = N.getX(); m[2][1] = N.getY(); m[2][2] = N.getZ(); m[2][3] = 0.0;
    	m[3][0] = 0.0; 		m[3][1] = 0.0;		m[3][2] = 0.0; 		m[3][3] = 1.0f;
    }

    void initCamera(const Vector3f& target, const Vector3f& up, const Vector3f& view){
    	Vector3f N = target;
    	Vector3f U = up;
    	Vector3f V = view;

    	m[0][0] = U.getX(); m[0][1] = U.getY(); m[0][2] = U.getZ(); m[0][3] = 0.0;
    	m[1][0] = V.getX(); m[1][1] = V.getY(); m[1][2] = V.getZ(); m[1][3] = 0.0;
    	m[2][0] = N.getX(); m[2][1] = N.getY(); m[2][2] = N.getZ(); m[2][3] = 0.0;
    	m[3][0] = 0.0; 		m[3][1] = 0.0;		m[3][2] = 0.0; 		m[3][3] = 1.0;
    }

    Matrix4f normalize(){
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

    void print(){
    	for(unsigned int i = 0; i < 4; i++){
    		for(unsigned int j = 0; j < 4; j++){
    			std::cout << m[i][j] << " ";
    		}
    		std::cout << " " << std::endl;
    	}
    }

    Vector4f toVector4f() const
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
