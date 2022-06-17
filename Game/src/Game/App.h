#pragma once

#include "Engine.h"

namespace App
{
	class App : public Engine::Application
	{
	public:
		App();
		~App() = default;

	private:
		std::shared_ptr<Engine::VertexArray> m_SquareVertexArray;
		std::shared_ptr<Engine::VertexArray> m_VertexArray;
		std::shared_ptr<Engine::Shader> m_Shader;

		std::shared_ptr<Engine::Camera> m_MainCamera;

	private:
		virtual bool HandleEvent(Engine::Event & e) override;

		virtual void OnApplicationUpdate() override;
	};
}
