#ifndef PLANE_H_
#define PLANE_H_

#include <GL/glew.h>
#include "Camera.h"

// A 3D Plane
class Plane
{
public:

	// Plane Constructor
	Plane();

	// Plane Destructor
	~Plane();

	// Draw the plane
	// params:
	//   shaderProgram - The shader program to draw
	//                   the plane with
	//   cam - The camera (for light position)
	void Draw(GLuint shaderProgram, Camera& cam);

	// The plane texture
	GLuint texture;
private:
	void InitVertices();
	GLuint vertexArray;
	GLuint vertexBuffer;
};

#endif
