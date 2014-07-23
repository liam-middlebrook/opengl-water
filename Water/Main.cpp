#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Plane.h"
#include "Shader.h"
#include "Texture.h"

#pragma region Variables

GLFWwindow* window;

GLuint shader;

Plane* plane;

Camera cam;

#pragma endregion

#pragma region Function Headers

void setupWindowAndContext();

void update();
void render();

#pragma endregion
int main()
{
	setupWindowAndContext();
	
	glClearColor(100/255.0f, 149/255.0f, 237/255.0f, 1.0f);

	shader = loadShader("vertex.glsl", "fragment.glsl");

	plane = new Plane();

	cam.position = glm::vec3(3, 10, 3);
	cam.target = glm::vec3(5,0,5);

	cam.light = glm::vec3(0.0f, 0.0f, 0.0f);

	glBindTexture(GL_TEXTURE_2D, loadTexture("18_vertex_texture_02.jpg"));

	while(!glfwWindowShouldClose(window))
	{
		update();
		render();
	}
	return 0;
}

void setupWindowAndContext()
{
	glfwInit();

	window = glfwCreateWindow(640, 480, "OpenGL Water Demo", NULL, NULL);
	glfwMakeContextCurrent(window);

	glewExperimental = true;
	glewInit();
}

void update()
{
	//cam.position -= glm::vec3(0,0.00001f,0);
	cam.light -= glm::vec3(0.00001f,0.00002f,0);
	glfwPollEvents();
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	plane->Draw(shader, cam);

	glfwSwapBuffers(window);
}