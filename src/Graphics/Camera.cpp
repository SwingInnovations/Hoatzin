#include "Camera.h"

Camera::Camera(){
	mFOV = 0.0;
	mWIDTH = 0.0;
	mHEIGHT = 0.0;
	mZNear = 0.0;
	mZFar = 0.0;
	yAxis = Vector3f(0.0f, 1.0f, 0.0f);
	start = false;
}

Camera::Camera(AppWindow& app, Vector3f& pos, float FOV, float zNear, float zFar){
	mWIDTH = app.getWidth();
	mHEIGHT = app.getHeight();
	mFOV = FOV;
	mZNear = zNear;
	mZFar = zFar;

	mForward = Vector3f(0.0, 0.0, 1.0);
	mUp = Vector3f(0.0, 1.0f, 0.0);
	mView = Vector3f(1.0f, 0.0, 0.0);
	yAxis = Vector3f(0.0f, 1.0f, 0.0f);
	start = false;
	hAngle = 0;
	vAngle = 0;
	transform.setTranslate(pos);
}

Camera::Camera(AppWindow& app, Vector3f& pos, float FOV, float zNear, float zFar, int _viewMode, int _moveMode){
	mWIDTH = app.getWidth();
	mHEIGHT = app.getHeight();
	mFOV = FOV;
	mZNear = zNear;
	mZFar = zFar;

	mPosition = pos;
	transform.setTranslate(pos);
	mForward = Vector3f(0.0f, 0.0f, 1.0f);
	mUp = Vector3f(0.0, 1.0f, 0.0f);
	mView = Vector3f(1.0f, 0.0f, 0.0f);
	viewMode = _viewMode;
	moveMode = _moveMode;

	hAngle = 0;
	vAngle = 0;

	start = false;
}

Camera::Camera(Vector3f& pos, float FOV, float WIDTH, float HEIGHT, float zNear, float zFar){
	mFOV = FOV;
	mWIDTH = WIDTH;
	mHEIGHT = HEIGHT;
	mZNear = zNear;
	mZFar = zFar;

	mPosition = pos;
	transform.setTranslate(pos);
	mForward = Vector3f(1.0f, 0.0, 0.0);
	mUp = Vector3f(0.0, 1.0f, 0.0);
	mView = Vector3f(0.0f, 0.0, 1.0f);

	hAngle = 0;
	vAngle = 0;
	start = false;
}

Camera::Camera(Vector3f& pos, float FOV, float WIDTH, float HEIGHT, float zNear, float zFar, int _viewMode, int _moveMode){
	mPosition = pos;
	mFOV = FOV;
	mWIDTH = WIDTH;
	mHEIGHT = HEIGHT;
	mZNear = zNear;
	mZFar = zFar;

	mForward = Vector3f(0.0f, 0.0f, 1.0f);
	mUp = Vector3f(0.0f, 1.0f, 0.0f);
	mView = Vector3f(1.0f, 0.0f, 0.0f);
	transform.setTranslate(pos);

	hAngle = 0;
	vAngle = 0;
	viewMode = _viewMode;
	moveMode = _moveMode;
	start = false;
}

void Camera::update(){
	Vector3f vAxis(0.0f, 1.0f, 0.0f);

	mView = Vector3f(1.0f, 0.0f, 0.0f);
	mView.rotate(hAngle, vAxis);
	mView.normalize();

	Vector3f hAxis = vAxis.cross(mView);
	hAxis.normalize();
	mView.rotate(vAngle, hAxis);

	mForward = mView;
	mForward.normalize();

	mUp = mForward.cross(hAxis);
	mUp.normalize();

}

void Camera::setRotateX(const float _x){
	Vector3f hAxis = yAxis.cross(mForward);
	hAxis.print();
	hAxis.normalize();

	mForward.rotate(_x, yAxis);

	mForward.normalize();
	mUp = mForward.cross(hAxis);
	mUp.normalize();
}

