#include "Actor.h"
#include "../Components/Component.h"
#include "../Components/Meshes/DynamicMeshComponent.h"

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
            {{-100.0f, -100.0f,  100.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}, {0.0f, 0.0f, -1.0f}},  // 0
            {{ 100.0f, -100.0f,  100.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f, -1.0f}},  // 1
            {{ 100.0f,  100.0f,  100.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}, {0.0f, 0.0f, -1.0f}},  // 2
            {{-100.0f,  100.0f,  100.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}, {0.0f, 0.0f, -1.0f}},  // 3
            // Back face (z = -100)
            {{-100.0f, -100.0f, -100.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}},   // 4
            {{-100.0f,  100.0f, -100.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}},   // 5
            {{ 100.0f,  100.0f, -100.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}},   // 6
            {{ 100.0f, -100.0f, -100.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}},   // 7
        }, {
            // Front face
            0, 2, 1,  0, 3, 2,
            // Back face
            4, 6, 5,  4, 7, 6,
            // Left face
            4, 3, 0,  4, 5, 3,
            // Right face
            1, 6, 7,  1, 2, 6,
            // Top face
            3, 6, 2,  3, 5, 6,
            // Bottom face
            4, 1, 7,  4, 0, 1,
        });
        this->AddComponent(modelComp);
        Actor::Construct();
    }

    void BeginPlay() override {
        Actor::BeginPlay();
    }

    void Tick(float deltaTime, World* world) override {
        Actor::Tick(deltaTime, world);
    }

    void Render(VinceWindow* Window, class Camera* Cam) override {
        // Skybox must render at far plane with LEQUAL depth, no depth write
        glDepthFunc(GL_LEQUAL);
        glDepthMask(GL_FALSE);
        Actor::Render(Window, Cam);
        glDepthMask(GL_TRUE);
        glDepthFunc(GL_LESS);
    }
    void EndPlay() override {
        Actor::EndPlay();
    }
};