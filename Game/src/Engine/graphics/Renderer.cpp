#include "epch.h"
#include "Renderer.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "RendererAPI.h"

namespace Engine
{
	void Renderer::Init()
	{
		RendererAPI::Init();
	}

	void Renderer::Shutdown()
	{

	}

	void Renderer::BeginScene()
	{

	}

	//void Renderer::Submit(const std::shared_ptr<OpenGLVertexArray>& vertexArray)
	//{
	//	//shader->Bind();
	//	//shader->SetMat4("u_ViewProjection", s_SceneData->ViewProjectionMatrix);
	//	//shader->SetMat4("u_Transform", transform);

	//	//vertexArray->Bind();
	//	//RenderCommand::DrawIndexed(vertexArray);
	//}

	void Renderer::EndScene()
	{

	}
}
