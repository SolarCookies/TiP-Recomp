/** 
******************************************************************************
* ReTiP: Viva Pinata Recompiled                                              *
******************************************************************************
* Copyright (c) 2026 SolarCookies. Licensed under custom noncommercial terms.
*
* This software is licensed for non-commercial, private, and educational use 
* only. You may modify, rewrite, and optimize this code provided that full 
* attribution is given to the original authors listed on the project repository. 
* Commercial use is prohibited.
*
* DISCLAIMER: This software is provided "as-is" without warranty of any kind. 
* This project is an unofficial fan translation layer and does NOT provide, 
* distribute, or package any copyrighted game assets, binaries, or media belonging 
* to Microsoft or Rare. Users must provide their own legally obtained game assets. 
* This software must not be used in any manner that violates Microsoft's copyrights.
* DO NOT REDISTRIBUTE GAME ASSETS OR PROMOTE PIRACY.
*
* AI USE GUIDELINES:
* This project is built with minimal AI usage. We may utilize basic inline code 
* suggestions or rely on AI assistance for debugging, but the vast majority of 
* this codebase is written by hand. We manually decompile functions,
* reverse engineer structs, and write hooks to ensure accuracy and maintainability.
*
* The core goal of ReTiP is not only to get the game running, but to 
* research, document, and learn exactly how the game operates under the hood so that 
* we can provide modding support. We do not support using AI for creative 
* task or problem solving. i.e asking an AI agent to "find a way to 
* make freecam work". Instead, AI should only be used for small, boilerplate tasks or
* parsing a 1000 line crash log to isolate an error. We actively encourage all project 
* contributors to avoid the use of AI agents entirely when writing code or decompiling functions.
*
* The truth of the matter is that AI when used currectly by people who understand the output
* can be incredibly useful just like intelisense, being able to press Tab to autocomplete a
* for loop can save time. However, AI is not a replacement for human understanding and
* should not be used to replace the process of learning and understanding how the game works.
*
* We strongly prefer the use of local models that do not harm the environment and 
* can run entirely on your own local hardware over cloud based AI services. Ultimately, 
* all pull requests and code contributions will be strictly reviewed by people who 
* understand the codebase and the game. If you list Claude or any other AI as a coauthor 
* or contributor, your PR will be rejected regardless of whether it works.
******************************************************************************
*/

#pragma once
#include "CommonTypes.h"
#include <string>

/* 1073 */
enum requirementsAnimal_e : uint32_t
{
	reqAnimal_Null = 0x0,
	reqAnimal_TimeIsBetween = 0x1,
	reqAnimal_DoesNotJustComeIn = 0x2,
	reqAnimal_BeginSection = 0x3,
	reqAnimal_EndSection = 0x4,
	reqAnimal_And = 0x5,
	reqAnimal_Or = 0x6,
	reqAnimal_Not = 0x7,
	reqAnimal_GardenSurfaceCoverMultipleTagGroup = 0x8,
	reqAnimal_PlayerHasAttainedLevel = 0x9,
	reqAnimal_TargetIsOfType = 0xA,
	reqAnimal_TargetIsLogicallySmaller = 0xB,
	reqAnimal_TargetIsLogicallyLarger = 0xC,
	reqAnimal_TargetIsOfClass = 0xD,
	reqAnimal_GardenContainsTagGroup = 0xE,
	reqAnimal_PlayerPoints = 0xF,
	reqAnimal_PlayerHasAward = 0x10,
	reqAnimal_PlayerHasCredits = 0x11,
	reqAnimal_ActorHasEatenRequiredAmountOfAvatars = 0x12,
	reqAnimal_GardenHasEnoughSpace = 0x13,
	reqAnimal_InsertRequirementAsset = 0x14,
	reqAnimal_AnimalHasAccessory = 0x15,
	reqAnimal_AnimalCheckEvents = 0x16,
	reqAnimal_GameTimeReached = 0x17,
	reqAnimal_GamePlayTimeReached = 0x18,
	reqAnimal_GardenSurfaceCoverSingle = 0x19,
	reqAnimal_GardenValue = 0x1A,
	reqAnimal_GardenSurfaceCoverMultiple = 0x1B,
	reqAnimal_PlayerHasEvent = 0x1C,
	reqAnimal_TargetIsOfTagGroup = 0x1D,
	reqAnimal_PlayerHasAwardFilter = 0x1E,
	reqAnimal_PlayerHasStat = 0x1F,
	reqAnimal_AnimalGeneratorFlagSet = 0x20,
	reqAnimal_LocalPlayerPoints = 0x21,
	reqAnimal_LocalPlayerHasAttainedLevel = 0x22,
	reqAnimal_PlayerIsClient = 0x23,
	reqAnimal_LocalPlayerHasCredits = 0x24,
	reqAnimal_LocalGamePlayTimeReached = 0x25,
	reqAnimal_CurrentGardenIsOfType = 0x26,
	reqAnimal_Dummy = 0x27,
	reqAnimal_Max = 0x28,
};

