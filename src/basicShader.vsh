#version 330

#define MAX_LIGHT 10

in vec3 position;
in vec2 texCoord;
in vec3 normal;
in vec3 tangent;
in vec3 biTangent;

uniform mat4 model;
uniform mat4 camera; 
uniform vec3 newColor;

out vec3 position0;
out vec2 texCoord0;
out vec3 normal0;
out vec3 Normal;
out vec3 newColor0;
out vec3 tangent0;
out vec3 biTangent0;

void main(void){
	gl_Position = camera * model * vec4(position, 1.0);
	position0 = (model * vec4(position, 1.0)).xyz;
	texCoord0 = texCoord;
	Normal = normal;
	normal0 = (model * vec4(normal, 0.0)).xyz;
	tangent0 = (model*vec4(tangent, 0.0)).xyz;
	biTangent0 = (model*vec4(biTangent, 0.0)).xyz;
	
	newColor0 = newColor;
}