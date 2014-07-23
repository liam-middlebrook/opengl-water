#version 330

varying vec3 vertex;
varying vec2 texCoord;

uniform sampler2D tex;

vec3 lightPos = vec3(1, .5, 0);
vec4 lightDiff = vec4(1.0, 1.0, 1.0, 1.0);

void main()
{
	vec3 L = normalize(lightPos - vertex);
	vec4 Idiff = lightDiff * max(dot(vec3(0, 1, 0), L), 0.0);

	Idiff = clamp(Idiff, 0.0, 1.0);

	gl_FragColor = texture(tex, texCoord) * Idiff;
}