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
	Camera(){}
	Camera(Vector3f& pos, float FOV, float WIDTH, float HEIGHT, float zNear, float zFar){
		mPerspective.InitPerspectiveProjection(FOV, WIDTH, HEIGHT, zNear, zFar);
		this->position = pos;
		mForward = Vector3f(0.0, 0.0, 1.0);
		mUp = Vector3f(0.0, 1.0, 0.0);
		mCameraProjection.InitCamera(this->position, mUp);
	}

	Matrix4f GetViewProjection(){
		Matrix4f ret;
		ret = mPerspective * mCameraProjection;
		return ret;
	}
private:
	Matrix4f mPerspective;
	Matrix4f mCameraProjection;
	Vector3f mForward;
	Vector3f mUp;
};



#endif /* CAMERA_H_ */
