#pragma once

#include <string>
#include "Utils/ini.h"
#include <filesystem>
#include <functional>
#include "Shaders/Texture.h"
#include "half/half.hpp"
#include "World/Camera.h"
#include "tip_engine/globals.h"

inline float window_width1 = 800;
inline float window_height1 = 600;

inline bool ExtractAll = false; // True when extracting all files from a package, this is to prevent unnecessary gpu loading as extracting all files does not have a view to display them anyway

inline Texture* PreviewTexture = nullptr; //If Valid, texture is previewed in viewport

inline bool PendingChange = false; //If Valid, texture is previewed in viewport


inline std::function<void(const std::vector<unsigned char>&)> GlobalSaveFunction = nullptr;

struct Vertex1 {
	Vector3 position; // 12 bytes
	Vector3 normal; // 12 bytes
	Vector2 texCoord; // 8 bytes
	VertexBlock extraData; 
};

//fuck you lol
struct Object1 {
	std::vector<Vertex1> objectsVerts;
	std::vector<GLuint> objectsIndices;
	std::vector<unsigned char> rawVertBlock;
	std::vector<unsigned char> rawIndexBlock;
	int VertexSize;
	std::string ColorTextureName; 
	std::string NormalTextureName;
};

inline std::string CurrentModelName = "";
inline std::vector<Object1> CurrentModel; // Current object being viewed in the viewport

namespace globals {
	inline Camera* cam = nullptr;
	inline Camera* cam2 = nullptr; //used for shadows
}
