#pragma once
#include <memory>
#include <SDL_rect.h>
#include <SDL_render.h>

#include "core/graphics/sprite.h"

namespace FF
{
    class player
    {
    public:
        player() = default;
        ~player() = default;

        void Initialize();

        sprite* GetSprite() const;

        void Draw();

    private:
        std::unique_ptr<sprite> m_Sprite = nullptr;
        SDL_Point m_Position {0,0};
    };
}


