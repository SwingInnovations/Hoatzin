#version 330

in vec2 texCoord0;
in vec3 normal0;
in vec3 newColor0;

uniform sampler2D diffuse;
out vec4 color;

void main(void){
	color = texture2D( diffuse, texCoord0) * clamp(dot(-vec3(0.5, -0.5, 0.0f), normal0), 0, 1.0);
	//color = vec4(newColor0, 1.0) * clamp(dot(-vec3(0.5, -0.5, 0.0f), normal0), 0, 1.0);
}