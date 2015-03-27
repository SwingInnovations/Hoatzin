#version 330 

in vec3 position;
in vec2 texCoord;

uniform mat4 camera;

out vec2 _texCoord;

void main(void){
	gl_Position = camera * vec4(position, 1.0);
	_texCoord = position;
}

