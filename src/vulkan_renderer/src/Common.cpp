#include "VulkanRenderer/Common.h"

#include <spdlog/sinks/stdout_color_sinks.h>

bool md_renderer::InitializeLogger()
{
	g_logger = spdlog::stdout_color_mt("VulkanRenderer");
	if (!g_logger)
		return false;
	
	g_logger->info("Logger initialized successfully");
	return true;
}
