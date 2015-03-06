#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#pragma once

#include <vector>
#include "../STechOne.h"
#include "../Utility/SWComponent.h"

class Camera;
class Texture;
class Mesh;
class SWSceneManager;
class AppWindow;

struct SWRenderPass{
	Shader* s;
	Mesh* m;
	int sWidth, sHeight;
	std::vector<SWComponent*> objects;
	Texture* tex;
	GLuint frameBuffer;
	GLuint texBuffer;
	GLuint renderBuff;

	SWRenderPass();

	SWRenderPass(int x, int y);

	~SWRenderPass();
	void setShader(Shader* shdr){ s = shdr; }
	void setShader(std::string& str){ s = new Shader(str); }

	Shader* getShader(){return s;}

	void addObjects(SWComponent* comp){
		objects.push_back(comp);
	}

	void draw(Camera* cam);
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
