#include "epch.h"
#include "App.h"

namespace App
{
	bool App::HandleEvent(Engine::Event& e)
	{
		APP_INFO("Event: {0}", e.ToString());
		return false;
	}
}
