project "BasicEngine"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"

    targetdir("../bin/" ..outputdir.. "/%{prj.name}")
    objdir("../intermediate/" ..outputdir.. "/%{prj.name}")
    
    -- pchheader "EnginePCH.h"
    -- pchsource "src/EnginePCH.cpp"

    files {
        "src/**.cpp",
        "src/**.h"
    }
    
    includedirs {
        "src",
        "external/spdlog/include",
        "external/GLFW/include"
    }

    libdirs{
        "external/GLFW/lib-vc2022"
    }

    links {
        "glfw3"
    }


    filter "system:windows"
        systemversion "latest"
        defines {
            "ENG_PLATFORM_WINDOWS",
            "ENG_BUILD_DLL"
        }

    postbuildcommands {
        ("{COPYFILE} %{cfg.targetdir}/BasicEngine.dll ../bin/"..outputdir.."/SandBox")
    }
    
     