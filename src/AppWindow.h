#ifndef APPWINDOW_H_
#define APPWINDOW_H_

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengl.h>
#include <string>
#include <iostream>
#include <vector>

#include "Graphics/Graphics.h"
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

	void start();
	void addState(GameState* newState);
	void enterState(int id){mCurrentState = id;}
	void useScript(bool val){script = val;}
	Input *getInput(){ return input; }
	void setRunning(bool val){Running = val;}
	void setPause(bool val){pause = val;}
	void showCursor(bool val);
	void centerCursor();
	void setTargetFPS(float val){fps = val;}
	void setIcon(const std::string filePath);

	void setCamera(Camera* camera);
	Camera* getCamera();

	int getWidth(){return WIDTH;}
	int getHeight(){return HEIGHT;}
	bool getPause(){return pause;}

	Uint32 getFPS(){return fps;}
	Uint32 getDelta(){return delta;}

	SDL_Window* GetWindow(){return mWindow;}

protected:
	bool Running;
	void init();
	void updateInput(SDL_Event &e);
	void updateAuto();
	void render();
	void calcDelta();
private:
	SDL_Window* mWindow;
	SDL_GLContext mContext;
	SDL_Event e;
	Input *input;
	Graphics* g;
	bool pause;
	bool script;
	unsigned int WIDTH, HEIGHT;
	int mCurrentState;
	Uint32 delta, oldTime, newTime, fps;
	std::vector<GameState*> state;
};

#endif /* APPWINDOW_H_ */
