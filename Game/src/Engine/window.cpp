#include "epch.h"
#include "window.h"

#include "Engine/Events/ApplicationEvents.h"


namespace Engine
{
	Window::Window(const std::string& title, uint32_t width, uint32_t height)
	{
		m_WindowProp = WindowProps(title, width, height);
		Create();
	}

	Window::~Window()
	{
		Shutdown();
	}

	void Window::Create()
	{
		m_WindowData.Title = m_WindowProp.Title;
		m_WindowData.Width = m_WindowProp.Width;
		m_WindowData.Height = m_WindowProp.Height;

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

		m_window = glfwCreateWindow((int)m_WindowData.Width, (int)m_WindowData.Height, m_WindowData.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);

		SetCallbacks();

		// enable VSync
		glfwSwapInterval(1);
	}

	void Window::SetCallbacks()
	{
		// pass data to glfw
		glfwSetWindowUserPointer(m_window, &m_WindowData);

		// set event callbacks
		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});
	}

	void Window::Shutdown()
	{
		glfwDestroyWindow(m_window);
	}

	void Window::OnUpdate()
	{
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

}