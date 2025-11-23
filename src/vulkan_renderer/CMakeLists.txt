set (renderer_core
    src/VulkanRenderer.cpp include/VulkanRenderer.h
)

source_group("Core" FILES ${renderer_core})

add_library(VulkanRenderer STATIC
    ${renderer_core}
)

target_include_directories(VulkanRenderer PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(VulkanRenderer PUBLIC ${VULKAN_LIBRARIES} ${SDL3_LIBRARIES})

target_include_directories(VulkanRenderer PUBLIC
    ${VULKAN_HEADERS}
    ${SDL3_HEADERS}
    ${VMA_HEADERS}
    ${GLM_HEADERS}
)