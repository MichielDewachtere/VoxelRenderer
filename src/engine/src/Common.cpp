#include "Engine/Common.h"

#include <spdlog/sinks/stdout_color_sinks.h>

bool md_engine::InitializeLoggers()
{
	g_logger = spdlog::stdout_color_mt("Engine");
	if (!g_logger)
		return false;
	
	g_logger->info("Engine logger initialized successfully");

	g_sdlLogger = spdlog::stdout_color_mt("SDL");
	if (g_sdlLogger == nullptr)
		return false;

	g_sdlLogger->info("SDL logger initialized successfully");

	return true;
}
