#pragma once

#include "Events/Event.h"

#include "GLFW/glfw3.h"

#include <string>
#include <functional>

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

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

	public:
		Window(const std::string& title = "Engine",
			uint32_t width = 1600,
			uint32_t height = 900);
		~Window();

		void OnUpdate();

		// Window attributes
		void SetEventCallback(const EventCallbackFn& callback) { m_WindowData.EventCallback = callback; }
		uint32_t GetWidth() { return m_WindowProp.Width; }
		uint32_t GetHeight() { return m_WindowProp.Height; }

	private:
		GLFWwindow* m_window;
		WindowProps m_WindowProp;
		
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_WindowData;

	private:
		void Create();
		void Shutdown();
		void SetApplicationEventCallbacks();
		void SetKeyEventCallbacks();
		
	};
}
