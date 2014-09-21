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
}

Camera::Camera(Vector3f& pos, float FOV, float WIDTH, float HEIGHT, float zNear, float zFar){
	mFOV = FOV;
	mWIDTH = WIDTH;
	mHEIGHT = HEIGHT;
	mZNear = zNear;
	mZFar = zFar;

	mPosition = pos;
	mForward = Vector3f(0.0, 0.0, 1.0);
	mUp = Vector3f(0.0, 1.0, 0.0);
}

void Camera::Update(Input &input){
	mRotX = input.getMouseCoord().GetX();
	mRotY = input.getMouseCoord().GetY();

	Vector3f vAxis(0.0f, 1.0f, 0.0f);

	Vector3f view(1.0f, 0.0f, 0.0f);
	view.Rotate(mRotX, vAxis);
	view.Normalize();

	Vector3f hAxis = vAxis.cross(view);
	hAxis.Normalize();
	view.Rotate(mRotY, hAxis);

	mForward = view;
	mForward.Normalize();

	mUp = mForward.cross(hAxis);
	mUp.Normalize();
}

Matrix4f Camera::GetViewProjection(){
	Matrix4f View, Camera, Perspective;
	Perspective.InitPerspectiveProjection(mFOV, mWIDTH, mHEIGHT, mZNear, mZFar);
	Camera.InitCamera(mForward, mUp);
	View = Perspective * this->transform.GetModel() * Camera;
	return View;
}
