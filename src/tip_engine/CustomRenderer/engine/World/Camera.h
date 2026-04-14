#pragma once
#ifndef __gl_h_
#include "glad/glad.h"
#endif
#include "GLFW/glfw3.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "../Shaders/ShaderClass.h"
#include "CameraClass.h"

using namespace glm;

class SpectateCamera : public Camera
{
public:
    SpectateCamera(float width, float height, vec3 Position);

    void updateMatrix(float FOV, float nearPlane, float farPlane) override;
    void Matrix(Shader& shader, const char* uniform) override;
    void Inputs(GLFWwindow* window) override;
};