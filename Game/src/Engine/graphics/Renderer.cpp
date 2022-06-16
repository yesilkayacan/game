#include "epch.h"
#include "Renderer.h"

#include "RendererAPI.h"

namespace Engine
{
	void Renderer::Init()
	{
		RendererAPI::Init();
	}

	void Renderer::Shutdown()
	{
		RendererAPI::Shutdown();
	}

	void Renderer::BeginScene()
	{
		// Todo
		// initialize the camera
	}

	void Renderer::OnWindowResize(uint32_t width, uint32_t height)
	{
		RendererAPI::SetViewport(width, height);
	}

	void Renderer::Submit(const std::shared_ptr<Shader>& shader,
		const std::shared_ptr<VertexArray>& vertexArray)
	{
		shader->Bind();

		RendererAPI::DrawIndexed(vertexArray);
	}

	void Renderer::EndScene()
	{

	}
}
