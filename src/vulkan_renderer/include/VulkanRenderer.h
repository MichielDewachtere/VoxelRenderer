#ifndef VULKANRENDERER_VULKANRENDERER_H
#define VULKANRENDERER_VULKANRENDERER_H

#include <vulkan/vulkan.h>

namespace md
{
	class VulkanRenderer final
	{
	public:
		VulkanRenderer();
		~VulkanRenderer() = default;
	
		void Init();
		void Shutdown();

	private:
		VkInstance instance = VK_NULL_HANDLE;
	};
}

#endif //VULKANRENDERER_VULKANRENDERER_H