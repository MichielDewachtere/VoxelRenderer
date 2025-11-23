#include "VulkanRenderer/Instance.h"

#include <SDL3/SDL_vulkan.h>

#include "VulkanRenderer/Common.h"

void md_renderer::Instance::Init()
{
	const VkApplicationInfo appInfo = GetApplicationInfo();
	const VkInstanceCreateInfo createInfo = GetCreateInfo(appInfo);

	if (vkCreateInstance(&createInfo, nullptr, &m_pInstance) != VK_SUCCESS)
		g_logger->error("Failed to create Vulkan instance!");
	else
		g_logger->info("Successfully created Vulkan instance");
}

void md_renderer::Instance::ShutDown()
{
	if (m_pInstance)
		vkDestroyInstance(m_pInstance, nullptr);

	g_logger->info("Successfully destroyed Vulkan instance");
}

VkApplicationInfo md_renderer::Instance::GetApplicationInfo()
{
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Voxel Renderer";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "md_engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_4;
	return appInfo;
}

VkInstanceCreateInfo md_renderer::Instance::GetCreateInfo(const VkApplicationInfo& appInfo)
{
	{
		uint32_t extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

		std::vector<VkExtensionProperties> extensions(extensionCount);

		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

		g_logger->info("available extensions:");
		for (const auto& extension : extensions)
			g_logger->info("\t{}", extension.extensionName);
	}

	uint32_t extensionCount = 0;
	auto extensions = SDL_Vulkan_GetInstanceExtensions(&extensionCount);
	
	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;
	createInfo.enabledExtensionCount = extensionCount;
	createInfo.ppEnabledExtensionNames = extensions;
	createInfo.enabledLayerCount = 0;

	return createInfo;
}
