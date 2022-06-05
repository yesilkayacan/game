#pragma once

#include "OpenGLVertexArray.h"
#include "glm/glm.hpp"

namespace Engine
{
	// Low level controls of the renderer
	// currently using OPENGL
	class RenderCommand
	{
	public:
		static void Init();
		static void Shutdown();

		static void SetViewport(uint32_t width, uint32_t height);
		static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);

		static void SetClearColor(const glm::vec4& color);
		static void Clear();
		
		static void DrawIndexed(const std::shared_ptr<OpenGLVertexArray>& vertexArray, uint32_t indexCount = 0);
	};
}
