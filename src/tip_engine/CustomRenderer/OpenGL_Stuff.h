#pragma once
#ifndef __gl_h_
#include "glad/glad.h"
#endif
#include "stb_image/stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <rex/logging.h>

#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

namespace retip::log {
    inline const rex::LogCategoryId Input = rex::RegisterLogCategory("retip_GL");
}



#define RETIP_TRACE(...) REXLOG_CAT_TRACE(::retip::log::Input, __VA_ARGS__)
#define RETIP_DEBUG(...) REXLOG_CAT_DEBUG(::retip::log::Input, __VA_ARGS__)
#define RETIP_INFO(...)  REXLOG_CAT_INFO(::retip::log::Input, __VA_ARGS__)
#define RETIP_WARN(...)  REXLOG_CAT_WARN(::retip::log::Input, __VA_ARGS__)
#define RETIP_ERROR(...) REXLOG_CAT_ERROR(::retip::log::Input, __VA_ARGS__)

// Function to check for OpenGL errors
inline static void checkOpenGLError(const char* stmt, const char* fname, int line)
{
	GLenum err = glGetError();
	while (err != GL_NO_ERROR)
	{
		const char* error;
		switch (err)
		{
		case GL_INVALID_OPERATION:      error = "INVALID_OPERATION";      break;
		case GL_INVALID_ENUM:           error = "INVALID_ENUM";           break;
		case GL_INVALID_VALUE:          error = "INVALID_VALUE";          break;
		case GL_OUT_OF_MEMORY:          error = "OUT_OF_MEMORY";          break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:  error = "INVALID_FRAMEBUFFER_OPERATION";  break;
		default:                        error = "UNKNOWN_ERROR";          break;
		}
		std::cerr << "OpenGL error [" << error << "] (" << err << "): " << stmt << " in " << fname << " at line " << line << std::endl;
		err = glGetError();
	}
}

#define CHECK_GL_ERROR(stmt) do { \
    stmt; \
    checkOpenGLError(#stmt, __FILE__, __LINE__); \
} while (0)

inline static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "GLFW Error %d: %s\n", error, description);
    RETIP_ERROR("GLFW Error {}: {}", error, description);
}