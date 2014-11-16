#ifndef COLOR_H_
#define COLOR_H_

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
		PURPLE = 12,
		//Alpha colored
		A_WHITE = 13,
		A_LIGHTGRAY = 14,
		A_GRAY = 15,
		A_DARKGRAY = 16,
		A_BLACK = 17,
		A_RED = 18,
		A_MAGENTA = 19,
		A_ORANGE = 20,
		A_YELLOW = 21,
		A_GREEN = 22,
		A_CYAN = 23,
		A_BLUE = 24,
		A_PURPLE = 25
	};

	struct Func{
		//-Asserts the color between range 0.0f and 1.0f
		static float assertCol(float val){
			if(val > 1.0f){
				if(val > 255){
					return 0.0f;
				}else{
					val/=255.0f;
					return val;
				}
			}else{
				return val;
			}
		}
	};

};


#endif /* COLOR_H_ */
