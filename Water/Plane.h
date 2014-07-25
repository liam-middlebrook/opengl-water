#ifndef PLANE_H_
#define PLANE_H_

#include <GL/glew.h>
#include "Camera.h"

class Plane
{
public:
	Plane();
	~Plane();
	void Draw(GLuint shaderProgram, Camera& cam);
	GLuint texture;
private:
	void InitVertices();
	GLuint vertexArray;
	GLuint vertexBuffer;
};

#endif