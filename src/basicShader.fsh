#version 330

#define MAX_LIGHT 10

uniform int numLight;

uniform struct Light{
	vec4 position;
	vec3 intensity;
	float attenuation;
	float ambientCoefficient;
	float coneAngle;
	vec3 coneDirection;
}SWLight[MAX_LIGHT];

in vec2 texCoord0;
in vec3 normal0;
in vec3 tangent0;
in vec3 biTangent0;
in vec3 newColor0;

uniform sampler2D diffuse;
out vec4 color;

void main(void){
	//vec3 posTest = SWLight[0].intensity.xyz;
	float brightness = clamp(dot(-SWLight[0].position.xyz, normal0), 0.0f, 1.0f);
	
	//color = texture2D( diffuse, texCoord0) * clamp(dot(-vec3(0.0, -1.0f, 1.0f), normal0), 0, 1.0);
	//color = vec4(newColor0, 1.0) * clamp(dot(-vec3(0.0, -1.0f, 1.0f), normal0), 0, 1.0f);
	color = texture2D(diffuse, texCoord0)*brightness;
	//color = vec4(posTest, 1.0f);
}