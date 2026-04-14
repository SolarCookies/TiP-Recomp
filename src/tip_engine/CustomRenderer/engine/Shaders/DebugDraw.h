#pragma once
#ifndef __gl_h_
#include "glad/glad.h"
#endif
#include "stb_image/stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GLFW/glfw3.h>
#include "../World/Camera.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

struct ThreeDeMesh {
    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;
};


namespace Debug {

    inline static ThreeDeMesh CreateCubeMesh(glm::vec3 Position, glm::vec4 color, float thickness) {
        // Half size for centering the cube
        float half = thickness * 0.5f * 0.01f;
        // 8 corners of the cube
        glm::vec3 p0 = Position + glm::vec3(-half, -half, -half);
        glm::vec3 p1 = Position + glm::vec3(half, -half, -half);
        glm::vec3 p2 = Position + glm::vec3(half, half, -half);
        glm::vec3 p3 = Position + glm::vec3(-half, half, -half);
        glm::vec3 p4 = Position + glm::vec3(-half, -half, half);
        glm::vec3 p5 = Position + glm::vec3(half, -half, half);
        glm::vec3 p6 = Position + glm::vec3(half, half, half);
        glm::vec3 p7 = Position + glm::vec3(-half, half, half);
        // Each vertex: position (3), color (3), texcoord (2), normal (3)
        std::vector<GLfloat> vertices = {
            // positions         // color           // texcoord // normal
            p0.x, p0.y, p0.z,   color.r, color.g, color.b, 0.0f, 0.0f,  -1.0f, -1.0f, -1.0f,
            p1.x, p1.y, p1.z,   color.r, color.g, color.b, 1.0f, 0.0f,   1.0f, -1.0f, -1.0f,
            p2.x, p2.y, p2.z,   color.r, color.g, color.b, 1.0f, 1.0f,   1.0f,  1.0f, -1.0f,
			p3.x, p3.y, p3.z,   color.r, color.g, color.b, 0.0f, 1.0f,  -1.0f,  1.0f, -1.0f,
            p4.x, p4.y, p4.z,   color.r, color.g, color.b, 0.0f, 0.0f,  -1.0f, -1.0f,  1.0f,
            p5.x, p5.y, p5.z,   color.r, color.g, color.b, 1.0f, 0.0f,   1.0f, -1.0f,  1.0f,
            p6.x, p6.y, p6.z,   color.r, color.g, color.b, 1.0f, 1.0f,   1.0f,  1.0f,  1.0f,
            p7.x, p7.y, p7.z,   color.r, color.g, color.b, 0.0f, 1.0f,  -1.0f,  1.0f,  1.0f,
        };
        // Indices for 12 triangles (2 per face)
        std::vector<GLuint> indices = {
            // Bottom
            0, 1, 2, 2, 3, 0,
            // Top
            4, 5, 6, 6, 7, 4,
            // Front
            0, 1, 5, 5, 4, 0,
            // Back
            3, 2, 6, 6, 7, 3,
            // Left
            0, 3, 7 ,7 ,4 ,0,
            // Right
            1 ,2 ,6 ,6 ,5 ,1
        };
        return { vertices , indices };
	}

    inline static ThreeDeMesh AppendMesh(const ThreeDeMesh& mesh1, const ThreeDeMesh& mesh2) {
        ThreeDeMesh result;
        result.vertices = mesh1.vertices;
        result.indices = mesh1.indices;
        // Offset indices of the second mesh
        size_t offset = result.vertices.size() / 11; // Each vertex has 11 floats
        for (size_t i = 0; i < mesh2.indices.size(); ++i) {
            result.indices.push_back(mesh2.indices[i] + offset);
        }
        result.vertices.insert(result.vertices.end(), mesh2.vertices.begin(), mesh2.vertices.end());
        return result;
	}


