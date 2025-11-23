set (app_app
    src/main.cpp
)

source_group("App" FILES ${app_app})

add_executable(App ${app_app})

target_link_libraries(App PUBLIC
        Engine
        VulkanRenderer
        ${SDL3_LIBRARIES}
)

target_include_directories(App PUBLIC
    ${SDL3_HEADERS}
    ${GLM_HEADERS}
    ${SPDLOG_HEADERS}
)