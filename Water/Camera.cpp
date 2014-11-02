#include "Camera.h"
#include <iostream>
void Camera::Update(GLFWwindow* window)
{
	float angle = 1.0f;

	if (glfwGetKey(window, GLFW_KEY_LEFT))
	{
		rotation.y += 1.0f;
	}

	if (glfwGetKey(window, GLFW_KEY_RIGHT))
	{
		rotation.y -= 1.0f;
	}

	if (glfwGetKey(window, GLFW_KEY_UP))
	{
		rotation.x += 1.0f;
	}

	if (glfwGetKey(window, GLFW_KEY_DOWN))
	{
		rotation.x -= 1.0f;
	}


	//rotation = rotation * glm::angleAxis(angle, 1.0f, 0.0f, 0.0f);// rotate on axis 1,0,0
	//rotation = rotation * glm::angleAxis(angle, 0.0f, 0.0f, 1.0f);// rotate on axis 1,0,0
}

void Camera::Translate(glm::vec3 vel)
{
	glm::vec3 direction = glm::vec3(rotMat*glm::vec4(vel, 1.0f));
	position += direction;
}

void printVector(glm::vec3 vector)
{
	std::cout << "X: " << vector.x << " Y: " << vector.y << " Z: " << vector.z << std::endl;
}
void printVector(glm::vec3 vector, const char* message)
{
	std::cout << message << " X: " << vector.x << " Y: " << vector.y << " Z: " << vector.z << std::endl;
}

glm::mat4 Camera::ViewMatrix()
{
	rotMat = glm::mat4();
	rotMat = glm::rotate(rotMat, rotation.y, glm::vec3(0, 1, 0));

	printVector(rotation, "Rotation: ");

	rotMat = glm::rotate(rotMat, rotation.x, glm::vec3(1, 0, 0));

	glm::vec3 direction = glm::vec3(rotMat * glm::vec4(0, 1, 1, 1));
	printVector(position, "Camera Position");
	printVector(direction, "Camera Direction");
	printVector(position + direction, "Camera LookTo");
	return glm::lookAt(position, position + direction, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Camera::ProjectionMatrix()
{
	return glm::perspective(45.0f, WIN_WIDTH / WIN_HEIGHT, 0.01f, 100.0f);
}
