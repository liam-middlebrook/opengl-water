#include "Camera.h"
#include "Utils.h"

#include <iostream>

#define DEBUG
void Camera::UpdateRotation(GLFWwindow* window, float angleStep)
{
	if (glfwGetKey(window, GLFW_KEY_LEFT))
	{
		rotation.y += angleStep;
	}

	if (glfwGetKey(window, GLFW_KEY_RIGHT))
	{
		rotation.y -= angleStep;
	}

	if (glfwGetKey(window, GLFW_KEY_UP))
	{
		rotation.x += angleStep;
	}

	if (glfwGetKey(window, GLFW_KEY_DOWN))
	{
		rotation.x -= angleStep;
	}
}

void Camera::Translate(glm::vec3 vel)
{
	// Interpolate the direction of movement based on the velocity
	// and camera rotation matrix
	glm::vec3 direction = glm::vec3(rotMat * glm::vec4(vel, 1.0f));
	position += direction;
}

glm::mat4 Camera::ViewMatrix()
{
	// Set lower rotation bound
	if (rotation.x < -220)
		rotation.x = -220;

	// Set upper rotation bound
	if (rotation.x > 90)
		rotation.x = 90;

	// Reset rotation matrix
	rotMat = glm::mat4();

	// Rotate the Yaw
	rotMat = glm::rotate(rotMat, rotation.y, glm::vec3(0, 1, 0));

	// Rotate the Pitch
	rotMat = glm::rotate(rotMat, rotation.x, glm::vec3(1, 0, 0));

	// Find direction of rotation
	glm::vec3 direction = glm::vec3(rotMat * glm::vec4(0, 1, 1, 1));
	
#ifdef DEBUG
	// Print out some debug info
	printVector(rotation, "Rotation: ");
	printVector(position, "Camera Position");
	printVector(direction, "Camera Direction");
	printVector(position + direction, "Camera LookTo");
#endif

	return glm::lookAt(position, position + direction, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Camera::ProjectionMatrix()
{
	return glm::perspective(45.0f, WIN_WIDTH / WIN_HEIGHT, 0.01f, 100.0f);
}
