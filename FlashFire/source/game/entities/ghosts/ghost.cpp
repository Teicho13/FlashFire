#include "ghost.h"

namespace FF
{
    void ghost::Initialize(const std::string& spritePath, int columns, int rows)
    {
        m_Sprite.reset(new sprite(spritePath,columns,rows));
    }

    void ghost::Draw() const
    {
        if (m_Sprite)
        {
            const auto displaySize = static_cast<float>(m_Size);
            const SDL_FRect tempRec{ m_Position.x - displaySize / 2, m_Position.y - displaySize / 2, displaySize, displaySize};
            m_Sprite->Draw(tempRec);
        }
    }
}

