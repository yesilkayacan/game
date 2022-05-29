#include "epch.h"
#include "Application.h"

#include "glad/glad.h"

namespace Engine
{
	Application::Application()
		:m_running(true)
	{
		Log::Init();
		ENGINE_INFO("Initializing the Engine");

		m_window = new Window();

		m_window->SetEventCallback(BIND_EVENT_FN(&Application::OnEvent));
	}


	void Application::OnEvent(Event& e)
	{
		ENGINE_INFO("Event: {0}", e.ToString());

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(&Application::OnWindowClose));
	}


	void Application::Run()
	{
		// glad: load all OpenGL function pointers
		// ---------------------------------------
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			ENGINE_ERROR("Failed to initialize GLAD!");
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


	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_running = false;
		return true;
	}

}