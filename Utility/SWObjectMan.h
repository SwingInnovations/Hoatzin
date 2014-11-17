#ifndef SWOBJECTMAN_H_
#define SWOBJECTMAN_H_

#include <vector>
#include "SWObject.h"

class SWObjectManager{
public:
	SWObjectManager(){}
	virtual ~SWObjectManager(){
		SceneGraph.clear();
	}

	void addSWObject(SWObject* NewObject){
		SceneGraph.push_back(NewObject);
	}

private:
	std::vector<SWObject*> SceneGraph;
};


#endif /* SWOBJECTMAN_H_ */
