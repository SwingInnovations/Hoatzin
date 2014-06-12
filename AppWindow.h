#ifndef APPWINDOW_H_
#define APPWINDOW_H_

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <string>
#include <iostream>
#include <vector>


#include "Input.h"
#include "Utility/GameState.h"

class GameState;
class Input;

class AppWindow {
public:
	AppWindow();
	AppWindow(const std::string title, int WIDTH, int HEIGHT);
	void SetOpenGLVersion(int MajorVersion, int MinorVersion);
	virtual ~AppWindow();

	void Start();
	void AddState(GameState* newState);
	void EnterState(int id){mCurrentState = id;}
	Input GetInput(){ return input; }
	void SetRunning(bool val){Running = val;}
protected:
	bool Running;
	void Init();
	void Update(SDL_Event &e);
	void Render();
private:
	SDL_Window* mWindow;
	SDL_GLContext mContext;
	SDL_Event e;
	Input input;
	int mCurrentState;
	std::vector<GameState*> state;
};

#endif /* APPWINDOW_H_ */
