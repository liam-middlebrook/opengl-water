#include "Utils.h"

void printVector(glm::vec3 vector)
{
	std::cout << "X: " << vector.x << " Y: " << vector.y << " Z: " << vector.z << std::endl;
}
void printVector(glm::vec3 vector, const char* message)
{
	std::cout << message << " X: " << vector.x << " Y: " << vector.y << " Z: " << vector.z << std::endl;
}
