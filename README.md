<img width="3347" height="2198" alt="image" src="https://github.com/user-attachments/assets/8841c75d-1d5b-43f5-b19e-050b05fb7d08" />

Created with [Rexglue-SDK](https://github.com/rexglue/rexglue-sdk)

This Recomp has a strict no AI rule, No Vibe Coding, No AI generated Assets, No AI assisted Disassembly/Analysis

The goal of this project is to move away from emulating the game on xenia, with this the game is now moddable the same way the PC Port of the first game is with function hooking. While right now the renderer is the same as Xenia's we plan on replacing it in the near future. If you have any issues with this Recomp please submit a bug report on the Issues page

Showcase Video: https://youtu.be/Kih42KlocII?si=WeSh2FvBYrwQuNB-

Currently only supports windows, Linux is planned though. This project is still very early on so you will run into issues, if you do please report them in the github issues tab, Just make sure before you do no one else as made that same issue.

## Setup
- 1 Download the latest Launcher somewhere on the C drive (Depending on your system you might need to disable the antivirus to download or extract)
- 2 Obtain a legal copy of TiP's Iso (World) (I dont support piracy)
- 3 Inside the launcher press "Select Iso"
- 4 Once Selected the Iso will start to extract, if it doesn't work make sure the name is normalized aka "C:/Games/" not "C:/Games but with a space and a $/"
- 5 Once its extracted it will say "Download", Press it
- 6 Now that the recompiled exe is downloaded you can press "Launch"
- 7 If an update is out the launcher will force you to update, this is by design. As we rapidly fix bugs we want people to be using to latest version.

## Building from scratch
- 1 Clone and Build the Rexglue SDK https://github.com/rexglue/rexglue-sdk/

```
git clone --recursive https://github.com/rexglue/rexglue-sdk.git
cd rexglue-sdk
cmake --preset win-amd64
cmake --build --preset win-amd64-relwithdebinfo --target install
```
- 2 Clone TiP-Recomp
```
cd ../
git clone https://github.com/SolarCookies/TiP-Recomp.git
```
- 3 Extract the (world) version of the iso to the ```assets/``` folder, the default xex sould be located here: ```assets/default.xex```

- 4 Run ```RegenAndRebuild.bat``` to run the recompile process and build
- 5 Run ```Play.bat``` to move the exe to the root and run it with the default arguments

## Credits
- [Franksy32](https://https://github.com/Franksy32) For providing the unlimited garden space patches
- [Smash-chu](https://smash-chu.carrd.co/) For the Title Artwork
- [birabittoh](https://github.com/birabittoh) For the Github Building Workflows
