/*
 * AppWindow.cpp
 *
 *  Created on: Jun 11, 2014
 *      Author: Nathan_z400
 */

#include "AppWindow.h"

AppWindow::AppWindow() {
	pause = false;

}

AppWindow::AppWindow(const std::string title, int WIDTH, int HEIGHT) : fps(60){
	//Setup Window
	this->WIDTH = WIDTH;
	this->HEIGHT = HEIGHT;
	if(SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_JOYSTICK) == -1){
		std::cout << "Error 401: Failed to load SDL: " << SDL_GetError() << std::endl;
		if(SDL_NumJoysticks() < 1){
			std::cout << "Error 411: No Joysticks Connected" << std::endl;
		}
	}else{
		mWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
		if(mWindow == NULL){
			std::cout << "Error 402: Failed to load Window: " << SDL_GetError() << std::endl;
		}else{
			input = new Input(this, e);
		}
	}
	pause = false;
	oldTime = 0;
	newTime = SDL_GetTicks();
}

void AppWindow::SetOpenGLVersion(int MajorVersion, int MinorVersion){
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, MajorVersion);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, MinorVersion);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	mContext = SDL_GL_CreateContext(mWindow);
	if(mContext == NULL){
		std::cout << "Error 403: Failed to create context! " << SDL_GetError() << std::endl;
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		mContext = SDL_GL_CreateContext(mWindow);
		if(mContext == NULL){
			std::cout << "Error 403: Failed to create context! " << SDL_GetError() << std::endl;
		}else{
			glewExperimental = GL_TRUE;
			glewInit();
		}
	}else{
		glewExperimental = GL_TRUE;
		glewInit();

		std::cout << "Using OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
		std::cout << "Using Graphics Driver: " << glGetString(GL_VENDOR) << std::endl;
	}
}

void AppWindow::addState(GameState* newState){
	state.push_back(newState);
}

void AppWindow::init(){
	if(!state.empty()){
		for(unsigned int i = 0; i < state.size(); i++){
			state.at(i)->init();
		}
	}
}

void AppWindow::updateInput(SDL_Event& e){
	input->poll(e);
	if(input->isCloseRequested()){
		setRunning(false);
	}

	if(!state.empty()){
		state.at(mCurrentState)->updateInput(this, delta);
	}
}

void AppWindow::updateAuto(){
	if(!state.empty()){
		state.at(mCurrentState)->updateAuto(this, delta);
	}
}

void AppWindow::calcDelta(){
	if(newTime > oldTime){
		delta = newTime - oldTime;
		Uint32 targetInterval = (Uint32)(1.0/this->getFPS() * 1000);
		if(delta < targetInterval || delta > targetInterval){
			delta = targetInterval;
		}
		oldTime = newTime;
		newTime = SDL_GetTicks();
	}
}

void AppWindow::render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.2, 1.0);

	glEnable(GL_DEPTH_TEST);

	if(!state.empty()){
		state.at(mCurrentState)->render();
	}

	SDL_GL_SwapWindow(mWindow);
}

void AppWindow::start(){
	setRunning(true);
	init();
	while(Running){
		if(!pause){
			calcDelta();
		}else{
			delta = 0;
		}
		while(SDL_PollEvent(&e)){
			updateInput(e);
		}

		updateAuto();
		render();
	}
}

void AppWindow::showCursor(bool val){
	if(val){
		SDL_ShowCursor(SDL_ENABLE);
	}else{
		SDL_ShowCursor(SDL_DISABLE);
	}
}

void AppWindow::centerCursor(){
	int newX = this->getWidth()/2;
	int newY = this->getHeight()/2;
	SDL_WarpMouseInWindow(this->GetWindow(), newX, newY);
}

AppWindow::~AppWindow() {
	SDL_DestroyWindow(mWindow);
	SDL_GL_DeleteContext(mContext);
	mWindow = 0;
	mContext = 0;
	SDL_Quit();
}

