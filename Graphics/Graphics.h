#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "../Utility/SWObject.h"

class SWObject;

namespace COLOR{
	enum{
		WHITE = 0,
		LIGHTGRAY = 1,
		GRAY = 2,
		DARKGRAY = 3,
		BLACK = 4,
		RED = 5,
		MAGENTA = 6,
		ORANGE = 7,
		YELLOW = 8,
		GREEN = 9,
		CYAN = 10,
		BLUE = 11,
		PURPLE = 12
	};
};

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
