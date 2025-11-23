#include "VulkanRenderer.h"

#include <iostream>

md::VulkanRenderer::VulkanRenderer()
{
	std::cout << "Hello from Vulkan Renderer\n";
}

void md::VulkanRenderer::Init()
{
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Voxel Renderer";
    appInfo.apiVersion = VK_API_VERSION_1_4; // 1.4 may not be available in loader yet

    VkInstanceCreateInfo create{};
    create.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    create.pApplicationInfo = &appInfo;

    if (vkCreateInstance(&create, nullptr, &instance) != VK_SUCCESS)
        std::cout << "Failed to create Vulkan instance!\n";
    else
        std::cout << "Successfully created Vulkan instance\n";
}

void md::VulkanRenderer::Shutdown()
{
    if (instance)
        vkDestroyInstance(instance, nullptr);

    std::cout << "Successfully destroyed Vulkan instance\n";
}