project "Game"
	kind "ConsoleApp"
    language "C++"
	cppdialect "C++17"
	staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "epch.h"
	pchsource "src/epch.cpp"

    files
	{
		"src/**.h",
		"src/**.cpp"
    }

    includedirs
	{
        "%{prj.location}/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.GLM}",
        "%{IncludeDir.spdlog}"
    }

    links
	{
        "%{LibraryDir.GLFW}/glfw3_mt.lib",
		"opengl32.lib",
        "Glad"
	}

    filter "configurations:Debug"
        defines "GAME_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "GAME_RELEASE"
        runtime "Release"
        optimize "on"
