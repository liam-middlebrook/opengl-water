#include "Camera.h"
#include <iostream>
void Camera::Update()
{
  float angle = 5.0f;
  //rotation = rotation * glm::angleAxis(angle, 1.0f, 0.0f, 0.0f);// rotate on axis 1,0,0
  rotation = rotation * glm::angleAxis(angle, 0.0f, 0.0f, 1.0f);// rotate on axis 1,0,0
}

glm::mat4 Camera::ViewMatrix()
{
	glm::vec3 direction = glm::vec3(glm::toMat4(rotation)*glm::vec4(1));
	std::cout << direction.x << " " << direction.y << " " << direction.z <<std::endl;
	return glm::lookAt(position, position + direction, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Camera::ProjectionMatrix()
{
	return glm::perspective(45.0f, WIN_WIDTH/WIN_HEIGHT, 0.01f, 100.0f);
}
