#pragma once

#include "glm/glm.hpp"

namespace Engine
{
	class Camera
	{
	public:
		~Camera() = default;

		void Init();

		static std::shared_ptr<Camera> Create();

		void Rotate();
		void Translate();

		glm::mat4 GetViewMatrix();

	private:
		glm::mat4 m_View;
	};
}
