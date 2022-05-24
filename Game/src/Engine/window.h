#pragma once

#include "GLFW/glfw3.h"
#include <string>

namespace Engine
{
	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& title = "Engine",
			uint32_t width = 1600,
			uint32_t height = 900)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	class window
	{
	public:
		window(const std::string& title = "Engine",
			uint32_t width = 1600,
			uint32_t height = 900);
		~window();

		void OnUpdate();

		uint32_t GetWidth() { return m_width; }
		uint32_t GetHeight() { return m_height; }

	private:
		GLFWwindow* m_window;
		std::string m_title;
		uint32_t m_width;
		uint32_t m_height;

	private:
		void Create();
		void Shutdown();
		
	};
}