inline std::string GetReqAnimalString(requirementsAnimal_e req) {
	switch (req)
	{
	case reqAnimal_Null: return "Null";
	case reqAnimal_TimeIsBetween: return "Time Is Between";
	case reqAnimal_DoesNotJustComeIn: return "Does Not Just Come In";
	case reqAnimal_BeginSection: return "Begin Section";
	case reqAnimal_EndSection: return "End Section";
	case reqAnimal_And: return "And";
	case reqAnimal_Or: return "Or";
	case reqAnimal_Not: return "Not";
	case reqAnimal_GardenSurfaceCoverMultipleTagGroup: return "Garden Surface Cover Multiple Tag Group";
	case reqAnimal_PlayerHasAttainedLevel: return "Player Has Attained Level";
	case reqAnimal_TargetIsOfType: return "Target Is Of Type";
	case reqAnimal_TargetIsLogicallySmaller: return "Target Is Logically Smaller";
	case reqAnimal_TargetIsLogicallyLarger: return "Target Is Logically Larger";
	case reqAnimal_TargetIsOfClass: return "Target Is Of Class";
	case reqAnimal_GardenContainsTagGroup: return "Garden Contains Tag Group";
	case reqAnimal_PlayerPoints: return "Player Points";
	case reqAnimal_PlayerHasAward: return "Player Has Award";
	case reqAnimal_PlayerHasCredits: return "Player Has Credits";
	case reqAnimal_ActorHasEatenRequiredAmountOfAvatars: return "Actor Has Eaten Required Amount Of Avatars";
	case reqAnimal_GardenHasEnoughSpace: return "Garden Has Enough Space";
	case reqAnimal_InsertRequirementAsset: return "Insert Requirement Asset";
	case reqAnimal_AnimalHasAccessory: return "Animal Has Accessory";
	case reqAnimal_AnimalCheckEvents: return "Animal Check Events";
	case reqAnimal_GameTimeReached: return "Game Time Reached";
	case reqAnimal_GamePlayTimeReached: return "Game Play Time Reached";
	case reqAnimal_GardenSurfaceCoverSingle: return "Garden Surface Cover Single";
	case reqAnimal_GardenValue: return "Garden Value";
	case reqAnimal_GardenSurfaceCoverMultiple: return "Garden Surface Cover Multiple";
	case reqAnimal_PlayerHasEvent: return "Player Has Event";
	case reqAnimal_TargetIsOfTagGroup: return "Target Is Of Tag Group";
	case reqAnimal_PlayerHasAwardFilter: return "Player Has Award Filter";
	case reqAnimal_PlayerHasStat: return "Player Has Stat";
	case reqAnimal_AnimalGeneratorFlagSet: return "Animal Generator Flag Set";
	case reqAnimal_LocalPlayerPoints: return "Local Player Points";
	case reqAnimal_LocalPlayerHasAttainedLevel: return "Local Player Has Attained Level";
	case reqAnimal_PlayerIsClient: return "Player Is Client";
	case reqAnimal_LocalPlayerHasCredits: return "Local Player Has Credits";
	case reqAnimal_LocalGamePlayTimeReached: return "Local Game Play Time Reached";
	case reqAnimal_CurrentGardenIsOfType: return "Current Garden Is Of Type";
	case reqAnimal_Max: return "Max";
	default: return "Unknown";
	}
};

/* 11669 */
struct reqAnimal_Structure_s
{
	requirementsAnimal_e reqId;
};

/* 1279 */
enum requirementsInstWhen_e : uint32_t
{
	requirementsInstWhen_Unused = 0xFFFFFFFF,
	requirementsInstWhen_Always = 0x0,
	requirementsInstWhen_Prompted = 0x1,
	requirementsInstWhen_Fought = 0x2,
	requirementsInstWhen_MAX = 0x3,
};

inline std::string GetReqInstWhenString(requirementsInstWhen_e req) {
	switch (req)
	{
	case requirementsInstWhen_Unused: return "Unused";
	case requirementsInstWhen_Always: return "Always";
	case requirementsInstWhen_Prompted: return "Prompted";
	case requirementsInstWhen_Fought: return "Fought";
	case requirementsInstWhen_MAX: return "Max";
	default: return "Unknown";
	}
};
