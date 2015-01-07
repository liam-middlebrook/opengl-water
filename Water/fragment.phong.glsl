#version 330
#extension GL_ARB_shading_language_420pack : require

varying vec3 vertex;
varying vec2 texCoord;

uniform sampler2D tex;
layout(binding = 1) uniform sampler2D frameBuffer;
uniform vec3 texOffset;

vec3 lightPos = vec3(0, 7.4, 5);
vec4 lightDiff = vec4(.5, .5, .5, 1.0)*20;

vec4 specular = vec4(1.0,1.0,1.0,1.0)*5;
float shininess = 7.5f;

float waveScale = 1.0f;

void main()
{
	vec3 vert = vertex;
	vec4 texData = texture(tex, texCoord + texOffset.xy * vec2(0.4)) * waveScale;
	vec4 texData2 = texture(tex, texCoord + texOffset.xy * vec2(0.1, .2)) * waveScale;
	vec3 N = normalize(texData.xyz + texData2.xyz) * 1.2;

	
	vec3 L = normalize(lightPos - vert);
	vec3 E = normalize(vec3(3, 10, 3));
	vec3 R = normalize(-reflect(L, N));

	vec4 Iamb = vec4(0);
	vec4 Idiff = lightDiff * max(dot(N, L), 0.0);

	vec4 Ispec = specular * pow(max(dot(R,E),0.0),shininess);
	Ispec = clamp(Ispec, 0.0, 1.0);
	Idiff = clamp(Idiff, 0.0, 1.0);
	Idiff = vec4(1.0) - Idiff;
	gl_FragColor = Iamb + Idiff + Ispec + vec4(0.0, 0.0, .05, 1.0);
	gl_FragColor.a *= 0.4;
	gl_FragColor += (texture(frameBuffer, texCoord + 0.1*refract(L, N, 1.0/1.31).xy) * waveScale);
}
