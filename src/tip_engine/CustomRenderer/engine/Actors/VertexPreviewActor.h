#pragma once
#include "Actor.h"
#include "../Components/Meshes/DynamicMeshComponent.h"
#include "tip_engine/Globals.h"
#include "tip_engine/Log.h"
#include <mutex>
#include <vector>
#include <algorithm>
#include <glm/glm.hpp>

// Global vertex buffer for the hook to push positions into each frame.
// The actor consumes and clears this every Tick.
struct VertexPreviewBuffer {
    std::mutex mutex;
    std::vector<glm::vec3> positions;
    std::vector<uint32_t> indices; // triangle indices (when available)
    bool enabled = false;
    static constexpr size_t MAX_BUFFERED_VERTS = 50000;
    static constexpr size_t MAX_BUFFERED_INDICES = 150000;

    // Pending draw state from BeginIndexedVertices (single-threaded, no lock needed)
    struct PendingDraw {
        uint32_t vertBufGuestPtr = 0;
        uint32_t idxBufGuestPtr = 0;
        uint32_t numVertices = 0;
        uint32_t stride = 0;
        uint32_t indexFormat = 0;
        bool valid = false;
    } pending;

    void Clear() {
        std::lock_guard<std::mutex> lock(mutex);
        positions.clear();
        indices.clear();
    }

    void Push(const glm::vec3& pos) {
        std::lock_guard<std::mutex> lock(mutex);
        if (positions.size() >= MAX_BUFFERED_VERTS) return;
        positions.push_back(pos);
    }

    void PushIndexedMesh(const std::vector<glm::vec3>& verts, const std::vector<uint32_t>& triIndices) {
        std::lock_guard<std::mutex> lock(mutex);
        if (positions.size() + verts.size() > MAX_BUFFERED_VERTS) return;
        if (indices.size() + triIndices.size() > MAX_BUFFERED_INDICES) return;
        uint32_t baseVert = static_cast<uint32_t>(positions.size());
        for (const auto& v : verts) positions.push_back(v);
        for (const auto& i : triIndices) indices.push_back(baseVert + i);
    }

    struct ConsumedData {
        std::vector<glm::vec3> positions;
        std::vector<uint32_t> indices;
    };

    // Swap out the current buffer to avoid holding the lock during rendering
    ConsumedData Consume() {
        std::lock_guard<std::mutex> lock(mutex);
        ConsumedData out;
        out.positions.swap(positions);
        out.indices.swap(indices);
        return out;
    }
};

inline VertexPreviewBuffer g_VertexPreview;

class VertexPreviewActor : public Actor {
public:
    VertexPreviewActor() {
        this->className = "VertexPreview";
    }

    // Simple hash to generate a pseudo-random color from an index
    static glm::vec3 HashColor(uint32_t idx) {
        uint32_t h = idx * 2654435761u; // Knuth multiplicative hash
        float r = ((h >> 0)  & 0xFF) / 255.0f;
        float g = ((h >> 8)  & 0xFF) / 255.0f;
        float b = ((h >> 16) & 0xFF) / 255.0f;
        // Boost brightness so colors are visible
        float maxC = std::max({r, g, b, 0.3f});
        return glm::vec3(r / maxC, g / maxC, b / maxC) * 0.8f + 0.2f;
    }

    void Construct() override {
        auto meshComp = new DynamicMeshComponent("Color");
        meshComp->ConstructMesh({
            {{0,0,0}, {1,1,1}, {0,0}, {0,1,0}},
            {{0,0,0}, {1,1,1}, {0,0}, {0,1,0}},
            {{0,0,0}, {1,1,1}, {0,0}, {0,1,0}},
        }, {0, 1, 2});
        this->AddComponent(meshComp);
        Actor::Construct();
    }

    void Tick(float deltaTime, World* world) override {
        if (!g_VertexPreview.enabled) {
            Actor::Tick(deltaTime, world);
            return;
        }

        auto data = g_VertexPreview.Consume();

        if (data.positions.empty()) {
            Actor::Tick(deltaTime, world);
            return;
        }

        std::vector<DynamicVertex> meshVerts;
        std::vector<GLuint> meshIndices;

        if (!data.indices.empty()) {
            // Indexed triangle mode - render actual faces with random per-vertex colors
            meshVerts.reserve(data.positions.size());
            for (size_t i = 0; i < data.positions.size(); i++) {
                meshVerts.push_back({data.positions[i], HashColor(static_cast<uint32_t>(i)), {0, 0}, {0, 1, 0}});
            }
            meshIndices.reserve(data.indices.size());
            for (auto idx : data.indices) {
                meshIndices.push_back(static_cast<GLuint>(idx));
            }
        } else {
            // Point mode fallback - build cubes from positions
            float pointSize = 0.75f;
            size_t maxVerts = std::min(data.positions.size(), size_t(2000));
            meshVerts.reserve(maxVerts * 8);
            meshIndices.reserve(maxVerts * 36);

            for (size_t i = 0; i < maxVerts; i++) {
                const glm::vec3& p = data.positions[i];
                float half = pointSize * 0.5f;
                glm::vec3 color = HashColor(static_cast<uint32_t>(i));

                GLuint base = static_cast<GLuint>(meshVerts.size());

                glm::vec3 corners[8] = {
                    p + glm::vec3(-half, -half, -half),
                    p + glm::vec3( half, -half, -half),
                    p + glm::vec3( half,  half, -half),
                    p + glm::vec3(-half,  half, -half),
                    p + glm::vec3(-half, -half,  half),
                    p + glm::vec3( half, -half,  half),
                    p + glm::vec3( half,  half,  half),
                    p + glm::vec3(-half,  half,  half),
                };

                for (int c = 0; c < 8; c++) {
                    meshVerts.push_back({corners[c], color, {0, 0}, {0, 1, 0}});
                }

                GLuint cubeIdx[] = {
                    0,1,2, 2,3,0,
                    4,5,6, 6,7,4,
                    0,1,5, 5,4,0,
                    3,2,6, 6,7,3,
                    0,3,7, 7,4,0,
                    1,2,6, 6,5,1,
                };
                for (int j = 0; j < 36; j++) {
                    meshIndices.push_back(base + cubeIdx[j]);
                }
            }
        }

        auto* meshComp = dynamic_cast<DynamicMeshComponent*>(GetComponentByName("DynamicMesh"));
        if (meshComp && !meshVerts.empty()) {
            meshComp->ConstructMesh(meshVerts, meshIndices);
            meshComp->SetParameter("unlit", 1);
        }

        Actor::Tick(deltaTime, world);
    }

    void Render(VinceWindow* Window, class Camera* Cam) override {
        if (!g_VertexPreview.enabled) return;
        glDisable(GL_DEPTH_TEST);
        Actor::Render(Window, Cam);
        glEnable(GL_DEPTH_TEST);
    }

    void EndPlay() override {
        Actor::EndPlay();
    }
};
