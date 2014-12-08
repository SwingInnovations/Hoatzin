#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#pragma once

#include <vector>
#include "../STechOne.h"

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

private:
	std::vector<SWRenderPass> renderPass;
	bool legacyGraphicsInUse;
	Camera* camera;
	bool shadowEnabled;
};

#endif /* GRAPHICS_H_ */
