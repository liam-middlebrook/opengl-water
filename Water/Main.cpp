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

Camera cam;

glm::vec2 mousePosLast;

char* waveShader;

#pragma endregion

#pragma region Function Headers

void setupWindowAndContext();

void update();
void render();

#pragma endregion

int main(int argc, char* argv[])
 {
	setupWindowAndContext();

	// Set background to cornflowerblue
	glClearColor(100/255.0f, 149/255.0f, 237/255.0f, 1.0f);

	if(argc < 3)
	{ 
		printf("Error only %d arguments provided!\n", argc);
		printf("The proper format for arguments is `water [shader] [backgroundtexture]`\n");
		exit(EXIT_FAILURE);
 	}

	waveShader = argv[1];

	// Load in our shaders
	shader = loadShader("vertex.glsl", waveShader);
	shader2 = loadShader("vertex.glsl", "fragment.glsl");

	plane = new Plane();

	// Set camera position and light position
	cam.position = glm::vec3(3, 5, 3);
	cam.light = glm::vec3(0.0f, 0.0f, 0.0f);

	// Set wave texture
	waterTex = loadTexture("water3.jpg");
	plane->texture=waterTex;

	// Load in background texture
	tex = loadTexture(argv[2]);

	// Bind background texture to SLOT1
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, tex);
	glActiveTexture(GL_TEXTURE0);

	cam.rotation = glm::vec3(-173, -142, 0);

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

	glfwWindowHint(GLFW_DECORATED, GL_FALSE);
	glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "OpenGL Water Demo", NULL, NULL);
	glfwShowWindow(window);
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
	//cam.position -= glm::vec3(0.5f,1.0f,0) * gameTime.GetDeltaTimeSecondsF();
	cam.light -= glm::vec3(0.1f,0.2f,0) * gameTime.GetDeltaTimeSecondsF();

	cam.UpdateRotation(window, 20.0f * gameTime.GetDeltaTimeSecondsF());

	//Camera Rotations
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	//cam.Rotation(-(xpos-mousePosLast.x), glm::vec3(0, 1, 0));
	//cam.Rotation((ypos-mousePosLast.y), glm::vec3(1, 0, 0));
	mousePosLast = glm::vec2(xpos, ypos);

	//Camera Translations
	glm::vec3 vel;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		vel += glm::vec3(-1, 0, 0);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		vel += glm::vec3(1, 0, 0);
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		vel += glm::vec3(0, 0, 1);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		vel += glm::vec3(0, 0, -1);
	}

	// On spacebar reload wave shader
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		shader = loadShader("vertex.glsl", waveShader);
	}


	vel *= gameTime.GetDeltaTimeSecondsF();

	cam.Translate(vel);
	

	glfwPollEvents();
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	plane->Draw(shader, cam);

	glfwSwapBuffers(window);
}
