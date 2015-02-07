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

    void setTranslate(Vector3f& vec){translate = vec;}
    void setTranslateX(float _x){translate.setX(_x);}
    void setTranslateY(float _y){translate.setY(_y);}
    void setTranslateZ(float _z){translate.setZ(_z);}

    void setRotate(Vector3f& axis, float amt){
    	rotate = axis * amt;
    }
    void setRotate(Vector3f& vec){rotate = vec;}
    void setRotateX(float _x){rotate.setX(_x);}
    void setRotateY(float _y){rotate.setY(_y);}
    void setRotateZ(float _z){rotate.setZ(_z);}

    void setScale(Vector3f& vec){scale = vec;}
    void setScaleX(float _x){scale.setX(_x);}
    void setScaleY(float _y){scale.setY(_y);}
    void setScaleZ(float _z){scale.setZ(_z);}

    Vector3f getTranslate()const{return translate;}
    Vector3f getRotate()const{return rotate;}
    Vector3f getScale()const{return scale;}

    Vector2f map(Vector2f& vec){
    	Vector4f v1 = calcModel().toVector4f();
    	Vector2f v2(v1.getX(), v1.getY());
    	vec = vec + v2;
    	return vec;
    }

    Vector3f map(Vector3f& vec){
    	Vector4f v1 = calcModel().toVector4f();
    	Vector3f v2(v1.getX(), v1.getY(), v1.getZ());
    	vec = vec + v2;
    	return vec;
    }

    Vector4f map(Vector4f& vec){
    	Vector4f v1 = calcModel().toVector4f();
    	vec = vec + v1;
    	return vec;
    }

private:
    Vector3f translate;
    Vector3f scale;
    Vector3f rotate;

    Matrix4f calcModel()const {
    	Matrix4f transMat, rotXMat, rotYMat, rotZMat, scaleMat;

    	transMat.initTranslation(translate.getX(), translate.getY(), translate.getZ());
    	rotXMat.initRotation(rotate.getX(), new Vector3f(1.0, 0.0, 0.0));
    	rotYMat.initRotation(rotate.getY(), new Vector3f(0.0, 1.0, 0.0));
    	rotZMat.initRotation(rotate.getZ(), new Vector3f(0.0, 0.0, 1.0));
    	scaleMat.initScale(scale.getX(), scale.getY(), scale.getZ());

        Matrix4f ret, rotMat;
        rotMat = rotZMat * rotYMat * rotXMat;

        ret = scaleMat * rotMat * transMat;

        return ret;
    }
};


#endif /* TRANSFORM_H_ */
