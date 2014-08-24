#include "Camera.h"

void Camera::Rotation(float amount, glm::vec3& axis)
{
	direction =  glm::rotate(direction, amount, axis);
}

void Camera::Translate(glm::vec3& direction)
{
	position += glm::rotate(direction, 1.0f, this->direction);
}

glm::mat4 Camera::ViewMatrix()
{
	return glm::lookAt(position, position + direction, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Camera::ProjectionMatrix()
{
	return glm::perspective(45.0f, WIN_WIDTH/WIN_HEIGHT, 0.01f, 100.0f);
}