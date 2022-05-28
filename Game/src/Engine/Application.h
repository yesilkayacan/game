#pragma once

#include "window.h"
#include "Engine/Events/Event.h"

#include "Engine/Events/ApplicationEvents.h"

namespace Engine
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void Run();
	private:
		Window* m_window;
		bool m_running;
		
	private:
		void OnWindowClose(WindowCloseEvent& e);
	};
}
