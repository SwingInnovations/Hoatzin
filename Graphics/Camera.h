/*
 * Camera.h
 *
 *  Created on: Jun 30, 2014
 *      Author: Nathan_z400
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "../Utility/Math/Matrix.h"
#include "../Utility/Math/Vector.h"
#include "../Utility/SWObject.h"

class Camera : public SWObject{
public:
	Camera(){
		this->position = Vector3f(0.0, 0.0, 0.0);
		mFOV = 0.0;
		mWIDTH = 0.0;
		mHEIGHT = 0.0;
		mZNear = 0.0;
		mZFar = 0.0;

	}
	Camera(Vector3f& pos, float FOV, float WIDTH, float HEIGHT, float zNear, float zFar){
//		std::cout << " " << std::endl;
//		mPerspective.InitPerspectiveProjection(FOV, WIDTH, HEIGHT, zNear, zFar);
//		mPerspective.Print();
//		std::cout << " " << std::endl;
//		this->position = pos;
//		mForward = Vector3f(0.0, 0.0, 1.0);
//		mUp = Vector3f(0.0, 1.0, 0.0);
//		mCameraProjection.InitCamera(mForward, mUp);
//
//		mCameraProjection.Print();
//
//		mViewProjection = mPerspective * this->transform.GetModel() * mCameraProjection;
//
//		std::cout << " " << std::endl;
//		mViewProjection.Print();

		mFOV = FOV;
		mWIDTH = WIDTH;
		mHEIGHT = HEIGHT;
		mZNear = zNear;
		mZFar = zFar;

		mForward = Vector3f(0.0, 0.0, 1.0);
		mUp = Vector3f(0.0, 1.0, 0.0);
	}

	void SetTranslateX(const float _x){
		this->transform.SetTranslateX(_x);
	}

	const Matrix4f GetViewProjection(){
		Matrix4f View, Camera, Perspective;
		Perspective.InitPerspectiveProjection(mFOV, mWIDTH, mHEIGHT, mZNear, mZFar);
		Camera.InitCamera(mForward, mUp);
		View = Perspective * this->transform.GetModel() * Camera;
		return View;
;	}
private:
	Vector3f mForward;
	Vector3f mUp;
	float mFOV, mWIDTH, mHEIGHT, mZNear, mZFar;
};



#endif /* CAMERA_H_ */
