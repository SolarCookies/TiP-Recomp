#pragma once
#ifndef __gl_h_
#include "glad/glad.h"
#endif

#include <gli/gli.hpp>
#include <stb_image/stb_image.h>
#include <vector>

#include "ShaderClass.h"

class Texture
{
public:
	GLuint ID;
	GLenum type;
	bool IsValid = false;
	std::string NameOfTexture; // used for lookups
	Texture() = default;
	Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
	Texture(const char* DDSimage);
	Texture(const std::vector<unsigned char>& DDSdata);
	Texture(std::vector<unsigned char>& Rawdata, GLenum pixelType, int widthImg, int heightImg);

	//Compressed texture (GL_COMPRESSED_RGBA_S3TC_DXT3_EXT)
	Texture(std::vector<unsigned char>& Rawdata, int widthImg, int heightImg);

	// Assigns a texture unit to a texture
	void texUnit(Shader& shader, const char* uniform, GLuint unit);
	// Binds a texture
	void Bind();
	// Unbinds a texture
	void Unbind();
	// Deletes a texture
	void Delete();
};