<img width="3347" height="2198" alt="image" src="https://github.com/user-attachments/assets/8841c75d-1d5b-43f5-b19e-050b05fb7d08" />

> [!IMPORTANT]
> ReTiP is an unofficial project

> [!NOTE]
> This Repo has a strict no AI rule, No Vibe Coding, No AI generated Assets, No AI assisted Disassembly/Analysis.

# ReTiP

ReTiP recompiles and hooks Viva Pinata Trouble in Paradise in order to better mod support, and QoL features.

The main priority of this project is not to be playable on low end hardware or to be fully optimized. I started this project as a means to mod Trouble in Paradise, Adding cheats, Reverse Engineering the asset formats, Texture Packs, and adding other cool stuff. Im not a purest when it comes to making this recomp be fully native. Eventually I or someone else will add a native renderer that will lower the system requirements, But thats not my priority. It runs on my system (rtx 3050) at 200fps, and over 100fps on a gtx 1660. Ive added some optimizations and have decompiled some broken shaders so that the recomp doesn't have the same performance/quality issues as xenia. Uncapped xenia can only run the game at 70fps, while this recomp runs at 240fps on my machine.

Showcase Video: https://youtu.be/Kih42KlocII?si=WeSh2FvBYrwQuNB-

Currently only supports windows, Linux is planned though. This project is still very early on and personally I dont have a Steam Deck to work on compatibility.

## Hardware Requirements

Requires the retail Viva Pinata Trouble in Paradise disc. Steam Deck is not supported yet. Windows x86-64 only.

### Minimum

- OS: Windows 11 version 1909 or later
- Processor: Intel Core i5-4460 3.2 GHz 4 Core or AMD Ryzen 3 1200, or equivalent
- Memory: 16 GB RAM
- GPU: Nvidia GTX 1660 Ti or AMD Radeon RX 5600 XT or better
- Storage: 15 GB available space
- IO: A controller or a gaming mouse with forward and back buttons

### Recommended
- OS: Windows 11 version 1909 or later
- Processor: Intel Core i7-9700K or AMD Ryzen 7 3700X, or equivalent
- Memory: 32 GB RAM
- GPU: Nvidia RTX 3050 or AMD RX 6600 or better
- Storage: 15 GB available space
- IO: A controller or a gaming mouse with forward and back buttons

## How to Install
You can download and install the game from https://gamejolt.com/games/retip/1087631 If you use their launcher you will get trophies on GameJolt for the actual achievements you would get on Xbox Live.
Otherwise you can download it here, Its the same build just without GameJolt.

Once downloaded and ran, you will be prompted to select a Iso file, This should be a copy of the disk from a legitimate copy of the game. You can follow https://github.com/xenia-canary/xenia-canary/wiki/Quickstart#how-to-rip-games for more details.

After extracting, you can press F5 to manage the mods, The latest 1.12.1 update includes a ThunderStore mod browser that allows you to download user made mods directly from the recomp. Im looking into getting r2modman support so that the external Thunderstore Mod manager works.

## Features

Everything below is new to ReTiP. Most of it is configurable via F4 Menu. Id do ingame menus but all the Viva Pinata menus are hardcoded.

### Graphics

- Custom Aspect ratios via "AspectRatio" value in F4 menu.
- Four quality presets, Low through Ultra via launch menu.
- Anisotropic filtering and Mipmap bias control.
- Graphics toggles to help low end hardware by cutting off Shadows, Ambient Occlusion, Post Processing etc.
- Unlocked FPS with optional caps and VSync.
- Texturepacks.
- Shaderpacks.
- Ice shader that would be broken in xenia is fixed in the recomp.

### Quality of Life

- Unlocked frame rate with a way to cap the fps back to the original fps or vsync.
- Field of view adjustment, By adjusting the aspect ratio the FOV will change as well.
- Skip the in-game cutscenes with a mod I uploaded to thunderstore.
- Partial Unlimited Garden space, Its not complete but it does work with store items. (included and enabled by default)
- Ill need to update this list more later... (I ran out of time)

### Mods

- Built-in mod manager
- TexturePacks
- ShaderPacks
- AudioPacks
- DataPacks
- Lua Script mods

### Platforms and Languages

- Windows on DX12
- Linux, Soon.
- macOS, Soon.
- Language can be changed if you using The Goopie Launcher, Ill need to add it to the launch menu.

## Credits
- [Franksy32](https://https://github.com/Franksy32) For providing the unlimited garden space patches
- [Smash-chu](https://smash-chu.carrd.co/) For the Title Artwork
- [birabittoh](https://github.com/birabittoh) For the Github Building Workflows
- [Zorkats](https://github.com/Zorkats) For Mouse and Keyboard Support
