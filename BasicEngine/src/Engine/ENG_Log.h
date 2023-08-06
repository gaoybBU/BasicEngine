#pragma once
#include<memory>

#include"Core.h"
#include"spdlog/spdlog.h"
#include"spdlog/sinks/stdout_color_sinks.h"

namespace Engine {

    class ENG_API ENG_Log
    {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#ifdef _ASSERTION
    #define ENG_CORE_INFO(...) ::Engine::ENG_Log::GetCoreLogger()->info(__VA_ARGS__)
    #define ENG_CORE_TRACE(...) ::Engine::ENG_Log::GetCoreLogger()->trace(__VA_ARGS__)
    #define ENG_CORE_WARN(...) ::Engine::ENG_Log::GetCoreLogger()->warn(__VA_ARGS__)
    #define ENG_CORE_ERROR(...) ::Engine::ENG_Log::GetCoreLogger()->error(__VA_ARGS__)

    #define ENG_INFO(...) ::Engine::ENG_Log::GetClientLogger()->info(__VA_ARGS__)
    #define ENG_TRACE(...) ::Engine::ENG_Log::GetClientLogger()->trace(__VA_ARGS__)
    #define ENG_WARN(...) ::Engine::ENG_Log::GetClientLogger()->warn(__VA_ARGS__)
    #define ENG_ERROR(...) ::Engine::ENG_Log::GetClientLogger()->error(__VA_ARGS__)
#elif
    #define ENGINE_CORE_INFO(...) 
    #define ENGINE_CORE_TRACE(...)
    #define ENGINE_CORE_WARN(...) 
    #define ENGINE_CORE_ERROR(...) 

    #define ENGINE_CLIENT_INFO(...) 
    #define ENGINE_CLIENT_TRACE(...)
    #define ENGINE_CLIENT_WARN(...) 
    #define ENGINE_CLIENT_ERROR(...)
#endif