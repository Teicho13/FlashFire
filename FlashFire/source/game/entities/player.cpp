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
            constexpr SDL_FRect tempRec{ 150, 150, 32, 32};
            m_AnimatedSprite->Draw(tempRec);
        }
    }

    void player::Update(const float deltaTime)
    {
        if (m_AnimatedSprite)
        {
            m_AnimatedSprite->Update(deltaTime);
        }
    }
}
