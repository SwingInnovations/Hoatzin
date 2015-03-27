#version 330

in vec2 _texCoord;

uniform sampler2D frameBuff;

out vec4 color;

const float blurSizeH = 1.0/300.0;
const float blurSizeW = 1.0/200.0;
void main(void){
	vec4 sum = vec4(0.0);
	for(int x = -4; x <= 4; x++){
		for(int y = -4; y <= 4; y++){
			sum += texture(frameBuff, vec2(_texCoord.x + x * blurSizeH, _texCoord.y + y * blurSizeW)) / 81.0;
		}
	}
	//color = sum;
	color = texture(frameBuff, _texCoord);
	//color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}
