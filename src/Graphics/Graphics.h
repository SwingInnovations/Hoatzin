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

class Graphics;

class SWGBuffer{
public:
	SWGBuffer();
	bool init(Graphics* g);

private:
	GLuint mFBO, mTexBuff, mRBO;
};

struct SWRenderPass{
	Shader* s;
	Shader* sceneShader;
	Mesh* m;
	int sWidth, sHeight;
	std::vector<SWComponent*> objects;
	std::string m_RPName;
	Texture* tex;
	GLuint frameBuffer;
	GLuint texBuffer;
	GLuint renderBuff;

	SWRenderPass();

	SWRenderPass(int x, int y);
	SWRenderPass(int x, int y, char* type);

	~SWRenderPass();
	void setShader(Shader* shdr){ s = shdr; }
	void setShader(std::string& str){ s = new Shader(str); }
	void setRPName(char* n){ m_RPName = n; }
	void bind();
	void unbind();

	Shader* getShader(){return s;}
	std::string getRPName(){return m_RPName;}

	void addObjects(SWComponent* comp){
		objects.push_back(comp);
	}

	void draw(Graphics* g);
};

/*-Graphics Class - Manages drawing the scenes-*/
class Graphics {
public:
	Graphics(AppWindow*);
	Graphics();
	virtual ~Graphics();

	void processScene(SWSceneManager* scene);

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
			renderPass[i]->draw(this);
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
