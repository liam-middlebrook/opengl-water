#include <GL/glew.h>
#include <GLFW/glfw3.h>

#pragma region Variables

GLFWwindow* window;

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
	glfwPollEvents();
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);
}