#pragma once
#include "../Actors/Actor.h"
//#include <rpc.h>
#include "tip_engine/CustomRenderer/Window.h"
#include <imgui.h>

class LightComponent;

class World {

public:
	Actor* GetActorOfClass(const std::string& ClassName) {
		for (auto& actor : Actors) {
			if (actor->GetClassName() == ClassName) {
				return actor.get();
			}
		}
		return nullptr;
	}

	std::vector<Actor*> GetAllActorsOfClass(const std::string& ClassName) {
		std::vector<Actor*> FoundActors;
		for (auto& actor : Actors) {
			if (actor->GetClassName() == ClassName) {
				FoundActors.push_back(actor.get());
			}
		}
		return FoundActors;
	}

	std::vector<Actor*> GetAllActorsWithTag(std::string Tag) {
		std::vector<Actor*> FoundActors;
		for (auto& actor : Actors) {
			for(const std::string& actorTag : actor->ActorTags) {
				if (actorTag == Tag) {
					FoundActors.push_back(actor.get());
					break;
				}
			}
		}
		return FoundActors;
	}

	void AddActor(std::unique_ptr<Actor> actor) {
		//Name the actor
		int index = 0;
		for(auto& Actor : Actors) {
			if (Actor->GetClassName() == actor->GetClassName()) {
				index++;
			}
		}
		actor->ActorName = actor->GetClassName() + std::to_string(index);
		Actors.push_back(std::move(actor));
	}

	void Render(VinceWindow* window, class Camera* Cam) {
		for (auto& actor : Actors) {
			actor->Render(window, Cam);
		}
	}

	void ConstructWorld() {
		for (auto& actor : Actors) {
			actor->Construct();
		}
	}

	void TickWorld(float DeltaTime) {
		for (auto& actor : Actors) {
			actor->Tick(DeltaTime, this);
		}
	}

	LightComponent* GetLightSource();

	uint32_t GetActorCount() {
		return static_cast<uint32_t>(Actors.size());
	}

	void RenderWorldOutliner();

	Actor* CurrentlySelectedActor = nullptr;

private:
	std::vector<std::unique_ptr<Actor>> Actors;

};