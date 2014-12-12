#ifndef SWSCENEMANAGER_H_
#define SWSCENEMANAGER_H_

#include <Vector>
#include "SWComponent.h"
#include "SWLight.h"

class SWSceneManager{
public:
	SWSceneManager(){numLight = 0;}
	void add(SWComponent* component){sceneNodes.push_back(component);}
	void add(SWLight* light){
		numLight++;
		light->setIndex(numLight);
		sceneLights.push_back(light);
	}
	SWComponent* getComponent(int i){return sceneNodes.at(i);}
	std::vector<SWComponent*> *getSceneObjects(){return &sceneNodes;}
	std::vector<SWLight*> *getLights(){return &sceneLights;}
private:
	std::vector<SWComponent*> sceneNodes;
	std::vector<SWLight*> sceneLights;
	int numLight;
};



#endif /* SWSCENEMANAGER_H_ */
