#include "player.h"
#include "core/managers/textureManager.h"

namespace FF
{
    void player::Initialize()
    {
        m_AnimatedSprite.reset(new animatedSprite("assets/images/characters/pacman.png",12,1,true,true));
        m_AnimatedSprite->getAnimation()->SetMaxFrames(2);
        m_AnimatedSprite->SetAnimationOffset(0);
    }

    sprite* player::GetSprite() const
    {
        return m_AnimatedSprite.get();
    }

    void player::Draw()
    {
        if (m_AnimatedSprite)
        {
            const auto displaySize = static_cast<float>(m_Size);
            const SDL_FRect tempRec{ m_Position.x, m_Position.y, displaySize, displaySize};
            m_AnimatedSprite->Draw(tempRec);
        }
    }

    void player::Update(const float deltaTime)
    {
        if (m_AnimatedSprite)  m_AnimatedSprite->Update(deltaTime);

        m_Position.x += (m_Speed * m_Direction.x) * deltaTime;
        m_Position.y += (m_Speed * m_Direction.y) * deltaTime;
    }

    void player::SetDirection(const int32_t direction)
    {
        switch (direction)
        {
        default:
        case 100:
            m_Direction.x = 1.f;
            m_Direction.y = 0.f;
            m_AnimatedSprite->SetAnimationOffset(0);
            break;

        case 97:
            m_Direction.x = -1.f;
            m_Direction.y = 0.f;
            m_AnimatedSprite->SetAnimationOffset(3);
            break;

        case 115:
            m_Direction.x = 0.f;
            m_Direction.y = 1.f;
            m_AnimatedSprite->SetAnimationOffset(6);
            break;

        case 119:
            m_Direction.x = 0.f;
            m_Direction.y = -1.f;
            m_AnimatedSprite->SetAnimationOffset(9);
            break;
        }
    }
}
