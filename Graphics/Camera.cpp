#include "../Utility/SWObject.h"
#include "Camera.h"

Camera::Camera(){
	mFOV = 0.0;
	mWIDTH = 0.0;
	mHEIGHT = 0.0;
	mZNear = 0.0;
	mZFar = 0.0;
	yAxis = Vector3f(0.0f, 1.0f, 0.0f);
	init = false;
}

Camera::Camera(CameraType camType, AppWindow& app, Vector3f& pos, float FOV, float zNear, float zFar){
	mCameraType = camType;
	mWIDTH = app.GetWidth();
	mHEIGHT = app.GetHeight();
	mFOV = FOV;
	mZNear = zNear;
	mZFar = zFar;

	mForward = Vector3f(0.0, 0.0, 1.0);
	mUp = Vector3f(0.0, 1.0f, 0.0);
	mView = Vector3f(1.0f, 0.0, 0.0);
	yAxis = Vector3f(0.0f, 1.0f, 0.0f);
	init = false;
}

Camera::Camera(Vector3f& pos, float FOV, float WIDTH, float HEIGHT, float zNear, float zFar){
	mFOV = FOV;
	mWIDTH = WIDTH;
	mHEIGHT = HEIGHT;
	mZNear = zNear;
	mZFar = zFar;

	mPosition = pos;
	mForward = Vector3f(0.0, 0.0, 1.0);
	mForward = mForward.Normalize();
	mUp = Vector3f(0.0, 1.0f, 0.0);
	mView = Vector3f(1.0f, 0.0, 0.0);
	yAxis = Vector3f(0.0f, 1.0f, 0.0f);

	hAngle = 0;
	vAngle = 0;
	init = false;
}

void Camera::Update(){
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

}

void Camera::SetRotateX(const float _x){
	Vector3f hAxis = yAxis.cross(mForward);
	hAxis.Print();
	hAxis.Normalize();

	mForward.Rotate(_x, yAxis);

	mForward.Normalize();
	mUp = mForward.cross(hAxis);
	mUp.Normalize();
}

void Camera::SetRotateY(const float _y){
	Vector3f hAxis = yAxis.cross(mForward);
	hAxis.Normalize();
	mForward.Rotate(_y, hAxis);
	mForward.Normalize();
	mUp = mForward.cross(hAxis);
	mUp.Normalize();
}

void Camera::Update(Input &input){

	if(!init){
		hAngle = 0;
		vAngle = 0;
		input.CenterMouseInWindow();
		init = true;
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
	Matrix4f View, Camera, Perspective, TransformTranslate;
	Perspective.InitPerspectiveProjection(mFOV, mWIDTH, mHEIGHT, mZNear, mZFar);
	Camera.InitCamera(mForward, mUp);
	TransformTranslate.InitTranslation(transform.GetTranslation().GetX(), transform.GetTranslation().GetY(), transform.GetTranslation().GetZ());
	View = Perspective * TransformTranslate * Camera;
	return View;
}
