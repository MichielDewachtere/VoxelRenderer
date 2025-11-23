#ifndef VULKANRENDERER_UTIL_COMMON_H
#define VULKANRENDERER_UTIL_COMMON_H

#include <spdlog/spdlog.h>

namespace md_renderer
{
	inline std::shared_ptr<spdlog::logger> g_logger;

	bool InitializeLogger();
}

#endif // VULKANRENDERER_UTIL_COMMON_H