    inline static void drawLine(const glm::vec3& start, const glm::vec3& end, const glm::vec4& color, const float thickness, Camera& cam, VinceWindow& window) {
		// Compute quad corners for the line
		glm::vec3 camDir = glm::normalize(cam.Orientation);
		glm::vec3 dir = glm::normalize(end - start);
		glm::vec3 perp = glm::normalize(glm::cross(dir, camDir));
		if (glm::length(perp) < 0.001f) {
			perp = glm::normalize(glm::cross(dir, glm::vec3(0, 1, 0)));
		}
		float halfThickness = thickness * 0.5f * 0.01f;

		glm::vec3 v0 = start + perp * halfThickness;
		glm::vec3 v1 = start - perp * halfThickness;
		glm::vec3 v2 = end - perp * halfThickness;
		glm::vec3 v3 = end + perp * halfThickness;

		// Each vertex: position (3), color (3), texcoord (2), normal (3) = 11 floats
		std::vector<GLfloat> vertices = {
			// v0
			v0.x, v0.y, v0.z,  color.r, color.g, color.b,  0.0f, 0.0f,  1.0f, 0.0f, 1.0f,
			// v1
			v1.x, v1.y, v1.z,  color.r, color.g, color.b,  0.0f, 1.0f,  1.0f, 0.0f, 1.0f,
			// v2
			v2.x, v2.y, v2.z,  color.r, color.g, color.b,  1.0f, 1.0f,  1.0f, 0.0f, 1.0f,
			// v3
			v3.x, v3.y, v3.z,  color.r, color.g, color.b,  1.0f, 0.0f,  1.0f, 0.0f, 1.0f
		};
		std::vector<GLuint> indices = {
			0, 1, 2,
			2, 3, 0
		};

		// Create a temporary Model for the line quad
		Model lineModel(
			"Assets/Shaders/line.vert",
			"Assets/Shaders/line.frag",
            "",
			vertices,
			indices
		);
		glm::vec4 colorr = glm::vec4(color.r, color.g, color.b, color.a);
		lineModel.SetMaterialParameter("LineColor", colorr);

		//update the model matrix with the current transform
		glm::mat4 Mat = glm::mat4(1.0f);
		lineModel.SetMaterialParameter("model", Mat);

		lineModel.SetMaterialParameter("cameraPos", cam.Position);
		cam.Matrix(*lineModel.material->shaderProgram.get(), "camMatrix");


		glDisable(GL_DEPTH_TEST);
		lineModel.Draw();
		glEnable(GL_DEPTH_TEST);

		lineModel.Destroy(); // Clean up GPU resources
	}

    inline static void Draw3DPoint(const glm::vec3& Position, const glm::vec4& color, const float thickness, Camera& cam, VinceWindow& window, bool infront = true) {
        // Half size for centering the cube
        float half = thickness * 0.5f * 0.01f;

        // 8 corners of the cube
        glm::vec3 p0 = Position + glm::vec3(-half, -half, -half);
        glm::vec3 p1 = Position + glm::vec3(half, -half, -half);
        glm::vec3 p2 = Position + glm::vec3(half, half, -half);
        glm::vec3 p3 = Position + glm::vec3(-half, half, -half);
        glm::vec3 p4 = Position + glm::vec3(-half, -half, half);
        glm::vec3 p5 = Position + glm::vec3(half, -half, half);
        glm::vec3 p6 = Position + glm::vec3(half, half, half);
        glm::vec3 p7 = Position + glm::vec3(-half, half, half);

        // Each vertex: position (3), color (3), texcoord (2), normal (3)
        std::vector<GLfloat> vertices = {
            // positions         // color           // texcoord // normal
            p0.x, p0.y, p0.z,   color.r, color.g, color.b, 0.0f, 0.0f,  -1.0f, -1.0f, -1.0f,
            p1.x, p1.y, p1.z,   color.r, color.g, color.b, 1.0f, 0.0f,   1.0f, -1.0f, -1.0f,
            p2.x, p2.y, p2.z,   color.r, color.g, color.b, 1.0f, 1.0f,   1.0f,  1.0f, -1.0f,
            p3.x, p3.y, p3.z,   color.r, color.g, color.b, 0.0f, 1.0f,  -1.0f,  1.0f, -1.0f,
            p4.x, p4.y, p4.z,   color.r, color.g, color.b, 0.0f, 0.0f,  -1.0f, -1.0f,  1.0f,
            p5.x, p5.y, p5.z,   color.r, color.g, color.b, 1.0f, 0.0f,   1.0f, -1.0f,  1.0f,
            p6.x, p6.y, p6.z,   color.r, color.g, color.b, 1.0f, 1.0f,   1.0f,  1.0f,  1.0f,
            p7.x, p7.y, p7.z,   color.r, color.g, color.b, 0.0f, 1.0f,  -1.0f,  1.0f,  1.0f,
        };

        // Indices for 12 triangles (2 per face)
        std::vector<GLuint> indices = {
            // Bottom
            0, 1, 2,  2, 3, 0,
            // Top
            4, 5, 6,  6, 7, 4,
            // Front
            0, 1, 5,  5, 4, 0,
            // Back
            3, 2, 6,  6, 7, 3,
            // Left
            0, 3, 7,  7, 4, 0,
            // Right
            1, 2, 6,  6, 5, 1
        };

        Model boxModel(
            "Assets/Shaders/line.vert",
            "Assets/Shaders/line.frag",
            "",
            vertices,
            indices
        );

        glm::vec4 colorr = glm::vec4(color.r, color.g, color.b, color.a);
        boxModel.SetMaterialParameter("LineColor", colorr);

        glm::mat4 Mat = glm::mat4(1.0f);
        boxModel.SetMaterialParameter("model", Mat);

        boxModel.SetMaterialParameter("cameraPos", cam.Position);
        cam.Matrix(*boxModel.material->shaderProgram.get(), "camMatrix");
        if (infront) {
            glDisable(GL_DEPTH_TEST);
        }
        boxModel.Draw();
        if (infront) {
            glEnable(GL_DEPTH_TEST);
		}

        boxModel.Destroy();
    }

