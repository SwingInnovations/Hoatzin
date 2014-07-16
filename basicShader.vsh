#version 330

attribute vec3 position;
attribute vec2 texCoord;

uniform mat4 MVP; 

varying vec2 texCoord0;

void main(void){
	vec4 v = vec4(position, 1.0);
	gl_Position = MVP * v;
	texCoord0 = texCoord;
}