#include "Graphics.h"

Graphics::Graphics() {
	// TODO Auto-generated constructor stub

}

Graphics::~Graphics() {
	delete camera;
}

void Graphics::drawScene(SWSceneManager* scene){
	if(scene->getSceneObjects()->size() > 0){
		for(int i = 0; i < scene->getSceneObjects()->size(); i++){
			scene->getSceneObjects()->at(i)->draw(camera);
		}
	}
}
