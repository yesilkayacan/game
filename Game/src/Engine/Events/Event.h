#pragma once

#include <string>

#define BIND_EVENT_FN(fn) std::bind(fn, this, std::placeholders::_1)

namespace Engine
{
	enum class EventCategory
	{
		None,
		EventCategoryApplication,
	};


	enum class EventType
	{
		None,
		WindowClose
	};


	class Event
	{
	public:
		bool Handled = false;

	public:
		virtual ~Event() = default;

		virtual std::string ToString() const { return GetName(); };

		virtual EventType GetStaticType() const = 0;
		virtual const char* GetName() const = 0;
	};


	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		// F will be deduced by the compiler
		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			m_Event.Handled |= func(static_cast<T&>(m_Event));
			return true;
		}
	private:
		Event& m_Event;
	};
}
