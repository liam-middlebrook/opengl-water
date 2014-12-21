#include "Plane.h"

Plane::Plane()
{
	InitVertices();
	this->texture = 0;
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
	
	// x y z u v
	GLfloat vertices[] =
	{
	  0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
	  1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 
	  1.0f, 0.0f, 1.0f, 0.0f, 1.0f,

	  1.0f, 0.0f, 1.0f, 0.0f, 1.0f,
	  0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
	  0.0f, 0.0f, 0.0f, 1.0f, 0.0f
	};

	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	
	//Bind data from buffer to the first shader layout (xyz)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
	glDisableVertexAttribArray(0);

	//Bind data from the buffer to the second shader layout (uv)
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	glDisableVertexAttribArray(1);
	
}

void Plane::Draw(GLuint shaderProgram, Camera& cam)
{
	glUseProgram(shaderProgram);
	
	if(this->texture != 0)
	{
		glBindTexture(GL_TEXTURE_2D, this->texture);
	}

	glUniformMatrix4fv(
		glGetUniformLocation(shaderProgram, "viewMatrix"),
		1,
		GL_FALSE,
		glm::value_ptr(cam.ViewMatrix() * glm::scale(glm::mat4(1), glm::vec3(10, 1, 10)))
		);
	glUniformMatrix4fv(
		glGetUniformLocation(shaderProgram, "projectionMatrix"),
		1,
		GL_FALSE,
		glm::value_ptr(cam.ProjectionMatrix())
		);
	glUniform3f(
		glGetUniformLocation(shaderProgram, "texOffset"),
		cam.light.x,
		cam.light.y,
		cam.light.z
		);

	glBindVertexArray(this->vertexArray);
	
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
}
