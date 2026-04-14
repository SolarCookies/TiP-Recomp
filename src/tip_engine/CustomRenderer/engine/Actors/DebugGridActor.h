#pragma once
#include "Actor.h"
#include "../Components/Component.h"
#include "../Components/Meshes/DynamicMeshComponent.h"
#include "tip_engine/Globals.h"

class DebugGrid : public Actor {
public:
    DebugGrid() {
        this->className = "DebugGrid";
    }

    void Construct() override {
        // Spawn a 10x10 grid of cubes on the XZ plane
        const int gridSize = 10;
        const float cubeSize = 10.0f;

        for (int gx = 0; gx < gridSize; gx++) {
            for (int gz = 0; gz < gridSize; gz++) {
                float r = static_cast<float>(gx) / (gridSize - 1);
                float g = 0.3f;
                float b = static_cast<float>(gz) / (gridSize - 1);

                auto cube = new DynamicMeshComponent("Color");
                cube->Position = glm::vec3(0.0f);
                float s = cubeSize;
                cube->ConstructMesh({
                    {{-s, -s,  s}, {r, g, b}, {0,0}, { 0, 0, 1}},
                    {{ s, -s,  s}, {r, g, b}, {1,0}, { 0, 0, 1}},
                    {{ s,  s,  s}, {r, g, b}, {1,1}, { 0, 0, 1}},
                    {{-s,  s,  s}, {r, g, b}, {0,1}, { 0, 0, 1}},
                    {{-s, -s, -s}, {r, g, b}, {1,0}, { 0, 0,-1}},
                    {{-s,  s, -s}, {r, g, b}, {1,1}, { 0, 0,-1}},
                    {{ s,  s, -s}, {r, g, b}, {0,1}, { 0, 0,-1}},
                    {{ s, -s, -s}, {r, g, b}, {0,0}, { 0, 0,-1}},
                }, {
                    0,1,2, 0,2,3,
                    4,5,6, 4,6,7,
                    4,0,3, 4,3,5,
                    7,6,2, 7,2,1,
                    3,2,6, 3,6,5,
                    4,7,1, 4,1,0,
                });
                this->AddComponent(cube);
            }
        }
        Actor::Construct();
    }

    void BeginPlay() override { Actor::BeginPlay(); }

    void Tick(float deltaTime, World* world) override {
        const int gridSize = 10;
        const float spacing = 50.0f;
        const float halfGrid = (gridSize - 1) * spacing * 0.5f;

        // Center the grid on the camera's XZ position, Y=0
        glm::vec3 camPos(0.0f);
        if (g_camera) {
            //camPos = g_camera->Position;
        }

        int idx = 0;
        for (int gx = 0; gx < gridSize; gx++) {
            for (int gz = 0; gz < gridSize; gz++) {
                if (idx >= static_cast<int>(components.size())) break;
                auto* mesh = dynamic_cast<DynamicMeshComponent*>(components[idx].get());
                if (mesh) {
                    float x = camPos.x + gx * spacing - halfGrid;
                    float z = camPos.z + gz * spacing - halfGrid;
                    mesh->Position = glm::vec3(x, 0.0f, z);
                    mesh->SetParameter("unlit", 1);
                }
                idx++;
            }
        }
        Actor::Tick(deltaTime, world);
    }

    void Render(VinceWindow* Window, class Camera* Cam) override {
        //glDisable(GL_CULL_FACE);
        //return;
        // Set unlit right before draw so it's guaranteed active
        for (auto& comp : components) {
            auto* mesh = dynamic_cast<DynamicMeshComponent*>(comp.get());
            if (mesh) {
                mesh->SetParameter("unlit", 1);
            }
        }
        Actor::Render(Window, Cam);
    }
    void EndPlay() override { Actor::EndPlay(); }
};
