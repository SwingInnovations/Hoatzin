
#include "AppWindow.h"
#include "DemoLevel.h"
#include "Level2.h"

int main(int argc, char** argv){
	AppWindow app("Hoatzin --- ENGINE V.0.0.45", 1440, 900);
	app.SetOpenGLVersion(3, 3);
	app.addState(new DemoLevel(0));
	app.addState(new Level2(1));
	app.enterState(0);
	app.setTargetFPS(60);
	app.start();
	return 0;
}
