
#include "AppWindow.h"
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

Input::Input(unsigned int _screenWidth, unsigned int _screenHeight, Uint32 delta, SDL_Event& e){
	this->e = e;
	closeRequested = false;
	mouseX = 0;
	mouseY = 0;
	screenWidth = _screenWidth;
	screenHeight = _screenHeight;
	this->delta = delta;
}

Input::Input(AppWindow* app, SDL_Event& e){
	this->e = e;
	closeRequested = false;
	mouseX = 0;
	mouseY = 0;
	screenWidth = app->getWidth();
	screenHeight = app->getHeight();
	templateWin = app->GetWindow();
	delta = app->getDelta();
}

Input::~Input() {

}

void Input::poll(SDL_Event &event)
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

void Input::addJoystick(int id){
	if(SDL_NumJoysticks() < 1){
		std::cout << "Error 411: No Joysticks Connected";
	}else{
		mJoystick[id] = SDL_JoystickOpen(id);
	}
}

void Input::getJoystickAxis(int numJoystick, int* x, int* y){
	*x = SDL_JoystickGetAxis(mJoystick[numJoystick], 0);
	*y = SDL_JoystickGetAxis(mJoystick[numJoystick], 1);
}

void Input::getJoystickAxis(int numJoystick, double* x, double* y){
	*x = SDL_JoystickGetAxis(mJoystick[numJoystick], 0) / 32768.0;
	*y = SDL_JoystickGetAxis(mJoystick[numJoystick], 1) / 32768.0;
}

void Input::getJoystickAxis(int numJoystick, int* x, int* y, int* z){
	*x = SDL_JoystickGetAxis(mJoystick[numJoystick], 0);
	*y = SDL_JoystickGetAxis(mJoystick[numJoystick], 1);
	*z = SDL_JoystickGetAxis(mJoystick[numJoystick], 2);
}

void Input::getJoystickAxis(int numJoystick, double* x, double* y, double* z){
	*x = SDL_JoystickGetAxis(mJoystick[numJoystick], 0) / 32768.0;
	*y = SDL_JoystickGetAxis(mJoystick[numJoystick], 1) / 32768.0;
	*z = SDL_JoystickGetAxis(mJoystick[numJoystick], 2) / 32768.0;
}

void Input::CenterMouseInWindow(){
	int cX = screenWidth/2;
	int cY = screenHeight/2;
	SDL_WarpMouseInWindow(templateWin, cX, cY);
}

bool Input::getJoystickButton(int numJoystick, int btn){
	return (bool)SDL_JoystickGetButton(mJoystick[numJoystick], btn);
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
