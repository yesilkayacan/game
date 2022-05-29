#pragma once

#include "Event.h"

namespace Engine
{


	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		virtual const char* GetName() const override { return "WindowClose"; };

		virtual EventType GetStaticType() const override { return EventType::WindowClose; };
	};
}