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

//rex_supportPinataTagClassify_825A0818 (Used to verify a tag to see if it has a valid class) returns supportPinataTagClass_e
REX_PPC_EXTERN_IMPORT(supportPinataTagClassify_825A0818);

// Show all spawn-menu categories (including normally hidden ones).
// Toggleable from the F4 recomp settings menu.
REXCVAR_DEFINE_BOOL(SpawnMenuShowAllCategories, false, "_Trouble in Paradise", "Show all spawn menu categories (including normally hidden ones)");

static constexpr float kSpawnListWidth = 300.0f;
static constexpr float kSpawnListHeight = 400.0f;
static constexpr float kSpawnOptionsWidth = 260.0f;
static constexpr float kSpawnItemHeight = 26.0f;
static constexpr int kSpawnOptionCount = 3; // resident, size, SPAWN button

static const std::vector<const char*> kColorOptions = {
    "Default", "Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Pink", "White", "Black"
};

static ImColor GetTypeColor(supportPinataTagClass_e type) {
    switch (type) {
        case supportPinataTag_Class_Animal:         return ImColor(255, 80, 80);
        case supportPinataTag_Class_Crate:          return ImColor(80, 200, 80);
        case supportPinataTag_Class_Egg:            return ImColor(80, 80, 255);
        case supportPinataTag_Class_Fruit:          return ImColor(255, 220, 50);
        case supportPinataTag_Class_Helper:         return ImColor(220, 80, 220);
        case supportPinataTag_Class_Seed:           return ImColor(80, 220, 220);
        case supportPinataTag_Class_SeedHole:       return ImColor(160, 160, 40);
        case supportPinataTag_Class_Home:           return ImColor(160, 40, 160);
        case supportPinataTag_Class_Surface:        return ImColor(40, 160, 160);
        case supportPinataTag_Class_Produce:        return ImColor(160, 160, 160);
        case supportPinataTag_Class_Prop:           return ImColor(255, 165, 50);
        case supportPinataTag_Class_BifPlant:       return ImColor(34, 139, 34);
        case supportPinataTag_Class_BifTree:        return ImColor(0, 100, 0);
        case supportPinataTag_Class_Bud:            return ImColor(144, 238, 144);
        case supportPinataTag_Class_Contract:       return ImColor(218, 165, 32);
        case supportPinataTag_Class_Fence:          return ImColor(139, 90, 43);
        case supportPinataTag_Class_Fertiliser:     return ImColor(160, 82, 45);
        case supportPinataTag_Class_FertiliserPile: return ImColor(139, 69, 19);
        case supportPinataTag_Class_FlowerHead:     return ImColor(255, 105, 180);
        case supportPinataTag_Class_HouseBlock:     return ImColor(178, 102, 178);
        case supportPinataTag_Class_LifeSweet:      return ImColor(255, 182, 193);
        case supportPinataTag_Class_Money:          return ImColor(255, 215, 0);
        case supportPinataTag_Class_Paving:         return ImColor(128, 128, 128);
        case supportPinataTag_Class_Projectile:     return ImColor(255, 69, 0);
        case supportPinataTag_Class_Sweet:          return ImColor(255, 140, 200);
        case supportPinataTag_Class_Vegetable:      return ImColor(107, 142, 35);
        case supportPinataTag_Class_ShopKeeper:     return ImColor(70, 130, 180);
        case supportPinataTag_Class_ZZSignpost:     return ImColor(210, 180, 140);
        case supportPinataTag_Class_ZZTrap:         return ImColor(178, 34, 34);
        case supportPinataTag_Class_Accessory:      return ImColor(200, 150, 255);
        case supportPinataTag_Class_Background:     return ImColor(100, 100, 180);
        case supportPinataTag_Class_Camera:         return ImColor(150, 150, 150);
        case supportPinataTag_Class_CameraTarget:   return ImColor(120, 120, 120);
        case supportPinataTag_Class_Cursor:         return ImColor(180, 180, 80);
        case supportPinataTag_Class_Journal:        return ImColor(180, 140, 100);
        case supportPinataTag_Class_Packet:         return ImColor(200, 180, 120);
        case supportPinataTag_Class_SlotMachine:    return ImColor(200, 200, 60);
        case supportPinataTag_Class_Spade:          return ImColor(100, 80, 60);
        case supportPinataTag_Class_SpadePart:      return ImColor(120, 100, 80);
        case supportPinataTag_Class_WateringCan:    return ImColor(60, 120, 200);
        case supportPinataTag_Class_ZZBag:          return ImColor(160, 120, 80);
        case supportPinataTag_Class_UNKNOWN:        return ImColor(200, 200, 200);
        default:                                    return ImColor(200, 200, 200);
    }
}

