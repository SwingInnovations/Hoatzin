#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "../AppWindow.h"
#include "../Graphics/Graphics.h"
#include "SWSceneManager.h"

class AppWindow;
class Graphics;

class GameState {
public:
	GameState();
	GameState(int id){this->id = id; scene = 0;}
	virtual ~GameState();
	virtual void init(){}
	virtual void updateInput(AppWindow* app, int delta){}
	virtual void updateAuto(AppWindow* app ,int delta){}
	virtual void render(){}
	virtual void render(Graphics* g){}
	virtual int getID(){return id;}
private:
	int id;
	SWSceneManager* scene;
};

#endif /* GAMESTATE_H_ */
