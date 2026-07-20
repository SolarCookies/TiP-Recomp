#include "SpawnMenu.h"
#include "../SmartStyles.h"
#include "../TiPWidgets.h"
#include "src/tip_engine/rex_macros.h"
#include "src/tip_engine/Globals.h"
#include "src/tip_engine/Log.h"
#include <rex/cvar.h>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <set>
#include <string>

//Used to verify a tag to see if it has a valid class
REX_PPC_EXTERN_IMPORT(supportPinataTagClassify_825A0818);

REXCVAR_DEFINE_BOOL(SpawnMenuShowAllCategories, false, "TiP", "Show all spawn menu categories (including normally hidden ones)");

static constexpr float kSpawnListWidth = 300.0f;
static constexpr float kSpawnListHeight = 400.0f;
static constexpr float kSpawnOptionsWidth = 260.0f;
static constexpr float kSpawnItemHeight = 26.0f;
static constexpr int kSpawnOptionCount = 3;

static const std::vector<const char*> kColorOptions = {
    "Default", "Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Pink", "White", "Black"
};

static ImColor GetTypeColor(supportPinataTagClass_e type) {
    switch (type) {
        case supportPinataTag_Class_Animal: return ImColor(255, 80, 80);
        case supportPinataTag_Class_Crate: return ImColor(80, 200, 80);
        case supportPinataTag_Class_Egg: return ImColor(80, 80, 255);
        case supportPinataTag_Class_Fruit: return ImColor(255, 220, 50);
        case supportPinataTag_Class_Helper: return ImColor(220, 80, 220);
        case supportPinataTag_Class_Seed: return ImColor(80, 220, 220);
        case supportPinataTag_Class_SeedHole: return ImColor(160, 160, 40);
        case supportPinataTag_Class_Home: return ImColor(160, 40, 160);
        case supportPinataTag_Class_Surface: return ImColor(40, 160, 160);
        case supportPinataTag_Class_Produce: return ImColor(160, 160, 160);
        case supportPinataTag_Class_Prop: return ImColor(255, 165, 50);
        case supportPinataTag_Class_BifPlant: return ImColor(34, 139, 34);
        case supportPinataTag_Class_BifTree: return ImColor(0, 100, 0);
        case supportPinataTag_Class_Bud: return ImColor(144, 238, 144);
        case supportPinataTag_Class_Contract: return ImColor(218, 165, 32);
        case supportPinataTag_Class_Fence: return ImColor(139, 90, 43);
        case supportPinataTag_Class_Fertiliser: return ImColor(160, 82, 45);
        case supportPinataTag_Class_FertiliserPile: return ImColor(139, 69, 19);
        case supportPinataTag_Class_FlowerHead: return ImColor(255, 105, 180);
        case supportPinataTag_Class_HouseBlock: return ImColor(178, 102, 178);
        case supportPinataTag_Class_LifeSweet: return ImColor(255, 182, 193);
        case supportPinataTag_Class_Money: return ImColor(255, 215, 0);
        case supportPinataTag_Class_Paving: return ImColor(128, 128, 128);
        case supportPinataTag_Class_Projectile: return ImColor(255, 69, 0);
        case supportPinataTag_Class_Sweet: return ImColor(255, 140, 200);
        case supportPinataTag_Class_Vegetable: return ImColor(107, 142, 35);
        case supportPinataTag_Class_ShopKeeper: return ImColor(70, 130, 180);
        case supportPinataTag_Class_ZZSignpost: return ImColor(210, 180, 140);
        case supportPinataTag_Class_ZZTrap: return ImColor(178, 34, 34);
        case supportPinataTag_Class_Accessory: return ImColor(200, 150, 255);
        case supportPinataTag_Class_Background: return ImColor(100, 100, 180);
        case supportPinataTag_Class_Camera: return ImColor(150, 150, 150);
        case supportPinataTag_Class_CameraTarget: return ImColor(120, 120, 120);
        case supportPinataTag_Class_Cursor: return ImColor(180, 180, 80);
        case supportPinataTag_Class_Journal: return ImColor(180, 140, 100);
        case supportPinataTag_Class_Packet: return ImColor(200, 180, 120);
        case supportPinataTag_Class_SlotMachine: return ImColor(200, 200, 60);
        case supportPinataTag_Class_Spade: return ImColor(100, 80, 60);
        case supportPinataTag_Class_SpadePart: return ImColor(120, 100, 80);
        case supportPinataTag_Class_WateringCan: return ImColor(60, 120, 200);
        case supportPinataTag_Class_ZZBag: return ImColor(160, 120, 80);
        case supportPinataTag_Class_UNKNOWN: return ImColor(200, 200, 200);
        default: return ImColor(200, 200, 200);
    }
}

