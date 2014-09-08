#ifndef SWOBJECT_H_
#define SWOBJECT_H_

#include "Math/Vector.h"
#include "Transform.h"
#include "../Graphics/Shader.h"
#include "../Graphics/Texture.h"
#include "../Graphics/Graphics.h"

class SWObject{
public:
	SWObject(){}
	virtual ~SWObject(){}
	Vector3f *Position(){return &this->position;}
	Vector3f position;
	Transform transform;
	//Mesh mesh
	//Shader shader
	//Texture tex

	void SetTranslate(Vector3f& vec){transform.SetTranslate(vec);}
	void SetTranslateX(float _x){transform.SetTranslateX(_x);}
	void SetTranslateY(float _y){transform.SetTranslateY(_y);}
	void SetTranslateZ(float _z){transform.SetTranslateZ(_z);}

	void SetRotate(Vector3f& vec){transform.SetRotate(vec);}
	void SetRotateX(float _x){transform.SetRotateX(_x);}
	void SetRotateY(float _y){transform.SetRotateY(_y);}
	void SetRotateZ(float _z){transform.SetRotateZ(_z);}

	void SetScale(Vector3f& vec){transform.SetScale(vec);}
	void SetScaleX(float _x){transform.SetScaleX(_x);}
	void SetScaleY(float _y){transform.SetScaleY(_y);}
	void SetScaleZ(float _z){transform.SetScaleZ(_z);}

	//void Draw(Graphics g);
};



#endif /* SWOBJECT_H_ */