void Camera::setRotateY(const float _y){
	Vector3f hAxis = yAxis.cross(mForward);
	hAxis.normalize();
	mForward.rotate(_y, hAxis);
	mForward.normalize();
	mUp = mForward.cross(hAxis);
	mUp.normalize();
}

void Camera::update(Input *input){
	if(moveMode == CAMERA_MOVEMENT::FirstPerson){
		processFPS(input);

		int delta = input->getDelta();

		if(input->isKeyDown(input->inputMapping()->get(MOVEMENT::FORWARD))){
			float _x = transform.getTranslate().getX();
			float _z = transform.getTranslate().getZ();
			_x += mForward.getX() * 0.0025f * delta;
			_z += mForward.getZ() * 0.0025f * delta;
			setTranslateX(_x);
			setTranslateZ(_z);
		}

		if(input->isKeyDown(input->inputMapping()->get(MOVEMENT::BACKWARD))){
			float _x = transform.getTranslate().getX();
			float _z = transform.getTranslate().getZ();
			_x -= mForward.getX() * 0.0025f * delta;
			_z -= mForward.getZ() * 0.0025f * delta;
			setTranslateX(_x);
			setTranslateZ(_z);
		}

		Vector3f right = mForward.cross(mUp);
		right.normalize();

		if(input->isKeyDown(input->inputMapping()->get(MOVEMENT::STRAFE_LEFT))){
			float _x = transform.getTranslate().getX();
			float _z = transform.getTranslate().getZ();
			_x -= right.getX() * 0.0025f * delta;
			_z -= right.getZ() * 0.0025f * delta;
			setTranslateX(_x);
			setTranslateZ(_z);
		}

		if(input->isKeyDown(input->inputMapping()->get(MOVEMENT::STRAFE_RIGHT))){
			float _x = transform.getTranslate().getX();
			float _z = transform.getTranslate().getZ();
			_x += right.getX() * 0.0025f * delta;
			_z += right.getZ() * 0.0025f * delta;
			setTranslateX(_x);
			setTranslateZ(_z);
		}

	}else if(moveMode == CAMERA_MOVEMENT::ThirdPerson){

	}else if(moveMode == CAMERA_MOVEMENT::ISOMETRIC){

	}else{

	}
}

void Camera::processFPS(Input* input){
	if(!start){
		input->CenterMouseInWindow();
		hAngle = 0;
		vAngle = 0;
		Vector3f vAxis(0.0f, 1.0f, 0.0f);

		mView = Vector3f(1.0f, 0.0f, 0.0f);
		mView.rotate(hAngle, vAxis);
		mView.normalize();

		Vector3f hAxis = vAxis.cross(mView);
		hAxis.normalize();
		mView.rotate(vAngle, hAxis);

		mForward = mView;
		mForward.normalize();

		mUp = mForward.cross(hAxis);
		mUp.normalize();
		start = true;
	}else{
		hAngle += 0.035f * (float)((mWIDTH/2) - input->getMouseCoord().getX());
		vAngle += 0.035f * (float)((mHEIGHT/2) - input->getMouseCoord().getY());

		Vector3f vAxis(0.0f, 1.0f, 0.0f);

		mView = Vector3f(1.0f, 0.0f, 0.0f);
		mView.rotate(hAngle, vAxis);
		mView.normalize();

		Vector3f hAxis = vAxis.cross(mView);
		hAxis.normalize();
		mView.rotate(vAngle, hAxis);

		mForward = mView;
		mForward.normalize();

		mUp = mForward.cross(hAxis);
		mUp.normalize();
		input->CenterMouseInWindow();
	}
}

Matrix4f Camera::getViewProjection(){
	Matrix4f View, Camera, Perspective, TransformTranslate;
	Perspective.initPerspectiveProjection(mFOV, mWIDTH, mHEIGHT, mZNear, mZFar);
	Camera.initCamera(mForward, mUp);
	TransformTranslate.initTranslation(transform.getTranslate().getX(), transform.getTranslate().getY(), transform.getTranslate().getZ());
	View = Perspective * Camera * TransformTranslate;
	return View;
}
