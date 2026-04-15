#pragma once
#include "../Actor.h"
#include "../../Components/Lights/LightComponent.h"

class APointLight : public Actor
{
public:
	APointLight() { 

		className = "APointLight"; 
		
		// Add a light component to the actor  
		auto lightComponent = std::make_shared<LightComponent>();
		Actor::AddComponent(lightComponent);
	}

	void Construct() override
	{
		Actor::Construct();
	}
};
