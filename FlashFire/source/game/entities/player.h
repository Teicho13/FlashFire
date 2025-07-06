#pragma once
#include <memory>
#include <SDL_rect.h>
#include <SDL_render.h>

#include "core/graphics/animatedSprite.h"
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
        void Update(const float deltaTime);

        void SetDirection(int32_t direction);

    private:
        std::unique_ptr<animatedSprite> m_AnimatedSprite = nullptr;
        SDL_FPoint m_Position {0.f,0.f};
        int m_Size = 32;
        
        float m_Speed = 100.f;
        SDL_FPoint m_Direction {0.f,0.f};
    };
}


