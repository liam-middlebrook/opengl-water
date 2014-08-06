#include "Camera.h"

glm::mat4 Camera::ViewMatrix()
{
	return glm::lookAt(position, target, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Camera::ProjectionMatrix()
{
	return glm::perspective(45.0f, WIN_WIDTH/WIN_HEIGHT, 0.01f, 100.0f);
}