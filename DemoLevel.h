#ifndef DEMOLEVEL_H_
#define DEMOLEVEL_H_

#include <cmath>

#include "Utility/GameState.h"
#include "Utility/Mesh.h"
#include "Utility/Transform.h"
#include "Utility/Math/Vector.h"
#include "Utility/Vertex.h"
#include "Graphics/Texture.h"
#include "Graphics/Shader.h"
#include "Utility/SWObject.h"
#include "Graphics/Camera.h"
#include "Utility/Math/Geom/Plane.h"
#include "Utility/Math/Geom/Box.h"
#include "Utility/LuaScript.h"

class DemoLevel : public GameState{
public:
	DemoLevel(int id){
		this->id = id;
	}

	void init(){

		camPos = Vector3f(0.0, -3.0, 4.0);
		camera = new Camera(camPos, 66.0f, 1024.0f, 768.0f, 1.0f, 1000.0f);

		l = new LuaScript("script.lua");

		shader = new Shader("basicShader");
		tex = new Texture("grid.png");
		tex2 = new Texture("flower.jpg");
		Vector3f position(0.0, 0.0, 0.0);

		plane = new SWObject(new Mesh(new Plane(30, 30)), shader, tex);
		plane->SetTranslateY(-10);
		plane->SetTranslateX(-10);
		plane->SetTranslateZ(3);
		plane->SetRotateX(90);
		box = new SWObject(new Mesh(new Box(position, 3.0f, 3.0f, 3.0f)), shader, tex2);
		box->addChild(new SWObject(new Mesh(new Plane(10, 10)), shader, new Texture("profilePic.png")));

		rot = 0;
		rot2 = 0;
		rotAmt = 0;
		transX = 0; transZ = 0;
	}

	void updateAuto(AppWindow* app, int delta){
		rot2+= 0.025f * delta;
		rotAmt = cos(rot2);
		box->SetRotateY(rot2);
		box->SetRotateZ(rot2);
		box->SetRotateX(rot2);
		box->SetTranslateY(rotAmt/4);

		box->getChild(0)->SetTranslateY(rotAmt);
	}

	void updateInput(AppWindow* app, int delta){
		Input *input = app->getInput();
		app->showCursor(false);

		if(input->isKeyDown(KEY::KEY_Q)){
			std::cout << "Quiting" << std::endl;
			input->requestClose();
		}

		if(input->isKeyDown(KEY::KEY_1)){
			app->enterState(1);
		}

		if(input->isKeyDown(KEY::KEY_P)){
			bool temp = app->getPause();
			app->setPause(!temp);
		}

		if(input->isKeyDown(KEY::KEY_A)){
			transX += 0.025f*delta;
			camera->setTranslateX(transX);
		}
		if(input->isKeyDown(KEY::KEY_D)){
			transX -= 0.025f*delta;
			camera->setTranslateX(transX);
		}
		if(input->isKeyDown(KEY::KEY_W)){
			transZ += 0.025f*delta;
			camera->setTranslateZ(transZ);
		}
		if(input->isKeyDown(KEY::KEY_S)){
			transZ -= 0.025f * delta;
			camera->setTranslateZ(transZ);
		}

		std::cout << "delta: " << delta << std::endl;

		camera->update(*input);
	}

	void render(){
//		obj->Draw(*camera);
		plane->Draw(*camera);
		box->Draw(*camera);
		//box2->Draw(*camera);
	}

	int getID(){
		return id;
	}

	~DemoLevel(){
		std::cout << SDL_GetError() << std::endl;
	}
private:
	int id;
	Shader* shader;
	Texture* tex;
	Texture* tex2;
	Camera* camera;
	Vector3f test;
	float rot;
	float rot2;
	float rotAmt;
	float transX, transZ;
	Vector3f camPos;
	SWObject *plane, *box, *box2;
	SWObject *boxArray[3][3];
	LuaScript* l;
};


#endif /* DEMOLEVEL_H_ */
