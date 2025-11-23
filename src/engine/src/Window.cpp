#include "Window.h"

#include <iostream>
#include <ostream>

#include <SDL.h>

void md::Window::Init(const WindowData& data)
{
    if (SDL_Init(SDL_INIT_VIDEO) == false)
    {
        SDL_Log("SDL could not initialize! SDL error: %s\n", SDL_GetError());
        return;
    }

    // Tell SDL we want a Vulkan-capable window
    m_pWindow.reset(SDL_CreateWindow(
        data.title.data(),
        data.width, data.height,
		SDL_WINDOW_VULKAN
    ));

    if (m_pWindow == nullptr)
    {
        SDL_Log("Window could not be created! SDL error: %s\n", SDL_GetError());
        SDL_Quit();
    }
}
