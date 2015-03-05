#version 330

#define MAX_LIGHT 10

uniform int numLight;

uniform struct SWMaterial{
	sampler2D diffuseMap;
	sampler2D specularMap;
	sampler2D normalMap;
};

uniform struct Light{
	vec4 position;
	vec3 intensity;
	float attenuation;
	float ambientCoefficient;
	float coneAngle;
	vec3 coneDirection;
}SWLight[MAX_LIGHT];

in vec3 position0;
in vec2 texCoord0;
in vec3 normal0;
in vec3 tangent0;
in vec3 biTangent0;
in vec3 newColor0;

uniform sampler2D diffuse;
uniform vec3 cameraPosition; 
out vec4 color;

vec3 applyLight(Light light, vec3 surfaceColor, vec3 normal, vec3 surfacePos, vec3 surfaceToCamera){
	vec3 surfaceToLight;
	float attenuation = 0.0f;
	if(light.position.w == 0.0){
		surfaceToLight = normalize(light.position.xyz);
		attenuation = 1.0;
	}else{
		surfaceToLight = normalize(light.position.xyz - surfacePos);
		float distanceToLight = length(light.position.xyz - surfacePos);
		attenuation = 1.0f/(1.0f + light.attenuation + pow(distanceToLight, 2));
		
		float lightToSurfaceAngle = degrees(acos(dot(-surfaceToLight, normalize(light.coneDirection))));
		if(lightToSurfaceAngle > light.coneAngle){
			attenuation = 0.0f;
		}
	}
	vec3 ambient = light.ambientCoefficient * surfaceColor.rgb * light.intensity;
	
	float diffuseCoefficient = max(0.0, dot(normal, surfaceToLight));
	vec3 diffuse = diffuseCoefficient * surfaceColor.rgb * light.intensity;
	
	float specularCoefficient = 0.0;
	if(diffuseCoefficient > 0.0){
		specularCoefficient = pow(max(0.0, dot(surfaceToCamera, reflect(-surfaceToLight, normal))), 1.0);
	}
	vec3 specular = specularCoefficient * vec3(1.0, 1.0, 1.0f) * light.intensity;
	
	return ambient + attenuation * (diffuse + specular);
}

void main(void){
	//vec3 posTest = SWLight[0].intensity.xyz;
	//float brightness = clamp(dot(-SWLight[0].position.xyz, normal0), 0.0f, 1.0f);
	
	//vec4 ambientColor = vec4(SWLight[0].intensity, 1.0) * SWLight[0].ambientCoefficient;
	
	vec3 surfaceColor = texture2D(diffuse, texCoord0).rgb;
	vec3 linearColor;
	for(int i = 1; i < numLight; i++){
		linearColor +=  applyLight(SWLight[i], surfaceColor, normal0, position0, normalize(cameraPosition-SWLight[i].position.xyz)) * clamp(dot(-SWLight[i].position.xyz, normal0), 0.0f, 1.0f);
	}
	
	//color = vec4(linearColor, 1.0);
	color = vec4(surfaceColor, 1.0);
	
}