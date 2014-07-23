#include "Plane.h"

Plane::Plane()
{
	InitVertices();
}

Plane::~Plane()
{
	glDeleteVertexArrays(1, &this->vertexArray);
	glDeleteBuffers(1, &this->vertexBuffer);
}

void Plane::InitVertices()
{
	glGenVertexArrays(1, &this->vertexArray);
	glBindVertexArray(this->vertexArray);

	glGenBuffers(1, &this->vertexBuffer);
	GLfloat vertices[] =
	{
	  0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
	  1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 
	  1.0f, 0.0f, 1.0f, 1.0f, 1.0f,

	  1.0f, 0.0f, 1.0f, 1.0f, 1.0f,
	  0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
	  0.0f, 0.0f, 0.0f, 0.0f, 0.0f
	};
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	//Bind data from buffer to the first shader layout
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
	glDisableVertexAttribArray(0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	glDisableVertexAttribArray(1);
	
}

void Plane::Draw(GLuint shaderProgram, Camera& cam)
{
	glUseProgram(shaderProgram);
	
	glUniformMatrix4fv(
		glGetUniformLocation(shaderProgram, "viewMatrix"),
		1,
		GL_FALSE,
		glm::value_ptr(cam.ViewMatrix())
		);
	glUniformMatrix4fv(
		glGetUniformLocation(shaderProgram, "projectionMatrix"),
		1,
		GL_FALSE,
		glm::value_ptr(cam.ProjectionMatrix())
		);

	glBindVertexArray(this->vertexArray);
	
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
}