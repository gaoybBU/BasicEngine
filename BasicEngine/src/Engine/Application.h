#pragma once
#include "Core.h"

namespace Engine {

	class ENG_API Application 
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}