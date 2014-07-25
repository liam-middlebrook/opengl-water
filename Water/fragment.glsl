#version 330

varying vec3 vertex;
varying vec2 texCoord;

uniform sampler2D tex;

uniform vec3 texOffset;

vec3 lightPos = vec3(5, 1.5, 5);
vec4 lightDiff = vec4(1.0, 1.0, 1.0, 1.0);

void main()
{
	gl_FragColor = texture(tex, texCoord);
}