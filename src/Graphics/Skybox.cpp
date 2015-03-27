/*
 * Skybox.cpp
 *
 *  Created on: Mar 26, 2015
 *      Author: Nathan_z400
 */

#include "Skybox.h"

Skybox::Skybox() {
	// TODO Auto-generated constructor stub
	initSkyboxID();
	m_SkyMesh = new Mesh();
	m_SkyShader = new Shader();
}

Skybox::Skybox(std::vector<std::string> ref){
	initSkyboxID();
	for(unsigned int i = 0; i < ref.size(); i++){
		SDL_Surface* img = NULL;
		img = IMG_Load(ref.at(i).c_str());
		if(img == NULL){ std::cout << "Invalid Texture!" << std::endl; break; }
		GLenum mode;
		GLint nOfColors = img->format->BytesPerPixel;
		if(nOfColors == 4){
			if(img->format->Rmask == 0x000000ff){
				mode = GL_RGBA;
			}else{
				mode = GL_BGRA;
			}
		}else if(nOfColors == 3){
			if(img->format->Rmask == 0x000000ff){
				mode = GL_RGB;
			}else{
				mode = GL_BGR;
			}
		}else{
			std::cout << "Invalid Texture! " << std::endl;
			break;
		}

		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, mode, img->w, img->h, 0, mode, GL_UNSIGNED_BYTE, img->pixels);
		SDL_FreeSurface(img);
		img = 0;
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	m_SkyShader = new Shader("Shader/skybox");
	m_SkyMesh = new Mesh("res/skyMesh.obj", MESH_TYPE::MODEL_OBJ);
}

void Skybox::draw(Camera* camera){
	m_SkyShader->update(*camera);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_SkyboxID);
	m_SkyMesh->draw();
}

void Skybox::initSkyboxID(){
	glGenTextures(1, &m_SkyboxID);
	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_SkyboxID);
}

Skybox::~Skybox() {
	// TODO Auto-generated destructor stub
}