    //Renders all 3d points in one mesh
    inline static void Draw3DPoints(const std::vector<glm::vec3>& Positions, const glm::vec4& color, const float thickness, Camera& cam, VinceWindow& window, bool infront = false) {
		ThreeDeMesh FinalMesh;
        ThreeDeMesh mesh1;
        ThreeDeMesh mesh2;
        for (glm::vec3 pos : Positions) {
			mesh1 = CreateCubeMesh(pos, color, thickness);
            mesh2 = AppendMesh(FinalMesh, mesh1);
			FinalMesh = mesh2;
		}

        Model boxModel(
            "Assets/Shaders/line.vert",
            "Assets/Shaders/line.frag",
            "",
            FinalMesh.vertices,
            FinalMesh.indices
        );

        boxModel.SetMaterialParameter("LineColor", color);

        glm::mat4 Mat = glm::mat4(1.0f);
        boxModel.SetMaterialParameter("model", Mat);

        boxModel.SetMaterialParameter("cameraPos", cam.Position);
        cam.Matrix(*boxModel.material->shaderProgram.get(), "camMatrix");
        if (infront) {
            glDisable(GL_DEPTH_TEST);
        }
        boxModel.Draw();
        if (infront) {
            glEnable(GL_DEPTH_TEST);
        }

        boxModel.Destroy();

    }

    inline static void DrawPoint(const glm::vec3& Position, const glm::vec4& color, const float thickness, Camera& cam, VinceWindow& window) {
        // 1. Project the 3D point to clip space
        glm::mat4 view = cam.getViewMatrix();
        glm::mat4 proj = glm::perspective(glm::radians(45.0f), window.width / (float)window.height, 0.1f, 10000.0f);
        glm::vec4 clipSpace = proj * view * glm::vec4(Position, 1.0f);

        // 2. Perspective divide to get NDC
        glm::vec3 ndc = glm::vec3(clipSpace) / clipSpace.w;

        // 3. Convert NDC to screen space (pixels)
        float x_screen = ((ndc.x + 1.0f) * 0.5f) * window.width;
        float y_screen = ((1.0f - ndc.y) * 0.5f) * window.height; // OpenGL: y=0 is bottom

        // 4. Build a square in screen space (pixels)
        float half = thickness * 0.5f;
        float left = x_screen - half;
        float right = x_screen + half;
        float top = y_screen - half;
        float bottom = y_screen + half;

        // 5. Convert screen space back to NDC
        auto screenToNDC = [&](float x, float y) {
            float ndc_x = (x / window.width) * 2.0f - 1.0f;
            float ndc_y = 1.0f - (y / window.height) * 2.0f;
            return glm::vec3(ndc_x, ndc_y, ndc.z);
            };

        glm::vec3 ndc0 = screenToNDC(left, top);
        glm::vec3 ndc1 = screenToNDC(right, top);
        glm::vec3 ndc2 = screenToNDC(right, bottom);
        glm::vec3 ndc3 = screenToNDC(left, bottom);

        // 6. Unproject NDC back to world space at the original depth
        glm::mat4 invVP = glm::inverse(proj * view);
        auto ndcToWorld = [&](const glm::vec3& ndc) {
            glm::vec4 world = invVP * glm::vec4(ndc, 1.0f);
            return glm::vec3(world) / world.w;
            };

        glm::vec3 w0 = ndcToWorld(ndc0);
        glm::vec3 w1 = ndcToWorld(ndc1);
        glm::vec3 w2 = ndcToWorld(ndc2);
        glm::vec3 w3 = ndcToWorld(ndc3);

        // 7. Build Model vertices (11 floats per vertex)
        std::vector<GLfloat> vertices = {
            w0.x, w0.y, w0.z, color.r, color.g, color.b, 0.0f, 0.0f, 0,0,1,
            w1.x, w1.y, w1.z, color.r, color.g, color.b, 1.0f, 0.0f, 0,0,1,
            w2.x, w2.y, w2.z, color.r, color.g, color.b, 1.0f, 1.0f, 0,0,1,
            w3.x, w3.y, w3.z, color.r, color.g, color.b, 0.0f, 1.0f, 0,0,1,
        };
        std::vector<GLuint> indices = { 0, 1, 2, 2, 3, 0 };

        Model squareModel(
            "Assets/Shaders/line.vert",
            "Assets/Shaders/line.frag",
            "",
            vertices,
            indices
        );

        squareModel.SetMaterialParameter("LineColor", color);
        glm::mat4 Mat = glm::mat4(1.0f);
        squareModel.SetMaterialParameter("model", Mat);
        squareModel.SetMaterialParameter("cameraPos", cam.Position);
        cam.Matrix(*squareModel.material->shaderProgram.get(), "camMatrix");

        glDisable(GL_DEPTH_TEST);
        squareModel.Draw();
        glEnable(GL_DEPTH_TEST);

        squareModel.Destroy();
    }

}