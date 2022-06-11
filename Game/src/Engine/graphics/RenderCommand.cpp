#include "epch.h"
#include "RenderCommand.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Engine 
{
	void RenderCommand::Init()
	{
		// glad: load all OpenGL function pointers
		// ---------------------------------------
		ENGINE_INFO("Initializing OpenGL");
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			ENGINE_ERROR("Failed to initialize GLAD!");
		}

		ENGINE_INFO(glGetString(GL_VENDOR));
		ENGINE_INFO(glGetString(GL_VERSION));

		//glEnable(GL_BLEND);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		//glEnable(GL_DEPTH_TEST);
	}

	void RenderCommand::Shutdown()
	{

	}

	void RenderCommand::SetViewport(uint32_t width, uint32_t height)
	{
		glViewport(0, 0, width, height);
	}

	void RenderCommand::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		glViewport(x, y, width, height);
	}
	
	void RenderCommand::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void RenderCommand::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}
	//void RenderCommand::DrawIndexed(const std::shared_ptr<OpenGLVertexArray>& vertexArray, uint32_t indexCount)
	//{
	//	uint32_t count = indexCount ? indexCount : vertexArray->GetIndexBuffer()->GetCount();
	//	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
	//	//glBindTexture(GL_TEXTURE_2D, 0);
	//}
}
