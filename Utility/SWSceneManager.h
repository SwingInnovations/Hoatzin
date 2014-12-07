#ifndef SWSCENEMANAGER_H_
#define SWSCENEMANAGER_H_

#include <Vector>
#include "SWComponent.h"

class SWSceneManager{
public:
	SWSceneManager(){}
	void add(SWComponent* component){sceneNodes.push_back(component);}
	void add(SWLight* light){sceneLights.push_back(light);}

	SWComponent* getComponent(int i){return sceneNodes.at(i);}
private:
	std::vector<SWComponent*> sceneNodes;
	std::vector<SWLight*> sceneLights;
};



#endif /* SWSCENEMANAGER_H_ */
