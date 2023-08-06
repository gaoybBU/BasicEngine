#include <BasicEngine.h>

class SandBox : public Engine::Application
{
public:
	SandBox() {};
	~SandBox() {};

};

Engine::Application* Engine::CreateApplication() {
	return new SandBox();
	
}


//#include <GLFW/glfw3.h>
//
//int main() {
//    glfwInit();
//    GLFWwindow* Window = glfwCreateWindow(1920, 1080, "Test", nullptr, nullptr);
//    while (true) {
//        glfwPollEvents();
//    }
//
//    return 0;
//}