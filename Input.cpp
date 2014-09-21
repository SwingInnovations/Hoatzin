
#include "Input.h"

static const int NUM_KEYS = 512;
static const int NUM_MOUSE = 0x40;

static bool mKeyPressed[NUM_KEYS];
static bool mMouseButtonPressed[NUM_MOUSE];

static Vector2f mousePosition;



Input::Input() {
    closeRequested = false;
    mouseX = 0;
    mouseY = 0;
}

Input::Input(SDL_Event& _e)
{
    e =_e;
    closeRequested = false;
    mouseX = 0;
    mouseY = 0;
}

Input::~Input() {

}

void Input::Poll(SDL_Event &event)
{
    if(event.type == SDL_QUIT)
    {
        closeRequested = true;
    }

    for(int i = 0; i < NUM_KEYS; i++)
    {
        mKeyPressed[i] = false;
    }

    for(int i = 0; i < NUM_MOUSE; i++)
    {
        mMouseButtonPressed[i] = false;
    }

    if(event.type == SDL_KEYDOWN)
    {
        int val = event.key.keysym.scancode;
        mKeyPressed[val] = true;
    }

    if(event.type == SDL_KEYUP)
    {
        int val = event.key.keysym.scancode;
        mKeyPressed[val] = false;
    }

    if(event.type == SDL_MOUSEMOTION)
    {
        mouseX = event.motion.x;
        mouseY = event.motion.y;
    }

    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        int val = event.button.button;
        mMouseButtonPressed[val] = true;
    }

    if(event.type == SDL_MOUSEBUTTONUP)
    {
        int val = event.button.button;
        mMouseButtonPressed[val] = false;
    }

}

bool Input::isCloseRequested()
{
    return closeRequested;
}

bool Input::isKeyDown(int Key)
{
    return mKeyPressed[Key];
}

bool Input::isMouseDown(int mouseButton)
{
    return mMouseButtonPressed[mouseButton];
}

Vector2f Input::getMouseCoord()
{
    return Vector2f((float)mouseX, (float)mouseY);
}
