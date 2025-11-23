#include "Engine/Engine.h"

#include <iostream>
#include <SDL_log.h>

#include <VulkanRenderer/VulkanRenderer.h>

#include "Engine/Common.h"

md_engine::Engine::Engine()
	: m_pWindow(new Window())
	, m_Renderer(new md_renderer::VulkanRenderer())
{
    InitializeLoggers();

    g_logger->info("Hello from Engine");
}

void md_engine::Engine::Init()
{
    m_pWindow->Init({});
    m_Renderer->Init();
}

void md_engine::Engine::Run()
{
	bool doContinue = true;
	while (doContinue)
    {
        SDL_Event e;

        // Get event data
        while (SDL_PollEvent(&e) == true)
        {
            // If event is quit type
            if (e.type == SDL_EVENT_QUIT)
            {
                // End the main loop
                doContinue = false;
            }
        }
    }
}

void md_engine::Engine::Shutdown()
{
    m_Renderer->Shutdown();
}
