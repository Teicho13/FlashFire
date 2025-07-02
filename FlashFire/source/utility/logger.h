#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

class Log
{
public:


	static void Init()
	{
		auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		sink->set_pattern("[%T][%^%l%$][%n]: %v");
		auto logger = std::make_shared<spdlog::logger>("Console", sink);
		logger->set_level(spdlog::level::trace);
		spdlog::set_default_logger(logger);
	}

	template<typename FormatString, typename... Args>
	static void Debug(const FormatString& fmt, const Args&... args)
	{
		spdlog::debug(fmt, args...);
	}

	template<typename FormatString, typename... Args>
	static void Info(const FormatString& fmt, const Args&... args)
	{
		spdlog::info(fmt, args...);
	}

	template<typename FormatString, typename... Args>
	static void Warning(const FormatString& fmt, const Args&... args)
	{
		spdlog::warn(fmt, args...);
	}

	template<typename FormatString, typename... Args>
	static void Error(const FormatString& fmt, const Args&... args)
	{
		spdlog::error(fmt, args...);
	}

};

