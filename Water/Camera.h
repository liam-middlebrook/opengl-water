#ifndef CAMERA_H_
#define CAMERA_H_

#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>

#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080.0f

// A basic camera class
class Camera
{
public:
	
	// Get the View Matrix (eye) of the camera
	glm::mat4 ViewMatrix();

	// Get the Projection Matrix for the camera
	glm::mat4 ProjectionMatrix();

	// Update the camera's position
	// params:
	//   window - the GLFWwindow to get input from
	//   angleStep - the amount to step the angle by each update call
	void UpdateRotation(GLFWwindow* window, float angleStep = 1.0f);

	// Translate the camera
	void Translate(glm::vec3 vel);

	// The position of the camera in world space
	glm::vec3 position;

	// The position of the world light
	glm::vec3 light;

	// The rotation of the camera in world space
	glm::vec3 rotation;

	// The matrix representing the camera rotation
	glm::mat4 rotMat;
};

#endif
