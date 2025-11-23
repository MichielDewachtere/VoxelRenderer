#ifndef ENGINE_CORE_ENGINE_H
#define ENGINE_CORE_ENGINE_H

#include <memory>

#include "Window.h"

namespace md
{
	class VulkanRenderer;

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
		VulkanRenderer* m_Renderer{ nullptr };
	};
}

#endif // ENGINE_ENGINE_H