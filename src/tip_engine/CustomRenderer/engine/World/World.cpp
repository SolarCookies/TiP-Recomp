#include "World.h"
#include "../Components/Lights/LightComponent.h"

LightComponent* World::GetLightSource()
{
	//get the first actor that has a LightComponent
	for (auto& actor : Actors) {
		if (actor->GetComponentByName("LightComponent")) {
			LightComponent* Light = dynamic_cast<LightComponent*>(actor->GetComponentByName("LightComponent"));
			if (Light) {
				return Light;
			}
			else {
				return nullptr;
			}
		}
	}
	return nullptr;
}

void World::RenderWorldOutliner()
{
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.1f, 0.0f, 0.2f, 0.5f));
    ImGui::Begin("WorldOutliner");

    // Prepare list of actor names
    std::vector<const char*> actorNames;
    for (const auto& actor : Actors) {
        actorNames.push_back(actor->ActorName.c_str());
    }

    // Find currently selected index
    int selectedIndex = -1;
    for (size_t i = 0; i < Actors.size(); ++i) {
        if (Actors[i].get() == CurrentlySelectedActor) {
            selectedIndex = static_cast<int>(i);
            break;
        }
    }

    // Get available size for the list box
    ImVec2 listBoxSize = ImGui::GetContentRegionAvail();

    // Use ImGui::BeginListBox and ImGui::EndListBox instead of ListBoxHeader/ListBoxFooter
    if (ImGui::BeginListBox("", listBoxSize)) {
        for (int i = 0; i < static_cast<int>(actorNames.size()); ++i) {
            bool isSelected = (selectedIndex == i);
            if (ImGui::Selectable(actorNames[i], isSelected)) {
                // Update selection
                if (CurrentlySelectedActor) {
                    CurrentlySelectedActor->Selected = false;
                }
                CurrentlySelectedActor = Actors[i].get();
                CurrentlySelectedActor->Selected = true;
            }
            if (isSelected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndListBox();
    }

    ImGui::End();
	ImGui::PopStyleColor();
}
