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
#include "Utility/SWLight.h"
#include "Utility/LuaScript.h"
#include "Utility/SWGameObject.h"

class DemoLevel : public GameState{
public:
	DemoLevel(int id){
		this->id = id;
	}

	void init(AppWindow* app){

		camera = app->getCamera();

		l = new LuaScript("script.lua");

		shader = new Shader("basicShader");
		tex = new Texture("grid.png");
		tex2 = new Texture("flower.jpg");
		Vector3f position(1.0, -1.0, 1.0);
		lightPosition = Vector3f(0.0, -3.0, 1.0);
		Vector3f lightIntensity(0.5, 0.5, 0.9);
		Vector3f coneDirection(0.0, 1.0f, 0.0);
		spotLight = new SWSpotLight(lightPosition, lightIntensity, coneDirection, 0.1f, 0.0f, 15.0f);
		gameObject = new SWGameObject(new Mesh("defaultFigure.obj", MESH_TYPE::MODEL_OBJ), new SWMaterial(shader));
		gameObject->getMaterial()->addDiffuseMap("grid.png");
		gameObject->transform->setRotateY(90.0f);
		rot = 0;
		rot2 = 0;
		rotAmt = 0;
		transX = 0; transZ = 0;
	}

	void updateAuto(AppWindow* app, int delta){
		rot2+= 0.025f * delta;
		gameObject->setRotateY(rot2);
		spotLight->draw(shader);
		float transAmount = lightPosition.getX() + cos(rot2)*10.0f;
		lightPosition.setX(transAmount);
		Vector4f ret(lightPosition, 1.0);
		spotLight->updateProperty("intensity", ret);
	}

	void updateInput(AppWindow* app, int delta){
		Input *input = app->getInput();
		app->showCursor(false);

		if(input->isKeyDown(KEY::KEY_ESC)){
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

		if(input->isKeyDown(KEY::KEY_Q)){
			float camY = camera->getTransform().getTranslate().getY();
			camY -= 0.025f * delta;
			camera->setTranslateY(camY);
		}

		if(input->isKeyDown(KEY::KEY_Z)){
			float camY = camera->getTransform().getTranslate().getY();
			camY += 0.025f * delta;
			camera->setTranslateY(camY);
		}

		camera->update(input);
	}

	void render(Graphics* g){
		g->draw(gameObject);
	}

	int getID(){
		return id;
	}

	~DemoLevel(){
		delete spotLight;
		std::cout << SDL_GetError() << std::endl;
	}
private:
	int id;
	Vector3f colorVec;
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
	SWSpotLight* spotLight;
	LuaScript* l;
	Vector3f lightPosition;
	SWGameObject* gameObject;
	SWGameObject* planeObject;
};


#endif /* DEMOLEVEL_H_ */
