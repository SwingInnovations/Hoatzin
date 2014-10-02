#include "../Utility/SWObject.h"
#include "Camera.h"

Camera::Camera(){
	mFOV = 0.0;
	mWIDTH = 0.0;
	mHEIGHT = 0.0;
	mZNear = 0.0;
	mZFar = 0.0;
}

Camera::Camera(CameraType camType, AppWindow& app, Vector3f& pos, float FOV, float zNear, float zFar){
	mCameraType = camType;
	mWIDTH = app.GetWidth();
	mHEIGHT = app.GetHeight();
	mFOV = FOV;
	mZNear = zNear;
	mZFar = zFar;

	mForward = Vector3f(0.0, 0.0, 1.0);
	mUp = Vector3f(0.0, 1.0, 0.0);
	mView = Vector3f(1.0, 0.0, 0.0);
}

Camera::Camera(Vector3f& pos, float FOV, float WIDTH, float HEIGHT, float zNear, float zFar){
	mFOV = FOV;
	mWIDTH = WIDTH;
	mHEIGHT = HEIGHT;
	mZNear = zNear;
	mZFar = zFar;

	mPosition = pos;
	mForward = Vector3f(0.0, 0.0, 1.0);
	mForward.Normalize();
	mUp = Vector3f(0.0, 1.0, 0.0);
	mUp.Normalize();
	mView = Vector3f(1.0, 0.0, 0.0);

	Vector3f HTarget(mForward.GetX(), 0.0f, mForward.GetZ());
	HTarget.Normalize();
	if(HTarget.GetZ() >= 0.0f){
		if(HTarget.GetX() >= 0.0f){
			hAngle = 360.0f - ToDegree(asin(HTarget.GetZ()));
		}else{
			hAngle = 360.0f - ToDegree(asin(HTarget.GetZ()));
		}
	}else{
		if(HTarget.GetX() >= 0.0f){
			hAngle = ToDegree(asin(-HTarget.GetZ()));
		}else{
			hAngle = 90.0f + ToDegree(asin(-HTarget.GetZ()));
		}
	}

	vAngle = ToDegree(asin(mForward.GetY()));

}

void Camera::Update(Input &input){

	if(hAngle > 360.0f){
		hAngle = 0.0f;
	}

	hAngle += 0.035f * (float)((1024/2) - input.getMouseCoord().GetX());
	vAngle += 0.035f * (float)((768/2) - input.getMouseCoord().GetY());

	Vector3f vAxis(0.0f, 1.0f, 0.0f);

	mView = Vector3f(1.0f, 0.0f, 0.0f);
	mView.Rotate(hAngle, vAxis);
	mView.Normalize();

	Vector3f hAxis = vAxis.cross(mView);
	hAxis.Normalize();
	mView.Rotate(vAngle, hAxis);

	mForward = mView;
	mForward.Normalize();

	mUp = mForward.cross(hAxis);
	mUp.Normalize();

	input.CenterMouseInWindow();
}

Matrix4f Camera::GetViewProjection(){
	Matrix4f View, Camera, Perspective;
	Perspective.InitPerspectiveProjection(mFOV, mWIDTH, mHEIGHT, mZNear, mZFar);
	Camera.InitCamera(mForward, mUp);
	View = Perspective * this->transform.GetModel() * Camera;
	return View;
}
