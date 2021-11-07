# Tara-Template
A template for making games with the Tara Engine. Most things about this should change!

## Cloning
When cloning the repository, using the `--recursive` option. There are a number of submodules. A game engine is generally a pretty large project, and using libraries and tools made by other excellent people helps the process a lot!

Some of these submodules (json) take a while to clone. To be sure your terminal is not hanging, use the `--progress` option.

## Updating the Engine
It may be that you want to update the Engine. for that, use the command:
`git submodule update --init --recursive --progress`
This will go through all submodules and update them.

## Compilation Guide
Tara uses [Premake](https://premake.github.io/) as its build configuration manager. Premake is similar to cmake, but much simpler and easier to use. It can generate project files for pretty much all platforms.

### Windows
Compiling on windows should be very straightforward. All that is required is some version of Visual Studios that supports C++17. For this example, VS 2019 will be assumed. If using a different version, then replace the year number in the commands with the appropriate one. Tara has not been tested on versions of Visual Studios older than 2019.

#### Step 1: Generate project files.
To generate project files, use [Premake](https://premake.github.io/).

	cd root/of/Tara-Template
	path/to/premake/premake5.exe vs2019
	
After this, Visual Studios project files are generated.

#### Step 2: Build.
Using Visual Studios, build the project as normal. All required libraries are in the project (under the ```Vendor``` folder)
To do this from the command line (as debug): 

	msbuild Tara.sln /p:Configuration=Debug /p:Platform="x64"
	
## Credit for other parts
A lot of my knowledge about game engine design comes from [The Cherno's Youtube series on the topic](https://www.youtube.com/watch?v=JxIZbV_XjAs&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=1), and I referenced some of the code I wrote following those tutorials while making this engine. Some things, (like window abstraction) are likely to be very similar, but others, like some of how I design input and layers, will be very different.

Anything in the "Vendor/Tara/Vendor" folder is third-party, and the license, if available, is in the folder of each individual part. As far as possible, these are also git submodules. The `premake5.lua` file directly in "Vendor/Tara/Vendor" is used for the various projects for these submodules.

Other submodules may be found in "Vendor/Tara/Tara/lua". These are lua libraries that make lua easier to use.

