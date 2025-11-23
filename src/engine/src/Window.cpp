#include "Engine/Window.h"

#include <vector>

#include <SDL.h>

#include "Engine/Common.h"

md_engine::Window::~Window()
{
	SDL_Quit();
}

void md_engine::Window::Init(const WindowData& data)
{
	if (SDL_Init(SDL_INIT_VIDEO) == false)
	{
		g_sdlLogger->error("SDL could not initialize! SDL error: {}", SDL_GetError());
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
		g_sdlLogger->error("Window could not be created! SDL error: {}", SDL_GetError());
		SDL_Quit();
	}
}
