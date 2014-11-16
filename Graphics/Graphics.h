#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "../Utility/SWObject.h"

class SWObject;

class Graphics {
public:
	Graphics();
	virtual ~Graphics();

	void DrawSWObject(SWObject* swobject){

	}
private:
	bool legacyGraphicsInUse;
};

#endif /* GRAPHICS_H_ */
