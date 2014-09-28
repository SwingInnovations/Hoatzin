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
	void SetRotateX(const float _x){this->hAngle = _x;}
	void SetRotateY(const float _y){this->vAngle = _y;}

	void Init();
	void Update(Input &input);

	void SetTranslate(Vector3f& vec){transform.SetTranslate(vec);}
	void SetTranslateX(float _x){transform.SetTranslateX(_x);}
	void SetTranslateY(float _y){transform.SetTranslateY(_y);}
	void SetTranslateZ(float _z){transform.SetTranslateZ(_z);}

	void SetScale(Vector3f& vec){transform.SetScale(vec);}
	void SetScaleX(float _x){transform.SetScaleX(_x);}
	void SetScaleY(float _y){transform.SetScaleY(_y);}
	void SetScaleZ(float _z){transform.SetScaleZ(_z);}

	Matrix4f GetViewProjection();
private:
	Transform transform;
	CameraType mCameraType;
	Vector3f mForward;
	Vector3f mUp;
	Vector3f mView;
	Vector3f mPosition;
	float mFOV, mWIDTH, mHEIGHT, mZNear, mZFar, mDeltaX, mDeltaY, mPasX, mPasY, hAngle, vAngle;
};



#endif /* CAMERA_H_ */
