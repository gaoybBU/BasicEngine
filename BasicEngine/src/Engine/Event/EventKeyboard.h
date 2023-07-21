#pragma once

#include "Event.h"

// KeyPressed, KeyReleased,


namespace Engine {
    class EventKeyPressed : public Event {
    public:
        inline int GetKeyCode() const { return m_keyCode; }
        EVENT_TYPE(KeyPressed)
        EVENT_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        int m_keyCode;
    };

    class EventKeyReleased : public Event {

    };
}