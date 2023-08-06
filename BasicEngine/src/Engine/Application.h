#pragma once

#include<memory>

#include "Core.h"
#include "Window.h"

namespace Engine {

	class ENG_API Application 
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}