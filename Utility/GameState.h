#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "../AppWindow.h"

class AppWindow;

class GameState {
public:
	GameState();
	GameState(int id){this->id = id;}
	virtual ~GameState();
	virtual void init(){}
	virtual void updateInput(AppWindow* app, int delta){}
	virtual void updateAuto(AppWindow* app ,int delta){}
	virtual void render(){}
	virtual int getID(){return id;}
private:
	int id;

};

#endif /* GAMESTATE_H_ */
