#pragma once

#include "VertexArray.h"
#include "Shader.h"

#include "glm/glm.hpp"

namespace Engine
{
	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene();
		static void EndScene();

		static void OnWindowResize(uint32_t width, uint32_t height);
		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};
	};
}
