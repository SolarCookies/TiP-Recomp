# Viva Piñata: Trouble in Paradise Recompiled

## Setup
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
- 3 Extract the USA version of the iso to the ```assets/``` folder, the default xex sould be located here: ```assets/default.xex```

- 4 Run ```RegenAndRebuild.bat``` to run the recompile process and build
- 5 Run ```Play.bat``` to move the exe to the root and run it with the default arguments
