#pragma once

#include"Event.h"

//         MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
//  EventCategoryMouse

 
namespace Engine {
    class ENG_API EventMouseButton : public Event {
    public:
        EVENT_CATEGORIES(EventCategoryMouse, EventCategoryInput)
    };

    class ENG_API EventMouseButtonPressed : public EventMouseButton {
    public:
        EVENT_TYPE(MouseButtonPressed)
    };

    class ENG_API EventMouseButtonReleased : public EventMouseButton {
    public:
        EVENT_TYPE(MouseButtonPressed)
    };

    class ENG_API EventMouseMoved : public EventMouseButton {
    public:
        EVENT_TYPE(MouseMoved)
    };

    class ENG_API EventMouseScrolled : public EventMouseButton {
    public:
        EVENT_TYPE(MouseScrolled)
    };
}