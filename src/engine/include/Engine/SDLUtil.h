#ifndef ENGINE_UTIL_SDLUTIL_H
#define ENGINE_UTIL_SDLUTIL_H

#include <SDL_video.h>
#include <SDL_render.h>

namespace md_engine
{
	struct SDLDeleter
	{
		void operator()(SDL_Window* window) const { SDL_DestroyWindow(window); }
		void operator()(SDL_Renderer* renderer) const { SDL_DestroyRenderer(renderer); }
	};
}

#endif // ENGINE_UTIL_SDLUTIL_H