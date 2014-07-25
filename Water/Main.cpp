#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Plane.h"
#include "Shader.h"
#include "Texture.h"
#include "GameTime.h"

#pragma region Variables

GLFWwindow* window;

GameTime gameTime;

GLuint shader;
GLuint shader2;

GLuint waterTex;
GLuint tex;

Plane* plane;
Plane* plane2;

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

	shader = loadShader("vertex.glsl", "fragment.phong.glsl");
	shader2 = loadShader("vertex.glsl", "fragment.glsl");

	plane = new Plane();

	plane2 = new Plane();

	cam.position = glm::vec3(3, 10, 3);
	cam.target = glm::vec3(5,0,5);

	cam.light = glm::vec3(0.0f, 0.0f, 0.0f);

	waterTex = loadTexture("18_vertex_texture_02.jpg");
	plane->texture=waterTex;

	tex = loadTexture("rubber_duck-1331px.png");
	plane2->texture = tex;

	while(!glfwWindowShouldClose(window))
	{
		update();
		render();
	}
	return 0;
}

void setupWindowAndContext()
{
	if(!glfwInit())
	{
		std::cout << "GLFW Failed to Initialize!" << std::endl;
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(640, 480, "OpenGL Water Demo", NULL, NULL);
	glfwMakeContextCurrent(window);

	glewExperimental = true;
	if(glewInit() != GLEW_OK)
	{
		std::cout << "Glew Failed to Initialize!" << std::endl;
		exit(EXIT_FAILURE);
	}
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void update()
{
	gameTime.Update();
	cam.position -= glm::vec3(0,0,0);
	cam.light -= glm::vec3(0.1f,0.2f,0) * gameTime.GetDeltaTimeSecondsF();
	glfwPollEvents();
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	plane2->Draw(shader2, cam);
	plane->Draw(shader, cam);

	glfwSwapBuffers(window);
}