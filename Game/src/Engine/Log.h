#pragma once

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Engine
{
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}


// Core logger
#define ENGINE_INFO(...)	::Engine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ENGINE_ERROR(...)	::Engine::Log::GetCoreLogger()->error(__VA_ARGS__)

// Client logger
#define APP_INFO(...)		::Engine::Log::GetClientLogger()->info(__VA_ARGS__)
#define APP_ERROR(...)		::Engine::Log::GetClientLogger()->error(__VA_ARGS__)
