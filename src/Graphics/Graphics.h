#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#pragma once

#include <vector>
#include "../STechOne.h"
#include "../Utility/SWComponent.h"

class Camera;
class SWSceneManager;
class AppWindow;

struct SWRenderPass{
	std::vector<SWComponent*> objects;
	void addObjects(SWComponent* comp){
		objects.push_back(comp);
	}
	void draw(Camera* cam){
		for(int i = 0; i < (int)objects.size(); i++){
			objects[i]->draw(cam);
		}
	}
};

class Graphics {
public:
	Graphics(AppWindow*);
	Graphics();
	virtual ~Graphics();

	void addRenderPass(){
		renderPass.push_back(SWRenderPass());
	}

	void addToPass(int i, SWComponent* comp){
		if(i < (int)renderPass.size()){
			renderPass[i].addObjects(comp);
		}
	}

	void drawPass(int i){
		if(i < (int)renderPass.size()){
			renderPass[i].draw(camera);
		}
	}

	void setCamera(Camera* cam){
		camera = cam;
	}

	void draw(SWComponent* swobject){
		swobject->draw(camera);
	}

	Camera* getCamera(){
		return camera;
	}

	void drawScene(SWSceneManager* scene);
private:
	std::vector<SWRenderPass> renderPass;
	int WIDTH, HEIGHT;
	bool legacyGraphicsInUse;
	Camera* camera;
	Shader* shader;
	bool shadowEnabled;
};

#endif /* GRAPHICS_H_ */
