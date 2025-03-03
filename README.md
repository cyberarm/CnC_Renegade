# Commando Engine
Porting Command & Conquer: Renegade to be multiplatform.

The focus is on getting the game to be playable. Porting tooling may be done later.

## Goals
* Native linux and mac port of the game
* Fulling working single player campaign
* Deprecate wwconfig for in-game options
* Replace all platform specific dependencies and APIs
* Headless console mode server (no graphics or audio inited)
* Functional multiplayer (20+ years of alternates will need to be reimplemented from the Tiberian Technologies scripts patch) to play on existing community servers
* Decouple frame rate from simulation and use a fixed physics timestep (See https://gafferongames.com/post/fix_your_timestep)

### Notable
* Hardware without Vulkan or modern OpenGL support will not be supported 

## Porting
- [x] Renamed all source files to be lowercase
- [x] Renamed most folders to be lowercase
- [ ] Fix enough errors and warnings to be able to start replacing bits

### TODO
- [ ] SDL3 | Window and main game loop
- [ ] SDL3 | replace mutex.h and thread.h with SDL3 implementations
- [ ] SDL3_net | replace win32 sockets with SDL3_net equivalents
- [ ] STD C++ | replace StringClass and WideStringClass with std::string and std::wstring
- [ ] STD C++ | replace VectorClass and co. with std::vector
- [ ] SDL3 & FFMPEG | replace BinkMovie with ffmpeg and SDL3 implementation
- [ ] SDL3 & SDL_Sound & mojoAL | replace miles sound system
- [ ] SDL3 | replace DirectInput with SDL3
- [ ] SDL3 & OpenGL/Vulkan | replace DirectX
- [ ] Reimplement | GameSpy server game listings
- [ ] webview | Possibly replace WebBrowser with webview 
- [ ] ArduinoJSON or other json library | replace window's registry with a json hash

### Purge
- [ ] SafeDisk

## Development
* TODO: See CMakeLists.txt in the root directory for the dependencies.

## Contributing
### Please Note
* All contributions must be compatible with the GPL license and restrictions.
* Changes adding FMOD or other GPL incompatible dependencies will not be accepted.
* Platform specific changes will be accepted on a case by case basis.
  * The goal is to have as little platform specific code as possible and rely on modern C++ and SDL3 to bridge the gap.
* Feature dumps and major changes not previously discussed in an issue will probably not be accepted. _Communicate first, please._

### Do it
1. Create your own fork
2. Create a feature branch
3. Implement your changes
4. Submit your pull request
5. Profit*

## Code of Conduct
**Everyone interacting with this project are expected behave in a polite and constructive manner. ⚑**

* **Be friendly.** Use welcoming and inclusive language.
* **Be empathetic.** Be respectful of differing viewpoints and experiences.
* **Be respectful.** When we disagree, we do so in a polite and constructive manner.
* **Be considerate.** Remember that decisions are often a difficult choice between competing priorities. Focus on what is best for the community. Keep discussions around technology choices constructive and respectful.
* **Be patient and generous.** If someone asks for help it is because they need it. When documentation is available that answers the question, politely point them to it. If the question is off-topic, suggest a more appropriate online space to seek help.
* **Try to be concise.** Read the discussion before commenting in order to not repeat a point that has been made.

The above list is an excerpt from [conduct.gnome.org](https://conduct.gnome.org/). CC-SA

___
### Original EA README below
___

# Command & Conquer Renegade

This repository includes source code for Command & Conquer Renegade. This release provides support to the [Steam Workshop](https://steamcommunity.com/workshop/browse/?appid=2229890) for the game.


## Dependencies

If you wish to rebuild the source code and tools successfully you will need to find or write new replacements (or remove the code using them entirely) for the following libraries;

- DirectX SDK (Version 8.0 or higher) (expected path `\Code\DirectX\`)
- RAD Bink SDK - (expected path `\Code\BinkMovie\`)
- RAD Miles Sound System SDK - (expected path `\Code\Miles6\`)
- NvDXTLib SDK - (expected path `\Code\NvDXTLib\`)
- Lightscape SDK - (expected path `\Code\Lightscape\`)
- Umbra SDK - (expected path `\Code\Umbra\`)
- GameSpy SDK - (expected path `\Code\GameSpy\`)
- GNU Regex - (expected path `\Code\WWLib\`)
- SafeDisk API - (expected path `\Code\Launcher\SafeDisk\`)
- Microsoft Cab Archive Library - (expected path `\Code\Installer\Cab\`)
- RTPatch Library - (expected path `\Code\Installer\`)
- Java Runtime Headers - (expected path `\Code\Tools\RenegadeGR\`)


## Compiling (Win32 Only)

To use the compiled binaries, you must own the game. The C&C Ultimate Collection is available for purchase on [EA App](https://www.ea.com/en-gb/games/command-and-conquer/command-and-conquer-the-ultimate-collection/buy/pc) or [Steam](https://store.steampowered.com/bundle/39394/Command__Conquer_The_Ultimate_Collection/).

### Renegade

The quickest way to build all configurations in the project is to open `commando.dsw` in Microsoft Visual Studio C++ 6.0 (SP5 recommended for binary matching to patch 1.037) and select Build -> Batch Build, then hit the “Rebuild All” button.

If you wish to compile the code under a modern version of Microsoft Visual Studio, you can convert the legacy project file to a modern MSVC solution by opening the `commando.dsw` in Microsoft Visual Studio .NET 2003, and then opening the newly created project and solution file in MSVC 2015 or newer.

NOTE: As modern versions of MSVC enforce newer revisions of the C++ standard, you will need to make extensive changes to the codebase before it successfully compiles, even more so if you plan on compiling for the Win64 platform.

When the workspace has finished building, the compiled binaries will be copied to the `/Run/` directory found in the root of this repository. 


### Free Dedicated Server
It’s possible to build the Windows version of the FDS (Free Dedicated Server) for Command & Conquer Renegade from the source code in this repository, just uncomment `#define FREEDEDICATEDSERVER` in [Combat\specialbuilds.h](Combat\specialbuilds.h) and perform a “Rebuild All” action on the Release config.


### Level Edit (Public Release)
To build the public release build of Level Edit, modify the LevelEdit project settings and add `PUBLIC_EDITOR_VER` to the preprocessor defines.


## Known Issues

The “Debug” configuration of the “Commando” project (the Renegade main project) will sometimes fail to link the final executable. This is due to Windows Defender incorrectly detecting RenegadeD.exe containing a virus (possibly due to the embedded browser code). Excluding the output `/Run/` folder found in the root of this repository in Windows Defender should resolve this for you.


## Contributing

This repository will not be accepting contributions (pull requests, issues, etc). If you wish to create changes to the source code and encourage collaboration, please create a fork of the repository under your GitHub user/organization space.


## Support

This repository is for preservation purposes only and is archived without support. 


## License

This repository and its contents are licensed under the GPL v3 license, with additional terms applied. Please see [LICENSE.md](LICENSE.md) for details.