static std::vector<supportPinataTagClass_e> sCategories;
static int sCategoriesBuildMode = -1;

static bool ShouldShowAllCategories() {
    return REXCVAR_GET(SpawnMenuShowAllCategories);
}

static void BuildCategories() {
    int mode = REXCVAR_GET(SpawnMenuShowAllCategories) ? 1 : 0;
    if (sCategoriesBuildMode == mode) return;
    std::set<supportPinataTagClass_e> seen;
    for (auto& [id, tag] : ItemTags) {
        bool include;
        if (mode == 1) {
            include = (tag.type != supportPinataTag_Class_UNKNOWN);
        } else {
            include = IsValidPinataTagClass(tag.type) && !(tag.uiFlags & UIFlag::Hide);
        }
        if (include)
            seen.insert(tag.type);
    }
    sCategories.assign(seen.begin(), seen.end());
    std::sort(sCategories.begin(), sCategories.end());
    sCategoriesBuildMode = mode;
}

const char* GetTypeName(supportPinataTagClass_e type) {
    switch (type) {
        case supportPinataTag_Class_Animal: return "Animals";
        case supportPinataTag_Class_Camera: return "Camera";
        case supportPinataTag_Class_Helper: return "Helpers";
        case supportPinataTag_Class_Background: return "Backgrounds";
        case supportPinataTag_Class_Accessory: return "Accessories";
        case supportPinataTag_Class_BifPlant: return "Plants";
        case supportPinataTag_Class_BifTree: return "Trees";
        case supportPinataTag_Class_Bud: return "Buds";
        case supportPinataTag_Class_CameraTarget: return "Camera Target";
        case supportPinataTag_Class_Contract: return "Contracts";
        case supportPinataTag_Class_Crate: return "Crates";
        case supportPinataTag_Class_Cursor: return "Cursor";
        case supportPinataTag_Class_Egg: return "Eggs";
        case supportPinataTag_Class_Fence: return "Fences";
        case supportPinataTag_Class_Fertiliser: return "Fertilisers";
        case supportPinataTag_Class_FertiliserPile: return "Fertiliser Piles";
        case supportPinataTag_Class_FlowerHead: return "Flower Heads";
        case supportPinataTag_Class_Fruit: return "Fruits";
        case supportPinataTag_Class_Home: return "Homes";
        case supportPinataTag_Class_HouseBlock: return "House Blocks";
        case supportPinataTag_Class_Journal: return "Journal";
        case supportPinataTag_Class_LifeSweet: return "Life Sweets";
        case supportPinataTag_Class_Money: return "Money";
        case supportPinataTag_Class_Packet: return "Packets";
        case supportPinataTag_Class_Paving: return "Paving";
        case supportPinataTag_Class_Produce: return "Produce";
        case supportPinataTag_Class_Projectile: return "Projectiles";
        case supportPinataTag_Class_Prop: return "Props";
        case supportPinataTag_Class_Seed: return "Seeds";
        case supportPinataTag_Class_SeedHole: return "Seed Holes";
        case supportPinataTag_Class_ShopKeeper: return "Shop Keepers";
        case supportPinataTag_Class_SlotMachine: return "Slot Machines";
        case supportPinataTag_Class_Spade: return "Spades";
        case supportPinataTag_Class_SpadePart: return "Spade Parts";
        case supportPinataTag_Class_Surface: return "Surfaces";
        case supportPinataTag_Class_Sweet: return "Sweets";
        case supportPinataTag_Class_Vegetable: return "Vegetables";
        case supportPinataTag_Class_WateringCan: return "Watering Cans";
        case supportPinataTag_Class_ZZBag: return "Bags";
        case supportPinataTag_Class_ZZSignpost: return "Signposts";
        case supportPinataTag_Class_ZZTrap: return "Traps";
        case supportPinataTag_Class_UNKNOWN: return "Unknown";
        default: return "Unknown";
    }
}

