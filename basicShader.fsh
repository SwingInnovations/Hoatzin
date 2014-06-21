#version 330

varying vec2 texCoord0;
uniform sampler2D diffuse;


void main(void){
	gl_FragColor = texture2D( diffuse, texCoord0);
}