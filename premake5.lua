--[[
This lua code file is used for premake5, a build tool, similar to cmake.
[https://premake.github.io/]
Download premake, and run the command:
/path/to/premake/executable/premake5 vs2019
to generate visual studios 2019 project files.
If another version of visual studios is desired, use the appropreate options in premake.


You **should** change the name of the workspace and the project.
you also **should** use this file to change project settings, and NOT use Visual Studios for that.
--]]

workspace("Tara-Template") 	--VS solution name
	architecture("x64")		--CPU architecture type. We only support 64 bit
	configurations{"Debug", "Release"}
	startproject("Project") --The project to run as an executable
	

--settings to make BEFORE including Tara's premake file
Tara_Included = true
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--include Tara, in a group called dependencies
group("Tara")
	include("Vendor/Tara")
group("")


--this is your actual project
project("Project")
	location("Project")
	kind("ConsoleApp")
	language("C++")
	cppdialect("C++17") --prefered C++19, but premake does not support that yet
	staticruntime("Off")
	
	targetdir("bin/"..outputdir.."/%{prj.name}")
	objdir("bin/int/"..outputdir.."/%{prj.name}")
	
	files({
		"%{prj.name}/**.h",
		"%{prj.name}/**.hpp",
		"%{prj.name}/**.c",
		"%{prj.name}/**.cpp"
	})
	
	includedirs({
		"%{prj.name}",
		"Vendor/Tara/Tara/src",
		"Vendor/Tara/%{Tara_IncludeDir.glad}",
		"Vendor/Tara/%{Tara_IncludeDir.loguru}",
		"Vendor/Tara/%{Tara_IncludeDir.glm}",
		"Vendor/Tara/%{Tara_IncludeDir.stb}",
		"Vendor/Tara/%{Tara_IncludeDir.json}",
		"Vendor/Tara/%{Tara_IncludeDir.lua}",
		"Vendor/Tara/%{Tara_IncludeDir.sol}",
	})
	
	
	links(Tara_Links)
	
	filter("system:Windows")
		system("windows")
		systemversion("latest")
		
		defines({})
		
		links({
			"opengl32.lib"
		})
	
	filter("system:linux")
		system("linux")
		systemversion("latest")
		toolset("clang")
		links({
			"GL",
			"X11", "dl", "pthread", "m", "z", --"Xtest", "Xfixes"
		})
	
	filter("")
	
	filter("configurations:Debug")
		runtime("Debug")
		defines("DEBUG")
		symbols("On")
		
	filter("configurations:Release")
		runtime("Release")
		defines("NDBUG")
		optimize("On")
	
	filter("")