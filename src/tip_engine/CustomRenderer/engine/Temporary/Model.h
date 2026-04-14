#pragma once
#ifndef __gl_h_
#include "glad/glad.h"
#endif
#include "imgui.h"
#include "stb_image/stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <stdio.h>
#include <array>

#define GL_SILENCE_DEPRECATION

#include <GLFW/glfw3.h>

// Include VivaEngine Shaders
#include "../Shaders/ShaderClass.h"
#include "../Shaders/VBO.h"
#include "../Shaders/VAO.h"
#include "../Shaders/EBO.h"
#include "../Shaders/FrameBuffer.h"
#include "../Shaders/Texture.h"

#include "../World/Camera.h"

#include "../Shaders/Material.h"

struct meshData {
	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;
};

class Model
{
public:
	Model(const char* VertexShader, const char* FragmentShader, const char* GeoShader, std::vector<GLfloat> verts, std::vector<GLuint> ind)
	{
		material = std::make_unique<Material>();
		material->SetShader(VertexShader, FragmentShader, GeoShader);
		vertices = verts;
		indices = ind;
		ModelVAO = std::make_unique<VAO>();
		ModelVBO = std::make_unique<VBO>(vertices);
		ModelEBO = std::make_unique<EBO>(indices);

		ModelVAO->Bind();
		ModelVBO->Bind();
		ModelEBO->Bind();

		ModelVAO->LinkAttrib(*ModelVBO.get(), 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
		ModelVAO->LinkAttrib(*ModelVBO.get(), 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
		ModelVAO->LinkAttrib(*ModelVBO.get(), 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
		ModelVAO->LinkAttrib(*ModelVBO.get(), 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

		ModelVAO->Unbind();
		ModelVBO->Unbind();
		ModelEBO->Unbind();
		vertexShader = VertexShader;
		fragmentShader = FragmentShader;
		geoShader = GeoShader;
	}

	void ReInitialize(const char* VertexShader, const char* FragmentShader, const char* GeoShader, std::vector<GLfloat> verts, std::vector<GLuint> ind) {
		Destroy();
		material = std::make_unique<Material>();
		material->SetShader(VertexShader, FragmentShader, GeoShader);
		vertices = verts;
		indices = ind;
		ModelVAO = std::make_unique<VAO>();
		ModelVBO = std::make_unique<VBO>(vertices);
		ModelEBO = std::make_unique<EBO>(indices);

		//Log("Shader Program Created From: " + std::string(VertexShader) + " and " + std::string(FragmentShader) + " and " + std::string(GeoShader), "Model");

		ModelVAO->Bind();
		ModelVBO->Bind();
		ModelEBO->Bind();

		ModelVAO->LinkAttrib(*ModelVBO.get(), 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
		ModelVAO->LinkAttrib(*ModelVBO.get(), 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
		ModelVAO->LinkAttrib(*ModelVBO.get(), 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
		ModelVAO->LinkAttrib(*ModelVBO.get(), 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

		ModelVAO->Unbind();
		ModelVBO->Unbind();
		ModelEBO->Unbind();
		vertexShader = VertexShader;
		fragmentShader = FragmentShader;
		geoShader = GeoShader;

	}

	void Draw(bool TriStrip = false, int Tris = 0,bool shadow = false, VinceWindow* window = nullptr, class Camera* Cam = nullptr) {
		if (shadow) {
			material->ShadowShaderProgram->Activate();
			ModelVAO->Bind();
			if (material->ShadowShaderProgram->ID != 0)
			{
				if (TriStrip) {
					glDrawArrays(GL_TRIANGLE_STRIP, Tris, static_cast<GLsizei>(vertices.size() / 11)); // Each vertex has 11 attributes
					return;
				}
				else {
					glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
				}

			}
		}
		else {
			glm::mat4 orthonalProjection = glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f, 0.1f, 50.0f);
			glm::mat4 directonalLightView = glm::lookAt(vec3(-20.0f, 20.0f, 20.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
			glm::mat4 lightProjection = orthonalProjection * directonalLightView;
			glUniformMatrix4fv(glGetUniformLocation(material->shaderProgram->ID, "lightProjection"), 1, GL_FALSE, value_ptr(lightProjection));
			if (material->ShadowTextureIndex != -1) {
				//Bind the shadow map texture and pass it to the shader
				glActiveTexture(GL_TEXTURE0 + material->ShadowTextureIndex);
				glBindTexture(GL_TEXTURE_2D, window->getFrameBuffer2()->texture_id);
				glUniform1f(glGetUniformLocation(material->shaderProgram->ID, "shadowMap"), 2);
			}

			material->shaderProgram->Activate();
			ModelVAO->Bind();
			if (material->shaderProgram->ID != 0)
			{
				if (TriStrip) {
					glDrawArrays(GL_TRIANGLE_STRIP, Tris, static_cast<GLsizei>(vertices.size() / 11)); // Each vertex has 11 attributes
					return;
				}
				else {
					glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
				}

			}
		}
	}

	void SetMaterialParameter(const char* name, glm::vec3 value) {
		material->shaderProgram->Activate();
		glUniform3f(glGetUniformLocation(material->shaderProgram->ID, name), value.x, value.y, value.z);
	}
	void SetMaterialParameter(const char* name, glm::vec4 value) {
		material->shaderProgram->Activate();
		glUniform4f(glGetUniformLocation(material->shaderProgram->ID, name), value.x, value.y, value.z, value.w);
	}
	void SetMaterialParameter(const char* name, float value) {
		material->shaderProgram->Activate();
		glUniform1f(glGetUniformLocation(material->shaderProgram->ID, name), value);
	}
	void SetMaterialParameter(const char* name, int value) {
		material->shaderProgram->Activate();
		glUniform1i(glGetUniformLocation(material->shaderProgram->ID, name), value);
	}
	void SetMaterialParameter(const char* name, Texture texture) {
		material->shaderProgram->Activate();
		texture.texUnit(*material->shaderProgram.get(), name, 0);
	}
	void SetMaterialParameter(const char* name, glm::mat4 value) {
		material->shaderProgram->Activate();
		glUniformMatrix4fv(glGetUniformLocation(material->shaderProgram->ID, name), 1, GL_FALSE, glm::value_ptr(value));
		material->ShadowShaderProgram->Activate();
		glUniformMatrix4fv(glGetUniformLocation(material->ShadowShaderProgram->ID, name), 1, GL_FALSE, glm::value_ptr(value));

	}

	void Destroy() {
		material->shaderProgram->Delete();
		material->ShadowShaderProgram->Delete();
		ModelVAO->Delete();
		ModelVBO->Delete();
		ModelEBO->Delete();
		material->shaderProgram = nullptr;
		material->ShadowShaderProgram = nullptr;
		ModelVAO = nullptr;
		ModelVBO = nullptr;
		ModelEBO = nullptr;
	}

	int GetNumVertices() const {
		return static_cast<int>(vertices.size() / 11); // Each vertex has 11 attributes
	}

	int GetNumIndices() const {
		return static_cast<int>(indices.size());
	}

	const char* GetVertexShader() const {
		return vertexShader;
	}
	const char* GetFragmentShader() const {
		return fragmentShader;
	}

	const char* GetGeoShader() const {
		return geoShader;
	}
	std::unique_ptr<Material> material;

private:
	// Vertices coordinates
	//     COORDINATES vec3     /        COLORS vec3         /    TexCoord vec2  /        NORMALS vec3      //
	std::vector <GLfloat> vertices;

	// Indices for vertices order
	std::vector <GLuint> indices;

	std::unique_ptr<VAO> ModelVAO;
	std::unique_ptr<VBO> ModelVBO;
	std::unique_ptr<EBO> ModelEBO;
	const char* vertexShader;
	const char* fragmentShader;
	const char* geoShader;
};

/*
// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS          /    TexCoord   /        NORMALS       //
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 5.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 5.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, -1.0f, 0.0f, // Bottom side

	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // Left Side
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // Left Side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,     -0.8f, 0.5f,  0.0f, // Left Side

	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f, -0.8f, // Non-facing side

	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.8f, 0.5f,  0.0f, // Right side
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.8f, 0.5f,  0.0f, // Right side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.8f, 0.5f,  0.0f, // Right side

	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f,  0.8f, // Facing side
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, 0.5f,  0.8f, // Facing side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f,  0.8f  // Facing side
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2, // Bottom side
	0, 2, 3, // Bottom side
	4, 6, 5, // Left side
	7, 9, 8, // Non-facing side
	10, 12, 11, // Right side
	13, 15, 14 // Facing side
};

GLfloat lightVertices[] =
{ //     COORDINATES     //
	-0.1f, -0.1f,  0.1f,
	-0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f,  0.1f,
	-0.1f,  0.1f,  0.1f,
	-0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f,  0.1f
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};
*/