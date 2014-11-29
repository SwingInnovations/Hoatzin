#version 330

in vec3 position;
in vec2 texCoord;
in vec3 normal;

uniform mat4 model;
uniform mat4 camera; 
uniform vec3 newColor;

out vec2 texCoord0;
out vec3 normal0;
out vec3 newColor0;

void main(void){
	gl_Position = camera * model * vec4(position, 1.0);
	texCoord0 = texCoord;
	normal0 = (model * vec4(normal, 1.0)).xyz;
	newColor0 = newColor;
}