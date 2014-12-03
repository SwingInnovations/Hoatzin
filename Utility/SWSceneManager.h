#ifndef SWSCENEMANAGER_H_
#define SWSCENEMANAGER_H_

#include <Vector>
#include "SWComponent.h"

class SWSceneManager{
public:
	SWSceneManager(){}
	void add(SWComponent* component){sceneNodes.push_back(component);}

	SWComponent* getComponent(int i){return sceneNodes.at(i);}
private:
	std::vector<SWComponent*> sceneNodes;
};



#endif /* SWSCENEMANAGER_H_ */
