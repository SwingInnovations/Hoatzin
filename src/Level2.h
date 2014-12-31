#ifndef LEVEL2_H_
#define LEVEL2_H_

#include "Utility/GameState.h"
#include "Utility/Math/Geom/Box.h"

class Level2 : public GameState{
public:
	Level2(int id){
		this->id = id;
	}

	void init(){
		Vector3f camPos(0.0, -3.0, 0.0);
		camera = new Camera(camPos, 66.0f, 1440, 900, 1.0f, 1000.0f);
	}

	void updateAuto(AppWindow* app, int delta){
		float pX = box->getChild(0)->transform->getTranslate().getX();
		pX += 0.035f * delta;
		for(unsigned int i = 0; i < box->children.size(); i++){
			box->getChild(i)->setTranslateY(cos(pX)*2);
		}
	}

	void updateInput(AppWindow* app, int delta){
		Input *input = app->getInput();
		if(input->isKeyDown(KEY::KEY_Q)){
			input->requestClose();
		}
		if(input->isKeyDown(KEY::KEY_1)){
			app->enterState(0);
		}
		if(input->isKeyDown(KEY::KEY_W)){
			float _z = camera->getTransform().getTranslate().getZ();
			_z += 0.025f*delta;
			camera->setTranslateZ(_z);
		}
		if(input->isKeyDown(KEY::KEY_S)){
			float _z = camera->getTransform().getTranslate().getZ();
			_z -= 0.025f*delta;
			camera->setTranslateZ(_z);
		}
		if(input->isKeyDown(KEY::KEY_A)){
			float _x = camera->getTransform().getTranslate().getX();
			_x += 0.025f*delta;
			camera->setTranslateX(_x);
		}
		if(input->isKeyDown(KEY::KEY_D)){
			float _x = camera->getTransform().getTranslate().getX();
			_x -= 0.025f*delta;
			camera->setTranslateX(_x);
		}
		camera->update(*input);
	}

	void render(){
		//box->draw(*camera);
	}

	int getID(){
		return id;
	}
	~Level2(){

	}

private:
	int id;
	SWComponent* box, *obj;
	Camera* camera;
};



#endif /* LEVEL2_H_ */
