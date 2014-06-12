#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Math/Vector.h"
#include "Math/Matrix.h"

class Transform{
    Transform(){
        translate = Vector3f();
        rotate = Vector3f();
        scale = Vector3f(1.0, 1.0, 1.0);
    }

    Matrix4f GetModel(){
        Matrix4f transMat = Matrix4f::InitTranslation(translate);
        Matrix4f rotXMat = Matrix4f::InitRotation(rotate.GetX(), new Vector3f(1.0, 0.0, 0.0));
        Matrix4f rotYMat = Matrix4f::InitRotation(rotate.GetY(), new Vector3f(0.0, 1.0, 0.0));
        Matrix4f rotZMat = Matrix4f::InitRotation(rotate.GetZ(), new Vector3f(0.0, 0.0, 1.0));
        Matrix4f scaleMat = Matrix4f::InitScale(scale);
        Matrix4f ret, rotMat;
        rotMat = rotZMat * rotYMat * rotXMat;
        ret = transMat * rotMat * scaleMat;
        return ret;
    }

    Vector3f *GetTranslation(){return *this->translate;}
    Vector3f *GetRotate(){return *this->rotate;}
    Vector3f *GetScale(){return *this->scale;}

private:
    Vector3f translate;
    Vector3f scale;
    Vector3f rotate;
};


#endif /* TRANSFORM_H_ */
