#ifndef VULKANRENDERER_CORE_INSTANCE_H
#define VULKANRENDERER_CORE_INSTANCE_H

#include <vulkan/vulkan.h>

namespace md_renderer
{
	class Instance final
	{
	public:
		Instance() = default;
		~Instance() = default;

		void Init();
		void ShutDown();

	private:
		VkInstance m_pInstance = VK_NULL_HANDLE;

		static VkApplicationInfo GetApplicationInfo();
		static VkInstanceCreateInfo GetCreateInfo(const VkApplicationInfo& appInfo);
	};
}

#endif // VULKANRENDERER_CORE_INSTANCE_H