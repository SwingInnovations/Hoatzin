#ifndef SWOBJECT_H_
#define SWOBJECT_H_

#include <vector>

#include "Math/Vector.h"
#include "Transform.h"
#include "Mesh.h"
#include "../Graphics/Shader.h"
#include "../Graphics/Texture.h"
#include "../Graphics/Graphics.h"

class Texture;
class Mesh;
class Shader;

class SWObject{
public:
	Vector3f *Position(){return &this->position;}
	Vector3f position;
	Transform* transform;
	Mesh* mesh;
	Shader* shader;
	Texture* tex;
	std::vector<SWObject*> children;
	bool hasChildren;

	SWObject();
	SWObject(Mesh* mesh, Shader* shader, Texture* texture);
	virtual ~SWObject(){}

	void AddChild(SWObject* child){hasChildren = true; children.push_back(child);}
	SWObject* GetChild(int i){return children.at(i);}

	void SetTranslate(Vector3f& vec){
		if(!hasChildren){
			transform->SetTranslate(vec);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->SetTranslate(vec);
				children[i]->transform->SetTranslate(vec);
			}
		}
	}
	void SetTranslateX(float _x){
		if(!hasChildren){
			transform->SetTranslateX(_x);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->SetTranslateX(_x);
				children[i]->transform->SetTranslateX(_x);
			}
		}
	}
	void SetTranslateY(float _y){
		if(!hasChildren){
			transform->SetTranslateY(_y);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->SetTranslateY(_y);
				children[i]->transform->SetTranslateY(_y);
			}
		}
	}
	void SetTranslateZ(float _z){
		if(!hasChildren){
			transform->SetTranslateZ(_z);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->SetTranslateZ(_z);
				children[i]->transform->SetTranslateZ(_z);
			}
		}
	}

	void SetRotate(Vector3f& vec){
		if(!hasChildren){
			transform->SetRotate(vec);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->SetRotate(vec);
				children[i]->transform->SetRotate(vec);
			}
		}
	}
	void SetRotateX(float _x){
		if(!hasChildren){
			transform->SetRotateX(_x);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->SetRotateX(_x);
				children[i]->transform->SetRotateX(_x);
			}
		}
	}
	void SetRotateY(float _y){
		if(!hasChildren){
			transform->SetRotateY(_y);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->SetRotateY(_y);
				children[i]->transform->SetRotateY(_y);
			}
		}
	}
	void SetRotateZ(float _z){
		if(!hasChildren){
			transform->SetRotateZ(_z);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->SetRotateZ(_z);
				children[i]->transform->SetRotateZ(_z);
			}
		}
	}

	void SetScale(Vector3f& vec){
		if(!hasChildren){
			transform->SetScale(vec);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->SetScale(vec);
				children[i]->SetScale(vec);
			}
		}
	}
	void SetScaleX(float _x){
		if(!hasChildren){
			transform->SetScaleX(_x);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->SetScaleX(_x);
				children[i]->SetScaleX(_x);
			}
		}
	}
	void SetScaleY(float _y){
		if(!hasChildren){
			transform->SetScaleY(_y);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->SetScaleY(_y);
				children[i]->transform->SetScaleY(_y);
			}
		}
	}
	void SetScaleZ(float _z){
		if(!hasChildren){
			transform->SetScaleZ(_z);
		}else{
			for(unsigned int i = 0; i < children.size(); i++){
				transform->SetScaleZ(_z);
				children[i]->transform->SetScaleZ(_z);
			}
		}
	}

	void Draw(Camera& cam){
		shader->Update(*transform, cam);
		shader->Bind();
		tex->bind(0);
		mesh->Draw();
		if(hasChildren){
			for(unsigned int i = 0; i < children.size(); i++){
				children[i]->Draw(cam);
			}
		}
	}

	void Draw(){
		shader->Update(*transform);
		shader->Bind();
		tex->bind(0);
		mesh->Draw();
		if(hasChildren){
			for(unsigned int i = 0; i < children.size(); i++){
				children[i]->Draw();
			}
		}
	}
};




#endif /* SWOBJECT_H_ */
