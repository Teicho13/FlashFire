#pragma once
#include <SDL_rect.h>

namespace FF
{
    class pickup
    {
    public:
        pickup(float x, float y, bool powerUp);
        void Draw();

    private:
        bool m_IsPowerUp = false;
        float m_Size = 0.0f;
        SDL_FPoint m_position {0.f,0.f};
    };
}

