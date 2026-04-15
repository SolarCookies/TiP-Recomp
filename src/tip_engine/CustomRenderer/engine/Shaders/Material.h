#pragma once
#include <string>
#include "ShaderClass.h"



class Material {

	public:
		Material() = default;
		~Material() = default;

		bool ContainsString(const std::string& str, const std::string& substr) {
			return str.find(substr) != std::string::npos;
		}

		void Initialize() {
			ShadowShaderProgram = std::make_unique<Shader>("EngineAssets/Shaders/ShadowMap.vert", "EngineAssets/Shaders/ShadowMap.frag");
		}

		void SetShader(const std::string& vertexPath, const std::string& fragmentPath, const std::string& geoPath = "") {
			shaderProgram = std::make_unique<Shader>(vertexPath.c_str(), fragmentPath.c_str(), geoPath.c_str());

			Initialize();

			//Temporary hardcoded Texture locations
			if(ContainsString(fragmentPath, "Default")) {
				ColorTextureIndex = 0;
				NormalTextureIndex = 1;
				SpecularTextureIndex = 2;
			}
			if (ContainsString(fragmentPath, "Color")) {
				ShadowTextureIndex = 0;
			}
			if (ContainsString(fragmentPath, "GeoTest")) {
				ColorTextureIndex = 0;
				ShadowTextureIndex = 1;
			}
		}

		std::unique_ptr<Shader> shaderProgram;
		std::unique_ptr<Shader> ShadowShaderProgram;

		int ColorTextureIndex = -1;
		int NormalTextureIndex = -1;
		int SpecularTextureIndex = -1;
		int ShadowTextureIndex = -1;

};