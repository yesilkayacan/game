#include "window.h"
#include <iostream>


namespace Engine
{
	window::window(const std::string& title, uint32_t width, uint32_t height)
		: m_title(title), m_width(width), m_height(height)
	{
		Create();
	}

	window::~window()
	{
		Shutdown();
	}

	void window::Create()
	{
		std::cout << "Creating GLFW window" << std::endl;

		// glfw: initialize and configure
		// ------------------------------
		if (!glfwInit())
		{
			std::cout << "GLFW faild to initialize!" << std::endl;
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_window = glfwCreateWindow((int)m_width, m_height, m_title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_window);

		// enable VSync
		glfwSwapInterval(1);
	}

	void window::Shutdown()
	{
		glfwDestroyWindow(m_window);
	}

	void window::OnUpdate()
	{
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

}