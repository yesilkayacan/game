#pragma once

#include "window.h"

namespace Engine
{
	class Application
	{
	public:
		Application();
		~Application();

		void Run();
	private:
		window* m_window;
		
	};
}
