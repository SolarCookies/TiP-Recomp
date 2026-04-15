#include "Actor.h"

Actor::Actor() {}

Actor::~Actor() {}

void Actor::Construct() {
    for (auto& comp : components) {
		comp->owner = this;
        comp->Construct();
    }
    //move any delayed components to the main components list
    for (auto& comp : delayedComponents) {
        comp->owner = this;
        components.push_back(comp);
    }
    delayedComponents.clear();
}

void Actor::BeginPlay() {
    if (!hasBegunPlay) {
        hasBegunPlay = true;
        for (auto& comp : components) {
            comp->BeginPlay();
        }
    }
}

void Actor::Tick(float deltaTime,World* world) {
    for (auto& comp : components) {
        comp->Tick(deltaTime, world);
    }
}

void Actor::Render(VinceWindow* Window, class Camera* Cam) {
    for (auto& comp : components) {
        comp->Render(Window, Cam);
	}
}

void Actor::EndPlay() {
    for (auto& comp : components) {
        comp->EndPlay();
    }
}


void Actor::AddComponent(std::shared_ptr<Component> component) {
    component->owner = this;
    components.push_back(component);
}