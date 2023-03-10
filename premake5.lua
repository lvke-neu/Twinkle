workspace "Twinkle"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Twinkle/3rdparty/GLFW/include"

include "Twinkle/3rdparty/GLFW"

project "Twinkle"
	location "Twinkle"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "TwinklePch.h"
	pchsource "Twinkle/src/TwinklePch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/3rdparty/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

		links 
	{ 
		"GLFW",
		"opengl32.lib"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TWINKLE_PLATFORM_WINDOWS",
			"TWINKLE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "TWINKLE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TWINKLE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TWINKLE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Twinkle/3rdparty/spdlog/include",
		"Twinkle/src"
	}

	links
	{
		"Twinkle"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TWINKLE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TWINKLE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TWINKLE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TWINKLE_DIST"
		optimize "On"