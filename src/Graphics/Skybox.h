#ifndef SKYBOX_H_
#define SKYBOX_H_

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>
#include <iostream>

#include "Shader.h"
#include "../Utility/Mesh.h"

class Camera;
class Mesh;
class Shader;

class Skybox {
public:
	Skybox();
	Skybox(std::vector<std::string> ref);
	void draw(Camera* camera);
	virtual ~Skybox();
private:
	void initSkyboxID();
	GLuint m_SkyboxID;
	Mesh* m_SkyMesh;
	Shader* m_SkyShader;
};

#endif /* SKYBOX_H_ */
