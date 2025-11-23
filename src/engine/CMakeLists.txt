# Engine library

set (engine_core
    src/Engine.cpp include/Engine.h
    src/Window.cpp include/Window.h
)

set (engine_renderer
    src/Renderer.cpp include/Renderer.h
)

set(engine_util
    src/SDLUtil.cpp include/SDLUtil.h
)

source_group("Core" FILES ${engine_core})
source_group("Renderer" FILES ${engine_renderer})
source_group("Util" FILES ${engine_util})

add_library(Engine STATIC
    ${engine_core}
    ${engine_renderer}
    ${engine_util}
)

target_link_libraries(Engine PUBLIC VulkanRenderer ${SDL3_LIBRARIES})

# Add include directories
target_include_directories(Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${SDL3_HEADERS}
    ${GLM_HEADERS}
)