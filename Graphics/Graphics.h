#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <vector>
#include "../Utility/SWObject.h"
#include "../Utility/SWComponent.h"

class SWComponent;

struct SWRenderPass{
	std::vector<SWComponent*> objects;
	void addObjects(SWComponent* comp){
		objects.push_back(comp);
	}
	void draw(Camera* cam){
		for(unsigned int i = 0; i < objects.size(); i++){
			objects.at(i)->draw(*cam);
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
		swobject->draw(*camera);
	}

private:
	std::vector<SWRenderPass> renderPass;
	bool legacyGraphicsInUse;
	Camera* camera;
	bool shadowEnabled;
};

#endif /* GRAPHICS_H_ */
