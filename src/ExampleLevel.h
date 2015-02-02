

#ifndef EXAMPLELEVEL_H_
#define EXAMPLELEVEL_H_

#include "STechOne.h"

class ExampleLevel : public GameState {
public:
	ExampleLevel(){

	}

	ExampleLevel(int id){
		this->id = id;
	}

	virtual void init(AppWindow* app){
		shdr = new Shader("basicShader");
		figure = new SWGameObject(new Mesh("defaultFigure.obj", MESH_TYPE::MODEL_OBJ), new SWMaterial(shdr));
		Vector3f lightPosition(3.0f, -6.0f, 0.0f);
		Vector3f lightIntesity = COLOR::Color(COLOR::YELLOW);
		Vector3f coneDirection(0.0f, 1.0f, 0.0f);
		spotLight = new SWSpotLight(lightPosition, lightIntesity, coneDirection, 0.1f, 0.0f, 15.0f);
		figure->getMaterial()->addDiffuseMap("grid.png");
	}

	virtual void updateInput(AppWindow* app, int delta){
		Input* input = app->getInput();
		app->showCursor(false);
		if(input->isKeyDown(KEY::KEY_ESC)) input->requestClose();
		app->getCamera()->update(input);
	}

	virtual void updateAuto(AppWindow* app ,int delta){
		float rot = figure->transform->getRotate().getY();
		rot += 0.025f * delta;
		figure->setRotateY(rot);
	}

	virtual void render(Graphics* g){
		spotLight->draw(shdr);
		g->draw(figure);
	}

	virtual ~ExampleLevel(){

	}

	int getID(){return 0;}

private:
	Shader* shdr;
	SWSpotLight* spotLight;
	SWGameObject* figure;
};

#endif
