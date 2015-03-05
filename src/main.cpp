
#include <iostream>
#include "STechOne.h"
#include "DemoLevel.h"
#include "ExampleLevel.h"

int main(int argc, char** argv){
	InputMap* map = new InputMap();
	map->addMapping(MOVEMENT::FORWARD, KEY::KEY_W);
	map->addMapping(MOVEMENT::BACKWARD, KEY::KEY_S);
	map->addMapping(MOVEMENT::STRAFE_LEFT, KEY::KEY_A);
	map->addMapping(MOVEMENT::STRAFE_RIGHT, KEY::KEY_D);

	AppWindow app("Hoatzin --- ENGINE V.0.0.45", 1440, 900);
	Vector3f cameraPos(-5.0f, -6.0f, 0.0f);
	app.setCamera(new Camera(cameraPos, 66.0f, 1440.0f, 900.0f, 1.0f, 1000.0f, CAMERA_VIEW::PERSPECTIVE, CAMERA_MOVEMENT::FirstPerson));
	app.setInputMapping(map);
	app.SetOpenGLVersion(3, 3);
	app.addState(new ExampleLevel(0));
	app.enterState(0);
	app.setTargetFPS(60);
	app.start();
	return 0;
}
