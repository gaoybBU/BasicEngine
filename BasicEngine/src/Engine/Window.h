#pragma once

#include <functional>
#include <string>

#include "Engine/Core.h"
#include "Engine/Event/Event.h"

namespace Engine {

    struct WindowProperties {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProperties(
            const std::string& title = "Basic Engine",
            unsigned int width = 1920,
            unsigned int height = 1080
        )
            : Title(title), Width(width), Height(height) {}
    };

    class ENG_API Window {
    public:
        using EventCallbackFunction = std::function<void(Event&)>;

        virtual ~Window() {};
        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProperties& properties = WindowProperties());
    };
}