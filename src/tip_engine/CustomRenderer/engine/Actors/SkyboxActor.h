#include "Actor.h"
#include "../Components/Component.h"
#include "../Components/Meshes/DynamicMeshComponent.h"
#include "tip_engine/Globals.h"

class Skybox : public Actor {
public:
    Skybox() {
        this->className = "Skybox";
    }

    void Construct() override {
        //add a model component with the skybox shader and a cube mesh
        //Basic cube mesh with inverted normals for skybox
        auto modelComp = new DynamicMeshComponent("Sky");
        modelComp->ConstructMesh({
            // Front face (z = 100)
            {{-1.0f, -1.0f,  1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}, {0.0f, 0.0f, -1.0f}},  // 0
            {{ 1.0f, -1.0f,  1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f, -1.0f}},  // 1
            {{ 1.0f,  1.0f,  1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}, {0.0f, 0.0f, -1.0f}},  // 2
            {{-1.0f,  1.0f,  1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}, {0.0f, 0.0f, -1.0f}},  // 3
            // Back face (z = -100)
            {{-1.0f, -1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}},   // 4
            {{-1.0f,  1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}},   // 5
            {{ 1.0f,  1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}},   // 6
            {{ 1.0f, -1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}},   // 7
        }, {
            // Front face (CCW when viewed from outside, +Z)
            0, 1, 2,  0, 2, 3,
            // Back face (CCW when viewed from outside, -Z)
            4, 5, 6,  4, 6, 7,
            // Left face (CCW when viewed from outside, -X)
            4, 0, 3,  4, 3, 5,
            // Right face (CCW when viewed from outside, +X)
            1, 7, 6,  1, 6, 2,
            // Top face (CCW when viewed from outside, +Y)
            3, 2, 6,  3, 6, 5,
            // Bottom face (CCW when viewed from outside, -Y)
            4, 7, 1,  4, 1, 0,
        });
        this->AddComponent(modelComp);
        Actor::Construct();
    }

    void BeginPlay() override {
        Actor::BeginPlay();
    }

    void Tick(float deltaTime, World* world) override {
        // Move skybox to follow camera position
        if (g_camera) {
        //    this->SetWorldPosition(g_camera->Position);
        }
        this->SetWorldPosition(glm::vec3(0.0f)); // Keep skybox centered at origin for now
        this->SetWorldScale(glm::vec3(10.0f));  // Scale up so it's visible
        Actor::Tick(deltaTime, world);
    }

    void Render(VinceWindow* Window, class Camera* Cam) override {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        Actor::Render(Window, Cam);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    void EndPlay() override {
        Actor::EndPlay();
    }
};