#pragma once

#include"ENG_Log.h"

#ifdef ENG_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication(); 


int main() {
	Engine::ENG_Log::Init();
	Engine::ENG_Log::GetClientLogger()->info("Client Info");
	Engine::ENG_Log::GetCoreLogger()->trace("Core Trace");
	
	auto application = Engine::CreateApplication();
	application->Run();
	delete application;
	return 0;
}

#endif