/*
 * Texture.cpp
 *
 *  Created on: Jun 18, 2014
 *      Author: Nathan_z400
 */

#include <iostream>
#include "Texture.h"

Texture::Texture() {


}

Texture::Texture(const std::string& fileName){
	SDL_Surface* image = NULL;
	image = IMG_Load(fileName.c_str());

	GLenum mode;
	GLint nOfColors = image->format->BytesPerPixel;

	if(nOfColors == 4){
		if(image->format->Rmask == 0x000000ff){
			mode = GL_RGBA;
		}else{
			mode = GL_BGRA;
		}
	}else if(nOfColors == 3){
		if(image->format->Rmask == 0x000000ff){
			mode = GL_RGB;
		}else{
			mode = GL_BGR;
		}
	}else{
		std::cout << "Invalid Texture!" << std::endl;
	}

	glGenTextures(1, &mTexture);
	glBindTexture(GL_TEXTURE_2D, mTexture);

	glTexImage2D(mTexture, 0, nOfColors, image->w, image->h, 0, mode, GL_UNSIGNED_BYTE, image->pixels);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	SDL_FreeSurface(image);
	image = 0;
}

Texture::~Texture() {
	glDeleteTextures(1, &mTexture);
}

void Texture::bind(unsigned int index){
	assert(index >= 0 && index <= 31);

	glEnable(GL_TEXTURE_2D);

	glActiveTexture(GL_TEXTURE0 + index);
	glBindTexture(GL_TEXTURE_2D, mTexture);
}

