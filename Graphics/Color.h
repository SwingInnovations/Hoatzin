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
	};

	struct Func{
		static Vector3f Color(int entry){
			switch(entry){
			case 0:
				return Vector3f(1.0f, 1.0f, 1.0f);
				break;
			case 1:
				return Vector3f(0.75f, 0.75f, 0.75f);
				break;
			case 2:
				return Vector3f(0.50f, 0.50f, 0.50f);
				break;
			case 3:
				return Vector3f(0.25f, 0.25f, 0.25f);
				break;
			case 4:
				return Vector3f();
				break;
			case 5:
				return Vector3f(1.0f, 0.0f, 0.0f);
				break;
			case 6:
				return Vector3f(1.0f, 0.0f, 1.0f);
			    break;
			case 7:
				return Vector3f(1.0f, 0.5f, 1.0f);
				break;
			case 8:
				return Vector3f(0.0f, 1.0f, 1.0f);
				break;
			case 9:
				return Vector3f(0.0f, 0.0f, 1.0f);
				break;
			case 10:
				return Vector3f(0.0f, 1.0f, 1.0f);
				break;
			case 11:
				return Vector3f(0.0f, 1.0f, 0.0f);
				break;
			case 12:
				return Vector3f(1.0f, 1.0f, 0.0f);
				break;
			default:
				return Vector3f();
			}
		}
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
