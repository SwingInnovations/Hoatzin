
#include "AppWindow.h"
#include "DemoLevel.h"
#include "Level2.h"

int main(int argc, char** argv){
	AppWindow app("Test", 1024, 768);
	app.SetOpenGLVersion(3, 3);
	app.AddState(new DemoLevel(0));
	app.AddState(new Level2(1));
	app.EnterState(0);
	app.SetTargetFPS(60);
	app.Start();
	return 0;
}
