#ifndef SWMATERIAL_H_
#define SWMATERIAL_H_

#include <vector>

struct SWMaterial{
	SWMaterial(){
		shader = new Shader();
	}
	void setShader(Shader* shader){this->shader = shader;}
	Shader* getShader(){return shader;}
	void bind(){
		for(unsigned int i = 0; i < textures.size(); i++){
			textures[i]->bind(i);
		}
		shader->bind();
	}
private:
	Shader* shader;
	std::vector<Texture*> textures;
};


#endif /* SWMATERIAL_H_ */
