#include "Application.h"
#include "Event/Event.h"
#include "ENG_Log.h"
#include <stdio.h>

namespace Engine {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}
	void Application::Run() {
		while (true);
	}
}
