#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "../Utility/SWObject.h"

class SWObject;

namespace COLOR{
	enum{
		WHITE = 2,
		LIGHTGRAY = 3,
		GRAY = 4,
		DARKGRAY = 5,
		BLACK = 6,
		RED = 7,
		MAGENTA = 8,
		ORANGE = 9,
		YELLOW = 10,
		GREEN = 11,
		CYAN = 12,
		BLUE = 13,
		PURPLE = 14,

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
