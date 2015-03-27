#include "Graphics.h"

SWRenderPass::SWRenderPass(){
	sWidth = 0;
	sHeight = 0;
	m = new Mesh(new Plane(0, 0, 1, 1));
	s = new Shader("Shader/screen", "Shader/default");

	glGenFramebuffers(1, &frameBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);

	glGenTextures(1, &texBuffer);
	glBindTexture(GL_TEXTURE_2D, texBuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_BGR, sWidth, sHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texBuffer, 0);

	glGenRenderbuffers(1, &renderBuff);
	glBindRenderbuffer(GL_RENDERBUFFER, renderBuff);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, sWidth, sHeight);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, renderBuff);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

SWRenderPass::SWRenderPass(int x, int y){
	sWidth = x;
	sHeight = y;
	m = new Mesh(new Quad(2, 2));

	s = new Shader("Shader/screen", "Shader/default");

	glGenFramebuffers(1, &frameBuffer);
	glGenTextures(1, &texBuffer);

	glBindTexture(GL_TEXTURE_2D, texBuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, sWidth, sHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
	glFramebufferParameteri(GL_FRAMEBUFFER, GL_FRAMEBUFFER_DEFAULT_WIDTH, sWidth);
	glFramebufferParameteri(GL_FRAMEBUFFER, GL_FRAMEBUFFER_DEFAULT_HEIGHT, sHeight);
	glFramebufferParameteri(GL_FRAMEBUFFER, GL_FRAMEBUFFER_DEFAULT_SAMPLES, 4);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texBuffer, 0);

	glGenRenderbuffers(1, &renderBuff);
	glBindRenderbuffer(GL_RENDERBUFFER, renderBuff);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, sWidth, sHeight);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, renderBuff);

	GLenum drawBuffers[] = {GL_COLOR_ATTACHMENT0};
	glDrawBuffers(1, drawBuffers);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	if(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE){
		std::cout << "Successfully generated FrameBuffer" << std::endl;
	}
	glViewport(0, 0, sWidth, sHeight);
}

SWRenderPass::~SWRenderPass(){
	s->~Shader();
	m->~Mesh();
	glDeleteFramebuffers(1, &frameBuffer);
	glDeleteRenderbuffers(1, &renderBuff);
	glDeleteTextures(1, &texBuffer);
}

void SWRenderPass::draw(Camera* cam){

	glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.2, 1.0);
	glEnable(GL_DEPTH_TEST);
	for(int i = 0; i < (int)objects.size(); i++){
		objects[i]->draw(cam);
	}

	glEnable(GL_TEXTURE_2D);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_DEPTH_TEST);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texBuffer);
	s->bind();
	m->draw();

	glDisable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.2, 1.0);
	glEnable(GL_DEPTH_TEST);

	shader->update("numLight", scene->getNumLight());

	for(unsigned int i = 0; i < scene->getSceneObjects()->size(); i++){
		scene->getSceneObjects()->at(i)->draw(camera);
	}

	for(unsigned int i = 0; i < scene->getLights()->size(); i++){
		scene->getLights()->at(i)->draw(shader);
	}
}
