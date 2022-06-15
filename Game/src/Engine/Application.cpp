#include "epch.h"
#include "Application.h"

#include "graphics/Renderer.h"
#include "graphics/RendererAPI.h"

namespace Engine
{
	Application::Application()
		:m_running(true), m_app(this)
	{
		Log::Init();
		ENGINE_INFO("Initializing the Engine");

		m_window = new Window();

		m_window->SetEventCallback(BIND_EVENT_FN(&Application::OnEvent));

		Renderer::Init();
		RendererAPI::SetViewport(m_window->GetWidth(), m_window->GetHeight());
	}

	void Application::OnEvent(Event& e)
	{
		ENGINE_INFO("Event: {0}", e.ToString());

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(&Application::OnWindowClose));

		if (!e.Handled)
			m_app->HandleEvent(e);
	}

	void Application::Run()
	{
		// render loop
		// -----------
		while (m_running)
		{
			RendererAPI::SetClearColor({ 0.2f, 0.3f, 0.3f, 0.1f});
			RendererAPI::Clear();

			m_app->OnApplicationUpdate();

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