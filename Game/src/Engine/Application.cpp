#include "Application.h"

#include <iostream>

#include "glad/glad.h"


namespace Engine
{
	Application::Application()
	{
		std::cout << "Initializing the Engine" << std::endl;

		m_window = new window();
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
		while (true)
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			m_window->OnUpdate();
		}

		glfwTerminate();
	}


}