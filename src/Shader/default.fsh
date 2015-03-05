#version 330

in vec2 _texCoord;

uniform sampler2D frameBuff;

out vec4 color;

void main(void){
	color = texture2D(frameBuff, _texCoord);
	//color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}
