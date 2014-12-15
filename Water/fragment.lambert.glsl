#version 330
#extension GL_ARB_shading_language_420pack : require

varying vec3 vertex;
varying vec2 texCoord;

uniform sampler2D tex;
layout(binding = 1) uniform sampler2D frameBuffer;

uniform vec3 texOffset;

vec3 lightPos = vec3(5, 2.5, 5);
vec4 lightDiff = vec4(1.0, 1.0, 1.0, 1.0)*20;

void main()
{
	vec3 vert = vertex;
	vec4 texData = texture(tex, texCoord + texOffset.xy * vec2(0.4));
	vec4 texData2 = texture(tex, texCoord + texOffset.xy * vec2(0.1, .2));
	//vert.y += texture(tex, texCoord).r;
	vec3 L = normalize(lightPos - vert);
	vec3 N = vec3(0, (texData.r + texData2.r ), 0);
	vec4 Idiff = lightDiff * max(dot(N, L), 0);

	Idiff = clamp(Idiff, 0.0, 1.0);
	Idiff = vec4(1.0) - Idiff;
	gl_FragColor = Idiff + vec4(0.0, 0.0, 0.1, 1.0);
	gl_FragColor.a *= 0.4;
	gl_FragColor += texture(frameBuffer, texCoord + 0.1*refract(L, N, 1.0/1.31).xy);
}
