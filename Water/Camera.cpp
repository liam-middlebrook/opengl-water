#include "Camera.h"

glm::mat4 Camera::ViewMatrix()
{
	return glm::lookAt(position, position + rotation, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Camera::ProjectionMatrix()
{
	return glm::perspective(45.0f, 640.0f/480.0f, 0.01f, 100.0f);
}