<img width="3347" height="2198" alt="image" src="https://github.com/user-attachments/assets/8841c75d-1d5b-43f5-b19e-050b05fb7d08" />

Created with [Rexglue-SDK](https://github.com/rexglue/rexglue-sdk)

This Recomp has a strict no AI rule, No Vibe Coding, No AI generated Assets, No AI assisted Disassembly/Analysis

Showcase Video: https://youtu.be/Kih42KlocII?si=WeSh2FvBYrwQuNB-

## Setup
- 1 Download the latest Launcher (Depending on your system you might need to disable the antivirus to download or extract)
- 2 Obtain a legal copy of TiP's Iso (World) (I dont support piracy)
- 3 Inside the launcher press "Select Iso"
- 4 Once Selected the Iso will start to extract
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
