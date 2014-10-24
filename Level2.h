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
		Vector3f camPos(0.0, -3.0, 0.0);
		camera = new Camera(camPos, 66.0f, 1024, 768, 1.0f, 1000.0f);
	}

	void UpdateAuto(AppWindow* app, int delta){

	}

	void UpdateInput(AppWindow* app, int delta){
		Input *input = app->GetInput();
		if(input->isKeyDown(KEY::KEY_Q)){
			input->RequestClose();
		}
		if(input->isKeyDown(KEY::KEY_1)){
			app->EnterState(0);
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
