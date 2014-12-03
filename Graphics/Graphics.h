#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "../Utility/SWObject.h"

class SWComponent;

class Graphics {
public:
	Graphics();
	virtual ~Graphics();

	void DrawSWObject(SWComponent* swobject){

	}
private:
	bool legacyGraphicsInUse;
	Camera* camera;
	bool shadowEnabled;
};

#endif /* GRAPHICS_H_ */
