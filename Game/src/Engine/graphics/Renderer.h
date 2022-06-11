#pragma once

#include "VertexArray.h"
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

		//static void Submit(const std::shared_ptr<OpenGLVertexArray>& vertexArray);

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};
	};
}
