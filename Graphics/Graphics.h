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
};

#endif /* GRAPHICS_H_ */
