#version 420

varying vec3 vertex;
varying vec2 texCoord;

uniform sampler2D tex;
layout(binding = 1) uniform sampler2D frameBuffer;
uniform vec3 texOffset;

vec3 lightPos = vec3(5, 5, 5);
vec4 lightDiff = vec4(.5, .5, .5, 1.0)*20;

vec4 specular = vec4(1.0,1.0,1.0,1.0)*5;
float shininess = 50.0f;

void main()
{
	vec3 vert = vertex;
	vec4 texData = texture(tex, texCoord + texOffset.xy * vec2(0.4));
	vec4 texData2 = texture(tex, texCoord + texOffset.xy * vec2(0.1, .2));
	vec3 N = vec3(0.0, (texData.r + texData2.r ), 0.0);

	//vert.y += texture(tex, texCoord).r;
	
	vec3 L = normalize(lightPos - vert);
	vec3 E = normalize(-vert);
	vec3 R = normalize(-reflect(L, N));

	vec4 Iamb = vec4(0);
	vec4 Idiff = lightDiff * max(dot(N, L), 0.0);

	vec4 Ispec = specular * pow(max(dot(R,E),0.0),shininess);
	Ispec = clamp(Ispec, 0.0, 1.0);
	Idiff = clamp(Idiff, 0.0, 1.0);
	Idiff = vec4(1.0) - Idiff;
	gl_FragColor = Iamb + Idiff + Ispec + vec4(0.0, 0.0, .05, 1.0);
	gl_FragColor.a *= 0.4;
	gl_FragColor += texture(frameBuffer, texCoord + 0.1*refract(L, N, 1.0/1.31).xy);
}