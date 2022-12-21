#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Twinkle
{
	class TWINKLE_API Log
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
#define LOG_CORE_DEBUG(...)		Twinkle::Log::GetCoreLogger()->debug(__VA_ARGS__);
#define LOG_CORE_TRACE(...)		Twinkle::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define LOG_CORE_INFO(...)		Twinkle::Log::GetCoreLogger()->info(__VA_ARGS__);
#define LOG_CORE_WARN(...)		Twinkle::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define LOG_CORE_ERROR(...)		Twinkle::Log::GetCoreLogger()->error(__VA_ARGS__);
#define LOG_CORE_CRITICAL(...)	Twinkle::Log::GetCoreLogger()->critical(__VA_ARGS__);

#define LOG_APP_DEBUG(...)		Twinkle::Log::GetClientLogger()->debug(__VA_ARGS__);
#define LOG_APP_TRACE(...)		Twinkle::Log::GetClientLogger()->trace(__VA_ARGS__);
#define LOG_APP_INFO(...)		Twinkle::Log::GetClientLogger()->info(__VA_ARGS__);
#define LOG_APP_WARN(...)		Twinkle::Log::GetClientLogger()->warn(__VA_ARGS__);
#define LOG_APP_ERROR(...)		Twinkle::Log::GetClientLogger()->error(__VA_ARGS__);
#define LOG_APP_CRITICAL(...)	Twinkle::Log::GetClientLogger()->critical(__VA_ARGS__);
