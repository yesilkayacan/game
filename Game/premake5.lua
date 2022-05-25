project "Game"
	kind "ConsoleApp"
    language "C++"
	cppdialect "C++17"
	staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

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
        "%{IncludeDir.GLM}"
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
