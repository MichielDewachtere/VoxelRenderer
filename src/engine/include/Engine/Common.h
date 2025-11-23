#ifndef ENGINE_UTIL_COMMON_H
#define ENGINE_UTIL_COMMON_H

#include <memory>

#include <spdlog/logger.h>

namespace md_engine
{
	inline std::shared_ptr<spdlog::logger> g_logger{ nullptr };
	inline std::shared_ptr<spdlog::logger> g_sdlLogger{ nullptr };

	bool InitializeLoggers();
}

#endif // ENGINE_UTIL_COMMON_H