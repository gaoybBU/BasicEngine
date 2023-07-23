#pragma once

#include "Event.h"

// KeyPressed, KeyReleased,


namespace Engine {
    class ENG_API EventKey : public Event {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }
        EVENT_CATEGORIES(EventCategoryMouse, EventCategoryInput)
    protected:
        EventKey(int keycode)
            : m_KeyCode(keycode) {}
        int m_KeyCode;
    };

    class ENG_API EventKeyPressed : public EventKey {
    public:
        EVENT_TYPE(KeyPressed)

    };

    class ENG_API EventKeyReleased : public EventKey {
    public:
        EVENT_TYPE(KeyReleased)
    };
}