static bool ContainsCaseInsensitive(const char* haystack, const char* needle) {
    if (!needle[0]) return true;
    for (; *haystack; ++haystack) {
        const char* h = haystack;
        const char* n = needle;
        while (*h && *n && (std::tolower((unsigned char)*h) == std::tolower((unsigned char)*n))) { ++h; ++n; }
        if (!*n) return true;
    }
    return false;
}

REX_PPC_EXTERN_IMPORT(spawn_supportPinataCreateGeneralEx_82575C30);
void SpawnPinata(){
    Log(LogLevel::Info, "SpawnPinata function called");
  if (!g_SpawnRequest.pending) return;

  uint32_t tagID = g_SpawnRequest.tagID;
  float spawnScale = g_SpawnRequest.scale;
  int wildcard = g_SpawnRequest.wildcard;
  bool spawnWild = g_SpawnRequest.spawnWild;
  g_SpawnRequest.pending = false;

  if (scene == 0) return;

  int item = GuestToHostFunction<int>(__imp__rex_spawn_supportPinataCreateGeneralEx_82575C30,scene, 0, 0, tagID, 0, wildcard, spawnScale, 1.0);
}

REX_EXTERN(__imp__rex_spawn_supportPinataCreateGeneral_82575AB8);
REX_HOOK_RAW(rex_spawn_supportPinataCreateGeneral_82575AB8) {
    __imp__rex_spawn_supportPinataCreateGeneral_82575AB8(ctx, base);
}

int spawn_supportPinataCreateGeneralEx_82575C30_Hook(int a1, int a2, int a3, int a4, double spawnScale, double a6, int tagID, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15){
    //spawnScale = 10.5f;
    //a6 = 3.0f;

    // Get the guest address of the PPC function that called this hook
    uint32_t callerAddr = rex::ppc::GetGuestCallerAddress();

    char callerHex[32];
    snprintf(callerHex, sizeof(callerHex), "0x%08X", callerAddr);

    int item = GuestToHostFunction<int>(__imp__rex_spawn_supportPinataCreateGeneralEx_82575C30, a1, a2, a3, a4, spawnScale, a6, tagID, a8, a9, a10, a11, a12, a13, a14, a15);

    std::string tagName = "Unknown";
    auto it = ItemTags.find(tagID - 1);
    if (it != ItemTags.end()) {
        tagName = it->second.Tag;
    }

    std::string logmsg;
    logmsg += "spawn_supportPinataCreateGeneralEx called from:";
    logmsg += callerHex;
    logmsg += " with: ";
    logmsg += "tagName=" + tagName + " ";

    Log(LogLevel::Info, logmsg.c_str());
    return item;
};
REX_PPC_HOOK(spawn_supportPinataCreateGeneralEx_82575C30);

