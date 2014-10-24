/*
 * AppWindow.cpp
 *
 *  Created on: Jun 11, 2014
 *      Author: Nathan_z400
 */

#include "AppWindow.h"

AppWindow::AppWindow() {


}

AppWindow::AppWindow(const std::string title, int WIDTH, int HEIGHT){
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
	}else{
		glewExperimental = GL_TRUE;
		glewInit();

		std::cout << "Using OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
		std::cout << "Using Graphics Driver: " << glGetString(GL_VENDOR) << std::endl;
	}
}

void AppWindow::AddState(GameState* newState){
	state.push_back(newState);
}

void AppWindow::Init(){
	if(!state.empty()){
		for(unsigned int i = 0; i < state.size(); i++){
			state.at(i)->Init();
		}
	}
}

void AppWindow::UpdateInput(SDL_Event& e){
	input->Poll(e);
	if(input->isCloseRequested()){
		SetRunning(false);
	}

	if(!state.empty()){
		state.at(mCurrentState)->UpdateInput(this, delta);
	}
}

void AppWindow::UpdateAuto(){
	if(!state.empty()){
		state.at(mCurrentState)->UpdateAuto(this, delta);
	}
}

void AppWindow::CalcDelta(){
	if(newTime > oldTime){
		delta = newTime - oldTime;
		Uint32 targetInterval = (Uint32)(1.0/this->GetFPS() * 1000);
		if(delta < targetInterval){
			delta = targetInterval;
		}
		oldTime = newTime;
		newTime = SDL_GetTicks();
	}
}

void AppWindow::Render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.2, 1.0);

	glEnable(GL_DEPTH_TEST);

	if(!state.empty()){
		state.at(mCurrentState)->Render();
	}

	SDL_GL_SwapWindow(mWindow);
}

void AppWindow::Start(){
	SetRunning(true);
	Init();
	while(Running){
		CalcDelta();
		while(SDL_PollEvent(&e)){
			UpdateInput(e);
		}

		UpdateAuto();
		Render();
	}
}

void AppWindow::ShowCursor(bool val){
	if(val){
		SDL_ShowCursor(SDL_ENABLE);
	}else{
		SDL_ShowCursor(SDL_DISABLE);
	}
}

void AppWindow::CenterCursor(){
	int newX = this->GetWidth()/2;
	int newY = this->GetHeight()/2;
	SDL_WarpMouseInWindow(this->GetWindow(), newX, newY);
}

AppWindow::~AppWindow() {
	SDL_DestroyWindow(mWindow);
	SDL_GL_DeleteContext(mContext);
	mWindow = 0;
	mContext = 0;
	SDL_Quit();
}

