project "Copper-Math"
    location ""
    kind "ConsoleApp"
    language "C++"  
    cppdialect "C++17"

    targetdir("../Tests")
    objdir("../Tests/Int")

    files {

        "**.h",
        "**.cpp"

    }

    includedirs {

        "CMath",
        "../GLM/include"

    }

    defines {

        "INCLUDE_GLM"

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