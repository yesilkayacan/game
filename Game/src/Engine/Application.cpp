#include "epch.h"
#include "Application.h"

#include "glad/glad.h"

namespace Engine
{
	Application::Application()
		:m_running(true)
	{
		std::cout << "Initializing the Engine" << std::endl;

		m_window = new Window();
		m_window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}


	void Application::OnEvent(Event& e)
	{
		std::cout << e.ToString() << std::endl;

	}


	void Application::Run()
	{
		// glad: load all OpenGL function pointers
		// ---------------------------------------
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
		}

		// render loop
		// -----------
		while (m_running)
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			m_window->OnUpdate();
		}

		glfwTerminate();
	}

	Application::~Application()
	{
		delete m_window;
	}


	void Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_running = false;
	}

}