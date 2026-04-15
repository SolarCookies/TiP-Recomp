#pragma once

#ifndef __gl_h_
#include "glad/glad.h"
#endif
#include <iostream>

class FrameBuffer
{
public:
	FrameBuffer();
	~FrameBuffer();

	GLuint FBO;
	GLuint RBO;
	GLuint texture_id;
	int FrameBufferID;
	const GLint WIDTH = 800;
	const GLint HEIGHT = 600;

	void create_framebuffer(int ID);
	void rescale_framebuffer(float width, float height);
	void Bind();
	void Unbind();
	void Delete();
};