#pragma once

#include "window.h"
#include "Engine/Events/Event.h"

#include "Engine/Events/ApplicationEvents.h"
#include"Engine/Events/KeyEvents.h"

#include "Engine/graphics/OpenGLVertexArray.h"

namespace Engine
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		//virtual HandleEvents(Event& e) = 0;

		void OnEvent(Event& e);

		void Run();
	private:
		Window* m_window;
		bool m_running;
		Application* m_app;

		std::shared_ptr<OpenGLVertexArray> m_VertexArray;
		std::shared_ptr<OpenGLVertexArray> m_SquareVA;
		
	private:
		virtual void OnApplicationUpdate() {};

		bool OnWindowClose(WindowCloseEvent& e);

		virtual bool HandleEvent(Event& e) { return false; }
	};
}
