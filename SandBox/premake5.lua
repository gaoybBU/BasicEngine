project "SandBox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir("../bin/" ..outputdir.. "/%{prj.name}")
    objdir("../intermediate/" ..outputdir.. "/%{prj.name}")
    files {
        "src/**.cpp",
        "src/**.h"
    }

    includedirs {
        "../BasicEngine/external/spdlog/include",
        "../BasicEngine/external/GLFW/include",
        "../BasicEngine/src"
    }

    links {
        "BasicEngine"
    }

    filter "system:windows"
        systemversion "latest"
        defines {
            "ENG_PLATFORM_WINDOWS"
        }