#pragma once

#include "Engine/Window.h"
#include "Engine/ENG_Log.h"

#include <GLFW/glfw3.h>
#include <string>

namespace Engine {

    class WindowWindows : public Window {
    public:
        WindowWindows(const WindowProperties& properties);
        virtual ~WindowWindows();

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.Width; };
        inline unsigned int GetHeight() const override { return m_Data.Height; };

        inline void SetEventCallback(const EventCallbackFunction& callback) override { m_Data.EventCallback = callback; };
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;
    private:
        virtual void Init(const WindowProperties& properties);
        virtual void Shutdown();
    private:
        GLFWwindow* m_Window;
        
        struct WindowData {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFunction EventCallback;    
        };

        WindowData m_Data;
    };
}

