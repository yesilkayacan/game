#pragma once

#include "Engine.h"
#include "BasicDrawing.h"

namespace App
{
	class App : public Engine::Application
	{
	public:
		App();
		~App() = default;

	private:
		BasicDrawing m_Drawing;
		
		std::shared_ptr<Engine::Camera> m_MainCamera;

	private:
		virtual bool HandleEvent(Engine::Event & e) override;

		virtual void OnApplicationUpdate() override;
	};
}
