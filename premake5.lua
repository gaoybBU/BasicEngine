workspace "BasicEngine"
    architecture "x86_64"
    startproject "SandBox"
    configurations { 
        "Debug",
        "Release"
    }
    flags {
        "MultiProcessorCompile"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Core"
    include "BasicEngine"
group ""

group "Misc"
    include "SandBox"
group ""
