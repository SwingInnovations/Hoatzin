
#include "AppWindow.h"
#include "DemoLevel.h"
#include "Level2.h"

int main(int argc, char** argv){
	AppWindow app("Test", 1024, 768);
	app.SetOpenGLVersion(3, 3);
	app.addState(new DemoLevel(0));
	app.addState(new Level2(1));
	app.enterState(0);
	app.setTargetFPS(60);
	app.start();
	return 0;
}
