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
	virtual void Update(AppWindow& app, int delta){}
	virtual void Render(){}
	virtual int GetID(){}
private:
	int id;
};

#endif /* GAMESTATE_H_ */
