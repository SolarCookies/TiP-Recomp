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

using namespace glm;

class Camera
{
public:
	vec3 Position;
	vec3 Orientation = vec3(0.0f, 0.0f, -1.0f);
	vec3 Up = vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 cameraMatrix = glm::mat4(1.0f);


	bool ShadowPerspective = false;
	bool TestShadowPerspective = false;
	//glm::mat4 orthonalProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.1f, 50.0f);
	//glm::mat4 directonalLightView = glm::lookAt(vec3(-20.0f, 20.0f, 20.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
	//glm::mat4 lightProjection = orthonalProjection * directonalLightView;

	float width;
	float height;

	// Yaw and pitch
	float yaw = -90.0f; // Facing -Z
	float pitch = 0.0f;

	float speed = 0.01f;
	float sensitivity = 0.2f;

	Camera(float width, float height, vec3 Position);

	virtual void updateMatrix(float FOV, float nearPlane, float farPlane);
	glm::mat4 getViewMatrix() const {
		return cameraMatrix;
	}
	virtual void Matrix(Shader& shader, const char* uniform);
	virtual void Inputs(GLFWwindow* window);
};