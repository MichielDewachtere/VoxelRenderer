#include "VulkanRenderer/VulkanRenderer.h"

#include "VulkanRenderer/Common.h"

md_renderer::VulkanRenderer::VulkanRenderer()
	: m_pInstance(std::make_unique<Instance>())
{
    InitializeLogger();
    g_logger->info("Hello from Vulkan Renderer");
}

void md_renderer::VulkanRenderer::Init()
{
	m_pInstance->Init();
}

void md_renderer::VulkanRenderer::Shutdown()
{
	m_pInstance->ShutDown();
}
