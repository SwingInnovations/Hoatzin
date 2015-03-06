#version 330

in vec2 _texCoord;

uniform sampler2D frameBuff;

out vec4 color;

const float offset = 1.0/300;

void main(void){
	
	vec2 offsets[9] = vec2[](
		vec2(-offset, offset),  
        vec2(0.0f,    offset),  
        vec2(offset,  offset),  
        vec2(-offset, 0.0f),    
        vec2(0.0f,    0.0f),    
        vec2(offset,  0.0f),    
        vec2(-offset, -offset), 
        vec2(0.0f,    -offset), 
        vec2(offset,  -offset) 
	);
	
	float kernel[9] = float[](
        1.0/16, 2.0/16, 1.0/16,
        2.0/16,  4.0/16, 2.0/16,
        1.0/16, 2.0/16, 1.0/16
    );
    
    vec3 sample[9];
    for(int i = 0; i < 9; i++)
    {
        sample[i] = vec3(texture(frameBuff, _texCoord.st + offsets[i]));
    }
    vec3 col;
    for(int i = 0; i < 9; i++)
        col += sample[i] * kernel[i];
    
    color = vec4(col, 1.0);
	
	//color = texture(frameBuff, _texCoord);
	//color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}
