#include "pickup.h"

#include "utility/debugLines.h"

namespace FF
{
    pickup::pickup(float x, float y, bool powerUp)
    {
        m_position.x = x;
        m_position.y = y;
        m_IsPowerUp = powerUp;
        m_Size = m_IsPowerUp ? 24.f : 8.f;
    }

    void pickup::Draw()
    {
        debugLines::DrawBoxFill(m_position.x,m_position.y,m_Size,m_Size, SDL_Color{ 255,255,255,255 });
    }
}
