#pragma once

extern Engine::Application* Engine::CreateApplication(); 

int main() {

	auto application = Engine::CreateApplication();
	application->Run();
	delete application;
	return 0;
}