#pragma once
#include <memory>
#include <SDL_rect.h>
#include <SDL_render.h>

#include "core/graphics/animatedSprite.h"
#include "core/graphics/sprite.h"

namespace FF
{
    enum class direction : std::uint8_t { none, up, down, left, right };
    class map;
    class player
    {
    public:
        player() = default;
        ~player() = default;

        void Initialize();

        sprite* GetSprite() const;
        SDL_FPoint GetPosition() const;

        void Draw();
        void Update(float deltaTime);
        void Move(float deltaTime);

        void NextDirection(float deltaTime);
        void SetDirection(int32_t direction);
        bool NextTileIsWalkable() const;

        map* m_MapPointer = nullptr;
    private:
        std::unique_ptr<animatedSprite> m_AnimatedSprite = nullptr;
        SDL_FPoint m_Position {48.f,48.f};
        int m_Size = 32;
        
        float m_Speed = 100.f;
        direction m_NextDirection = direction::none;
        direction m_Direction = direction::none;
    };
}


