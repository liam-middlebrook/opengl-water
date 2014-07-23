#ifndef CAMERA_H_
#define CAMERA_H_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
	glm::mat4 ViewMatrix();
	glm::mat4 ProjectionMatrix();
	glm::vec3 position;
	glm::vec3 rotation;
};

#endif