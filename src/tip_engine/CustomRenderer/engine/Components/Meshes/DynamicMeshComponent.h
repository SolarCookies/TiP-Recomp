#pragma once
#include "../Component.h"
#include "../../Temporary/Model.h"


// Forward declaration
class World;

struct DynamicVertex
{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 texCoords;
	glm::vec3 normal;
};



class DynamicMeshComponent : public Component
{
public:
	DynamicMeshComponent(std::string ShaderName)
	{
		this->name = "DynamicMesh";
		this->shaderName = ShaderName;
	}
	virtual ~DynamicMeshComponent() = default;

	void Construct() override;
	void BeginPlay() override;
	void Tick(float deltaTime, World* World) override;
	void Render(VinceWindow* window, class Camera* Cam) override;
	void Draw(bool shadow, VinceWindow* window, class Camera* Cam) override;

	void ReInitializeModel()
	{
		// Convert DynamicVertex to GLfloat vector
		std::vector<GLfloat> convertedVertices;
		for (const auto& vertex : Vertices)
		{
			convertedVertices.push_back(vertex.position.x);
			convertedVertices.push_back(vertex.position.y);
			convertedVertices.push_back(vertex.position.z);

			convertedVertices.push_back(vertex.color.r);
			convertedVertices.push_back(vertex.color.g);
			convertedVertices.push_back(vertex.color.b);

			convertedVertices.push_back(vertex.texCoords.x);
			convertedVertices.push_back(vertex.texCoords.y);

			convertedVertices.push_back(vertex.normal.x);
			convertedVertices.push_back(vertex.normal.y);
			convertedVertices.push_back(vertex.normal.z);
		}
		
		// Create a new Model instance with the converted vertices and triangles
		OBJ = std::make_unique<Model>(std::string("EngineAssets/Shaders/" + std::string(shaderName) + ".vert").c_str(),
			std::string("EngineAssets/Shaders/" + std::string(shaderName) + ".frag").c_str(),
			"",
			convertedVertices,
			Triangles
		);

		if (ColorTexture.ID == 0) {
			ColorTexture = Texture("EngineAssets/Textures/Error.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
		}
		OBJ->SetMaterialParameter("tex0", ColorTexture);

		if (NormalTexture.ID != 0) {
			OBJ->SetMaterialParameter("tex1", NormalTexture);
		}

		
	}

	void AddTriangle(GLuint v1, GLuint v2, GLuint v3, bool isDirty)
	{
		Triangles.push_back(v1);
		Triangles.push_back(v2);
		Triangles.push_back(v3);
		if(isDirty)
			ReInitializeModel(); //Only reinitialize if the model is dirty Aka this is the last triangle to add
	}

	void AddVertex(const DynamicVertex& vertex, bool isDirty)
	{
		Vertices.push_back(vertex);
		if(isDirty)
			ReInitializeModel(); //Only reinitialize if the model is dirty Aka this is the last vertex to add
	}

	void ConstructMesh(std::vector<DynamicVertex> vertices1, std::vector<GLuint> triangles1, bool isDirty = true)
	{
		if(vertices1.size() == 0 || triangles1.size() == 0) {
			//std::cout << "Error: Cannot construct mesh with zero vertices or triangles." << std::endl;
			//std::cout << "Vertices size: " << vertices1.size() << std::endl;
			//std::cout << "Triangles size: " << triangles1.size() << std::endl;
		}
		Vertices = vertices1;
		Triangles = triangles1;
		ReInitializeModel(); //Only reinitialize if the model is dirty Aka this is the last triangle to add
	}

	void SetMeshSilently(std::vector<DynamicVertex> Vertices, std::vector<GLuint> Triangles)
	{
		this->Vertices = Vertices;
		this->Triangles = Triangles;
	}

	void EndPlay() override {
		Vertices.clear();
		Triangles.clear();
		ReInitializeModel(); // Reset to error model
	}

	glm::vec3 Position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 Mat = glm::mat4(1.0f);

	bool isTriangleStrip = false;
	Texture ColorTexture;
	Texture NormalTexture;
protected:
	//Model* OBJ;
	std::unique_ptr<Model> OBJ; // Temporary model for reinitialization
	std::string shaderName;
	std::vector <DynamicVertex> Vertices;
	std::vector <GLuint> Triangles; // Aka Indices
	// Vertices coordinates
	std::vector<GLfloat> ErrorVertices =
	{ //     COORDINATES     /        COLORS          /    TexCoord   /        NORMALS       //
		0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f, 	 0.0f, 0.0f,      0.0f, 0.0f, 0.0f, // Bottom side
		0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,		 0.0f, 0.0f,      0.0f, 0.0f, 0.0f, // Bottom side
		0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,		 0.0f, 0.0f,      0.0f, 0.0f, 0.0f, // Bottom side
	};

	// Indices for vertices order
	std::vector<GLuint> ErrorIndices =
	{
		0, 1, 2, // Bottom side
	};
};