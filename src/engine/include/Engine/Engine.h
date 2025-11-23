#ifndef ENGINE_CORE_ENGINE_H
#define ENGINE_CORE_ENGINE_H

#include <memory>

#include "Window.h"

namespace md_renderer
{
	class VulkanRenderer;
}

namespace md_engine
{
	class Engine final
	{
	public:
		Engine();
		~Engine() = default;

		void Init();
		void Run();
		void Shutdown();

	private:
		std::unique_ptr<Window> m_pWindow{ nullptr };
		md_renderer::VulkanRenderer* m_Renderer{ nullptr };
	};
}

#endif // ENGINE_ENGINE_H