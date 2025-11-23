set (renderer_core
    src/VulkanRenderer.cpp include/VulkanRenderer/VulkanRenderer.h
    src/Instance.cpp include/VulkanRenderer/Instance.h
)

set (renderer_util
    src/Common.cpp include/VulkanRenderer/Common.h
)

source_group("Core" FILES ${renderer_core})
source_group("Util" FILES ${renderer_util})

add_library(VulkanRenderer STATIC
    ${renderer_core}
    ${renderer_util}
)

target_include_directories(VulkanRenderer PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(VulkanRenderer PUBLIC 
    ${VULKAN_LIBRARIES} 
    ${SDL3_LIBRARIES}
    ${SPDLOG_LIBRARIES}
)

target_include_directories(VulkanRenderer PUBLIC
    ${VULKAN_HEADERS}
    ${SDL3_HEADERS}
    ${VMA_HEADERS}
    ${GLM_HEADERS}
    ${SPDLOG_HEADERS}
)