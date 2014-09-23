#ifndef INPUT_H_
#define INPUT_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_joystick.h>
#include <SDL2/SDL_gamecontroller.h>
#include "Utility/Math/Vector.h"

class AppWindow;

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
    Input(SDL_Event &_e);
    virtual ~Input();

    void Poll(SDL_Event &e);
    void RequestClose(){ closeRequested = true; }

    bool isCloseRequested();

    bool isKeyDown(int Key);
    bool isMouseDown(int mouseButton);

    Vector2f getMouseCoord();
private:
    bool closeRequested;
    SDL_Event e;

    int mouseX, mouseY;
};

#endif /* INPUT_H_ */
