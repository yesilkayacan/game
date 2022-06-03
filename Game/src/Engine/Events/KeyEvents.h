#pragma once
#include "Event.h"

#include <sstream>

namespace Engine
{
	class KeyEvent : public Event
	{
	protected:
		int m_KeyCode;

	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}
	};


	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		EVENT_TYPE_DEFFINITION(KeyPressed)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

	private:
		int m_RepeatCount;
	};


	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		EVENT_TYPE_DEFFINITION(KeyReleased)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}
	};
}