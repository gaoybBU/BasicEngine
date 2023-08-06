#include "WindowWindows.h"

namespace Engine {
    static bool s_GLFWInitialized = false;
    Window* Window::Create(const WindowProperties& properties) {
        return new WindowWindows(properties);
    };

    WindowWindows::WindowWindows(const WindowProperties& properties)
    {
        Init(properties);
    }

    WindowWindows::~WindowWindows()
    {
        Shutdown();
    }

    void WindowWindows::OnUpdate()
    {
        glfwPollEvents();
    }

    void WindowWindows::SetVSync(bool enabled)
    {
        m_Data.VSync = enabled;
    }

    bool WindowWindows::IsVSync() const
    {
        return m_Data.VSync;
    }

    void WindowWindows::Init(const WindowProperties& properties)
    {
        m_Data.Title = properties.Title;
        m_Data.Width = properties.Width;
        m_Data.Height = properties.Height;

        ENG_CORE_INFO("Creating window {0} ({1}, {2})", properties.Title, properties.Width, properties.Height);

        if (!s_GLFWInitialized) {
            int error = glfwInit();
            ENG_CORE_ASSERT(error, "GLFW could not be initialized"); 
            // Tell GLFW to not create an OpenGL context
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            s_GLFWInitialized = true;
        }
        m_Window = glfwCreateWindow(properties.Width, properties.Height, properties.Title.c_str(), nullptr, nullptr);
    }
    void WindowWindows::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }
}
