#ifndef CAMERA_H_
#define CAMERA_H_

#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>

#define WIN_WIDTH 1920.0f
#define WIN_HEIGHT 1080.0f

class Camera
{
public:
	glm::mat4 ViewMatrix();
	glm::mat4 ProjectionMatrix();
	void Rotation(float amount, glm::vec3 axis);
	void Translate(glm::vec3 direction);
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 light;
	glm::quat rotation;
};

#endif
