<img width="3347" height="2198" alt="image" src="https://github.com/user-attachments/assets/8841c75d-1d5b-43f5-b19e-050b05fb7d08" />

Created with [Rexglue-SDK](https://github.com/rexglue/rexglue-sdk)

This Repo has a strict no AI rule, No Vibe Coding, No AI generated Assets, No AI assisted Disassembly/Analysis.

The priority of this project is not to be playable on low end hardware or to be fully optimized. I started this project as a means to mod Trouble in Paradise, Adding cheats, Reverse Engineering the asset formats, Texture Packs, and adding other cool shit. Im not a purest when it comes to making this recomp be fully native. Eventually I or someone else will add a native renderer that will lower the system requirements, But thats not my priority. It runs on my system (rtx 3050) at 200fps, and thats good enough for me. Thats over 6x the normal speed of the game on hardware that is arguably low end desktop specs with todays standards with unreal engine games. Ive added some optimizations and have decompiled some broken shaders so that the recomp doesnt have the same performance and issues as xenia.

Showcase Video: https://youtu.be/Kih42KlocII?si=WeSh2FvBYrwQuNB-

Currently only supports windows, Linux is planned though. This project is still very early on and personally I dont have a Steam Deck to work on compatibility.

## Setup
- 1 Download the latest [Goopie](https://goopie.xyz) and install it, (Preferably at the defualt location, you can adjust the game location in the settings)
- 2 Obtain a legal copy of TiP's Iso (World) (We dont support piracy)
- 3 Inside the launcher press "Select Iso"
- 4 Once Selected the Iso will start to extract, if it doesn't work make sure the name is normalized aka "C:/Games/" not "C:/Games but with a space and a $/"
- 5 Once its extracted it will say "Download" or "Update", Press it
- 6 Now that the recompiled exe is downloaded you can press "Launch"

- If you run into any issues launching the game, third-party programs like "rivatuner" can cause the game to crash

## Building from scratch (We are on a Fork of Rexglue 0.8.1 https://github.com/SolarRecomps/rexglue-ostentation/tree/dev)
- 1 Clone and Build the https://github.com/SolarRecomps/rexglue-ostentation/tree/dev

- 2 Clone TiP-Recomp (The dev branch is what you should target for pull request)
```
cd ../
git clone https://github.com/SolarCookies/TiP-Recomp.git
```
- 3 Extract the (world) version of the iso to the ```assets/``` folder, the default xex sould be located here: ```assets/default.xex```

- 4 Run ```rexglue codegen``` to recompile the code from the xex
- 5 Run cmake build
- 6 Move the dlls for rexglue to the build dir then run the exe

## Credits
- [Franksy32](https://https://github.com/Franksy32) For providing the unlimited garden space patches
- [Smash-chu](https://smash-chu.carrd.co/) For the Title Artwork
- [birabittoh](https://github.com/birabittoh) For the Github Building Workflows
- [Zorkats](https://github.com/Zorkats) For Mouse and Keyboard Support
