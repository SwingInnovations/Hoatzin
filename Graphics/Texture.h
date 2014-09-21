#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/glew.h>
#include <string>
#include <cassert>

class Texture {
public:
	Texture();
	Texture(const std::string& fileName);
	virtual ~Texture();

	void bind(unsigned int index);
private:
	GLuint mTexture;
};

#endif /* TEXTURE_H_ */
