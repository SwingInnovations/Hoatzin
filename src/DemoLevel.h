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

class DemoLevel : public GameState{
public:
	DemoLevel(int id){
		this->id = id;
	}

	void init(){

		camPos = Vector3f(0.0, -3.0, 0.0);
		camera = new Camera(camPos, 66.0f, 1440.0f, 900.0f, 1.0f, 1000.0f);

		l = new LuaScript("script.lua");

		shader = new Shader("basicShader");
		tex = new Texture("grid.png");
		tex2 = new Texture("flower.jpg");
		Vector3f position(1.0, -1.0, 1.0);
		Vector3f lightPosition(0.0, 1.0, 3.0);
		Vector3f lightIntensity(0.5, 0.5, 0.9);
		Vector3f coneDirection(0.0, 1.0f, 0.0);
		spotLight = new SWSpotLight(lightPosition, lightIntensity, coneDirection, 0.1f, 0.0f, 15.0f);
		testObj = new SWObject(new Mesh("defaultFigure.obj", MESH_TYPE::MODEL_OBJ), shader, tex);

		rot = 0;
		rot2 = 0;
		rotAmt = 0;
		transX = 0; transZ = 0;
	}

	void updateAuto(AppWindow* app, int delta){
		rot2+= 0.025f * delta;
		testObj->setRotateY(rot2);
		spotLight->draw(shader);
	}

	void updateInput(AppWindow* app, int delta){
		Input *input = app->getInput();
		app->showCursor(false);

		if(input->isKeyDown(KEY::KEY_ESC)){
			std::cout << "Quiting" << std::endl;
			input->requestClose();
		}

		if(input->isKeyDown(KEY::KEY_R)){
			Vector3f resetVec(0.0f, 0.0f, 0.0f);
			testObj->setTranslate(resetVec);
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

		if(input->isKeyDown(KEY::KEY_R)){
			float r = colorVec.getX();
			r += 0.01f;
			colorVec.setX(r);
		}

		if(input->isKeyDown(KEY::KEY_G)){
			float g = colorVec.getY();
			g += 0.02f;
			colorVec.setY(g);
		}

		if(input->isKeyDown(KEY::KEY_B)){
			float b = colorVec.getZ();
			b += 0.01f;
			colorVec.setZ(b);
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
		testObj->setUniform("newColor", colorVec);
		camera->update(*input);
	}

	void render(){
		testObj->draw(camera);
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
	SWObject *plane, *box, *box2, *testObj;
	SWSpotLight* spotLight;
	LuaScript* l;
};


#endif /* DEMOLEVEL_H_ */
