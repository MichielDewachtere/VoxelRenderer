#ifndef VULKANRENDERER_VULKANRENDERER_H
#define VULKANRENDERER_VULKANRENDERER_H

#include <memory>

#include "Instance.h"

namespace md_renderer
{
	class VulkanRenderer final
	{
	public:
		VulkanRenderer();
		~VulkanRenderer() = default;
	
		void Init();
		void Shutdown();

	private:
		std::unique_ptr<Instance> m_pInstance;
	};
}

#endif //VULKANRENDERER_VULKANRENDERER_H