#include "Engine.h"

#include <iostream>
#include <SDL_log.h>

#include <VulkanRenderer.h>

md::Engine::Engine()
	: m_pWindow(new Window())
	, m_Renderer(new VulkanRenderer())
{
	std::cout << "Hello from Engine\n";
}

void md::Engine::Init()
{
	m_Renderer->Init();
	m_pWindow->Init({});
}

void md::Engine::Run()
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

void md::Engine::Shutdown()
{
	m_Renderer->Shutdown();
}
