#ifndef LEVEL2_H_
#define LEVEL2_H_

#include "Utility/GameState.h"
#include "Utility/Math/Geom/Box.h"

class Level2 : public GameState{
public:
	Level2(int id){
		this->id = id;
	}

	void Init(){
		box = new SWObject(new Mesh(new Box(3.0f, 3.0f, 3.0f)), new Shader("basicShader"), new Texture("grid.png"));
		box->AddChild(new SWObject(new Mesh(new Box(2.0f, 5.0f, 2.0f)), new Shader("basicShader"), new Texture("flower.jpg")));
		Vector3f camPos(0.0, -3.0, 0.0);
		camera = new Camera(camPos, 66.0f, 1024, 768, 1.0f, 1000.0f);
	}

	void UpdateAuto(AppWindow* app, int delta){
		float pX = box->GetChild(0)->transform->GetTranslation().GetX();
		pX += 0.035f * delta;
		for(unsigned int i = 0; i < box->children.size(); i++){
			box->GetChild(i)->SetTranslateY(cos(pX)*2);
		}
	}

	void UpdateInput(AppWindow* app, int delta){
		Input *input = app->GetInput();
		if(input->isKeyDown(KEY::KEY_Q)){
			input->RequestClose();
		}
		if(input->isKeyDown(KEY::KEY_1)){
			app->EnterState(0);
		}
		if(input->isKeyDown(KEY::KEY_W)){
			float _z = camera->GetTransform().GetTranslation().GetZ();
			_z += 0.025f*delta;
			camera->SetTranslateZ(_z);
		}
		if(input->isKeyDown(KEY::KEY_S)){
			float _z = camera->GetTransform().GetTranslation().GetZ();
			_z -= 0.025f*delta;
			camera->SetTranslateZ(_z);
		}
		if(input->isKeyDown(KEY::KEY_A)){
			float _x = camera->GetTransform().GetTranslation().GetX();
			_x += 0.025f*delta;
			camera->SetTranslateX(_x);
		}
		if(input->isKeyDown(KEY::KEY_D)){
			float _x = camera->GetTransform().GetTranslation().GetX();
			_x -= 0.025f*delta;
			camera->SetTranslateX(_x);
		}
		camera->Update(*input);
	}

	void Render(){
		box->Draw(*camera);
	}

	int getID(){
		return id;
	}
	~Level2(){

	}

private:
	int id;
	SWObject* box;
	Camera* camera;
};



#endif /* LEVEL2_H_ */
