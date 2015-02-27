#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#pragma once

#include <vector>
#include "../STechOne.h"
#include "../Utility/SWComponent.h"

class Camera;
class SWSceneManager;
class AppWindow;

struct SWRenderPass{
	Plane* p;
	Mesh* m;
	Shader* s;
	int sWidth, sHeight;
	std::vector<SWComponent*> objects;
	GLuint frameBuffer;
	GLuint texBuffer;

	SWRenderPass(){
		sWidth = 0;
		sHeight = 0;
		glGenFramebuffers(1, &frameBuffer);
		glGenTextures(1, &texBuffer);
		p = new Plane(0, 0, sWidth, sHeight);
	}

	SWRenderPass(int x, int y){
		sWidth = x;
		sHeight = y;
		glGenFramebuffers(1, &frameBuffer);
		glGenTextures(1, &texBuffer);
		p = new Plane(0, 0, sWidth, sHeight);
	}

	~SWRenderPass(){
		glDeleteFramebuffers(1, &frameBuffer);
		glDeleteTextures(1, &texBuffer);
	}

	void addObjects(SWComponent* comp){
		objects.push_back(comp);
	}
	void draw(Camera* cam){
		for(int i = 0; i < (int)objects.size(); i++){
			objects[i]->draw(cam);
		}
		glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);

		glBindTexture(GL_TEXTURE_2D, texBuffer);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, sWidth, sHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texBuffer, 0);


	}
};

class Graphics {
public:
	Graphics(AppWindow*);
	Graphics();
	virtual ~Graphics();

	/*Adds a Render Layer*/
	void addRenderPass(){
		renderPass.push_back(new SWRenderPass(WIDTH, HEIGHT));
	}

	void addToPass(int i, SWComponent* comp){
		if(i < (int)renderPass.size()){
			renderPass[i]->addObjects(comp);
		}
	}

	void drawPass(int i){
		if(i < (int)renderPass.size()){
			renderPass[i]->draw(camera);
		}
	}

	void addSkybox(){
		//TODO Skybox implementation
	}

	void setShader(Shader* shdr){
		shader = shdr;
	}

	void setCamera(Camera* cam){
		camera = cam;
	}

	void draw(SWComponent* swobject){
		swobject->draw(camera);
	}

	Camera* getCamera(){
		return camera;
	}

	Shader* getShader(){
		return shader;
	}

	void drawScene(SWSceneManager* scene);
private:
	std::vector<SWRenderPass*> renderPass;
	int WIDTH, HEIGHT;
	bool legacyGraphicsInUse;
	Camera* camera;
	Shader* shader;
	bool shadowEnabled;
};

#endif /* GRAPHICS_H_ */
