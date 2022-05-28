#pragma once

#include <string>

namespace Engine
{
	enum class EventCategory
	{
		None,
		EventCategoryApplication,
	};

	class Event
	{
	public:
		bool Handled = false;

	public:
		virtual ~Event() = default;

		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); };
		virtual EventCategory GetCategory() const = 0;

		virtual int GetEventType() const = 0;
	};
}
