-- Premake5 script 

targetdir "../bin/%{cfg.buildcfg}/Run"
objdir "../bin/%{cfg.buildcfg}/Obj"

includedirs { ".", "%{prj.location}" }

debugdir "../bin/%{cfg.buildcfg}/Run"

-- Configurations

filter "configurations:Debug"
    defines { "DEBUG" }
    flags { "Symbols" }
    
filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"
    
-- Solution

solution "TeamUSA"
    configurations { "Debug", "Release" }
    startproject "Game"
    
-- Project(s)
project "Game"
    location "."
    kind "ConsoleApp"
    language "C++"
    files {
    "*.h", "*.cpp",
    "Actor/**.h", "Actor/**.cpp",
    "Engine/**.h", "Engine/**.cpp"
    }

