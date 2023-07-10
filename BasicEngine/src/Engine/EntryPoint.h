#pragma once

#ifdef ENG_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication(); 


int main() {
	Engine::Log::Init();
	Engine::Log::GetClientLogger()->info("Client Info");
	Engine::Log::GetCoreLogger()->trace("Core Trace");
	
	auto application = Engine::CreateApplication();
	application->Run();
	delete application;
	return 0;
}

#endif