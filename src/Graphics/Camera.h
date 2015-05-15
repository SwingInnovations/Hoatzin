#ifndef CAMERA_H_
#define CAMERA_H_

#include "../STechOne.h"

namespace CAMERA_VIEW{
	enum Mode{
		PERSPECTIVE = 0,
		ORTHOGRAPHIC = 1
	};
};

namespace CAMERA_MOVEMENT{
	enum Mode{
		FirstPerson = 0,
		ThirdPerson = 1,
		ISOMETRIC = 2,
		LOCKED = 3
	};
};

class Camera{
public:
	Camera();

	Camera(AppWindow& app, Vector3f& pos, float FOV, float zNear, float zFar);
	Camera(AppWindow& app, Vector3f& pos, float FOV, float zNear, float zFar, int _viewMode, int _moveMode);

	Camera(Vector3f& pos, float FOV, float WIDTH, float HEIGHT, float zNear, float zFar);
	Camera(Vector3f& pos, float FOV, float WIDTH, float HEIGHT, float zNear, float zFar, int _viewMode, int _moveMode);

	void setViewMode(int mode){viewMode = mode;}
	void setMoveMode(int mode){moveMode = mode;}

	void setRotateX(const float _x);
	void setRotateY(const float _y);

	void init();
	void update();
	void update(Input *input);

	void info()const{
		std::cout << "m_Forward: " << mForward.info() << std::endl;
		std::cout << "m_Up: " << mUp.info() << std::endl;
	}
	void setYaw(float _h){ hAngle = _h; }
	void setPitch(float _v){ vAngle = _v; }
	void setFOV(float fov ){ mFOV = fov; }
	void setNear(float zNear ){ mZNear = zNear; }
	void setFar(float zFar){ mZFar = zFar; }
	float getYaw(){return this->hAngle;}
	float getPitch(){return this->vAngle;}
	float getFOV()const{ return mFOV; }
	float getZNear()const{ return mZNear; }
	float getZFar()const{ return mZFar; }

	Transform getTransform()const{return this->transform;}

	void setTranslate(Vector3f& vec){transform.setTranslate(vec);}
	void setTranslateX(float _x){transform.setTranslateX(_x);}
	void setTranslateY(float _y){transform.setTranslateY(_y);}
	void setTranslateZ(float _z){transform.setTranslateZ(_z);}

	void setScale(Vector3f& vec){transform.setScale(vec);}
	void setScaleX(float _x){transform.setScaleX(_x);}
	void setScaleY(float _y){transform.setScaleY(_y);}
	void setScaleZ(float _z){transform.setScaleZ(_z);}

	Transform getTransform(){return transform;}
	Matrix4f getViewProjection();
	Vector3f getLeft(){
		Vector3f left = mForward.cross(mUp);
		left.normalize();
		return left;
	}

	Vector3f getRight(){
		Vector3f right = mUp.cross(mForward);
		right.normalize();
		return right;
	}
private:
	void processFPS(Input* input);

	Transform transform;
	bool start;
	int viewMode;
	int moveMode;
	Vector3f mForward;
	Vector3f mUp;
	Vector3f yAxis;
	Vector3f mView;
	Vector3f mPosition;
	float mFOV, mWIDTH, mHEIGHT, mZNear, mZFar, hAngle, vAngle;
};



#endif /* CAMERA_H_ */
