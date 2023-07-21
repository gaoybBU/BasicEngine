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

    enum class EventCategory {
        None = 0,
        EventCategoryWindow = BIT(0),
        EventCategoryApp = BIT(1),
        EventCategorboardyKey = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryInput   = BIT(4)
    };

    class ENG_API Event {
        friend class EventDispatcher;
    public:
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual EventCategory GetEventCategory() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category) {
            return static_cast<int>(GetEventCategory()) & static_cast<int>(category);
        }
    protected:
        bool m_isProtected = false;
    };

    #define EVENT_TYPE(type) static EventType GetType() { return EventType::type; } \
                         EventType GetEventType() const override { return GetType(); } \
                         const char* GetName() const override { return #type; }

    #define EVENT_CATEGORY(category) EventCategory GetEventCategory() const override { return EventCategory::category; };

    class EventDispatecher {
      
        
    };
};
