#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/glew.h>
#include <string>
#include <vector>
#include <cassert>

class Texture {
public:
	Texture();
	Texture(const std::string& fileName);
	virtual ~Texture();
	GLuint genTex(const std::string& fileName);
	void addTexture(const std::string& fileName);
	void bind(unsigned int index);
private:
	//GLuint mTexture;
	void reBind();
	GLuint tex[32];
	unsigned int texIndex;
	std::vector<std::string> fileReference;
};

#endif /* TEXTURE_H_ */
