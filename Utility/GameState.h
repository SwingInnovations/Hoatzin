#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "../AppWindow.h"
#include "../Graphics/Graphics.h"

class AppWindow;
class Graphics;

class GameState {
public:
	GameState();
	GameState(int id){this->id = id;}
	virtual ~GameState();
	virtual void init(){}
	virtual void updateInput(AppWindow* app, int delta){}
	virtual void updateAuto(AppWindow* app ,int delta){}
	virtual void render(){}
	virtual void render(Graphics* g){}
	virtual int getID(){return id;}
private:
	int id;
};

#endif /* GAMESTATE_H_ */
