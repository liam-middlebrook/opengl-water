#include "Shader.h"

#include <string>
#include <fstream>

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

	// Load Fragment Shader
	file = loadFile(fragmentLocation);
	const char* fragmentChars = file->c_str();
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentChars, NULL);
	glCompileShader(fragmentShader);
	delete file;

	// Attach and Link Shaders
	GLuint shaderProg = glCreateProgram();
	glAttachShader(shaderProg, vertexShader);
	glAttachShader(shaderProg, fragmentShader);
	glLinkProgram(shaderProg);

	return shaderProg;
}