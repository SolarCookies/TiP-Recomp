#pragma once
#pragma once
#include "glad/glad.h"
#include <vector>

class EBO {
public:
	GLuint ID;
	EBO(GLuint* indices, GLsizeiptr size);
	EBO(const std::vector<GLuint>& indices);
	void Bind();
	void Unbind();
	void Delete();
};
