project "BasicEngine"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"

    targetdir("../bin/" ..outputdir.. "/%{prj.name}")
    objdir("../intermediate/" ..outputdir.. "/%{prj.name}")
    
    files {
        "src/**.cpp",
        "src/**.h"
    }
    
    includedirs {
        "src",
        "external/spdlog/include"
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
    
     