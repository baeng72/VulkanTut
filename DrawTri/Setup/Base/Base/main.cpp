//#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class HelloTriangleApplication {
	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 600;
	GLFWwindow* window;
	void initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);//don't want opengl
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);//don't allow window resize
		window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
	}

	void initVulkan() {

	}
	void mainLoop() {
		while (window&&!glfwWindowShouldClose(window)) {
			glfwPollEvents();
		}

	}
	void cleanup() {
		glfwDestroyWindow(window);
		glfwTerminate();

	}
public:
	void run() {
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();
	}
};

int main() {
	HelloTriangleApplication app;

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;

}

