workspace "Copper-Math"
    architecture "x64"
    configurations { "Debug", "Release" }

project "Copper-Math"
    location ""
    kind "ConsoleApp"
    language "C++"  
    cppdialect "C++17"

    targetdir("Tests")
    objdir("Tests/Int")

    files {

        "CMath/**.h",
        "CMath/**.cpp"

    }

    includedirs {

        "CMath"

    }

    filter "system:windows"
        systemversion "latest"

        defines {

            "CM_WINDOWS",

        }
    
    filter "configurations:Debug"
        defines "CM_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "CM_RELEASE"
        runtime "Release"
        optimize "on"