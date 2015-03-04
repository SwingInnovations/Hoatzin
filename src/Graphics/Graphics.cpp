#include "Graphics.h"

SWRenderPass::SWRenderPass(){
	sWidth = 0;
	sHeight = 0;
	glGenFramebuffers(1, &frameBuffer);
	glGenRenderbuffers(1, &renderBuff);
	glGenTextures(1, &texBuffer);
	m = new Mesh(new Plane(0, 0, sWidth, sHeight));
}

SWRenderPass::SWRenderPass(int x, int y){
	sWidth = x;
	sHeight = y;
	glGenFramebuffers(1, &frameBuffer);
	glGenTextures(1, &texBuffer);
	glGenRenderbuffers(1, &renderBuff);
	m = new Mesh(new Plane(0, 0, sWidth, sHeight));
}

Graphics::Graphics(AppWindow* app){
	WIDTH = app->getWidth();
	HEIGHT = app->getHeight();
}

Graphics::Graphics() {
	WIDTH = 0;
	HEIGHT = 0;

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
