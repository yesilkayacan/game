#pragma once

#include <string>

#define BIND_EVENT_FN(fn) std::bind(fn, this, std::placeholders::_1)

#define EVENT_TYPE_DEFFINITION(type) \
	static EventType GetStaticType() { return EventType::type; }\
	virtual EventType GetEventType() const override { return GetStaticType(); }\
	virtual const char* GetName() const override { return #type; }

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
		WindowClose,
		KeyPressed, KeyReleased,
	};


	class Event
	{
	public:
		bool Handled = false;

	public:
		virtual ~Event() = default;

		virtual std::string ToString() const { return GetName(); };

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
	};


	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		/* 
		F will be deduced by the compiler
		T is the event class type to be processed
		 */
		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled |= func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};
}
