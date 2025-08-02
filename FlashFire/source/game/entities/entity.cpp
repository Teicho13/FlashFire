#include "entity.h"

namespace FF
{
    void entity::SetPosition(int newX, int newY)
    {
        m_Position.x = newX;
        m_Position.y = newY;
    }

    sprite* entity::GetSprite() const
    {
        return m_Sprite.get();
    }

    SDL_FPoint entity::GetPosition() const
    {
        return m_Position;
    }

    void entity::Initialize(const std::string& texturePath, int columns, int rows)
    {
        m_Sprite = std::make_unique<sprite>(texturePath,columns,rows);
    }

    void entity::Draw()
    {
        if (m_Sprite)
        {
            const auto displaySize = static_cast<float>(m_Size);
            const SDL_FRect tempRec{ m_Position.x - displaySize / 2, m_Position.y - displaySize / 2, displaySize, displaySize};
            m_Sprite->Draw(tempRec);
        }
    }
}

