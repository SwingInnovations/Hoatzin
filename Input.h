#ifndef INPUT_H_
#define INPUT_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_joystick.h>
#include <SDL2/SDL_gamecontroller.h>
#include "Utility/Math/Vector.h"

class AppWindow;

namespace JOYSTICKBUTTON{
	enum{
		BUTTON_1 = 0,
		BUTTON_2 = 1,
		BUTTON_3 = 2,
		BUTTON_4 = 3,
		BUTTON_5 = 4,
		BUTTON_6 = 5,
		BUTTON_7 = 6,
		BUTTON_8 = 7,
		BUTTON_9 = 8,
		BUTTON_10 = 9,
		BUTTON_11 = 10,
		BUTTON_12 = 11,
		BUTTON_13 = 12,
		BUTTON_14 = 13,
		BUTTON_15 = 14,
		BUTTON_16 = 15
	};
};

namespace KEY{
    enum{
    //keyboard keys
        KEY_A = 4,
        KEY_B = 5,
        KEY_C = 6,
        KEY_D = 7,
        KEY_E = 8,
        KEY_F = 9,
        KEY_G = 10,
        KEY_H = 11,
        KEY_I = 12,
        KEY_J = 13,
        KEY_K = 14,
        KEY_L = 15,
        KEY_M = 16,
        KEY_N = 17,
        KEY_O = 18,
        KEY_P = 19,
        KEY_Q = 20,
        KEY_R = 21,
        KEY_S = 22,
        KEY_T = 23,
        KEY_U = 24,
        KEY_V = 25,
        KEY_W = 26,
        KEY_X = 27,
        KEY_Y = 28,
        KEY_Z = 29,

        KEY_1 = 30,
        KEY_2 = 31,
        KEY_3 = 32,
        KEY_4 = 33,
        KEY_5 = 34,
        KEY_6 = 35,
        KEY_7 = 36,
        KEY_8 = 37,
        KEY_9 = 38,
        KEY_0 = 39
    };
};

class Input {
public:
    Input();
    Input(unsigned int _screenWidth, unsigned int _screenHeight, Uint32 delta, SDL_Event& e);
    Input(SDL_Event &_e);
    virtual ~Input();

    void Poll(SDL_Event &e);
    void RequestClose(){ closeRequested = true; }

    void AddJoystick(int id);
    void GetJoystickAxis(int numJoystick, double* x, double* y);
    void GetJoystickAxis(int numJoystick, double* x, double* y, double* z);
    void GetJoystickAxis(int numJoystick, int* x, int* y);
    void GetJoystickAxis(int numJoystick, int* x, int* y, int* z);
    bool GetJoystickButton(int numJoystick, int button);

    bool isCloseRequested();

    bool isKeyDown(int Key);
    bool isMouseDown(int mouseButton);

    unsigned int GetScreenWidth(){return screenWidth;}
    unsigned int GetScreenHeight(){return screenHeight;}
    Uint32 GetDelta(){return delta;}

    Vector2f getMouseCoord();
private:
    bool closeRequested;
    SDL_Event e;
    SDL_Joystick* mJoystick[5];

    int mouseX, mouseY;
    unsigned int screenWidth, screenHeight;
    Uint32 delta;
};

#endif /* INPUT_H_ */
