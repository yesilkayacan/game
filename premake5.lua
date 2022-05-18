
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Game/dependencies/glfw/include"
IncludeDir["Glad"] = "%{wks.location}/Game/dependencies/GLAD/include"
IncludeDir["GLM"] = "%{wks.location}/Game/dependencies/GLM"

LibraryDir = {}
LibraryDir["GLFW"] = "%{wks.location}/Game/dependencies/glfw/lib-vc2022"

workspace "Game"
	architecture "x86_64"
	startproject "Game"

	configurations
	{
		"Debug",
		"Release",
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "Game/dependencies/GLAD"
group ""

include "Game"
