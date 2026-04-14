#pragma once
#include "../Component.h"
#include <imgui.h>

class LightComponent : public Component
{
public:
	LightComponent()
	{
		name = "LightComponent";
	}
	~LightComponent() override = default;
	void BeginPlay() override;
	void EndPlay() override;
	void Tick(float deltaTime, World* World) override;
	void Render(VinceWindow* window, Camera* Cam) override;
	void Draw(bool shadow, VinceWindow* window, Camera* Cam) override;
	void SetColor(const glm::vec4& color) { lightColor = color; }
	glm::vec4 GetColor() const { return lightColor; }
	void SetPosition(const glm::vec3& position) { lightPos = position; }
	glm::vec3 GetPosition() const { return lightPos; }
	

public:
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	float lightIntensity = 1.0f;
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);

};
