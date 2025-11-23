#ifndef ENGINE_CORE_WINDOW_H
#define ENGINE_CORE_WINDOW_H

#include <memory>
#include <string_view>

#include "SDLUtil.h"

namespace md_engine
{
    struct WindowData
    {
        std::string_view title = "app";
        uint16_t width = 800, height = 600;
    };

    class Window final
    {
    public:
        explicit Window() = default;
        ~Window();

        void Init(const WindowData& data);

    private:
        std::unique_ptr<SDL_Window, SDLDeleter> m_pWindow{ nullptr };
    };
}

#endif // ENGINE_CORE_WINDOW_H