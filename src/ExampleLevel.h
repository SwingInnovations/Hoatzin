

#ifndef EXAMPLELEVEL_H_
#define EXAMPLELEVEL_H_

#include "STechOne.h"

#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

class ExampleLevel : public GameState {
public:
	ExampleLevel(){

	}

	ExampleLevel(int id){
		this->id = id;
		scene = new SWSceneManager();
	}

	virtual void init(AppWindow* app){
		shdr = new Shader("basicShader");
		plane = new SWGameObject(new Mesh(new Plane(40, 40)), new SWMaterial(shdr));
		plane->getMaterial()->addDiffuseMap("flower.jpg");
		plane->setRotateX(90.0f);
		plane->setTranslateX(-20.0f);
		plane->setTranslateY(-20.0f);
		plane->setTranslateZ(0.0f);

		figure = new SWGameObject(new Mesh("defaultFigure.obj", MESH_TYPE::MODEL_OBJ), new SWMaterial(shdr));
		sphere = new SWGameObject(new Mesh("sphere.obj", MESH_TYPE::MODEL_OBJ), new SWMaterial(shdr));
		sphere->getMaterial()->addDiffuseMap("checker.png");
		Vector3f scale(0.3f, 0.3f, 0.3f);
		sphere->setTranslateY(5);
		sphere->setScale(scale);

		Vector3f lightPosition(3.0f, -6.0f, 2.0f);
		Vector3f lightIntesity = COLOR::Color(COLOR::WHITE);
		Vector3f coneDirection(0.0f, 1.0f, 0.0f);
		spotLight = new SWSpotLight(lightPosition, lightIntesity, coneDirection, 0.0f, 0.5f, 15.0f);

		Vector3f lP2(-3.0, -6.0f, -2.0f);
		Vector3f lI2 = COLOR::Color(COLOR::GREEN);
		Vector3f cD2(0.0f, 1.0f, 0.0f);
		light2 = new SWSpotLight(lP2, lI2, cD2, 0.0f, 0.5f, 15.0f);
		light2->setIndex(1);

		figure->getMaterial()->addDiffuseMap("grid.png");
		scene->add(plane);
		scene->add(figure);
		scene->add(sphere);
		scene->add(spotLight);
		scene->add(light2);
		loaded = false;
	}

	virtual void updateInput(AppWindow* app, int delta){
		Input* input = app->getInput();
		input->setMoveSpeed(0.0025f);
		app->showCursor(false);
		if(input->isKeyDown(KEY::KEY_ESC)) input->requestClose();
		app->getCamera()->update(input);
	}

	virtual void updateAuto(AppWindow* app ,int delta){
		float rot = figure->transform->getRotate().getY();
		rot += 0.025f * delta;
		figure->setRotateY(rot);
		sphere->setTranslateX(20.0);
		sphere->setRotateY(-rot);
	}

	virtual void render(Graphics* g){
		while(!loaded){
			g->addRenderPass();
			for(unsigned int i = 0; i < scene->getSceneObjects()->size(); i++){
				g->addToPass(0, scene->getComponent(i));
			}
			loaded = true;
		}
		g->setShader(shdr);
		g->drawPass(0);
		//g->drawScene(scene);
	}

	virtual ~ExampleLevel(){

	}

	int getID(){return 0;}

private:
	bool loaded;
	btVector3 vec;
	Shader* shdr;
	SWSpotLight* spotLight;
	SWSpotLight* light2;
	SWGameObject* figure;
	SWGameObject* plane;
	SWGameObject* sphere;
	Mesh* plane2;
};

#endif
