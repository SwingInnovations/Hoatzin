#include "Graphics.h"

Graphics::Graphics(AppWindow* app){
	WIDTH = app->getWidth();
	HEIGHT = app->getHeight();
}

Graphics::Graphics() {
	// TODO Auto-generated constructor stub

}

Graphics::~Graphics() {
	delete camera;
}

void Graphics::drawScene(SWSceneManager* scene){

	shader->update("numLight", scene->getNumLight());

	for(unsigned int i = 0; i < scene->getSceneObjects()->size(); i++){
		scene->getSceneObjects()->at(i)->draw(camera);
	}

	for(unsigned int i = 0; i < scene->getLights()->size(); i++){
		scene->getLights()->at(i)->draw(shader);
	}
}
