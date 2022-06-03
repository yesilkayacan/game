#include "epch.h"
#include "window.h"

#include "Engine/Events/ApplicationEvents.h"
#include "Engine/Events/KeyEvents.h"

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

		ENGINE_INFO("Creating GLFW window");

		// glfw: initialize and configure
		// ------------------------------
		if (!glfwInit())
		{
			ENGINE_ERROR("GLFW faild to initialize!");
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_window = glfwCreateWindow((int)m_WindowData.Width, (int)m_WindowData.Height, m_WindowData.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		
		// pass data to glfw
		glfwSetWindowUserPointer(m_window, &m_WindowData);
		SetApplicationEventCallbacks();
		SetKeyEventCallbacks();

		// enable VSync
		glfwSwapInterval(1);
	}

	void Window::SetApplicationEventCallbacks()
	{
		// set application event callbacks
		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);
			});
	}


	void Window::SetKeyEventCallbacks()
	{
		// set key event callbacks
		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
			}
		});

		//glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int keycode)
		//{
		//	WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		//	KeyTypedEvent event(keycode);
		//	data.EventCallback(event);
		//});
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