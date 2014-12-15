#include "Shader.h"

#include <string>
#include <fstream>
#include <iostream>

std::string* loadFile(char* fileLocation)
{
	std::string* file = new std::string();
	std::ifstream fs(fileLocation, std::ios::in);

	std::string line = "";

	if(!fs.is_open())
	{
		exit(EXIT_FAILURE);
	}

	while(!fs.eof())
	{
		std::getline(fs, line);
		file->append(line + "\n");
	}
	fs.close();
	return file;
}

GLuint loadShader(char* vertexLocation, char* fragmentLocation)
{
	// Load Vertex Shader
	std::string* file = loadFile(vertexLocation);
	const char* vertexChars = file->c_str();
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexChars, NULL);
	glCompileShader(vertexShader);
	delete file;

	GLint status;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
	std::cout << status << " Vertex Shader\n";


	// Load Fragment Shader
	file = loadFile(fragmentLocation);
	const char* fragmentChars = file->c_str();
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentChars, NULL);
	glCompileShader(fragmentShader);
	delete file;

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
	std::cout << status << " Fragment Shader\n";

	// Attach and Link Shaders
	GLuint shaderProg = glCreateProgram();
	glAttachShader(shaderProg, vertexShader);
	glAttachShader(shaderProg, fragmentShader);
	glLinkProgram(shaderProg);

	glGetShaderiv(fragmentShader, GL_LINK_STATUS, &status);
	std::cout << status << " Shader Linking\n";

	return shaderProg;
}
