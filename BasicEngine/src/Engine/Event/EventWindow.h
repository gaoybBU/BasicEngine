#pragma once

#include "Event.h"

#include <sstream>

// WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,

//    EventCategoryWindow

namespace Engine {
    class ENG_API EventWindow : public Event {
    public:
        EVENT_CATEGORIES(EventCategoryWindow, None)
    };

    class ENG_API EventWindowClose : public EventWindow {
    public:
        EVENT_TYPE(WindowClose)
        
    };

    class ENG_API EventWindowResize : public EventWindow {
    public:
        EventWindowResize(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "Window Resize Event: width:" << m_Width << " height:" << m_Height;
        }
        EVENT_TYPE(WindowResize)
    private:
        unsigned int m_Width, m_Height;
    };

    class ENG_API EventWindowFocus: public EventWindow {
        EVENT_TYPE(WindowFocus)
    };

    class ENG_API EventWindowLostFocus : public EventWindow {
        EVENT_TYPE(WindowLostFocus)
    };

    class ENG_API EventWindowMoved : public EventWindow {
        EVENT_TYPE(WindowMoved)
    };
}