// Built dynamically from ItemTags on first use
static std::vector<supportPinataTagClass_e> sCategories;
static int sCategoriesBuildMode = -1; // 0 = filtered, 1 = show all

static bool ShouldShowAllCategories() {
    return REXCVAR_GET(SpawnMenuShowAllCategories);
}

static void BuildCategories() {
    int mode = ShouldShowAllCategories() ? 1 : 0;
    if (sCategoriesBuildMode == mode) return;
    std::set<supportPinataTagClass_e> seen;
    for (auto& [id, tag] : ItemTags) {
        bool include;
        if (mode == 1) {
            // Show-all: include every tag with a known class, ignoring Hide flag
            // and the IsValidPinataTagClass allow-list.
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
        case supportPinataTag_Class_Animal:         return "Animals";
        case supportPinataTag_Class_Camera:         return "Camera";
        case supportPinataTag_Class_Helper:         return "Helpers";
        case supportPinataTag_Class_Background:     return "Backgrounds";
        case supportPinataTag_Class_Accessory:      return "Accessories";
        case supportPinataTag_Class_BifPlant:       return "Plants";
        case supportPinataTag_Class_BifTree:        return "Trees";
        case supportPinataTag_Class_Bud:            return "Buds";
        case supportPinataTag_Class_CameraTarget:   return "Camera Target";
        case supportPinataTag_Class_Contract:       return "Contracts";
        case supportPinataTag_Class_Crate:          return "Crates";
        case supportPinataTag_Class_Cursor:         return "Cursor";
        case supportPinataTag_Class_Egg:            return "Eggs";
        case supportPinataTag_Class_Fence:          return "Fences";
        case supportPinataTag_Class_Fertiliser:     return "Fertilisers";
        case supportPinataTag_Class_FertiliserPile: return "Fertiliser Piles";
        case supportPinataTag_Class_FlowerHead:     return "Flower Heads";
        case supportPinataTag_Class_Fruit:          return "Fruits";
        case supportPinataTag_Class_Home:           return "Homes";
        case supportPinataTag_Class_HouseBlock:     return "House Blocks";
        case supportPinataTag_Class_Journal:        return "Journal";
        case supportPinataTag_Class_LifeSweet:      return "Life Sweets";
        case supportPinataTag_Class_Money:          return "Money";
        case supportPinataTag_Class_Packet:         return "Packets";
        case supportPinataTag_Class_Paving:         return "Paving";
        case supportPinataTag_Class_Produce:        return "Produce";
        case supportPinataTag_Class_Projectile:     return "Projectiles";
        case supportPinataTag_Class_Prop:           return "Props";
        case supportPinataTag_Class_Seed:           return "Seeds";
        case supportPinataTag_Class_SeedHole:       return "Seed Holes";
        case supportPinataTag_Class_ShopKeeper:     return "Shop Keepers";
        case supportPinataTag_Class_SlotMachine:    return "Slot Machines";
        case supportPinataTag_Class_Spade:          return "Spades";
        case supportPinataTag_Class_SpadePart:      return "Spade Parts";
        case supportPinataTag_Class_Surface:        return "Surfaces";
        case supportPinataTag_Class_Sweet:          return "Sweets";
        case supportPinataTag_Class_Vegetable:      return "Vegetables";
        case supportPinataTag_Class_WateringCan:    return "Watering Cans";
        case supportPinataTag_Class_ZZBag:          return "Bags";
        case supportPinataTag_Class_ZZSignpost:     return "Signposts";
        case supportPinataTag_Class_ZZTrap:         return "Traps";
        case supportPinataTag_Class_UNKNOWN:        return "Unknown";
        default:                                    return "Unknown";
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

  int item = rex::GuestToHostFunction<int>(__imp__rex_spawn_supportPinataCreateGeneralEx_82575C30,scene, 0, 0, tagID, 0, wildcard, spawnScale, 1.0);
}

PPC_EXTERN_IMPORT(__imp__rex_spawn_supportPinataCreateGeneral_82575AB8);
PPC_EXTERN_FUNC(rex_spawn_supportPinataCreateGeneral_82575AB8) {
    Log(LogLevel::Info, "spawn_supportPinataCreateGeneral Hook Hit");
    __imp__rex_spawn_supportPinataCreateGeneral_82575AB8(ctx, base);
    Log(LogLevel::Info, "spawn_supportPinataCreateGeneral finished");
}

int spawn_supportPinataCreateGeneralEx_82575C30_Hook(int a1, int a2, int a3, int a4, double spawnScale, double a6, int tagID, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15){
    Log(LogLevel::Info, "spawn_supportPinataCreateGeneralEx Hook Hit");
    
    //spawnScale = 10.5f;
    //a6 = 3.0f;

    // Get the guest address of the PPC function that called this hook
    //uint32_t callerAddr = rex::GetGuestCallerAddress();
    
    //char callerHex[32];
    //snprintf(callerHex, sizeof(callerHex), "0x%08X", callerAddr);


    int item = rex::GuestToHostFunction<int>(__imp__rex_spawn_supportPinataCreateGeneralEx_82575C30, a1, a2, a3, a4, spawnScale, a6, tagID, a8, a9, a10, a11, a12, a13, a14, a15);
    Log(LogLevel::Info, "spawn_supportPinataCreateGeneralEx called original function");
    
    std::string tagName = "Unknown";
    auto it = ItemTags.find(tagID - 1);
    if (it != ItemTags.end()) {
        tagName = it->second.Tag;
    }


    std::string logmsg;
    logmsg += "spawn_supportPinataCreateGeneralEx called from:";
    //logmsg += callerHex;
    logmsg += " with: ";
    //logmsg += "a1=" + std::to_string(a1) + " "; //ptr to scene
    //logmsg += "a3=" + std::to_string(a3) + " ";
    //logmsg += "a4=" + std::to_string(a4) + " "; //Unk not ptr
    //logmsg += "spawnScale=" + std::to_string(spawnScale) + " "; //Scale as double
    //logmsg += "a6=" + std::to_string(a6) + " "; //Unk double
    logmsg += "tagName=" + tagName + " ";
    //logmsg += "a8=" + std::to_string(a8) + " "; //Looks like it could be a ptr
    //logmsg += "a9=" + std::to_string(a9) + " "; //Seems to always be 0
    //logmsg += "a10=" + std::to_string(a10) + " "; //Mostly 0 but sometimes 6 or 7 (Pun not intended) (Could be class?)
    //logmsg += "a11=" + std::to_string(a11) + " "; 
    //logmsg += "a12=" + std::to_string(a12) + " "; 
    //logmsg += "a13=" + std::to_string(a13) + " ";
    //logmsg += "a14=" + std::to_string(a14) + " ";
    //logmsg += "a15=" + std::to_string(a15) + " ";
    //logmsg += "-> item=" + std::to_string(item); //output is the ptr to the item

    Log(LogLevel::Error,logmsg.c_str());
    Log(LogLevel::Info, "spawn_supportPinataCreateGeneralEx Hook Finished");
    return item;
};
REX_PPC_HOOK(spawn_supportPinataCreateGeneralEx_82575C30);


void SpawnMenuPage::OnDraw() {
    BuildCategories();
    int kCategoryCount = (int)sCategories.size();

    auto input = TiPWidgets::PollInput(inputTimer, 0.12f);

    // Build per-category sorted item lists once (rebuilt when "show all" cvar changes)
    static std::unordered_map<int, std::vector<const VivaTag*>> categoryItems;
    static int categoryItemsBuildMode = -1;
    int curBuildMode = ShouldShowAllCategories() ? 1 : 0;
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
        // Reset focus since the category list size may have changed.
        if (categoryFocusIndex >= (int)sCategories.size()) categoryFocusIndex = 0;
    }

    const VivaTag* selectedTag = nullptr;
    bool inputConsumed = false;

    // Determine current panel for resetting accel on panel changes
    int curPanel = (selectedCategory < 0) ? 0 : (selectedItemIndex < 0 ? 1 : 2);
    if (curPanel != prevPanel) {
        vertAccel.Reset();
        sliderAccel.Reset();
        prevPanel = curPanel;
    }

    // Accelerated vertical navigation
    int vertDir = TiPWidgets::GetHeldDir(SDL_GAMEPAD_BUTTON_DPAD_UP, SDL_GAMEPAD_BUTTON_DPAD_DOWN,
                                          ImGuiKey_UpArrow, ImGuiKey_DownArrow);

    // --- Input handling ---
    if (selectedCategory < 0) {
        // Category navigation
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
        // Item list navigation (input handled after building filtered list below)
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

    // --- Draw ---
    TiPWidgets::PushListStyle();

    if (selectedCategory < 0) {
        // === CATEGORY LIST ===
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
        // === ITEM LIST (within selected category) ===
        supportPinataTagClass_e currentType = sCategories[selectedCategory];
        const auto& baseItems = categoryItems[(int)currentType];

        // Filter by search
        static std::vector<const VivaTag*> filteredItems;
        filteredItems.clear();
        for (const VivaTag* tag : baseItems) {
            if (ContainsCaseInsensitive(tag->UIName, searchBuffer))
                filteredItems.push_back(tag);
        }
        int itemCount = (int)filteredItems.size();

        // Clamp focus index
        if (itemCount > 0 && itemFocusIndex >= itemCount)
            itemFocusIndex = itemCount - 1;

        // Handle item navigation (deferred from input section)
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

        // Search bar (outside scroll area so it stays visible)
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

            if (TiPWidgets::ColorListButton(tag->UIName, GetTypeColor(tag->type),
                                              isFocused || isSelected, kSpawnListWidth, kSpawnItemHeight)) {
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

        // Capture selected tag for options panel
        if (selectedItemIndex >= 0 && selectedItemIndex < itemCount)
            selectedTag = filteredItems[selectedItemIndex];
    }

    TiPWidgets::PopListStyle();

    // --- Draw options panel (separate window to the right) ---
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

        // 0: Is Resident checkbox
        TiPWidgets::Toggle("Is Resident", isResident, optionsFocusIndex == 0, optW, input);

        // 1: Size slider
        TiPWidgets::FloatSlider("Scale", sizeScale, 0.1f, 5.0f, 0.1f,
            optionsFocusIndex == 1, optW, sliderAccel.holdTime, sliderAccel.accumulator);

        // 2: Spawn button (colored)
        if (TiPWidgets::ColorListButton("SPAWN", GetTypeColor(selectedTag->type),
                                          optionsFocusIndex == 2, optW, 32.0f) ||
            (optionsFocusIndex == 2 && input.confirm)) {
                g_SpawnRequest.tagID = selectedTag->ID + 1; // Game uses 1-based tag IDs for spawning
                g_SpawnRequest.scale = sizeScale;
                g_SpawnRequest.wildcard = wildcardIndex; // 0=none, 1-3=wildcard body traits
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
