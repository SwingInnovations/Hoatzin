#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include <iostream>
#include "Math/Vector.h"
#include "Math/Matrix.h"

class Transform{
public:
    Transform(){
        translate = Vector3f(0.0, 0.0, 0.0);
        rotate = Vector3f(0.0, 0.0, 0.0);
        scale = Vector3f(1.0, 1.0, 1.0);
    }

     	const Matrix4f GetModel(){

    	Matrix4f transMat, rotXMat, rotYMat, rotZMat, scaleMat;

    	transMat.InitTranslation(translate);
    	rotXMat.InitRotation(rotate.GetX(), new Vector3f(1.0, 0.0, 0.0));
    	rotYMat.InitRotation(rotate.GetY(), new Vector3f(0.0, 1.0, 0.0));
    	rotZMat.InitRotation(rotate.GetZ(), new Vector3f(0.0, 0.0, 1.0));
    	scaleMat.InitScale(scale);

        Matrix4f ret, rotMat;
        rotMat = rotZMat * rotYMat * rotXMat;

        ret = scaleMat * rotMat * transMat;

        ret.Print();

        return ret;
    }

    void SetTranslate(Vector3f& vec){this->translate = vec;}
    void SetTranslateX(float _x){this->translate.SetX(_x);}
    void SetTranslateY(float _y){this->translate.SetY(_y);}
    void SetTranslateZ(float _z){this->translate.SetZ(_z);}

    void SetRotate(Vector3f& vec){this->rotate = vec;}
    void SetRotateX(float _x){this->rotate.SetX(_x);}
    void SetRotateY(float _y){this->rotate.SetY(_y);}
    void SetRotateZ(float _z){this->rotate.SetZ(_z);}

    void SetScale(Vector3f& vec){this->scale = vec;}
    void SetScaleX(float _x){this->scale.SetX(_x);}
    void SetScaleY(float _y){this->scale.SetY(_y);}
    void SetScaleZ(float _z){this->scale.SetZ(_z);}

    Vector3f GetTranslation(){return this->translate;}
    Vector3f GetRotate(){return this->rotate;}
    Vector3f GetScale(){return this->scale;}

private:
    Vector3f translate;
    Vector3f scale;
    Vector3f rotate;
};


#endif /* TRANSFORM_H_ */
