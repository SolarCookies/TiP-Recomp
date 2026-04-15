#pragma once

#ifndef __gl_h_
#include "glad/glad.h"
#endif
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

class Shader
{
public:
	// Reference ID of the Shader Program
	GLuint ID;
	// Constructor that build the Shader Program from 2 different shaders
	Shader(const char* vertexFile, const char* fragmentFile, const char* geomatryFile = "");

	// Activates the Shader Program
	void Activate();
	// Deletes the Shader Program
	void Delete();
private:
	// Checks if the different Shaders have compiled properly
	void compileErrors(unsigned int shader, const char* type);
	std::string get_file_contents(const char* filename);
};
