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
        EventCategoryboardyKey = BIT(2),
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

    #define EVENT_TYPE(type) static EventType GetStaticType() { return EventType::type; } \
                         EventType GetEventType() const override { return GetType(); } \
                         const char* GetName() const override { return #type; }

    #define EVENT_CATEGORIES(category1, category2) EventCategory GetEventCategory() const override \
                        { return static_cast<EventCategory>(static_cast<int>(EventCategory::category1) | \
                                                            static_cast<int>(EventCategory::category2)); };

    class EventDispatcher {
        template<typename T>
        using EventFunction = std::function <bool(T&)>;
    public:
        EventDispatcher(Event& event)
            : m_Event(event) {}

        template<typename T>
        bool Dispatch(EventFunction<T> func) {
            if (m_Event.GetEventType() == T::GetStaticType()) {
                m_Event.m_Handled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }
        
    private:
        Event& m_Event;
    };
};