void SpawnMenuPage::OnDraw() {
    BuildCategories();
    int kCategoryCount = (int)sCategories.size();

    auto input = TiPWidgets::PollInput(inputTimer, 0.12f);

    static std::unordered_map<int, std::vector<const VivaTag*>> categoryItems;
    static int categoryItemsBuildMode = -1;
    int curBuildMode = REXCVAR_GET(SpawnMenuShowAllCategories) ? 1 : 0;
    if (categoryItems.empty() || categoryItemsBuildMode != curBuildMode) {
        categoryItems.clear();
        for (auto& [id, tag] : ItemTags) {
            bool include;
            if (curBuildMode == 1) {
                include = (tag.type != supportPinataTag_Class_UNKNOWN);
            } else {
                include = IsValidPinataTagClass(tag.type) && !(tag.uiFlags & UIFlag::Hide);
            }
            if (include)
                categoryItems[(int)tag.type].push_back(&tag);
        }
        for (auto& [type, items] : categoryItems) {
            std::sort(items.begin(), items.end(),
                [](const VivaTag* a, const VivaTag* b) { return a->ID < b->ID; });
        }
        categoryItemsBuildMode = curBuildMode;

        if (categoryFocusIndex >= (int)sCategories.size()) categoryFocusIndex = 0;
    }

    const VivaTag* selectedTag = nullptr;
    bool inputConsumed = false;

    int curPanel = (selectedCategory < 0) ? 0 : (selectedItemIndex < 0 ? 1 : 2);
    if (curPanel != prevPanel) {
        vertAccel.Reset();
        sliderAccel.Reset();
        prevPanel = curPanel;
    }

    int vertDir = TiPWidgets::GetHeldDir(SDL_GAMEPAD_BUTTON_DPAD_UP, SDL_GAMEPAD_BUTTON_DPAD_DOWN, ImGuiKey_UpArrow, ImGuiKey_DownArrow);

    if (selectedCategory < 0) {
        int vertDelta = TiPWidgets::AccelTick(vertAccel, vertDir, 20.0f, 1.0f);
        if (vertDelta != 0) { categoryFocusIndex += vertDelta; categoryScrollToFocus = true; }
        TiPWidgets::WrapIndex(categoryFocusIndex, kCategoryCount);

        if (input.confirm && kCategoryCount > 0) {
            selectedCategory = categoryFocusIndex;
            itemFocusIndex = 0;
            selectedItemIndex = -1;
            itemScrollToFocus = true;
            memset(searchBuffer, 0, sizeof(searchBuffer));
            TiPWidgets::SetInputCooldown(0.25f);
            inputConsumed = true;
        }
        if (input.back) {
            wantsClose = true;
        }
    } else if (selectedItemIndex < 0) {

    } else {
        // Options panel navigation
        int vertDelta = TiPWidgets::AccelTick(vertAccel, vertDir, 15.0f, 1.0f);
        optionsFocusIndex += vertDelta;
        TiPWidgets::WrapIndex(optionsFocusIndex, kSpawnOptionCount);

        if (input.back) {
            selectedItemIndex = -1;
            TiPWidgets::SetInputCooldown(0.25f);
        }
    }

    TiPWidgets::PushListStyle();

    if (selectedCategory < 0) {
        ImGui::BeginChild("##SpawnCategoryList", ImVec2(kSpawnListWidth, kSpawnListHeight), false);

        for (int i = 0; i < kCategoryCount; i++) {
            bool isFocused = (i == categoryFocusIndex);

            if (isFocused && categoryScrollToFocus) {
                ImGui::SetScrollHereY(0.5f);
                categoryScrollToFocus = false;
            }

            ImColor btnColor = isFocused ? GetTypeColor(sCategories[i]) : ImColor(120, 120, 120);
            if (TiPWidgets::ColorListButton(GetTypeName(sCategories[i]), btnColor,
                                              isFocused, kSpawnListWidth, kSpawnItemHeight)) {
                categoryFocusIndex = i;
                selectedCategory = i;
                itemFocusIndex = 0;
                selectedItemIndex = -1;
                itemScrollToFocus = true;
                memset(searchBuffer, 0, sizeof(searchBuffer));
            }

            if (ImGui::IsItemHovered())
                categoryFocusIndex = i;
        }

        ImGui::EndChild();
    } else {
        supportPinataTagClass_e currentType = sCategories[selectedCategory];
        const auto& baseItems = categoryItems[(int)currentType];

        static std::vector<const VivaTag*> filteredItems;
        filteredItems.clear();
        for (const VivaTag* tag : baseItems) {
            if (ContainsCaseInsensitive(tag->UIName, searchBuffer))
                filteredItems.push_back(tag);
        }
        int itemCount = (int)filteredItems.size();

        if (itemCount > 0 && itemFocusIndex >= itemCount)
            itemFocusIndex = itemCount - 1;

        if (selectedItemIndex < 0) {
            int itemVertDelta = TiPWidgets::AccelTick(vertAccel, vertDir, 30.0f, 1.5f);
            if (itemVertDelta != 0) { itemFocusIndex += itemVertDelta; itemScrollToFocus = true; }
            if (itemCount > 0) TiPWidgets::WrapIndex(itemFocusIndex, itemCount);

            if (input.confirm && !inputConsumed && itemCount > 0) {
                selectedItemIndex = itemFocusIndex;
                optionsFocusIndex = 0;
                variantIndex = 0;
                wildcardIndex = 0;
                Wild = false;
                isResident = false;
                sizeScale = 1.0f;
                TiPWidgets::SetInputCooldown(0.25f);
            }
            if (input.back) {
                selectedCategory = -1;
                TiPWidgets::SetInputCooldown(0.25f);
            }
        }

        float searchStartY = ImGui::GetCursorPosY();
        ImGui::SetNextItemWidth(kSpawnListWidth - 16.0f);
        if (ImGui::InputTextWithHint("##SpawnSearch", "Search...", searchBuffer, sizeof(searchBuffer))) {
            itemFocusIndex = 0;
            selectedItemIndex = -1;
            itemScrollToFocus = true;
        }
        ImGui::Separator();
        float searchHeight = ImGui::GetCursorPosY() - searchStartY;

        ImGui::BeginChild("##SpawnItemList", ImVec2(kSpawnListWidth, kSpawnListHeight - searchHeight), false);

        for (int i = 0; i < itemCount; i++) {
            const VivaTag* tag = filteredItems[i];
            bool isFocused = (i == itemFocusIndex);
            bool isSelected = (i == selectedItemIndex);

            if (isFocused && itemScrollToFocus) {
                ImGui::SetScrollHereY(0.5f);
                itemScrollToFocus = false;
            }

            if (TiPWidgets::ColorListButton(tag->UIName, GetTypeColor(tag->type), isFocused || isSelected, kSpawnListWidth, kSpawnItemHeight)) {
                itemFocusIndex = i;
                selectedItemIndex = i;
                optionsFocusIndex = 0;
                variantIndex = 0;
                wildcardIndex = 0;
                Wild = false;
                isResident = false;
                sizeScale = 1.0f;
            }

            if (ImGui::IsItemHovered())
                itemFocusIndex = i;
        }

        ImGui::EndChild();

        if (selectedItemIndex >= 0 && selectedItemIndex < itemCount) selectedTag = filteredItems[selectedItemIndex];
    }

    TiPWidgets::PopListStyle();

    if (selectedTag) {
        ImVec2 subPos = ImGui::GetWindowPos();
        float subWidth = ImGui::GetWindowSize().x;

        ImGui::SetNextWindowPos(ImVec2(subPos.x + subWidth + 2.0f, subPos.y), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2(kSpawnOptionsWidth, 0), ImGuiCond_Always);

        SetUIColor(GetTypeColor(selectedTag->type));

        std::string optTitle = std::string(selectedTag->UIName) + "###TiPSpawnOptions";
        bool optPanelOpen = true;
        ImGui::Begin(optTitle.c_str(), &optPanelOpen,
            ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize |
            ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove);

        TiPWidgets::PushListStyle();
        float optW = ImGui::GetContentRegionAvail().x;

        TiPWidgets::Toggle("Is Resident", isResident, optionsFocusIndex == 0, optW, input);

        TiPWidgets::FloatSlider("Scale", sizeScale, 0.1f, 5.0f, 0.1f,
            optionsFocusIndex == 1, optW, sliderAccel.holdTime, sliderAccel.accumulator);

        if (TiPWidgets::ColorListButton("SPAWN", GetTypeColor(selectedTag->type), optionsFocusIndex == 2, optW, 32.0f) || (optionsFocusIndex == 2 && input.confirm)) {
                g_SpawnRequest.tagID = selectedTag->ID + 1;
                g_SpawnRequest.scale = sizeScale;
                g_SpawnRequest.wildcard = wildcardIndex;
                g_SpawnRequest.spawnWild = !isResident;
                g_SpawnRequest.pending = true;
        }

        TiPWidgets::PopListStyle();
        ImGui::End();
        PopUIColor();

        if (!optPanelOpen) {
            selectedItemIndex = -1;
        }
    }
}
