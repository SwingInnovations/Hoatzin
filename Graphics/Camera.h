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
#include "../AppWindow.h"

class AppWindow;

class Camera : public SWObject{
public:
	enum CameraType{Perspective, Orthographic};

	Camera(){
		this->position = Vector3f(0.0, 0.0, 0.0);
		mFOV = 0.0;
		mWIDTH = 0.0;
		mHEIGHT = 0.0;
		mZNear = 0.0;
		mZFar = 0.0;
	}

	Camera(CameraType camType, AppWindow& app, Vector3f& pos, float FOV, float zNear, float zFar){
		mCameraType = camType;
		mWIDTH = app.GetWidth();
		mHEIGHT = app.GetHeight();
		mFOV = FOV;
		mZNear = zNear;
		mZFar = zFar;
		mForward = Vector3f(0.0, 0.0, 1.0);
		mUp = Vector3f(0.0, 1.0, 0.0);
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

	void SetTranslateX(const float _x){this->transform.SetTranslateX(_x);}
	void SetTranslateY(const float _y){this->transform.SetTranslateY(_y);}
	void SetTranslateZ(const float _z){this->transform.SetTranslateZ(_z);}
//	void SetRotateX(const float _x){this->transform.SetRotateX(_x);}
//	void SetRotateY(const float _y){this->transform.SetRotateY(_y);}
//	void SetRotateZ(const float _z){this->transform.SetRotateZ(_z);}
	void SetYaw(const float _val){this->transform.SetRotateY(_val);}
	void SetPitch(const float _val){this->transform.SetRotateX(_val);}

	const Matrix4f GetViewProjection(){
		Matrix4f View, Camera, Perspective;
		Perspective.InitPerspectiveProjection(mFOV, mWIDTH, mHEIGHT, mZNear, mZFar);
		Camera.InitCamera(mForward, mUp);
		View = Perspective * this->transform.GetModel() * Camera;
		return View;
;	}
private:
	CameraType mCameraType;
	Vector3f mForward;
	Vector3f mUp;
	float mFOV, mWIDTH, mHEIGHT, mZNear, mZFar;
};



#endif /* CAMERA_H_ */