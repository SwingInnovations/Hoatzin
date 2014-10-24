#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "../AppWindow.h"

class AppWindow;

class GameState {
public:
	GameState();
	GameState(int id){this->id = id;}
	virtual ~GameState();
	virtual void Init(){}
	virtual void UpdateInput(AppWindow* app, int delta){}
	virtual void UpdateAuto(AppWindow* app ,int delta){}
	virtual void Render(){}
	virtual int GetID(){return id;}
private:
	int id;

};

#endif /* GAMESTATE_H_ */
