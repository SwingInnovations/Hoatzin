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

     	const Matrix4f getModel(){

    	Matrix4f transMat, rotXMat, rotYMat, rotZMat, scaleMat;

    	transMat.initTranslation(translate);
    	rotXMat.initRotation(rotate.getX(), new Vector3f(1.0, 0.0, 0.0));
    	rotYMat.initRotation(rotate.getY(), new Vector3f(0.0, 1.0, 0.0));
    	rotZMat.initRotation(rotate.getZ(), new Vector3f(0.0, 0.0, 1.0));
    	scaleMat.initScale(scale);

        Matrix4f ret, rotMat;
        rotMat = rotZMat * rotYMat * rotXMat;

        ret = scaleMat * rotMat * transMat;

        return ret;
    }

    void setTranslate(Vector3f& vec){this->translate = vec;}
    void setTranslateX(float _x){this->translate.setX(_x);}
    void setTranslateY(float _y){this->translate.setY(_y);}
    void setTranslateZ(float _z){this->translate.setZ(_z);}

    void setRotate(Vector3f& axis, float amt){
    	rotate = axis * amt;
    }
    void setRotate(Vector3f& vec){this->rotate = vec;}
    void setRotateX(float _x){this->rotate.setX(_x);}
    void setRotateY(float _y){this->rotate.setY(_y);}
    void setRotateZ(float _z){this->rotate.setZ(_z);}

    void setScale(Vector3f& vec){this->scale = vec;}
    void setScaleX(float _x){this->scale.setX(_x);}
    void setScaleY(float _y){this->scale.setY(_y);}
    void setScaleZ(float _z){this->scale.setZ(_z);}

    Vector3f getTranslate(){return this->translate;}
    Vector3f getRotate(){return this->rotate;}
    Vector3f getScale(){return this->scale;}

private:
    Vector3f translate;
    Vector3f scale;
    Vector3f rotate;
};


#endif /* TRANSFORM_H_ */