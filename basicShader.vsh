#version 330

in vec3 position;
in vec2 texCoord;
in vec3 normal;

uniform mat4 MVP; 

out vec2 texCoord0;
out vec3 normal0;

void main(void){
	vec4 v = vec4(position, 1.0);
	gl_Position = MVP * v;
	texCoord0 = texCoord;
	normal0 = (MVP * vec4(normal, 1.0)).xyz;
}