cmake_minimum_required(VERSION 4.2.0)

project(VoxelRenderer
        VERSION 0.1.0  
        LANGUAGES CXX)

# Set C++ standard version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Vulkan SDK
if (DEFINED ENV{VULKAN_SDK})
    set(VULKAN_SDK $ENV{VULKAN_SDK})
    message(STATUS "Found Vulkan SDK: ${VULKAN_SDK}")
else ()
    message(FATAL_ERROR "VULKAN_SDK environment variable not set!")
endif()

# Find ThirdParty
set (MD_THIRDPARTY "${CMAKE_CURRENT_SOURCE_DIR}/../../ThirdParty")

# Setup all thirdparty includes
set(THIRDPARTY "${CMAKE_SOURCE_DIR}/cmake/ThirdParty.cmake")
include("${THIRDPARTY}")

# ---- Global warning configuration ----
# Apply strict warnings to all targets.
if (MSVC)
    add_compile_options(
        /W4        # Warning level 4
        /WX        # Treat warnings as errors
        /permissive-  # Stricter C++ conformance
        /utf-8
    )
      add_compile_options(/utf-8)

else()
    add_compile_options(
        -Wall -Wextra -Wpedantic -Werror  # GCC / Clang
    )
endif()

# Enable folders in Visual Studio
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Add source tree
add_subdirectory("src\\app")
add_subdirectory("src\\engine")
add_subdirectory("src\\vulkan_renderer")