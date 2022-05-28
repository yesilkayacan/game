#pragma once

#include "Event.h"

namespace Engine
{
	enum class AppEvents
	{
		None,
		WindowClose
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		virtual const char* GetName() const override { return "WindowClose"; };

		virtual EventCategory GetCategory() const override { return EventCategory::EventCategoryApplication; }

		virtual int GetEventType() const override { return (int)AppEvents::WindowClose; }
	};
}