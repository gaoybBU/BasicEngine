#pragma once

#include "Event.h"

#include <sstream>

// WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,

//    EventCategoryWindow

namespace Engine {
    class ENG_API EventWindowClose : public Event {
    public:
        EVENT_TYPE(WindowClose)
        EVENT_CATEGORY(EventCategoryWindow)
    };

    class ENG_API EventWindowResize : public Event {
    public:
        EventWindowResize(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "Window Resize Event: width:" << m_Width << " height:" << m_Height;
        }
        EVENT_TYPE(WindowResize)
        EVENT_CATEGORY(EventCategoryWindow)
    private:
        unsigned int m_Width, m_Height;
    };

    class ENG_API EventWindowFocus: public Event{
        EVENT_TYPE(WindowFocus)
        EVENT_CATEGORY(EventCategoryWindow)
    };

    class ENG_API EventWindowLostFocus : public Event{
        EVENT_TYPE(WindowLostFocus)
        EVENT_CATEGORY(EventCategoryWindow)
    };

    class ENG_API EventWindowMoved : public Event{
        EVENT_TYPE(WindowMoved)
        EVENT_CATEGORY(EventCategoryWindow)
    };
}