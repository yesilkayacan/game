#include "epch.h"
#include "App.h"

#include "glad/glad.h"

namespace App
{
	App::App()
	{
		m_Drawing = BasicDrawing();

		m_MainCamera = Engine::Camera::Create();
	}

	bool App::HandleEvent(Engine::Event& e)
	{
		APP_INFO("Event: {0}", e.ToString());
		return false;
	}

	void App::OnApplicationUpdate()
	{
		Engine::Renderer::BeginScene();

		Engine::Renderer::Submit(m_Drawing.m_Shader, m_Drawing.m_SquareVertexArray);
		Engine::Renderer::Submit(m_Drawing.m_Shader, m_Drawing.m_VertexArray);
		
		//Engine::Renderer::Submit(m_Shader, m_SquareVertexArray);
		//Engine::Renderer::Submit(m_Shader, m_VertexArray);
	}
}
