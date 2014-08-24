#include <GLFW/glfw3.h>
#include <iostream>

int main()
{

	if (!glfwInit())
	{
		std::cout << "GLFW Failed to Initialize!" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (glfwJoystickPresent(0))
	{
		std::cout << glfwGetJoystickName(0) << std::endl;
		
		while (true)
		{
			const float* joyVals;
			int count;
			joyVals = glfwGetJoystickAxes(0, &count);

			for (int i = 0; i < count; i++)
			{
				std::cout << "Axis " << i << " : " << joyVals[i] << std::endl;
			}
		}
	}
	else
	{
		char a;
		std::cin >> a;
	}
}
