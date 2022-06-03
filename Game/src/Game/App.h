#pragma once

#include "Engine.h"

namespace App
{
	class App : public Engine::Application
	{
	public:
		App() = default;
		~App() = default;

	private:
		virtual bool HandleEvent(Engine::Event & e) override;
	};
}
