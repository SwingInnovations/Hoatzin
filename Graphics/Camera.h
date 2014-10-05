#ifndef CAMERA_H_
#define CAMERA_H_

#include "../Utility/Math/Matrix.h"
#include "../Utility/Math/Vector.h"
#include "../AppWindow.h"

class AppWindow;

class Camera{
public:
	enum CameraType{Perspective, Orthographic};

	Camera();

	Camera(CameraType camType, AppWindow& app, Vector3f& pos, float FOV, float zNear, float zFar);

	Camera(Vector3f& pos, float FOV, float WIDTH, float HEIGHT, float zNear, float zFar);
	void SetRotateX(const float _x);
	void SetRotateY(const float _y);

	void Init();
	void Update();
	void Update(Input &input);

	float GetYaw(){return this->hAngle;}
	float GetPitch(){return this->vAngle;}

	void SetTranslate(Vector3f& vec){transform.SetTranslate(vec);}
	void SetTranslateX(float _x){transform.SetTranslateX(_x);}
	void SetTranslateY(float _y){transform.SetTranslateY(_y);}
	void SetTranslateZ(float _z){transform.SetTranslateZ(_z);}

	void SetScale(Vector3f& vec){transform.SetScale(vec);}
	void SetScaleX(float _x){transform.SetScaleX(_x);}
	void SetScaleY(float _y){transform.SetScaleY(_y);}
	void SetScaleZ(float _z){transform.SetScaleZ(_z);}

	Matrix4f GetViewProjection();
	Vector3f GetLeft(){
		Vector3f left = mForward.cross(mUp);
		left.Normalize();
		return left;
	}

	Vector3f GetRight(){
		Vector3f right = mUp.cross(mForward);
		right.Normalize();
		return right;
	}
private:
	Transform transform;
	CameraType mCameraType;
	Vector3f mForward;
	Vector3f mUp;
	Vector3f yAxis;
	Vector3f mView;
	Vector3f mPosition;
	float mFOV, mWIDTH, mHEIGHT, mZNear, mZFar, mDeltaX, mDeltaY, mPasX, mPasY, hAngle, vAngle;
};



#endif /* CAMERA_H_ */
