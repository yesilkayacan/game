#pragma once

#include "Event.h"

namespace Engine
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		EVENT_TYPE_DEFFINITION(WindowClose)
	};
}