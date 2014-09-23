#include "Camera.h"
#include <iostream>
void Camera::Update(GLFWwindow* window)
{
  float angle = 1.0f;
  
  if(glfwGetKey(window, GLFW_KEY_LEFT))
  {
    yawRotation = yawRotation * glm::angleAxis(angle, 0.0f, -1.0f, 0.0f);
  }
  
  if(glfwGetKey(window, GLFW_KEY_RIGHT))
  {
    yawRotation = yawRotation * glm::angleAxis(angle, 0.0f, 1.0f, 0.0f);
  }

  if(glfwGetKey(window, GLFW_KEY_UP))
  {
    pitchRotation = pitchRotation * glm::angleAxis(angle, 1.0f, 0.0f, 0.0f);
  }

  if(glfwGetKey(window, GLFW_KEY_DOWN))
  {
    pitchRotation = pitchRotation * glm::angleAxis(angle, -1.0f, 0.0f, 0.0f);
  }


  //rotation = rotation * glm::angleAxis(angle, 1.0f, 0.0f, 0.0f);// rotate on axis 1,0,0
  //rotation = rotation * glm::angleAxis(angle, 0.0f, 0.0f, 1.0f);// rotate on axis 1,0,0
}

void Camera::Translate(glm::vec3 vel)
{
  glm::vec3 direction = glm::vec3(glm::toMat4(pitchRotation) * glm::toMat4(yawRotation)*glm::vec4(vel, 1.0f));
  position+=direction;
}

glm::mat4 Camera::ViewMatrix()
{
	glm::vec3 direction = glm::vec3(glm::toMat4(pitchRotation) * glm::toMat4(yawRotation)*glm::vec4(1));
	return glm::lookAt(position, position + direction, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Camera::ProjectionMatrix()
{
	return glm::perspective(45.0f, WIN_WIDTH/WIN_HEIGHT, 0.01f, 100.0f);
}
