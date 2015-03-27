#version 330

in vec2 _texCoord;
out vec4 color;

uniform samplerCube skyBox;

void main(void){
	color = texture(skyBox, _texCoord);
}