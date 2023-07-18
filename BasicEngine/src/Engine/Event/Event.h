#pragma once

#include "Engine/Core.h"

#include <string>
#include <functional>

namespace Engine {

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCatergory {
		None = 0,
		EventCatergoyMouse
	};
}

