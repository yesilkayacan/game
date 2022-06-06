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
		//std::shared_ptr<Engine::OpenGLVertexArray> m_VertexArray;
		uint32_t m_VertexArray;
		std::shared_ptr<Engine::VertexBuffer> m_VertexBuffer;
		std::shared_ptr<Engine::IndexBuffer> m_IndexBuffer;
		std::shared_ptr<Engine::Shader> m_Shader;

	private:
		virtual bool HandleEvent(Engine::Event & e) override;

		virtual void OnApplicationUpdate() override;
	};
}
