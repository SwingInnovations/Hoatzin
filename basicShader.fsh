#version 330

in vec2 texCoord0;
in vec3 normal0;

uniform sampler2D diffuse;
out vec4 color;

void main(void){
	color = texture2D( diffuse, texCoord0) * clamp(dot(-vec3(1, 0, 0), normal0), 0, 1.0);
}